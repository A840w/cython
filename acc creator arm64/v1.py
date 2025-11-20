#!/usr/bin/env python3
import re
import bz2
import zlib
import struct

def extract_cython_strings(filename):
    with open(filename, 'r', errors='ignore') as f:
        content = f.read()
    
    # Pattern to find compressed string sections
    patterns = [
        # BZ2 compressed strings
        r'const char\* const cstring = "([^"]+)"',
        # Zlib compressed strings  
        r'const char\* const cstring = "([^"]+)"',
        # Raw UTF-8 strings
        r'const char\* const bytes = "([^"]+)"'
    ]
    
    all_strings = []
    
    for pattern in patterns:
        matches = re.findall(pattern, content, re.DOTALL)
        for match in matches:
            try:
                # Try BZ2 decompression
                decompressed = bz2.decompress(eval(f'b"{match}"'))
                all_strings.append(("BZ2", decompressed))
            except:
                try:
                    # Try zlib decompression
                    decompressed = zlib.decompress(eval(f'b"{match}"'))
                    all_strings.append(("ZLIB", decompressed))
                except:
                    # Treat as raw bytes
                    all_strings.append(("RAW", eval(f'b"{match}"')))
    
    return all_strings

if __name__ == "__main__":
    strings = extract_cython_strings("payload.c")
    for i, (comp_type, data) in enumerate(strings):
        print(f"String {i} ({comp_type}): {data[:100]}...")