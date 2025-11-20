
#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif 

#if defined(Py_LIMITED_API)
  #if !defined(CYTHON_LIMITED_API)
  #define CYTHON_LIMITED_API 1
  #endif
#elif defined(CYTHON_LIMITED_API)
  #ifdef _MSC_VER
  #pragma message ("Limited API usage is enabled with 'CYTHON_LIMITED_API' but 'Py_LIMITED_API' does not define a Python target version. Consider setting 'Py_LIMITED_API' instead.")
  #else
  #warning Limited API usage is enabled with 'CYTHON_LIMITED_API' but 'Py_LIMITED_API' does not define a Python target version. Consider setting 'Py_LIMITED_API' instead.
  #endif
#endif

#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x03080000
    #error Cython requires Python 3.8+.
#else
#define __PYX_ABI_VERSION "3_2_1"
#define CYTHON_HEX_VERSION 0x030201F0
#define CYTHON_FUTURE_DIVISION 1

#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(_WIN32) && !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#define __PYX_LIMITED_VERSION_HEX PY_VERSION_HEX
#if defined(GRAALVM_PYTHON)
  
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 1
  #define CYTHON_COMPILING_IN_CPYTHON_FREETHREADING 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_TYPE_SPECS
  #define CYTHON_USE_TYPE_SPECS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
  #define CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS 0
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_ASSUME_SAFE_SIZE
  #define CYTHON_ASSUME_SAFE_SIZE 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #undef CYTHON_USE_MODULE_STATE
  #define CYTHON_USE_MODULE_STATE 0
  #undef CYTHON_USE_SYS_MONITORING
  #define CYTHON_USE_SYS_MONITORING 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_AM_SEND
  #define CYTHON_USE_AM_SEND 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 1
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
  #undef CYTHON_USE_FREELISTS
  #define CYTHON_USE_FREELISTS 0
  #undef CYTHON_IMMORTAL_CONSTANTS
  #define CYTHON_IMMORTAL_CONSTANTS 0
#elif defined(PYPY_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_CPYTHON_FREETHREADING 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 1
  #ifndef CYTHON_USE_TYPE_SPECS
    #define CYTHON_USE_TYPE_SPECS 0
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
  #define CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #ifndef CYTHON_ASSUME_SAFE_SIZE
    #define CYTHON_ASSUME_SAFE_SIZE 1
  #endif
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #if PY_VERSION_HEX < 0x03090000
    #undef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #elif !defined(CYTHON_PEP489_MULTI_PHASE_INIT)
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #undef CYTHON_USE_MODULE_STATE
  #define CYTHON_USE_MODULE_STATE 0
  #undef CYTHON_USE_SYS_MONITORING
  #define CYTHON_USE_SYS_MONITORING 0
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PYPY_VERSION_NUM >= 0x07030C00)
  #endif
  #undef CYTHON_USE_AM_SEND
  #define CYTHON_USE_AM_SEND 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC (PYPY_VERSION_NUM >= 0x07031100)
  #endif
  #undef CYTHON_USE_FREELISTS
  #define CYTHON_USE_FREELISTS 0
  #undef CYTHON_IMMORTAL_CONSTANTS
  #define CYTHON_IMMORTAL_CONSTANTS 0
#elif defined(CYTHON_LIMITED_API)
  #ifdef Py_LIMITED_API
    #undef __PYX_LIMITED_VERSION_HEX
    #define __PYX_LIMITED_VERSION_HEX Py_LIMITED_API
  #endif
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 1
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_CPYTHON_FREETHREADING 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_TYPE_SPECS
  #define CYTHON_USE_TYPE_SPECS 1
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #endif
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
    #define CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS 0
  #endif
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_ASSUME_SAFE_SIZE
  #define CYTHON_ASSUME_SAFE_SIZE 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL (__PYX_LIMITED_VERSION_HEX >= 0x030C0000)
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #ifndef CYTHON_USE_MODULE_STATE
    #define CYTHON_USE_MODULE_STATE 0
  #endif
  #undef CYTHON_USE_SYS_MONITORING
  #define CYTHON_USE_SYS_MONITORING 0
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 0
  #endif
  #ifndef CYTHON_USE_AM_SEND
    #define CYTHON_USE_AM_SEND (__PYX_LIMITED_VERSION_HEX >= 0x030A0000)
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
  #ifndef CYTHON_USE_FREELISTS
  #define CYTHON_USE_FREELISTS 1
  #endif
  #undef CYTHON_IMMORTAL_CONSTANTS
  #define CYTHON_IMMORTAL_CONSTANTS 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 0
  #ifdef Py_GIL_DISABLED
    #define CYTHON_COMPILING_IN_CPYTHON_FREETHREADING 1
  #else
    #define CYTHON_COMPILING_IN_CPYTHON_FREETHREADING 0
  #endif
  #if PY_VERSION_HEX < 0x030A0000
    #undef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #elif !defined(CYTHON_USE_TYPE_SLOTS)
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #ifndef CYTHON_USE_TYPE_SPECS
    #define CYTHON_USE_TYPE_SPECS 0
  #endif
  #ifndef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #ifndef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    #undef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLIST_INTERNALS)
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING || PY_VERSION_HEX >= 0x030B00A2
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    #undef CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
    #define CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS 1
  #elif !defined(CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS)
    #define CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_ASSUME_SAFE_SIZE
    #define CYTHON_ASSUME_SAFE_SIZE 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    #undef CYTHON_FAST_GIL
    #define CYTHON_FAST_GIL 0
  #elif !defined(CYTHON_FAST_GIL)
    #define CYTHON_FAST_GIL (PY_VERSION_HEX < 0x030C00A6)
  #endif
  #ifndef CYTHON_METH_FASTCALL
    #define CYTHON_METH_FASTCALL 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #ifndef CYTHON_USE_MODULE_STATE
    #define CYTHON_USE_MODULE_STATE 0
  #endif
  #ifndef CYTHON_USE_SYS_MONITORING
    #define CYTHON_USE_SYS_MONITORING (PY_VERSION_HEX >= 0x030d00B1)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 1
  #endif
  #ifndef CYTHON_USE_AM_SEND
    #define CYTHON_USE_AM_SEND 1
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    #undef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS 0
  #elif !defined(CYTHON_USE_DICT_VERSIONS)
    #define CYTHON_USE_DICT_VERSIONS  (PY_VERSION_HEX < 0x030C00A5 && !CYTHON_USE_MODULE_STATE)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK 1
  #endif
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 1
  #endif
  #ifndef CYTHON_USE_FREELISTS
    #define CYTHON_USE_FREELISTS (!CYTHON_COMPILING_IN_CPYTHON_FREETHREADING)
  #endif
  #if defined(CYTHON_IMMORTAL_CONSTANTS) && PY_VERSION_HEX < 0x030C0000
    #undef CYTHON_IMMORTAL_CONSTANTS
    #define CYTHON_IMMORTAL_CONSTANTS 0  // definitely won't work
  #elif !defined(CYTHON_IMMORTAL_CONSTANTS)
    #define CYTHON_IMMORTAL_CONSTANTS (PY_VERSION_HEX >= 0x030C0000 && !CYTHON_USE_MODULE_STATE && CYTHON_COMPILING_IN_CPYTHON_FREETHREADING)
  #endif
#endif
#ifndef CYTHON_COMPRESS_STRINGS
  #define CYTHON_COMPRESS_STRINGS 1
#endif
#ifndef CYTHON_FAST_PYCCALL
#define CYTHON_FAST_PYCCALL  CYTHON_FAST_PYCALL
#endif
#ifndef CYTHON_VECTORCALL
#if CYTHON_COMPILING_IN_LIMITED_API
#define CYTHON_VECTORCALL  (__PYX_LIMITED_VERSION_HEX >= 0x030C0000)
#else
#define CYTHON_VECTORCALL  (CYTHON_FAST_PYCCALL)
#endif
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
  #if defined(__cplusplus)
    
    #if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
      #if __has_cpp_attribute(maybe_unused)
        #define CYTHON_UNUSED [[maybe_unused]]
      #endif
    #endif
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
  #define CYTHON_MAYBE_UNUSED_VAR(x) CYTHON_UNUSED_VAR(x)
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON && !CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_USE_CPP_STD_MOVE
  #if defined(__cplusplus) && (\
    __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1600))
    #define CYTHON_USE_CPP_STD_MOVE 1
  #else
    #define CYTHON_USE_CPP_STD_MOVE 0
  #endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#include <stdint.h>
typedef uintptr_t  __pyx_uintptr_t;
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus)
    
    #if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
      #if __has_cpp_attribute(fallthrough)
        #define CYTHON_FALLTHROUGH [[fallthrough]]
      #endif
    #endif
    #ifndef CYTHON_FALLTHROUGH
      #if __has_cpp_attribute(clang::fallthrough)
        #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
      #elif __has_cpp_attribute(gnu::fallthrough)
        #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
      #endif
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif
#ifndef Py_UNREACHABLE
  #define Py_UNREACHABLE()  assert(0); abort()
#endif
#ifdef __cplusplus
  template <typename T>
  struct __PYX_IS_UNSIGNED_IMPL {static const bool value = T(0) < T(-1);};
  #define __PYX_IS_UNSIGNED(type) (__PYX_IS_UNSIGNED_IMPL<type>::value)
#else
  #define __PYX_IS_UNSIGNED(type) (((type)-1) > 0)
#endif
#if CYTHON_COMPILING_IN_PYPY == 1
  #define __PYX_NEED_TP_PRINT_SLOT  (PY_VERSION_HEX < 0x030A0000)
#else
  #define __PYX_NEED_TP_PRINT_SLOT  (PY_VERSION_HEX < 0x03090000)
#endif
#define __PYX_REINTERPRET_FUNCION(func_pointer, other_pointer) ((func_pointer)(void(*)(void))(other_pointer))


#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif


#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#define __Pyx_BUILTIN_MODULE_NAME "builtins"
#define __Pyx_DefaultClassType PyType_Type
#if CYTHON_COMPILING_IN_LIMITED_API
    #ifndef CO_OPTIMIZED
    static int CO_OPTIMIZED;
    #endif
    #ifndef CO_NEWLOCALS
    static int CO_NEWLOCALS;
    #endif
    #ifndef CO_VARARGS
    static int CO_VARARGS;
    #endif
    #ifndef CO_VARKEYWORDS
    static int CO_VARKEYWORDS;
    #endif
    #ifndef CO_ASYNC_GENERATOR
    static int CO_ASYNC_GENERATOR;
    #endif
    #ifndef CO_GENERATOR
    static int CO_GENERATOR;
    #endif
    #ifndef CO_COROUTINE
    static int CO_COROUTINE;
    #endif
#else
    #ifndef CO_COROUTINE
      #define CO_COROUTINE 0x80
    #endif
    #ifndef CO_ASYNC_GENERATOR
      #define CO_ASYNC_GENERATOR 0x200
    #endif
#endif
static int __Pyx_init_co_variables(void);
#if PY_VERSION_HEX >= 0x030900A4 || defined(Py_IS_TYPE)
  #define __Pyx_IS_TYPE(ob, type) Py_IS_TYPE(ob, type)
#else
  #define __Pyx_IS_TYPE(ob, type) (((const PyObject*)ob)->ob_type == (type))
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_Is)
  #define __Pyx_Py_Is(x, y)  Py_Is(x, y)
#else
  #define __Pyx_Py_Is(x, y) ((x) == (y))
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsNone)
  #define __Pyx_Py_IsNone(ob) Py_IsNone(ob)
#else
  #define __Pyx_Py_IsNone(ob) __Pyx_Py_Is((ob), Py_None)
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsTrue)
  #define __Pyx_Py_IsTrue(ob) Py_IsTrue(ob)
#else
  #define __Pyx_Py_IsTrue(ob) __Pyx_Py_Is((ob), Py_True)
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsFalse)
  #define __Pyx_Py_IsFalse(ob) Py_IsFalse(ob)
#else
  #define __Pyx_Py_IsFalse(ob) __Pyx_Py_Is((ob), Py_False)
#endif
#define __Pyx_NoneAsNull(obj)  (__Pyx_Py_IsNone(obj) ? NULL : (obj))
#if PY_VERSION_HEX >= 0x030900F0 && !CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyObject_GC_IsFinalized(o) PyObject_GC_IsFinalized(o)
#else
  #define __Pyx_PyObject_GC_IsFinalized(o) _PyGC_FINALIZED(o)
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef Py_TPFLAGS_SEQUENCE
  #define Py_TPFLAGS_SEQUENCE 0
#endif
#ifndef Py_TPFLAGS_MAPPING
  #define Py_TPFLAGS_MAPPING 0
#endif
#ifndef Py_TPFLAGS_IMMUTABLETYPE
  #define Py_TPFLAGS_IMMUTABLETYPE (1UL << 8)
#endif
#ifndef Py_TPFLAGS_DISALLOW_INSTANTIATION
  #define Py_TPFLAGS_DISALLOW_INSTANTIATION (1UL << 7)
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#ifndef METH_FASTCALL
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #if PY_VERSION_HEX >= 0x030d00A4
  #  define __Pyx_PyCFunctionFast PyCFunctionFast
  #  define __Pyx_PyCFunctionFastWithKeywords PyCFunctionFastWithKeywords
  #else
  #  define __Pyx_PyCFunctionFast _PyCFunctionFast
  #  define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
  #endif
#endif
#if CYTHON_METH_FASTCALL
  #define __Pyx_METH_FASTCALL METH_FASTCALL
  #define __Pyx_PyCFunction_FastCall __Pyx_PyCFunctionFast
  #define __Pyx_PyCFunction_FastCallWithKeywords __Pyx_PyCFunctionFastWithKeywords
#else
  #define __Pyx_METH_FASTCALL METH_VARARGS
  #define __Pyx_PyCFunction_FastCall PyCFunction
  #define __Pyx_PyCFunction_FastCallWithKeywords PyCFunctionWithKeywords
#endif
#if CYTHON_VECTORCALL
  #define __pyx_vectorcallfunc vectorcallfunc
  #define __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET  PY_VECTORCALL_ARGUMENTS_OFFSET
  #define __Pyx_PyVectorcall_NARGS(n)  PyVectorcall_NARGS((size_t)(n))
#else
  #define __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET  0
  #define __Pyx_PyVectorcall_NARGS(n)  ((Py_ssize_t)(n))
#endif
#if PY_VERSION_HEX >= 0x030900B1
#define __Pyx_PyCFunction_CheckExact(func)  PyCFunction_CheckExact(func)
#else
#define __Pyx_PyCFunction_CheckExact(func)  PyCFunction_Check(func)
#endif
#define __Pyx_CyOrPyCFunction_Check(func)  PyCFunction_Check(func)
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_CyOrPyCFunction_GET_FUNCTION(func)  (((PyCFunctionObject*)(func))->m_ml->ml_meth)
#elif !CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_CyOrPyCFunction_GET_FUNCTION(func)  PyCFunction_GET_FUNCTION(func)
#endif
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_CyOrPyCFunction_GET_FLAGS(func)  (((PyCFunctionObject*)(func))->m_ml->ml_flags)
static CYTHON_INLINE PyObject* __Pyx_CyOrPyCFunction_GET_SELF(PyObject *func) {
    return (__Pyx_CyOrPyCFunction_GET_FLAGS(func) & METH_STATIC) ? NULL : ((PyCFunctionObject*)func)->m_self;
}
#endif
static CYTHON_INLINE int __Pyx__IsSameCFunction(PyObject *func, void (*cfunc)(void)) {
#if CYTHON_COMPILING_IN_LIMITED_API
    return PyCFunction_Check(func) && PyCFunction_GetFunction(func) == (PyCFunction) cfunc;
#else
    return PyCFunction_Check(func) && PyCFunction_GET_FUNCTION(func) == (PyCFunction) cfunc;
#endif
}
#define __Pyx_IsSameCFunction(func, cfunc)   __Pyx__IsSameCFunction(func, cfunc)
#if PY_VERSION_HEX < 0x03090000 || (CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000)
  #define __Pyx_PyType_FromModuleAndSpec(m, s, b)  ((void)m, PyType_FromSpecWithBases(s, b))
  typedef PyObject *(*__Pyx_PyCMethod)(PyObject *, PyTypeObject *, PyObject *const *, size_t, PyObject *);
#else
  #define __Pyx_PyType_FromModuleAndSpec(m, s, b)  PyType_FromModuleAndSpec(m, s, b)
  #define __Pyx_PyCMethod  PyCMethod
#endif
#ifndef METH_METHOD
  #define METH_METHOD 0x200
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)
#elif CYTHON_COMPILING_IN_GRAAL && defined(GRAALPY_VERSION_NUM) && GRAALPY_VERSION_NUM > 0x19000000
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) GraalPyFrame_SetLineNumber((frame), (lineno))
#elif CYTHON_COMPILING_IN_GRAAL
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) _PyFrame_SetLineNumber((frame), (lineno))
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyThreadState_Current PyThreadState_Get()
#elif !CYTHON_FAST_THREAD_STATE
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x030d00A1
  #define __Pyx_PyThreadState_Current PyThreadState_GetUnchecked()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#endif
#if CYTHON_USE_MODULE_STATE
static CYTHON_INLINE void *__Pyx__PyModule_GetState(PyObject *op)
{
    void *result;
    result = PyModule_GetState(op);
    if (!result)
        Py_FatalError("Couldn't find the module state");
    return result;
}
#define __Pyx_PyModule_GetState(o) (__pyx_mstatetype *)__Pyx__PyModule_GetState(o)
#else
#define __Pyx_PyModule_GetState(op) ((void)op,__pyx_mstate_global)
#endif
#define __Pyx_PyObject_GetSlot(obj, name, func_ctype)  __Pyx_PyType_GetSlot(Py_TYPE((PyObject *) obj), name, func_ctype)
#define __Pyx_PyObject_TryGetSlot(obj, name, func_ctype) __Pyx_PyType_TryGetSlot(Py_TYPE(obj), name, func_ctype)
#define __Pyx_PyObject_GetSubSlot(obj, sub, name, func_ctype) __Pyx_PyType_GetSubSlot(Py_TYPE(obj), sub, name, func_ctype)
#define __Pyx_PyObject_TryGetSubSlot(obj, sub, name, func_ctype) __Pyx_PyType_TryGetSubSlot(Py_TYPE(obj), sub, name, func_ctype)
#if CYTHON_USE_TYPE_SLOTS
  #define __Pyx_PyType_GetSlot(type, name, func_ctype)  ((type)->name)
  #define __Pyx_PyType_TryGetSlot(type, name, func_ctype) __Pyx_PyType_GetSlot(type, name, func_ctype)
  #define __Pyx_PyType_GetSubSlot(type, sub, name, func_ctype) (((type)->sub) ? ((type)->sub->name) : NULL)
  #define __Pyx_PyType_TryGetSubSlot(type, sub, name, func_ctype) __Pyx_PyType_GetSubSlot(type, sub, name, func_ctype)
#else
  #define __Pyx_PyType_GetSlot(type, name, func_ctype)  ((func_ctype) PyType_GetSlot((type), Py_##name))
  #define __Pyx_PyType_TryGetSlot(type, name, func_ctype)\
    ((__PYX_LIMITED_VERSION_HEX >= 0x030A0000 ||\
     (PyType_GetFlags(type) & Py_TPFLAGS_HEAPTYPE) || __Pyx_get_runtime_version() >= 0x030A0000) ?\
     __Pyx_PyType_GetSlot(type, name, func_ctype) : NULL)
  #define __Pyx_PyType_GetSubSlot(obj, sub, name, func_ctype) __Pyx_PyType_GetSlot(obj, name, func_ctype)
  #define __Pyx_PyType_TryGetSubSlot(obj, sub, name, func_ctype) __Pyx_PyType_TryGetSlot(obj, name, func_ctype)
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
#define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#if CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStrWithError(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
static CYTHON_INLINE PyObject * __Pyx_PyDict_GetItemStr(PyObject *dict, PyObject *name) {
    PyObject *res = __Pyx_PyDict_GetItemStrWithError(dict, name);
    if (res == NULL) PyErr_Clear();
    return res;
}
#elif !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07020000
#define __Pyx_PyDict_GetItemStrWithError  PyDict_GetItemWithError
#define __Pyx_PyDict_GetItemStr           PyDict_GetItem
#else
static CYTHON_INLINE PyObject * __Pyx_PyDict_GetItemStrWithError(PyObject *dict, PyObject *name) {
#if CYTHON_COMPILING_IN_PYPY
    return PyDict_GetItem(dict, name);
#else
    PyDictEntry *ep;
    PyDictObject *mp = (PyDictObject*) dict;
    long hash = ((PyStringObject *) name)->ob_shash;
    assert(hash != -1);
    ep = (mp->ma_lookup)(mp, name, hash);
    if (ep == NULL) {
        return NULL;
    }
    return ep->me_value;
#endif
}
#define __Pyx_PyDict_GetItemStr           PyDict_GetItem
#endif
#if CYTHON_USE_TYPE_SLOTS
  #define __Pyx_PyType_GetFlags(tp)   (((PyTypeObject *)tp)->tp_flags)
  #define __Pyx_PyType_HasFeature(type, feature)  ((__Pyx_PyType_GetFlags(type) & (feature)) != 0)
#else
  #define __Pyx_PyType_GetFlags(tp)   (PyType_GetFlags((PyTypeObject *)tp))
  #define __Pyx_PyType_HasFeature(type, feature)  PyType_HasFeature(type, feature)
#endif
#define __Pyx_PyObject_GetIterNextFunc(iterator)  __Pyx_PyObject_GetSlot(iterator, tp_iternext, iternextfunc)
#if CYTHON_USE_TYPE_SPECS
#define __Pyx_PyHeapTypeObject_GC_Del(obj)  {\
    PyTypeObject *type = Py_TYPE((PyObject*)obj);\
    assert(__Pyx_PyType_HasFeature(type, Py_TPFLAGS_HEAPTYPE));\
    PyObject_GC_Del(obj);\
    Py_DECREF(type);\
}
#else
#define __Pyx_PyHeapTypeObject_GC_Del(obj)  PyObject_GC_Del(obj)
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_ReadChar(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((void)u, 1114111U)
  #define __Pyx_PyUnicode_KIND(u)         ((void)u, (0))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)u)
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)k, PyUnicode_ReadChar((PyObject*)(d), i))
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GetLength(u))
#else
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_READY(op)       (0)
  #else
    #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                                0 : _PyUnicode_Ready((PyObject *)(op)))
  #endif
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         ((int)PyUnicode_KIND(u))
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, (Py_UCS4) ch)
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #else
    #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
    #else
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
    #endif
  #endif
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #if !defined(PyUnicode_DecodeUnicodeEscape)
    #define PyUnicode_DecodeUnicodeEscape(s, size, errors)  PyUnicode_Decode(s, size, "unicode_escape", errors)
  #endif
  #if !defined(PyUnicode_Contains)
    #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
  #endif
  #if !defined(PyByteArray_Check)
    #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
  #endif
  #if !defined(PyObject_Format)
    #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
  #endif
#endif
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  #define __Pyx_PySequence_ListKeepNew(obj)\
    (likely(PyList_CheckExact(obj) && PyUnstable_Object_IsUniquelyReferenced(obj)) ? __Pyx_NewRef(obj) : PySequence_List(obj))
#elif CYTHON_COMPILING_IN_CPYTHON
  #define __Pyx_PySequence_ListKeepNew(obj)\
    (likely(PyList_CheckExact(obj) && Py_REFCNT(obj) == 1) ? __Pyx_NewRef(obj) : PySequence_List(obj))
#else
  #define __Pyx_PySequence_ListKeepNew(obj)  PySequence_List(obj)
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        __Pyx_IS_TYPE(obj, &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
enum __Pyx_ReferenceSharing {
  __Pyx_ReferenceSharing_DefinitelyUnique, // We created it so we know it's unshared - no need to check
  __Pyx_ReferenceSharing_OwnStrongReference,
  __Pyx_ReferenceSharing_FunctionArgument,
  __Pyx_ReferenceSharing_SharedReference, // Never trust it to be unshared because it's a global or similar
};
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING && PY_VERSION_HEX >= 0x030E0000
#define __Pyx_IS_UNIQUELY_REFERENCED(o, sharing)\
    (sharing == __Pyx_ReferenceSharing_DefinitelyUnique ? 1 :\
      (sharing == __Pyx_ReferenceSharing_FunctionArgument ? PyUnstable_Object_IsUniqueReferencedTemporary(o) :\
      (sharing == __Pyx_ReferenceSharing_OwnStrongReference ? PyUnstable_Object_IsUniquelyReferenced(o) : 0)))
#elif (CYTHON_COMPILING_IN_CPYTHON && !CYTHON_COMPILING_IN_CPYTHON_FREETHREADING) || CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_IS_UNIQUELY_REFERENCED(o, sharing) (((void)sharing), Py_REFCNT(o) == 1)
#else
#define __Pyx_IS_UNIQUELY_REFERENCED(o, sharing) (((void)o), ((void)sharing), 0)
#endif
#if CYTHON_AVOID_BORROWED_REFS || CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
  #if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
    #define __Pyx_PyList_GetItemRef(o, i) PyList_GetItemRef(o, i)
  #elif CYTHON_COMPILING_IN_LIMITED_API || !CYTHON_ASSUME_SAFE_MACROS
    #define __Pyx_PyList_GetItemRef(o, i) (likely((i) >= 0) ? PySequence_GetItem(o, i) : (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
  #else
    #define __Pyx_PyList_GetItemRef(o, i) PySequence_ITEM(o, i)
  #endif
#elif CYTHON_COMPILING_IN_LIMITED_API || !CYTHON_ASSUME_SAFE_MACROS
  #if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
    #define __Pyx_PyList_GetItemRef(o, i) PyList_GetItemRef(o, i)
  #else
    #define __Pyx_PyList_GetItemRef(o, i) __Pyx_XNewRef(PyList_GetItem(o, i))
  #endif
#else
  #define __Pyx_PyList_GetItemRef(o, i) __Pyx_NewRef(PyList_GET_ITEM(o, i))
#endif
#if CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS && !CYTHON_COMPILING_IN_LIMITED_API && CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PyList_GetItemRefFast(o, i, unsafe_shared) (__Pyx_IS_UNIQUELY_REFERENCED(o, unsafe_shared) ?\
    __Pyx_NewRef(PyList_GET_ITEM(o, i)) : __Pyx_PyList_GetItemRef(o, i))
#else
  #define __Pyx_PyList_GetItemRefFast(o, i, unsafe_shared) __Pyx_PyList_GetItemRef(o, i)
#endif
#if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
#define __Pyx_PyDict_GetItemRef(dict, key, result) PyDict_GetItemRef(dict, key, result)
#elif CYTHON_AVOID_BORROWED_REFS || CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
static CYTHON_INLINE int __Pyx_PyDict_GetItemRef(PyObject *dict, PyObject *key, PyObject **result) {
  *result = PyObject_GetItem(dict, key);
  if (*result == NULL) {
    if (PyErr_ExceptionMatches(PyExc_KeyError)) {
      PyErr_Clear();
      return 0;
    }
    return -1;
  }
  return 1;
}
#else
static CYTHON_INLINE int __Pyx_PyDict_GetItemRef(PyObject *dict, PyObject *key, PyObject **result) {
  *result = PyDict_GetItemWithError(dict, key);
  if (*result == NULL) {
    return PyErr_Occurred() ? -1 : 0;
  }
  Py_INCREF(*result);
  return 1;
}
#endif
#if defined(CYTHON_DEBUG_VISIT_CONST) && CYTHON_DEBUG_VISIT_CONST
  #define __Pyx_VISIT_CONST(obj)  Py_VISIT(obj)
#else
  #define __Pyx_VISIT_CONST(obj)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_ITEM(o, i) PySequence_ITEM(o, i)
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
  #define __Pyx_PyTuple_SET_ITEM(o, i, v) (PyTuple_SET_ITEM(o, i, v), (0))
  #define __Pyx_PyTuple_GET_ITEM(o, i) PyTuple_GET_ITEM(o, i)
  #define __Pyx_PyList_SET_ITEM(o, i, v) (PyList_SET_ITEM(o, i, v), (0))
  #define __Pyx_PyList_GET_ITEM(o, i) PyList_GET_ITEM(o, i)
#else
  #define __Pyx_PySequence_ITEM(o, i) PySequence_GetItem(o, i)
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
  #define __Pyx_PyTuple_SET_ITEM(o, i, v) PyTuple_SetItem(o, i, v)
  #define __Pyx_PyTuple_GET_ITEM(o, i) PyTuple_GetItem(o, i)
  #define __Pyx_PyList_SET_ITEM(o, i, v) PyList_SetItem(o, i, v)
  #define __Pyx_PyList_GET_ITEM(o, i) PyList_GetItem(o, i)
#endif
#if CYTHON_ASSUME_SAFE_SIZE
  #define __Pyx_PyTuple_GET_SIZE(o) PyTuple_GET_SIZE(o)
  #define __Pyx_PyList_GET_SIZE(o) PyList_GET_SIZE(o)
  #define __Pyx_PySet_GET_SIZE(o) PySet_GET_SIZE(o)
  #define __Pyx_PyBytes_GET_SIZE(o) PyBytes_GET_SIZE(o)
  #define __Pyx_PyByteArray_GET_SIZE(o) PyByteArray_GET_SIZE(o)
  #define __Pyx_PyUnicode_GET_LENGTH(o) PyUnicode_GET_LENGTH(o)
#else
  #define __Pyx_PyTuple_GET_SIZE(o) PyTuple_Size(o)
  #define __Pyx_PyList_GET_SIZE(o) PyList_Size(o)
  #define __Pyx_PySet_GET_SIZE(o) PySet_Size(o)
  #define __Pyx_PyBytes_GET_SIZE(o) PyBytes_Size(o)
  #define __Pyx_PyByteArray_GET_SIZE(o) PyByteArray_Size(o)
  #define __Pyx_PyUnicode_GET_LENGTH(o) PyUnicode_GetLength(o)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_InternFromString)
  #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
#endif
#define __Pyx_PyLong_FromHash_t PyLong_FromSsize_t
#define __Pyx_PyLong_AsHash_t   __Pyx_PyIndex_AsSsize_t
#if __PYX_LIMITED_VERSION_HEX >= 0x030A0000
    #define __Pyx_PySendResult PySendResult
#else
    typedef enum {
        PYGEN_RETURN = 0,
        PYGEN_ERROR = -1,
        PYGEN_NEXT = 1,
    } __Pyx_PySendResult;
#endif
#if CYTHON_COMPILING_IN_LIMITED_API || PY_VERSION_HEX < 0x030A00A3
  typedef __Pyx_PySendResult (*__Pyx_pyiter_sendfunc)(PyObject *iter, PyObject *value, PyObject **result);
#else
  #define __Pyx_pyiter_sendfunc sendfunc
#endif
#if !CYTHON_USE_AM_SEND
#define __PYX_HAS_PY_AM_SEND 0
#elif __PYX_LIMITED_VERSION_HEX >= 0x030A0000
#define __PYX_HAS_PY_AM_SEND 1
#else
#define __PYX_HAS_PY_AM_SEND 2  // our own backported implementation
#endif
#if __PYX_HAS_PY_AM_SEND < 2
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
#else
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
        __Pyx_pyiter_sendfunc am_send;
    } __Pyx_PyAsyncMethodsStruct;
    #define __Pyx_SlotTpAsAsync(s) ((PyAsyncMethods*)(s))
#endif
#if CYTHON_USE_AM_SEND && PY_VERSION_HEX < 0x030A00F0
    #define __Pyx_TPFLAGS_HAVE_AM_SEND (1UL << 21)
#else
    #define __Pyx_TPFLAGS_HAVE_AM_SEND (0)
#endif
#if PY_VERSION_HEX >= 0x03090000
#define __Pyx_PyInterpreterState_Get() PyInterpreterState_Get()
#else
#define __Pyx_PyInterpreterState_Get() PyThreadState_Get()->interp
#endif
#if CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX < 0x030A0000
#ifdef __cplusplus
extern "C"
#endif
PyAPI_FUNC(void *) PyMem_Calloc(size_t nelem, size_t elsize);
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
static int __Pyx_init_co_variable(PyObject *inspect, const char* name, int *write_to) {
    int value;
    PyObject *py_value = PyObject_GetAttrString(inspect, name);
    if (!py_value) return 0;
    value = (int) PyLong_AsLong(py_value);
    Py_DECREF(py_value);
    *write_to = value;
    return value != -1 || !PyErr_Occurred();
}
static int __Pyx_init_co_variables(void) {
    PyObject *inspect;
    int result;
    inspect = PyImport_ImportModule("inspect");
    result =
#if !defined(CO_OPTIMIZED)
        __Pyx_init_co_variable(inspect, "CO_OPTIMIZED", &CO_OPTIMIZED) &&
#endif
#if !defined(CO_NEWLOCALS)
        __Pyx_init_co_variable(inspect, "CO_NEWLOCALS", &CO_NEWLOCALS) &&
#endif
#if !defined(CO_VARARGS)
        __Pyx_init_co_variable(inspect, "CO_VARARGS", &CO_VARARGS) &&
#endif
#if !defined(CO_VARKEYWORDS)
        __Pyx_init_co_variable(inspect, "CO_VARKEYWORDS", &CO_VARKEYWORDS) &&
#endif
#if !defined(CO_ASYNC_GENERATOR)
        __Pyx_init_co_variable(inspect, "CO_ASYNC_GENERATOR", &CO_ASYNC_GENERATOR) &&
#endif
#if !defined(CO_GENERATOR)
        __Pyx_init_co_variable(inspect, "CO_GENERATOR", &CO_GENERATOR) &&
#endif
#if !defined(CO_COROUTINE)
        __Pyx_init_co_variable(inspect, "CO_COROUTINE", &CO_COROUTINE) &&
#endif
        1;
    Py_DECREF(inspect);
    return result ? 0 : -1;
}
#else
static int __Pyx_init_co_variables(void) {
    return 0;  // It's a limited API-only feature
}
#endif


#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)
  #ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES
  #endif
#endif
#include <math.h>
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#ifndef CYTHON_CLINE_IN_TRACEBACK_RUNTIME
#define CYTHON_CLINE_IN_TRACEBACK_RUNTIME 0
#endif
#ifndef CYTHON_CLINE_IN_TRACEBACK
#define CYTHON_CLINE_IN_TRACEBACK CYTHON_CLINE_IN_TRACEBACK_RUNTIME
#endif
#if CYTHON_CLINE_IN_TRACEBACK
#define __PYX_MARK_ERR_POS(f_index, lineno)  { __pyx_filename = __pyx_f[f_index]; (void) __pyx_filename; __pyx_lineno = lineno; (void) __pyx_lineno; __pyx_clineno = __LINE__; (void) __pyx_clineno; }
#else
#define __PYX_MARK_ERR_POS(f_index, lineno)  { __pyx_filename = __pyx_f[f_index]; (void) __pyx_filename; __pyx_lineno = lineno; (void) __pyx_lineno; (void) __pyx_clineno; }
#endif
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifdef CYTHON_EXTERN_C
    #undef __PYX_EXTERN_C
    #define __PYX_EXTERN_C CYTHON_EXTERN_C
#elif defined(__PYX_EXTERN_C)
    #ifdef _MSC_VER
    #pragma message ("Please do not define the '__PYX_EXTERN_C' macro externally. Use 'CYTHON_EXTERN_C' instead.")
    #else
    #warning Please do not define the '__PYX_EXTERN_C' macro externally. Use 'CYTHON_EXTERN_C' instead.
    #endif
#else
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__hdcs
#define __PYX_HAVE_API__hdcs

#ifdef _OPENMP
#include <omp.h>
#endif 

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE Py_ssize_t __Pyx_ssize_strlen(const char *s);
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
static CYTHON_INLINE PyObject* __Pyx_PyByteArray_FromString(const char*);
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if CYTHON_ASSUME_SAFE_MACROS
    #define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
    #define __Pyx_PyByteArray_AsString(s) PyByteArray_AS_STRING(s)
#else
    #define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AsString(s))
    #define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AsString(s))
    #define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AsString(s))
    #define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AsString(s))
    #define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AsString(s))
    #define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AsString(s))
    #define __Pyx_PyByteArray_AsString(s) PyByteArray_AsString(s)
#endif
#define __Pyx_PyObject_AsWritableString(s)    ((char*)(__pyx_uintptr_t) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*)(__pyx_uintptr_t) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*)(__pyx_uintptr_t) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
#define __Pyx_PyUnicode_FromOrdinal(o)       PyUnicode_FromOrdinal((int)o)
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
static CYTHON_INLINE PyObject *__Pyx_NewRef(PyObject *obj) {
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030a0000 || defined(Py_NewRef)
    return Py_NewRef(obj);
#else
    Py_INCREF(obj);
    return obj;
#endif
}
static CYTHON_INLINE PyObject *__Pyx_XNewRef(PyObject *obj) {
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030a0000 || defined(Py_XNewRef)
    return Py_XNewRef(obj);
#else
    Py_XINCREF(obj);
    return obj;
#endif
}
static CYTHON_INLINE PyObject *__Pyx_Owned_Py_None(int b);
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_Long(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyLong_FromSize_t(size_t);
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject*);
#if CYTHON_ASSUME_SAFE_MACROS
#define __Pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#define __Pyx_PyFloat_AS_DOUBLE(x) PyFloat_AS_DOUBLE(x)
#else
#define __Pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#define __Pyx_PyFloat_AS_DOUBLE(x) PyFloat_AsDouble(x)
#endif
#define __Pyx_PyFloat_AsFloat(x) ((float) __Pyx_PyFloat_AsDouble(x))
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#if CYTHON_USE_PYLONG_INTERNALS
  #if PY_VERSION_HEX >= 0x030C00A7
  #ifndef _PyLong_SIGN_MASK
    #define _PyLong_SIGN_MASK 3
  #endif
  #ifndef _PyLong_NON_SIZE_BITS
    #define _PyLong_NON_SIZE_BITS 3
  #endif
  #define __Pyx_PyLong_Sign(x)  (((PyLongObject*)x)->long_value.lv_tag & _PyLong_SIGN_MASK)
  #define __Pyx_PyLong_IsNeg(x)  ((__Pyx_PyLong_Sign(x) & 2) != 0)
  #define __Pyx_PyLong_IsNonNeg(x)  (!__Pyx_PyLong_IsNeg(x))
  #define __Pyx_PyLong_IsZero(x)  (__Pyx_PyLong_Sign(x) & 1)
  #define __Pyx_PyLong_IsPos(x)  (__Pyx_PyLong_Sign(x) == 0)
  #define __Pyx_PyLong_CompactValueUnsigned(x)  (__Pyx_PyLong_Digits(x)[0])
  #define __Pyx_PyLong_DigitCount(x)  ((Py_ssize_t) (((PyLongObject*)x)->long_value.lv_tag >> _PyLong_NON_SIZE_BITS))
  #define __Pyx_PyLong_SignedDigitCount(x)\
        ((1 - (Py_ssize_t) __Pyx_PyLong_Sign(x)) * __Pyx_PyLong_DigitCount(x))
  #if defined(PyUnstable_Long_IsCompact) && defined(PyUnstable_Long_CompactValue)
    #define __Pyx_PyLong_IsCompact(x)     PyUnstable_Long_IsCompact((PyLongObject*) x)
    #define __Pyx_PyLong_CompactValue(x)  PyUnstable_Long_CompactValue((PyLongObject*) x)
  #else
    #define __Pyx_PyLong_IsCompact(x)     (((PyLongObject*)x)->long_value.lv_tag < (2 << _PyLong_NON_SIZE_BITS))
    #define __Pyx_PyLong_CompactValue(x)  ((1 - (Py_ssize_t) __Pyx_PyLong_Sign(x)) * (Py_ssize_t) __Pyx_PyLong_Digits(x)[0])
  #endif
  typedef Py_ssize_t  __Pyx_compact_pylong;
  typedef size_t  __Pyx_compact_upylong;
  #else
  #define __Pyx_PyLong_IsNeg(x)  (Py_SIZE(x) < 0)
  #define __Pyx_PyLong_IsNonNeg(x)  (Py_SIZE(x) >= 0)
  #define __Pyx_PyLong_IsZero(x)  (Py_SIZE(x) == 0)
  #define __Pyx_PyLong_IsPos(x)  (Py_SIZE(x) > 0)
  #define __Pyx_PyLong_CompactValueUnsigned(x)  ((Py_SIZE(x) == 0) ? 0 : __Pyx_PyLong_Digits(x)[0])
  #define __Pyx_PyLong_DigitCount(x)  __Pyx_sst_abs(Py_SIZE(x))
  #define __Pyx_PyLong_SignedDigitCount(x)  Py_SIZE(x)
  #define __Pyx_PyLong_IsCompact(x)  (Py_SIZE(x) == 0 || Py_SIZE(x) == 1 || Py_SIZE(x) == -1)
  #define __Pyx_PyLong_CompactValue(x)\
        ((Py_SIZE(x) == 0) ? (sdigit) 0 : ((Py_SIZE(x) < 0) ? -(sdigit)__Pyx_PyLong_Digits(x)[0] : (sdigit)__Pyx_PyLong_Digits(x)[0]))
  typedef sdigit  __Pyx_compact_pylong;
  typedef digit  __Pyx_compact_upylong;
  #endif
  #if PY_VERSION_HEX >= 0x030C00A5
  #define __Pyx_PyLong_Digits(x)  (((PyLongObject*)x)->long_value.ob_digit)
  #else
  #define __Pyx_PyLong_Digits(x)  (((PyLongObject*)x)->ob_digit)
  #endif
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_UTF8
  #define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#elif __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
  #define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeASCII(c_str, size, NULL)
#else
  #define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#endif



#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else 
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif 

#ifdef __cplusplus
#if __cplusplus > 201103L
#include <type_traits>
#endif
template <typename T>
static void __Pyx_pretend_to_initialize(T* ptr) {
#if __cplusplus > 201103L
    if ((std::is_trivially_default_constructible<T>::value))
#endif
        *ptr = T();
    (void)ptr;
}
#else
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }
#endif


#if !CYTHON_USE_MODULE_STATE
static PyObject *__pyx_m = NULL;
#endif
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * const __pyx_cfilenm = __FILE__;
static const char *__pyx_filename;



static const char* const __pyx_f[] = {
  "wlzbi_temp/hdcs.py",
};


#include <pythread.h>
#ifndef CYTHON_ATOMICS
    #define CYTHON_ATOMICS 1
#endif
#define __PYX_CYTHON_ATOMICS_ENABLED() CYTHON_ATOMICS
#define __PYX_GET_CYTHON_COMPILING_IN_CPYTHON_FREETHREADING() CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
#define __pyx_atomic_int_type int
#define __pyx_nonatomic_int_type int
#if CYTHON_ATOMICS && (defined(__STDC_VERSION__) &&\
                        (__STDC_VERSION__ >= 201112L) &&\
                        !defined(__STDC_NO_ATOMICS__))
    #include <stdatomic.h>
#elif CYTHON_ATOMICS && (defined(__cplusplus) && (\
                    (__cplusplus >= 201103L) ||\
                    (defined(_MSC_VER) && _MSC_VER >= 1700)))
    #include <atomic>
#endif
#if CYTHON_ATOMICS && (defined(__STDC_VERSION__) &&\
                        (__STDC_VERSION__ >= 201112L) &&\
                        !defined(__STDC_NO_ATOMICS__) &&\
                       ATOMIC_INT_LOCK_FREE == 2)
    #undef __pyx_atomic_int_type
    #define __pyx_atomic_int_type atomic_int
    #define __pyx_atomic_ptr_type atomic_uintptr_t
    #define __pyx_nonatomic_ptr_type uintptr_t
    #define __pyx_atomic_incr_relaxed(value) atomic_fetch_add_explicit(value, 1, memory_order_relaxed)
    #define __pyx_atomic_incr_acq_rel(value) atomic_fetch_add_explicit(value, 1, memory_order_acq_rel)
    #define __pyx_atomic_decr_acq_rel(value) atomic_fetch_sub_explicit(value, 1, memory_order_acq_rel)
    #define __pyx_atomic_sub(value, arg) atomic_fetch_sub(value, arg)
    #define __pyx_atomic_int_cmp_exchange(value, expected, desired) atomic_compare_exchange_strong(value, expected, desired)
    #define __pyx_atomic_load(value) atomic_load(value)
    #define __pyx_atomic_store(value, new_value) atomic_store(value, new_value)
    #define __pyx_atomic_pointer_load_relaxed(value) atomic_load_explicit(value, memory_order_relaxed)
    #define __pyx_atomic_pointer_load_acquire(value) atomic_load_explicit(value, memory_order_acquire)
    #define __pyx_atomic_pointer_exchange(value, new_value) atomic_exchange(value, (__pyx_nonatomic_ptr_type)new_value)
    #define __pyx_atomic_pointer_cmp_exchange(value, expected, desired) atomic_compare_exchange_strong(value, expected, desired)
    #if defined(__PYX_DEBUG_ATOMICS) && defined(_MSC_VER)
        #pragma message ("Using standard C atomics")
    #elif defined(__PYX_DEBUG_ATOMICS)
        #warning "Using standard C atomics"
    #endif
#elif CYTHON_ATOMICS && (defined(__cplusplus) && (\
                    (__cplusplus >= 201103L) ||\
\
                    (defined(_MSC_VER) && _MSC_VER >= 1700)) &&\
                    ATOMIC_INT_LOCK_FREE == 2)
    #undef __pyx_atomic_int_type
    #define __pyx_atomic_int_type std::atomic_int
    #define __pyx_atomic_ptr_type std::atomic_uintptr_t
    #define __pyx_nonatomic_ptr_type uintptr_t
    #define __pyx_atomic_incr_relaxed(value) std::atomic_fetch_add_explicit(value, 1, std::memory_order_relaxed)
    #define __pyx_atomic_incr_acq_rel(value) std::atomic_fetch_add_explicit(value, 1, std::memory_order_acq_rel)
    #define __pyx_atomic_decr_acq_rel(value) std::atomic_fetch_sub_explicit(value, 1, std::memory_order_acq_rel)
    #define __pyx_atomic_sub(value, arg) std::atomic_fetch_sub(value, arg)
    #define __pyx_atomic_int_cmp_exchange(value, expected, desired) std::atomic_compare_exchange_strong(value, expected, desired)
    #define __pyx_atomic_load(value) std::atomic_load(value)
    #define __pyx_atomic_store(value, new_value) std::atomic_store(value, new_value)
    #define __pyx_atomic_pointer_load_relaxed(value) std::atomic_load_explicit(value, std::memory_order_relaxed)
    #define __pyx_atomic_pointer_load_acquire(value) std::atomic_load_explicit(value, std::memory_order_acquire)
    #define __pyx_atomic_pointer_exchange(value, new_value) std::atomic_exchange(value, (__pyx_nonatomic_ptr_type)new_value)
    #define __pyx_atomic_pointer_cmp_exchange(value, expected, desired) std::atomic_compare_exchange_strong(value, expected, desired)
    #if defined(__PYX_DEBUG_ATOMICS) && defined(_MSC_VER)
        #pragma message ("Using standard C++ atomics")
    #elif defined(__PYX_DEBUG_ATOMICS)
        #warning "Using standard C++ atomics"
    #endif
#elif CYTHON_ATOMICS && (__GNUC__ >= 5 || (__GNUC__ == 4 &&\
                    (__GNUC_MINOR__ > 1 ||\
                    (__GNUC_MINOR__ == 1 && __GNUC_PATCHLEVEL__ >= 2))))
    #define __pyx_atomic_ptr_type void*
    #define __pyx_nonatomic_ptr_type void*
    #define __pyx_atomic_incr_relaxed(value) __sync_fetch_and_add(value, 1)
    #define __pyx_atomic_incr_acq_rel(value) __sync_fetch_and_add(value, 1)
    #define __pyx_atomic_decr_acq_rel(value) __sync_fetch_and_sub(value, 1)
    #define __pyx_atomic_sub(value, arg) __sync_fetch_and_sub(value, arg)
    static CYTHON_INLINE int __pyx_atomic_int_cmp_exchange(__pyx_atomic_int_type* value, __pyx_nonatomic_int_type* expected, __pyx_nonatomic_int_type desired) {
        __pyx_nonatomic_int_type old = __sync_val_compare_and_swap(value, *expected, desired);
        int result = old == *expected;
        *expected = old;
        return result;
    }
    #define __pyx_atomic_load(value) __sync_fetch_and_add(value, 0)
    #define __pyx_atomic_store(value, new_value) __sync_lock_test_and_set(value, new_value)
    #define __pyx_atomic_pointer_load_relaxed(value) __sync_fetch_and_add(value, 0)
    #define __pyx_atomic_pointer_load_acquire(value) __sync_fetch_and_add(value, 0)
    #define __pyx_atomic_pointer_exchange(value, new_value) __sync_lock_test_and_set(value, (__pyx_atomic_ptr_type)new_value)
    static CYTHON_INLINE int __pyx_atomic_pointer_cmp_exchange(__pyx_atomic_ptr_type* value, __pyx_nonatomic_ptr_type* expected, __pyx_nonatomic_ptr_type desired) {
        __pyx_nonatomic_ptr_type old = __sync_val_compare_and_swap(value, *expected, desired);
        int result = old == *expected;
        *expected = old;
        return result;
    }
    #ifdef __PYX_DEBUG_ATOMICS
        #warning "Using GNU atomics"
    #endif
#elif CYTHON_ATOMICS && defined(_MSC_VER)
    #include <intrin.h>
    #undef __pyx_atomic_int_type
    #define __pyx_atomic_int_type long
    #define __pyx_atomic_ptr_type void*
    #undef __pyx_nonatomic_int_type
    #define __pyx_nonatomic_int_type long
    #define __pyx_nonatomic_ptr_type void*
    #pragma intrinsic (_InterlockedExchangeAdd, _InterlockedExchange, _InterlockedCompareExchange, _InterlockedCompareExchangePointer, _InterlockedExchangePointer)
    #define __pyx_atomic_incr_relaxed(value) _InterlockedExchangeAdd(value, 1)
    #define __pyx_atomic_incr_acq_rel(value) _InterlockedExchangeAdd(value, 1)
    #define __pyx_atomic_decr_acq_rel(value) _InterlockedExchangeAdd(value, -1)
    #define __pyx_atomic_sub(value, arg) _InterlockedExchangeAdd(value, -arg)
    static CYTHON_INLINE int __pyx_atomic_int_cmp_exchange(__pyx_atomic_int_type* value, __pyx_nonatomic_int_type* expected, __pyx_nonatomic_int_type desired) {
        __pyx_nonatomic_int_type old = _InterlockedCompareExchange(value, desired, *expected);
        int result = old == *expected;
        *expected = old;
        return result;
    }
    #define __pyx_atomic_load(value) _InterlockedExchangeAdd(value, 0)
    #define __pyx_atomic_store(value, new_value) _InterlockedExchange(value, new_value)
    #define __pyx_atomic_pointer_load_relaxed(value) *(void * volatile *)value
    #define __pyx_atomic_pointer_load_acquire(value) _InterlockedCompareExchangePointer(value, 0, 0)
    #define __pyx_atomic_pointer_exchange(value, new_value) _InterlockedExchangePointer(value, (__pyx_atomic_ptr_type)new_value)
    static CYTHON_INLINE int __pyx_atomic_pointer_cmp_exchange(__pyx_atomic_ptr_type* value, __pyx_nonatomic_ptr_type* expected, __pyx_nonatomic_ptr_type desired) {
        __pyx_atomic_ptr_type old = _InterlockedCompareExchangePointer(value, desired, *expected);
        int result = old == *expected;
        *expected = old;
        return result;
    }
    #ifdef __PYX_DEBUG_ATOMICS
        #pragma message ("Using MSVC atomics")
    #endif
#else
    #undef CYTHON_ATOMICS
    #define CYTHON_ATOMICS 0
    #ifdef __PYX_DEBUG_ATOMICS
        #warning "Not using atomics"
    #endif
#endif


#if !CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
#define __Pyx_PyCriticalSection void*
#define __Pyx_PyCriticalSection2 void*
#define __Pyx_PyCriticalSection_End(cs)
#define __Pyx_PyCriticalSection2_End(cs)
#else
#define __Pyx_PyCriticalSection PyCriticalSection
#define __Pyx_PyCriticalSection2 PyCriticalSection2
#define __Pyx_PyCriticalSection_End PyCriticalSection_End
#define __Pyx_PyCriticalSection2_End PyCriticalSection2_End
#endif


#if !CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
#define __Pyx_PyCriticalSection_Begin(cs, arg) (void)(cs)
#define __Pyx_PyCriticalSection2_Begin(cs, arg1, arg2) (void)(cs)
#else
#define __Pyx_PyCriticalSection_Begin PyCriticalSection_Begin
#define __Pyx_PyCriticalSection2_Begin PyCriticalSection2_Begin
#endif
#if PY_VERSION_HEX < 0x030d0000 || CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_BEGIN_CRITICAL_SECTION(o) {
#define __Pyx_END_CRITICAL_SECTION() }
#else
#define __Pyx_BEGIN_CRITICAL_SECTION Py_BEGIN_CRITICAL_SECTION
#define __Pyx_END_CRITICAL_SECTION Py_END_CRITICAL_SECTION
#endif


#include <structmember.h>






struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate;
struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr;
struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr;
struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr;


struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate {
  PyObject_HEAD
  PyObject *__pyx_v_data_with_key;
  PyObject *__pyx_v_key;
};



struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *__pyx_outer_scope;
  PyObject *__pyx_genexpr_arg_0;
  PyObject *__pyx_v_i;
};



struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *__pyx_outer_scope;
  PyObject *__pyx_genexpr_arg_0;
  PyObject *__pyx_v_i;
};



struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *__pyx_outer_scope;
  PyObject *__pyx_genexpr_arg_0;
  PyObject *__pyx_v_c;
  PyObject *__pyx_v_i;
};





#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, Py_ssize_t);
    void (*DECREF)(void*, PyObject*, Py_ssize_t);
    void (*GOTREF)(void*, PyObject*, Py_ssize_t);
    void (*GIVEREF)(void*, PyObject*, Py_ssize_t);
    void* (*SetupContext)(const char*, Py_ssize_t, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), (__LINE__), (__FILE__));\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), (__LINE__), (__FILE__));\
          }
  #define __Pyx_RefNannyFinishContextNogil() {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __Pyx_RefNannyFinishContext();\
              PyGILState_Release(__pyx_gilstate_save);\
          }
  #define __Pyx_RefNannyFinishContextNogil() {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __Pyx_RefNannyFinishContext();\
              PyGILState_Release(__pyx_gilstate_save);\
          }
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_XINCREF(r)  do { if((r) == NULL); else {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) == NULL); else {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) == NULL); else {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) == NULL); else {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContextNogil()
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_Py_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; Py_XDECREF(tmp);\
    } while (0)
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#if PY_VERSION_HEX >= 0x030C00A6
#define __Pyx_PyErr_Occurred()  (__pyx_tstate->current_exception != NULL)
#define __Pyx_PyErr_CurrentExceptionType()  (__pyx_tstate->current_exception ? (PyObject*) Py_TYPE(__pyx_tstate->current_exception) : (PyObject*) NULL)
#else
#define __Pyx_PyErr_Occurred()  (__pyx_tstate->curexc_type != NULL)
#define __Pyx_PyErr_CurrentExceptionType()  (__pyx_tstate->curexc_type)
#endif
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  (PyErr_Occurred() != NULL)
#define __Pyx_PyErr_CurrentExceptionType()  PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030C00A6
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStrNoError(PyObject* obj, PyObject* attr_name);


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyList_FromArray(PyObject *const *src, Py_ssize_t n);
#endif
#if CYTHON_COMPILING_IN_CPYTHON || CYTHON_METH_FASTCALL
static CYTHON_INLINE PyObject* __Pyx_PyTuple_FromArray(PyObject *const *src, Py_ssize_t n);
#endif


#include <string.h>


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);


#if CYTHON_AVOID_BORROWED_REFS
    #define __Pyx_ArgRef_VARARGS(args, i) __Pyx_PySequence_ITEM(args, i)
#elif CYTHON_ASSUME_SAFE_MACROS
    #define __Pyx_ArgRef_VARARGS(args, i) __Pyx_NewRef(__Pyx_PyTuple_GET_ITEM(args, i))
#else
    #define __Pyx_ArgRef_VARARGS(args, i) __Pyx_XNewRef(PyTuple_GetItem(args, i))
#endif
#define __Pyx_NumKwargs_VARARGS(kwds) PyDict_Size(kwds)
#define __Pyx_KwValues_VARARGS(args, nargs) NULL
#define __Pyx_GetKwValue_VARARGS(kw, kwvalues, s) __Pyx_PyDict_GetItemStrWithError(kw, s)
#define __Pyx_KwargsAsDict_VARARGS(kw, kwvalues) PyDict_Copy(kw)
#if CYTHON_METH_FASTCALL
    #define __Pyx_ArgRef_FASTCALL(args, i) __Pyx_NewRef(args[i])
    #define __Pyx_NumKwargs_FASTCALL(kwds) __Pyx_PyTuple_GET_SIZE(kwds)
    #define __Pyx_KwValues_FASTCALL(args, nargs) ((args) + (nargs))
    static CYTHON_INLINE PyObject * __Pyx_GetKwValue_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues, PyObject *s);
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030d0000 || CYTHON_COMPILING_IN_LIMITED_API
    CYTHON_UNUSED static PyObject *__Pyx_KwargsAsDict_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues);
  #else
    #define __Pyx_KwargsAsDict_FASTCALL(kw, kwvalues) _PyStack_AsDict(kwvalues, kw)
  #endif
#else
    #define __Pyx_ArgRef_FASTCALL __Pyx_ArgRef_VARARGS
    #define __Pyx_NumKwargs_FASTCALL __Pyx_NumKwargs_VARARGS
    #define __Pyx_KwValues_FASTCALL __Pyx_KwValues_VARARGS
    #define __Pyx_GetKwValue_FASTCALL __Pyx_GetKwValue_VARARGS
    #define __Pyx_KwargsAsDict_FASTCALL __Pyx_KwargsAsDict_VARARGS
#endif
#define __Pyx_ArgsSlice_VARARGS(args, start, stop) PyTuple_GetSlice(args, start, stop)
#if CYTHON_METH_FASTCALL || (CYTHON_COMPILING_IN_CPYTHON && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
#define __Pyx_ArgsSlice_FASTCALL(args, start, stop) __Pyx_PyTuple_FromArray(args + start, stop - start)
#else
#define __Pyx_ArgsSlice_FASTCALL(args, start, stop) PyTuple_GetSlice(args, start, stop)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyDict_Items(PyObject* d);


#define __Pyx_CallCFunction(cfunc, self, args)\
    ((PyCFunction)(void(*)(void))(cfunc)->func)(self, args)
#define __Pyx_CallCFunctionWithKeywords(cfunc, self, args, kwargs)\
    ((PyCFunctionWithKeywords)(void(*)(void))(cfunc)->func)(self, args, kwargs)
#define __Pyx_CallCFunctionFast(cfunc, self, args, nargs)\
    ((__Pyx_PyCFunctionFast)(void(*)(void))(PyCFunction)(cfunc)->func)(self, args, nargs)
#define __Pyx_CallCFunctionFastWithKeywords(cfunc, self, args, nargs, kwnames)\
    ((__Pyx_PyCFunctionFastWithKeywords)(void(*)(void))(PyCFunction)(cfunc)->func)(self, args, nargs, kwnames)


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


#define __Pyx_PyObject_FastCall(func, args, nargs)  __Pyx_PyObject_FastCallDict(func, args, (size_t)(nargs), NULL)
static CYTHON_INLINE PyObject* __Pyx_PyObject_FastCallDict(PyObject *func, PyObject * const*args, size_t nargs, PyObject *kwargs);


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


typedef struct {
    PyObject *type;
    PyObject **method_name;
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING && CYTHON_ATOMICS
    __pyx_atomic_int_type initialized;
#endif
    PyCFunction func;
    PyObject *method;
    int flag;
} __Pyx_CachedCFunction;
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
static CYTHON_INLINE int __Pyx_CachedCFunction_GetAndSetInitializing(__Pyx_CachedCFunction *cfunc) {
#if !CYTHON_ATOMICS
    return 1;
#else
    __pyx_nonatomic_int_type expected = 0;
    if (__pyx_atomic_int_cmp_exchange(&cfunc->initialized, &expected, 1)) {
        return 0;
    }
    return expected;
#endif
}
static CYTHON_INLINE void __Pyx_CachedCFunction_SetFinishedInitializing(__Pyx_CachedCFunction *cfunc) {
#if CYTHON_ATOMICS
    __pyx_atomic_store(&cfunc->initialized, 2);
#endif
}
#else
#define __Pyx_CachedCFunction_GetAndSetInitializing(cfunc) 2
#define __Pyx_CachedCFunction_SetFinishedInitializing(cfunc)
#endif


CYTHON_UNUSED
static PyObject* __Pyx__CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self);
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self);
#else
#define __Pyx_CallUnboundCMethod0(cfunc, self)  __Pyx__CallUnboundCMethod0(cfunc, self)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyDict_Values(PyObject* d);


#if CYTHON_AVOID_BORROWED_REFS
static int __Pyx_PyDict_NextRef(PyObject *p, PyObject **ppos, PyObject **pkey, PyObject **pvalue);
#else
CYTHON_INLINE
static int __Pyx_PyDict_NextRef(PyObject *p, Py_ssize_t *ppos, PyObject **pkey, PyObject **pvalue);
#endif


static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);


static int __Pyx_ParseKeywordsTuple(
    PyObject *kwds,
    PyObject * const *kwvalues,
    PyObject ** const argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs
);
static int __Pyx_ParseKeywordDictToDict(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name
);
static int __Pyx_ParseKeywordDict(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject *values[],
    Py_ssize_t num_pos_args,
    Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs
);


CYTHON_UNUSED
static PyObject* __Pyx__CallUnboundCMethod2(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg1, PyObject* arg2);
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject *__Pyx_CallUnboundCMethod2(__Pyx_CachedCFunction *cfunc, PyObject *self, PyObject *arg1, PyObject *arg2);
#else
#define __Pyx_CallUnboundCMethod2(cfunc, self, arg1, arg2)  __Pyx__CallUnboundCMethod2(cfunc, self, arg1, arg2)
#endif


static CYTHON_INLINE int __Pyx_ParseKeywords(
    PyObject *kwds, PyObject *const *kwvalues, PyObject ** const argnames[],
    PyObject *kwds2, PyObject *values[],
    Py_ssize_t num_pos_args, Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs
);


static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);


static void __Pyx_RaiseUnboundLocalError(const char *varname);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030d0000
        L->ob_item[len] = x;
        #else
        PyList_SET_ITEM(list, len, x);
        #endif
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif


static void __Pyx_RaiseClosureNameError(const char *varname);


#if !CYTHON_COMPILING_IN_PYPY
static CYTHON_INLINE PyObject* __Pyx_PyLong_MultiplyObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyLong_MultiplyObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceMultiply(op1, op2) : PyNumber_Multiply(op1, op2))
#endif


#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck, has_gil, unsafe_shared)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck, unsafe_shared) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck, has_gil, unsafe_shared)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck, unsafe_shared) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck, int unsafe_shared);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck, has_gil, unsafe_shared)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck, unsafe_shared) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck, int unsafe_shared);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck, int unsafe_shared);


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject *key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


static void __Pyx_Generator_Replace_StopIteration(int in_async_gen);


#if !CYTHON_COMPILING_IN_PYPY
static CYTHON_INLINE PyObject* __Pyx_PyLong_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyLong_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif


static CYTHON_INLINE int __Pyx_init_unicode_iteration(
    PyObject* ustring, Py_ssize_t *length, void** data, int *kind);


static CYTHON_INLINE Py_UCS4 __Pyx_PyUnicode_AsPy_UCS4(PyObject*);


#define __Pyx_PyObject_Ord(c)\
    (likely(PyUnicode_Check(c)) ? (long)__Pyx_PyUnicode_AsPy_UCS4(c) : __Pyx__PyObject_Ord(c))
static long __Pyx__PyObject_Ord(PyObject* c);


#if CYTHON_COMPILING_IN_PYPY && !defined(PyRange_Check)
  #define PyRange_Check(obj)  __Pyx_TypeCheck((obj), &PyRange_Type)
#endif


static CYTHON_INLINE Py_ssize_t __Pyx_div_Py_ssize_t(Py_ssize_t, Py_ssize_t, int b_is_constant);


#if CYTHON_USE_FREELISTS
#if CYTHON_USE_TYPE_SPECS
#define __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, expected_tp, expected_size) ((int) ((t) == (expected_tp)))
#define __PYX_CHECK_TYPE_FOR_FREELIST_FLAGS  Py_TPFLAGS_IS_ABSTRACT
#else
#define __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, expected_tp, expected_size) ((int) ((t)->tp_basicsize == (expected_size)))
#define __PYX_CHECK_TYPE_FOR_FREELIST_FLAGS  (Py_TPFLAGS_IS_ABSTRACT | Py_TPFLAGS_HEAPTYPE)
#endif
#define __PYX_CHECK_TYPE_FOR_FREELISTS(t, expected_tp, expected_size)\
    (__PYX_CHECK_FINAL_TYPE_FOR_FREELISTS((t), (expected_tp), (expected_size)) &\
     (int) (!__Pyx_PyType_HasFeature((t), __PYX_CHECK_TYPE_FOR_FREELIST_FLAGS)))
#endif


static PyObject *__Pyx_AllocateExtensionType(PyTypeObject *t, int is_final);


#if !CYTHON_USE_TYPE_SPECS || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX < 0x03090000)
#define __Pyx_call_type_traverse(o, always_call, visit, arg) 0
#else
static int __Pyx_call_type_traverse(PyObject *o, int always_call, visitproc visit, void *arg);
#endif


#if CYTHON_COMPILING_IN_LIMITED_API
static PyObject *__Pyx_GetTypeDict(PyTypeObject *tp);
#endif


static int __Pyx__SetItemOnTypeDict(PyTypeObject *tp, PyObject *k, PyObject *v);
#define __Pyx_SetItemOnTypeDict(tp, k, v) __Pyx__SetItemOnTypeDict((PyTypeObject*)tp, k, v)


static CYTHON_INLINE int __Pyx_fix_up_extension_type_from_spec(PyType_Spec *spec, PyTypeObject *type);


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);


#if !(CYTHON_VECTORCALL && (__PYX_LIMITED_VERSION_HEX >= 0x030C0000 || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x03090000)))
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);
#endif


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name);


#if CYTHON_COMPILING_IN_CPYTHON || CYTHON_COMPILING_IN_LIMITED_API || CYTHON_USE_TYPE_SPECS
static int __Pyx_validate_bases_tuple(const char *type_name, Py_ssize_t dictoffset, PyObject *bases);
#endif


CYTHON_UNUSED static int __Pyx_PyType_Ready(PyTypeObject *t);


static CYTHON_INLINE PyObject *__Pyx_PyDict_SetDefault(PyObject *d, PyObject *key, PyObject *default_value);


#if ((CYTHON_COMPILING_IN_CPYTHON_FREETHREADING ) ||\
     __PYX_LIMITED_VERSION_HEX < 0x030d0000)
  static PyObject *__Pyx_PyImport_AddModuleRef(const char *name);
#else
  #define __Pyx_PyImport_AddModuleRef(name) PyImport_AddModuleRef(name)
#endif


static PyObject *__Pyx_FetchSharedCythonABIModule(void);


static PyTypeObject* __Pyx_FetchCommonTypeFromSpec(PyTypeObject *metaclass, PyObject *module, PyType_Spec *spec, PyObject *bases);


static int __pyx_CommonTypesMetaclass_init(PyObject *module);
#define __Pyx_CommonTypesMetaclass_USED


static PyObject *__Pyx_PyMethod_New(PyObject *func, PyObject *self, PyObject *typ);


#if CYTHON_METH_FASTCALL && CYTHON_VECTORCALL
static CYTHON_INLINE PyObject *__Pyx_PyVectorcall_FastCallDict(PyObject *func, __pyx_vectorcallfunc vc, PyObject *const *args, size_t nargs, PyObject *kw);
#endif


#define __Pyx_CyFunction_USED
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CYFUNCTION_COROUTINE     0x08
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#if PY_VERSION_HEX < 0x030900B1 || CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_CyFunction_GetClassObj(f)\
      (((__pyx_CyFunctionObject *) (f))->func_classobj)
#else
  #define __Pyx_CyFunction_GetClassObj(f)\
      ((PyObject*) ((PyCMethodObject *) (f))->mm_class)
#endif
#define __Pyx_CyFunction_SetClassObj(f, classobj)\
    __Pyx__CyFunction_SetClassObj((__pyx_CyFunctionObject *) (f), (classobj))
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject_HEAD
    PyObject *func;
#elif PY_VERSION_HEX < 0x030900B1
    PyCFunctionObject func;
#else
    PyCMethodObject func;
#endif
#if CYTHON_COMPILING_IN_LIMITED_API && CYTHON_METH_FASTCALL
    __pyx_vectorcallfunc func_vectorcall;
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *func_weakreflist;
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    PyObject *func_dict;
#endif
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
#if PY_VERSION_HEX < 0x030900B1 || CYTHON_COMPILING_IN_LIMITED_API
    PyObject *func_classobj;
#endif
    PyObject *defaults;
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
    PyObject *func_is_coroutine;
} __pyx_CyFunctionObject;
#undef __Pyx_CyOrPyCFunction_Check
#define __Pyx_CyFunction_Check(obj)  __Pyx_TypeCheck(obj, __pyx_mstate_global->__pyx_CyFunctionType)
#define __Pyx_CyOrPyCFunction_Check(obj)  __Pyx_TypeCheck2(obj, __pyx_mstate_global->__pyx_CyFunctionType, &PyCFunction_Type)
#define __Pyx_CyFunction_CheckExact(obj)  __Pyx_IS_TYPE(obj, __pyx_mstate_global->__pyx_CyFunctionType)
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(PyObject *func, void (*cfunc)(void));
#undef __Pyx_IsSameCFunction
#define __Pyx_IsSameCFunction(func, cfunc)   __Pyx__IsSameCyOrCFunction(func, cfunc)
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void __Pyx__CyFunction_SetClassObj(__pyx_CyFunctionObject* f, PyObject* classobj);
static CYTHON_INLINE PyObject *__Pyx_CyFunction_InitDefaults(PyObject *func,
                                                         PyTypeObject *defaults_type);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(PyObject *module);
#if CYTHON_METH_FASTCALL
static PyObject * __Pyx_CyFunction_Vectorcall_NOARGS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_O(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
#if CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_CyFunction_func_vectorcall(f) (((__pyx_CyFunctionObject*)f)->func_vectorcall)
#else
#define __Pyx_CyFunction_func_vectorcall(f) (((PyCFunctionObject*)f)->vectorcall)
#endif
#endif


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __Pyx_XNewRef(__pyx_dict_cached_value);\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  do {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_mstate_global->__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  do {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


static PyObject* __Pyx_PyExec3(PyObject*, PyObject*, PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyExec2(PyObject*, PyObject*);


static PyObject* __Pyx_PyExecGlobals(PyObject*);


CYTHON_UNUSED static int __Pyx_VectorcallBuilder_AddArg_Check(PyObject *key, PyObject *value, PyObject *builder, PyObject **args, int n);
#if CYTHON_VECTORCALL
#if PY_VERSION_HEX >= 0x03090000
#define __Pyx_Object_Vectorcall_CallFromBuilder PyObject_Vectorcall
#else
#define __Pyx_Object_Vectorcall_CallFromBuilder _PyObject_Vectorcall
#endif
#define __Pyx_MakeVectorcallBuilderKwds(n) PyTuple_New(n)
static int __Pyx_VectorcallBuilder_AddArg(PyObject *key, PyObject *value, PyObject *builder, PyObject **args, int n);
static int __Pyx_VectorcallBuilder_AddArgStr(const char *key, PyObject *value, PyObject *builder, PyObject **args, int n);
#else
#define __Pyx_Object_Vectorcall_CallFromBuilder __Pyx_PyObject_FastCallDict
#define __Pyx_MakeVectorcallBuilderKwds(n) __Pyx_PyDict_NewPresized(n)
#define __Pyx_VectorcallBuilder_AddArg(key, value, builder, args, n) PyDict_SetItem(builder, key, value)
#define __Pyx_VectorcallBuilder_AddArgStr(key, value, builder, args, n) PyDict_SetItemString(builder, key, value)
#endif


#if CYTHON_CLINE_IN_TRACEBACK && CYTHON_CLINE_IN_TRACEBACK_RUNTIME
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#else
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#endif


#if CYTHON_COMPILING_IN_LIMITED_API
typedef PyObject __Pyx_CachedCodeObjectType;
#else
typedef PyCodeObject __Pyx_CachedCodeObjectType;
#endif
typedef struct {
    __Pyx_CachedCodeObjectType* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    __pyx_atomic_int_type accessor_count;
  #endif
};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static __Pyx_CachedCodeObjectType *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, __Pyx_CachedCodeObjectType* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


#if CYTHON_COMPILING_IN_LIMITED_API
typedef PyObject *__Pyx_TypeName;
#define __Pyx_FMT_TYPENAME "%U"
#define __Pyx_DECREF_TypeName(obj) Py_XDECREF(obj)
#if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
#define __Pyx_PyType_GetFullyQualifiedName PyType_GetFullyQualifiedName
#else
static __Pyx_TypeName __Pyx_PyType_GetFullyQualifiedName(PyTypeObject* tp);
#endif
#else  // !LIMITED_API
typedef const char *__Pyx_TypeName;
#define __Pyx_FMT_TYPENAME "%.200s"
#define __Pyx_PyType_GetFullyQualifiedName(tp) ((tp)->tp_name)
#define __Pyx_DECREF_TypeName(obj)
#endif


#if !defined(__INTEL_COMPILER) && defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define __Pyx_HAS_GCC_DIAGNOSTIC
#endif


static CYTHON_INLINE PyObject* __Pyx_PyLong_From_long(long value);


static CYTHON_INLINE long __Pyx_PyLong_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyLong_As_int(PyObject *);


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
#define __Pyx_TypeCheck2(obj, type1, type2) __Pyx_IsAnySubtype2(Py_TYPE(obj), (PyTypeObject *)type1, (PyTypeObject *)type2)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_IsAnySubtype2(PyTypeObject *cls, PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_TypeCheck2(obj, type1, type2) (PyObject_TypeCheck(obj, (PyTypeObject *)type1) || PyObject_TypeCheck(obj, (PyTypeObject *)type2))
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2) {
    return PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2);
}
#endif
#define __Pyx_PyErr_ExceptionMatches2(err1, err2)  __Pyx_PyErr_GivenExceptionMatches2(__Pyx_PyErr_CurrentExceptionType(), err1, err2)
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)
#ifdef PyExceptionInstance_Check
  #define __Pyx_PyBaseException_Check(obj) PyExceptionInstance_Check(obj)
#else
  #define __Pyx_PyBaseException_Check(obj) __Pyx_TypeCheck(obj, PyExc_BaseException)
#endif


#if __PYX_LIMITED_VERSION_HEX < 0x030b0000
static unsigned long __Pyx_cached_runtime_version = 0;
static void __Pyx_init_runtime_version(void);
#else
#define __Pyx_init_runtime_version()
#endif
static unsigned long __Pyx_get_runtime_version(void);


static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);


#if CYTHON_USE_EXC_INFO_STACK && CYTHON_FAST_THREAD_STATE
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif


static CYTHON_INLINE PyObject *__Pyx_PyIter_Next_Plain(PyObject *iterator);
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
static PyObject *__Pyx_GetBuiltinNext_LimitedAPI(void);
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


static CYTHON_INLINE void __Pyx_ReturnWithStopIteration(PyObject* value, int async, int iternext);


struct __pyx_CoroutineObject;
typedef PyObject *(*__pyx_coroutine_body_t)(struct __pyx_CoroutineObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct __pyx_CoroutineObject {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    PyObject *gi_weakreflist;
#endif
    PyObject *classobj;
    PyObject *yieldfrom;
    __Pyx_pyiter_sendfunc yieldfrom_am_send;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    PyObject *gi_frame;
#if CYTHON_USE_SYS_MONITORING && (CYTHON_PROFILE || CYTHON_TRACE)
    PyMonitoringState __pyx_pymonitoring_state[__Pyx_MonitoringEventTypes_CyGen_count];
    uint64_t __pyx_pymonitoring_version;
#endif
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static __Pyx_PySendResult __Pyx_Coroutine_AmSend(PyObject *self, PyObject *value, PyObject **retval);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static __Pyx_PySendResult __Pyx_Coroutine_Close(PyObject *self, PyObject **retval);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);
static char __Pyx_Coroutine_test_and_set_is_running(__pyx_CoroutineObject *gen);
static void __Pyx_Coroutine_unset_is_running(__pyx_CoroutineObject *gen);
static char __Pyx_Coroutine_get_is_running(__pyx_CoroutineObject *gen);
static PyObject *__Pyx_Coroutine_get_is_running_getter(PyObject *gen, void *closure);
#if __PYX_HAS_PY_AM_SEND == 2
static void __Pyx_SetBackportTypeAmSend(PyTypeObject *type, __Pyx_PyAsyncMethodsStruct *static_amsend_methods, __Pyx_pyiter_sendfunc am_send);
#endif
static PyObject *__Pyx_Coroutine_fail_reduce_ex(PyObject *self, PyObject *arg);


#define __Pyx_Generator_USED
#define __Pyx_Generator_CheckExact(obj) __Pyx_IS_TYPE(obj, __pyx_mstate_global->__pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_mstate_global->__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(PyObject *module);
static CYTHON_INLINE PyObject *__Pyx_Generator_GetInlinedResult(PyObject *self);


static int __Pyx_check_binary_version(unsigned long ct_version, unsigned long rt_version, int allow_newer);


static PyObject *__Pyx_DecompressString(const char *s, Py_ssize_t length, int algo);


#if CYTHON_PEP489_MULTI_PHASE_INIT && CYTHON_USE_MODULE_STATE
static PyObject *__Pyx_State_FindModule(void*);
static int __Pyx_State_AddModule(PyObject* module, void*);
static int __Pyx_State_RemoveModule(void*);
#elif CYTHON_USE_MODULE_STATE
#define __Pyx_State_FindModule PyState_FindModule
#define __Pyx_State_AddModule PyState_AddModule
#define __Pyx_State_RemoveModule PyState_RemoveModule
#endif



#if CYTHON_COMPILING_IN_LIMITED_API
    #if CYTHON_METH_FASTCALL
        #define __PYX_FASTCALL_ABI_SUFFIX  "_fastcall"
    #else
        #define __PYX_FASTCALL_ABI_SUFFIX
    #endif
    #define __PYX_LIMITED_ABI_SUFFIX "limited" __PYX_FASTCALL_ABI_SUFFIX __PYX_AM_SEND_ABI_SUFFIX
#else
    #define __PYX_LIMITED_ABI_SUFFIX
#endif
#if __PYX_HAS_PY_AM_SEND == 1
    #define __PYX_AM_SEND_ABI_SUFFIX
#elif __PYX_HAS_PY_AM_SEND == 2
    #define __PYX_AM_SEND_ABI_SUFFIX "amsendbackport"
#else
    #define __PYX_AM_SEND_ABI_SUFFIX "noamsend"
#endif
#ifndef __PYX_MONITORING_ABI_SUFFIX
    #define __PYX_MONITORING_ABI_SUFFIX
#endif
#if CYTHON_USE_TP_FINALIZE
    #define __PYX_TP_FINALIZE_ABI_SUFFIX
#else
    #define __PYX_TP_FINALIZE_ABI_SUFFIX "nofinalize"
#endif
#if CYTHON_USE_FREELISTS || !defined(__Pyx_AsyncGen_USED)
    #define __PYX_FREELISTS_ABI_SUFFIX
#else
    #define __PYX_FREELISTS_ABI_SUFFIX "nofreelists"
#endif
#define CYTHON_ABI  __PYX_ABI_VERSION __PYX_LIMITED_ABI_SUFFIX __PYX_MONITORING_ABI_SUFFIX __PYX_TP_FINALIZE_ABI_SUFFIX __PYX_FREELISTS_ABI_SUFFIX __PYX_AM_SEND_ABI_SUFFIX
#define __PYX_ABI_MODULE_NAME "_cython_" CYTHON_ABI
#define __PYX_TYPE_MODULE_PREFIX __PYX_ABI_MODULE_NAME "."





#define __Pyx_MODULE_NAME "hdcs"
extern int __pyx_module_is_main_hdcs;
int __pyx_module_is_main_hdcs = 0;



static PyObject *__pyx_builtin_compile;
static PyObject *__pyx_builtin_enumerate;


static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0); 
static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_3genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0); 
static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_6genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0); 
static PyObject *__pyx_pf_4hdcs_wlzbi_deobfuscate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_data_with_key, CYTHON_UNUSED PyObject *__pyx_v_Layers); 
static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_1_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_2_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_3_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 



#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

typedef struct {
  PyObject *__pyx_d;
  PyObject *__pyx_b;
  PyObject *__pyx_cython_runtime;
  PyObject *__pyx_empty_tuple;
  PyObject *__pyx_empty_bytes;
  PyObject *__pyx_empty_unicode;
  PyObject *__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate;
  PyObject *__pyx_type_4hdcs___pyx_scope_struct_1_genexpr;
  PyObject *__pyx_type_4hdcs___pyx_scope_struct_2_genexpr;
  PyObject *__pyx_type_4hdcs___pyx_scope_struct_3_genexpr;
  PyTypeObject *__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate;
  PyTypeObject *__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr;
  PyTypeObject *__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr;
  PyTypeObject *__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr;
  __Pyx_CachedCFunction __pyx_umethod_PyDict_Type_items;
  __Pyx_CachedCFunction __pyx_umethod_PyDict_Type_pop;
  __Pyx_CachedCFunction __pyx_umethod_PyDict_Type_values;
  PyObject *__pyx_codeobj_tab[4];
  PyObject *__pyx_string_tab[52];
  PyObject *__pyx_number_tab[4];


#if CYTHON_USE_FREELISTS
struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *__pyx_freelist_4hdcs___pyx_scope_struct__wlzbi_deobfuscate[8];
int __pyx_freecount_4hdcs___pyx_scope_struct__wlzbi_deobfuscate;
#endif

#if CYTHON_USE_FREELISTS
struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *__pyx_freelist_4hdcs___pyx_scope_struct_1_genexpr[8];
int __pyx_freecount_4hdcs___pyx_scope_struct_1_genexpr;
#endif

#if CYTHON_USE_FREELISTS
struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *__pyx_freelist_4hdcs___pyx_scope_struct_2_genexpr[8];
int __pyx_freecount_4hdcs___pyx_scope_struct_2_genexpr;
#endif

#if CYTHON_USE_FREELISTS
struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *__pyx_freelist_4hdcs___pyx_scope_struct_3_genexpr[8];
int __pyx_freecount_4hdcs___pyx_scope_struct_3_genexpr;
#endif

PyTypeObject *__pyx_CommonTypesMetaclassType;


#if CYTHON_COMPILING_IN_LIMITED_API
PyObject *__Pyx_CachedMethodType;
#endif


PyTypeObject *__pyx_CyFunctionType;


struct __Pyx_CodeObjectCache __pyx_code_cache;


#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
PyObject *__Pyx_GetBuiltinNext_LimitedAPI_cache;
#endif


PyTypeObject *__pyx_GeneratorType;


} __pyx_mstatetype;

#if CYTHON_USE_MODULE_STATE
#ifdef __cplusplus
namespace {
extern struct PyModuleDef __pyx_moduledef;
} 
#else
static struct PyModuleDef __pyx_moduledef;
#endif

#define __pyx_mstate_global (__Pyx_PyModule_GetState(__Pyx_State_FindModule(&__pyx_moduledef)))

#define __pyx_m (__Pyx_State_FindModule(&__pyx_moduledef))
#else
static __pyx_mstatetype __pyx_mstate_global_static =
#ifdef __cplusplus
    {};
#else
    {0};
#endif
static __pyx_mstatetype * const __pyx_mstate_global = &__pyx_mstate_global_static;
#endif

#define __pyx_kp_u_ __pyx_string_tab[0]
#define __pyx_kp_u__2 __pyx_string_tab[1]
#define __pyx_kp_u__3 __pyx_string_tab[2]
#define __pyx_kp_u_disable __pyx_string_tab[3]
#define __pyx_kp_u_enable __pyx_string_tab[4]
#define __pyx_kp_u_gc __pyx_string_tab[5]
#define __pyx_kp_u_isenabled __pyx_string_tab[6]
#define __pyx_kp_u_wlzbi __pyx_string_tab[7]
#define __pyx_kp_u_wlzbi_temp_hdcs_py __pyx_string_tab[8]
#define __pyx_n_u_Encrypted_Code __pyx_string_tab[9]
#define __pyx_n_u_Layers __pyx_string_tab[10]
#define __pyx_n_u_Pyx_PyDict_NextRef __pyx_string_tab[11]
#define __pyx_n_u_asyncio_coroutines __pyx_string_tab[12]
#define __pyx_n_u_builtins __pyx_string_tab[13]
#define __pyx_n_u_c __pyx_string_tab[14]
#define __pyx_n_u_class_getitem __pyx_string_tab[15]
#define __pyx_n_u_cline_in_traceback __pyx_string_tab[16]
#define __pyx_n_u_close __pyx_string_tab[17]
#define __pyx_n_u_compile __pyx_string_tab[18]
#define __pyx_n_u_data_with_key __pyx_string_tab[19]
#define __pyx_n_u_decoded_code __pyx_string_tab[20]
#define __pyx_n_u_encrypted_text __pyx_string_tab[21]
#define __pyx_n_u_enumerate __pyx_string_tab[22]
#define __pyx_n_u_exec __pyx_string_tab[23]
#define __pyx_n_u_filename __pyx_string_tab[24]
#define __pyx_n_u_func __pyx_string_tab[25]
#define __pyx_n_u_genexpr __pyx_string_tab[26]
#define __pyx_n_u_hdcs __pyx_string_tab[27]
#define __pyx_n_u_i __pyx_string_tab[28]
#define __pyx_n_u_is_coroutine __pyx_string_tab[29]
#define __pyx_n_u_items __pyx_string_tab[30]
#define __pyx_n_u_key __pyx_string_tab[31]
#define __pyx_n_u_main __pyx_string_tab[32]
#define __pyx_n_u_mode __pyx_string_tab[33]
#define __pyx_n_u_module __pyx_string_tab[34]
#define __pyx_n_u_name __pyx_string_tab[35]
#define __pyx_n_u_next __pyx_string_tab[36]
#define __pyx_n_u_pop __pyx_string_tab[37]
#define __pyx_n_u_qualname __pyx_string_tab[38]
#define __pyx_n_u_send __pyx_string_tab[39]
#define __pyx_n_u_set_name __pyx_string_tab[40]
#define __pyx_n_u_setdefault __pyx_string_tab[41]
#define __pyx_n_u_test __pyx_string_tab[42]
#define __pyx_n_u_throw __pyx_string_tab[43]
#define __pyx_n_u_value __pyx_string_tab[44]
#define __pyx_n_u_values __pyx_string_tab[45]
#define __pyx_n_u_wlzbi_deobfuscate __pyx_string_tab[46]
#define __pyx_n_u_wlzbi_deobfuscate_locals_genexpr __pyx_string_tab[47]
#define __pyx_kp_b_iso88591_RuN_E_q_2U_a __pyx_string_tab[48]
#define __pyx_kp_b_iso88591__4 __pyx_string_tab[49]
#define __pyx_kp_b_iso88591_a __pyx_string_tab[50]
#define __pyx_kp_b_iso88591_q __pyx_string_tab[51]
#define __pyx_int_0 __pyx_number_tab[0]
#define __pyx_int_1 __pyx_number_tab[1]
#define __pyx_int_2 __pyx_number_tab[2]
#define __pyx_int_3 __pyx_number_tab[3]

#if CYTHON_USE_MODULE_STATE
static CYTHON_SMALL_CODE int __pyx_m_clear(PyObject *m) {
  __pyx_mstatetype *clear_module_state = __Pyx_PyModule_GetState(m);
  if (!clear_module_state) return 0;
  Py_CLEAR(clear_module_state->__pyx_d);
  Py_CLEAR(clear_module_state->__pyx_b);
  Py_CLEAR(clear_module_state->__pyx_cython_runtime);
  Py_CLEAR(clear_module_state->__pyx_empty_tuple);
  Py_CLEAR(clear_module_state->__pyx_empty_bytes);
  Py_CLEAR(clear_module_state->__pyx_empty_unicode);
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __Pyx_State_RemoveModule(NULL);
  #endif
  Py_CLEAR(clear_module_state->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate);
  Py_CLEAR(clear_module_state->__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate);
  Py_CLEAR(clear_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr);
  Py_CLEAR(clear_module_state->__pyx_type_4hdcs___pyx_scope_struct_1_genexpr);
  Py_CLEAR(clear_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr);
  Py_CLEAR(clear_module_state->__pyx_type_4hdcs___pyx_scope_struct_2_genexpr);
  Py_CLEAR(clear_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr);
  Py_CLEAR(clear_module_state->__pyx_type_4hdcs___pyx_scope_struct_3_genexpr);
  for (int i=0; i<4; ++i) { Py_CLEAR(clear_module_state->__pyx_codeobj_tab[i]); }
  for (int i=0; i<52; ++i) { Py_CLEAR(clear_module_state->__pyx_string_tab[i]); }
  for (int i=0; i<4; ++i) { Py_CLEAR(clear_module_state->__pyx_number_tab[i]); }


Py_CLEAR(clear_module_state->__pyx_CommonTypesMetaclassType);


Py_CLEAR(clear_module_state->__pyx_CyFunctionType);


Py_CLEAR(clear_module_state->__pyx_GeneratorType);


return 0;
}
#endif

#if CYTHON_USE_MODULE_STATE
static CYTHON_SMALL_CODE int __pyx_m_traverse(PyObject *m, visitproc visit, void *arg) {
  __pyx_mstatetype *traverse_module_state = __Pyx_PyModule_GetState(m);
  if (!traverse_module_state) return 0;
  Py_VISIT(traverse_module_state->__pyx_d);
  Py_VISIT(traverse_module_state->__pyx_b);
  Py_VISIT(traverse_module_state->__pyx_cython_runtime);
  __Pyx_VISIT_CONST(traverse_module_state->__pyx_empty_tuple);
  __Pyx_VISIT_CONST(traverse_module_state->__pyx_empty_bytes);
  __Pyx_VISIT_CONST(traverse_module_state->__pyx_empty_unicode);
  Py_VISIT(traverse_module_state->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate);
  Py_VISIT(traverse_module_state->__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate);
  Py_VISIT(traverse_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr);
  Py_VISIT(traverse_module_state->__pyx_type_4hdcs___pyx_scope_struct_1_genexpr);
  Py_VISIT(traverse_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr);
  Py_VISIT(traverse_module_state->__pyx_type_4hdcs___pyx_scope_struct_2_genexpr);
  Py_VISIT(traverse_module_state->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr);
  Py_VISIT(traverse_module_state->__pyx_type_4hdcs___pyx_scope_struct_3_genexpr);
  for (int i=0; i<4; ++i) { __Pyx_VISIT_CONST(traverse_module_state->__pyx_codeobj_tab[i]); }
  for (int i=0; i<52; ++i) { __Pyx_VISIT_CONST(traverse_module_state->__pyx_string_tab[i]); }
  for (int i=0; i<4; ++i) { __Pyx_VISIT_CONST(traverse_module_state->__pyx_number_tab[i]); }


Py_VISIT(traverse_module_state->__pyx_CommonTypesMetaclassType);


Py_VISIT(traverse_module_state->__pyx_CyFunctionType);


Py_VISIT(traverse_module_state->__pyx_GeneratorType);


return 0;
}
#endif





static PyObject *__pyx_pw_4hdcs_1wlzbi_deobfuscate(PyObject *__pyx_self, 
#if CYTHON_METH_FASTCALL
PyObject *const *__pyx_args, Py_ssize_t __pyx_nargs, PyObject *__pyx_kwds
#else
PyObject *__pyx_args, PyObject *__pyx_kwds
#endif
); 
static PyMethodDef __pyx_mdef_4hdcs_1wlzbi_deobfuscate = {"wlzbi_deobfuscate", (PyCFunction)(void(*)(void))(__Pyx_PyCFunction_FastCallWithKeywords)__pyx_pw_4hdcs_1wlzbi_deobfuscate, __Pyx_METH_FASTCALL|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_4hdcs_1wlzbi_deobfuscate(PyObject *__pyx_self, 
#if CYTHON_METH_FASTCALL
PyObject *const *__pyx_args, Py_ssize_t __pyx_nargs, PyObject *__pyx_kwds
#else
PyObject *__pyx_args, PyObject *__pyx_kwds
#endif
) {
  PyObject *__pyx_v_data_with_key = 0;
  CYTHON_UNUSED PyObject *__pyx_v_Layers = 0;
  #if !CYTHON_METH_FASTCALL
  CYTHON_UNUSED Py_ssize_t __pyx_nargs;
  #endif
  CYTHON_UNUSED PyObject *const *__pyx_kwvalues;
  PyObject* values[2] = {0,0};
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("wlzbi_deobfuscate (wrapper)", 0);
  #if !CYTHON_METH_FASTCALL
  #if CYTHON_ASSUME_SAFE_SIZE
  __pyx_nargs = PyTuple_GET_SIZE(__pyx_args);
  #else
  __pyx_nargs = PyTuple_Size(__pyx_args); if (unlikely(__pyx_nargs < 0)) return NULL;
  #endif
  #endif
  __pyx_kwvalues = __Pyx_KwValues_FASTCALL(__pyx_args, __pyx_nargs);
  {
    PyObject ** const __pyx_pyargnames[] = {&__pyx_mstate_global->__pyx_n_u_data_with_key,&__pyx_mstate_global->__pyx_n_u_Layers,0};
    const Py_ssize_t __pyx_kwds_len = (__pyx_kwds) ? __Pyx_NumKwargs_FASTCALL(__pyx_kwds) : 0;
    if (unlikely(__pyx_kwds_len) < 0) __PYX_ERR(0, 2, __pyx_L3_error)
    if (__pyx_kwds_len > 0) {
      switch (__pyx_nargs) {
        case  2:
        values[1] = __Pyx_ArgRef_FASTCALL(__pyx_args, 1);
        if (!CYTHON_ASSUME_SAFE_MACROS && unlikely(!values[1])) __PYX_ERR(0, 2, __pyx_L3_error)
        CYTHON_FALLTHROUGH;
        case  1:
        values[0] = __Pyx_ArgRef_FASTCALL(__pyx_args, 0);
        if (!CYTHON_ASSUME_SAFE_MACROS && unlikely(!values[0])) __PYX_ERR(0, 2, __pyx_L3_error)
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      const Py_ssize_t kwd_pos_args = __pyx_nargs;
      if (__Pyx_ParseKeywords(__pyx_kwds, __pyx_kwvalues, __pyx_pyargnames, 0, values, kwd_pos_args, __pyx_kwds_len, "wlzbi_deobfuscate", 0) < (0)) __PYX_ERR(0, 2, __pyx_L3_error)
      for (Py_ssize_t i = __pyx_nargs; i < 2; i++) {
        if (unlikely(!values[i])) { __Pyx_RaiseArgtupleInvalid("wlzbi_deobfuscate", 1, 2, 2, i); __PYX_ERR(0, 2, __pyx_L3_error) }
      }
    } else if (unlikely(__pyx_nargs != 2)) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = __Pyx_ArgRef_FASTCALL(__pyx_args, 0);
      if (!CYTHON_ASSUME_SAFE_MACROS && unlikely(!values[0])) __PYX_ERR(0, 2, __pyx_L3_error)
      values[1] = __Pyx_ArgRef_FASTCALL(__pyx_args, 1);
      if (!CYTHON_ASSUME_SAFE_MACROS && unlikely(!values[1])) __PYX_ERR(0, 2, __pyx_L3_error)
    }
    __pyx_v_data_with_key = values[0];
    __pyx_v_Layers = values[1];
  }
  goto __pyx_L6_skip;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("wlzbi_deobfuscate", 1, 2, 2, __pyx_nargs); __PYX_ERR(0, 2, __pyx_L3_error)
  __pyx_L6_skip:;
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L3_error:;
  for (Py_ssize_t __pyx_temp=0; __pyx_temp < (Py_ssize_t)(sizeof(values)/sizeof(values[0])); ++__pyx_temp) {
    Py_XDECREF(values[__pyx_temp]);
  }
  __Pyx_AddTraceback("hdcs.wlzbi_deobfuscate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_4hdcs_wlzbi_deobfuscate(__pyx_self, __pyx_v_data_with_key, __pyx_v_Layers);

  
  for (Py_ssize_t __pyx_temp=0; __pyx_temp < (Py_ssize_t)(sizeof(values)/sizeof(values[0])); ++__pyx_temp) {
    Py_XDECREF(values[__pyx_temp]);
  }
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)__pyx_tp_new_4hdcs___pyx_scope_struct_1_genexpr(__pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr, __pyx_mstate_global->__pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 3, __pyx_L1_error)
  } else {
    __Pyx_GOTREF((PyObject *)__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *) __pyx_self;
  __Pyx_INCREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __Pyx_GIVEREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __pyx_cur_scope->__pyx_genexpr_arg_0 = __pyx_genexpr_arg_0;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4hdcs_17wlzbi_deobfuscate_2generator, ((PyObject *)__pyx_mstate_global->__pyx_codeobj_tab[0]), (PyObject *) __pyx_cur_scope, __pyx_mstate_global->__pyx_n_u_genexpr, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate_locals_genexpr, __pyx_mstate_global->__pyx_n_u_hdcs); if (unlikely(!gen)) __PYX_ERR(0, 3, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("hdcs.wlzbi_deobfuscate.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF((PyObject *)__pyx_cur_scope);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *(*__pyx_t_2)(PyObject *);
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 3, __pyx_L1_error)
  __pyx_r = PyList_New(0); if (unlikely(!__pyx_r)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_r);
  if (unlikely(!__pyx_cur_scope->__pyx_genexpr_arg_0)) { __Pyx_RaiseUnboundLocalError(".0"); __PYX_ERR(0, 3, __pyx_L1_error) }
  __pyx_t_1 = PyObject_GetIter(__pyx_cur_scope->__pyx_genexpr_arg_0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = (CYTHON_COMPILING_IN_LIMITED_API) ? PyIter_Next : __Pyx_PyObject_GetIterNextFunc(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  for (;;) {
    {
      __pyx_t_3 = __pyx_t_2(__pyx_t_1);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (unlikely(!__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) __PYX_ERR(0, 3, __pyx_L1_error)
          PyErr_Clear();
        }
        break;
      }
    }
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_i);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_i, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_data_with_key)) { __Pyx_RaiseClosureNameError("data_with_key"); __PYX_ERR(0, 3, __pyx_L1_error) }
    __pyx_t_3 = __Pyx_PyLong_MultiplyObjC(__pyx_cur_scope->__pyx_v_i, __pyx_mstate_global->__pyx_int_2, 2, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 3, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = __Pyx_PyObject_GetItem(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_data_with_key, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 3, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(__Pyx_ListComp_Append(__pyx_r, (PyObject*)__pyx_t_4))) __PYX_ERR(0, 3, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  if (__Pyx_PyErr_Occurred()) {
    __Pyx_Generator_Replace_StopIteration(0);
    __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  }
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_5generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_3genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)__pyx_tp_new_4hdcs___pyx_scope_struct_2_genexpr(__pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr, __pyx_mstate_global->__pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 4, __pyx_L1_error)
  } else {
    __Pyx_GOTREF((PyObject *)__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *) __pyx_self;
  __Pyx_INCREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __Pyx_GIVEREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __pyx_cur_scope->__pyx_genexpr_arg_0 = __pyx_genexpr_arg_0;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4hdcs_17wlzbi_deobfuscate_5generator1, ((PyObject *)__pyx_mstate_global->__pyx_codeobj_tab[1]), (PyObject *) __pyx_cur_scope, __pyx_mstate_global->__pyx_n_u_genexpr, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate_locals_genexpr, __pyx_mstate_global->__pyx_n_u_hdcs); if (unlikely(!gen)) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("hdcs.wlzbi_deobfuscate.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF((PyObject *)__pyx_cur_scope);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_5generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *(*__pyx_t_2)(PyObject *);
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 4, __pyx_L1_error)
  __pyx_r = PyList_New(0); if (unlikely(!__pyx_r)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_r);
  if (unlikely(!__pyx_cur_scope->__pyx_genexpr_arg_0)) { __Pyx_RaiseUnboundLocalError(".0"); __PYX_ERR(0, 4, __pyx_L1_error) }
  __pyx_t_1 = PyObject_GetIter(__pyx_cur_scope->__pyx_genexpr_arg_0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = (CYTHON_COMPILING_IN_LIMITED_API) ? PyIter_Next : __Pyx_PyObject_GetIterNextFunc(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  for (;;) {
    {
      __pyx_t_3 = __pyx_t_2(__pyx_t_1);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (unlikely(!__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) __PYX_ERR(0, 4, __pyx_L1_error)
          PyErr_Clear();
        }
        break;
      }
    }
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_i);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_i, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_data_with_key)) { __Pyx_RaiseClosureNameError("data_with_key"); __PYX_ERR(0, 4, __pyx_L1_error) }
    __pyx_t_3 = __Pyx_PyLong_MultiplyObjC(__pyx_cur_scope->__pyx_v_i, __pyx_mstate_global->__pyx_int_2, 2, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = __Pyx_PyLong_AddObjC(__pyx_t_3, __pyx_mstate_global->__pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_data_with_key, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(__Pyx_ListComp_Append(__pyx_r, (PyObject*)__pyx_t_3))) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  if (__Pyx_PyErr_Occurred()) {
    __Pyx_Generator_Replace_StopIteration(0);
    __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  }
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_8generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4hdcs_17wlzbi_deobfuscate_6genexpr(PyObject *__pyx_self, PyObject *__pyx_genexpr_arg_0) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)__pyx_tp_new_4hdcs___pyx_scope_struct_3_genexpr(__pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr, __pyx_mstate_global->__pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 5, __pyx_L1_error)
  } else {
    __Pyx_GOTREF((PyObject *)__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *) __pyx_self;
  __Pyx_INCREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __Pyx_GIVEREF((PyObject *)__pyx_cur_scope->__pyx_outer_scope);
  __pyx_cur_scope->__pyx_genexpr_arg_0 = __pyx_genexpr_arg_0;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4hdcs_17wlzbi_deobfuscate_8generator2, ((PyObject *)__pyx_mstate_global->__pyx_codeobj_tab[2]), (PyObject *) __pyx_cur_scope, __pyx_mstate_global->__pyx_n_u_genexpr, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate_locals_genexpr, __pyx_mstate_global->__pyx_n_u_hdcs); if (unlikely(!gen)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("hdcs.wlzbi_deobfuscate.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF((PyObject *)__pyx_cur_scope);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_8generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  void *__pyx_t_5;
  int __pyx_t_6;
  int __pyx_t_7;
  Py_ssize_t __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  long __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  long __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 5, __pyx_L1_error)
  __pyx_r = PyList_New(0); if (unlikely(!__pyx_r)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_r);
  __Pyx_INCREF(__pyx_mstate_global->__pyx_int_0);
  __pyx_t_1 = __pyx_mstate_global->__pyx_int_0;
  if (unlikely(!__pyx_cur_scope->__pyx_genexpr_arg_0)) { __Pyx_RaiseUnboundLocalError(".0"); __PYX_ERR(0, 5, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_genexpr_arg_0 == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' is not iterable");
    __PYX_ERR(0, 5, __pyx_L1_error)
  }
  __Pyx_INCREF(__pyx_cur_scope->__pyx_genexpr_arg_0);
  __pyx_t_2 = __pyx_cur_scope->__pyx_genexpr_arg_0;
  __pyx_t_7 = __Pyx_init_unicode_iteration(__pyx_t_2, (&__pyx_t_4), (&__pyx_t_5), (&__pyx_t_6)); if (unlikely(__pyx_t_7 == ((int)-1))) __PYX_ERR(0, 5, __pyx_L1_error)
  for (__pyx_t_8 = 0; __pyx_t_8 < __pyx_t_4; __pyx_t_8++) {
    __pyx_t_3 = __pyx_t_8;
    __pyx_t_9 = __Pyx_PyUnicode_FromOrdinal(__Pyx_PyUnicode_READ(__pyx_t_6, __pyx_t_5, __pyx_t_3)); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_c);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_c, __pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_9);
    __pyx_t_9 = 0;
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_i);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_i, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_9 = __Pyx_PyLong_AddObjC(__pyx_t_1, __pyx_mstate_global->__pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_1);
    __pyx_t_1 = __pyx_t_9;
    __pyx_t_9 = 0;
    __pyx_t_10 = __Pyx_PyObject_Ord(__pyx_cur_scope->__pyx_v_c); if (unlikely(__pyx_t_10 == ((long)(long)(Py_UCS4)-1))) __PYX_ERR(0, 5, __pyx_L1_error)
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_key)) { __Pyx_RaiseClosureNameError("key"); __PYX_ERR(0, 5, __pyx_L1_error) }
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_key)) { __Pyx_RaiseClosureNameError("key"); __PYX_ERR(0, 5, __pyx_L1_error) }
    __pyx_t_9 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_key;
    __Pyx_INCREF(__pyx_t_9);
    if (unlikely(__pyx_t_9 == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "object of type 'NoneType' has no len()");
      __PYX_ERR(0, 5, __pyx_L1_error)
    }
    __pyx_t_11 = __Pyx_PyUnicode_GET_LENGTH(__pyx_t_9); if (unlikely(__pyx_t_11 == ((Py_ssize_t)-1))) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = PyLong_FromSsize_t(__pyx_t_11); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_12 = PyNumber_Remainder(__pyx_cur_scope->__pyx_v_i, __pyx_t_9); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = __Pyx_PyObject_GetItem(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_key, __pyx_t_12); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    __pyx_t_13 = __Pyx_PyObject_Ord(__pyx_t_9); if (unlikely(__pyx_t_13 == ((long)(long)(Py_UCS4)-1))) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = PyUnicode_FromOrdinal((__pyx_t_10 ^ __pyx_t_13)); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (unlikely(__Pyx_ListComp_Append(__pyx_r, (PyObject*)__pyx_t_9))) __PYX_ERR(0, 5, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_12);
  if (__Pyx_PyErr_Occurred()) {
    __Pyx_Generator_Replace_StopIteration(0);
    __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  }
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_4hdcs_wlzbi_deobfuscate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_data_with_key, CYTHON_UNUSED PyObject *__pyx_v_Layers) {
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *__pyx_cur_scope;
  PyObject *__pyx_v_encrypted_text = NULL;
  PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_2generator = 0;
  PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_5generator1 = 0;
  PyObject *__pyx_gb_4hdcs_17wlzbi_deobfuscate_8generator2 = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  size_t __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("wlzbi_deobfuscate", 0);
  __pyx_cur_scope = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)__pyx_tp_new_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(__pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, __pyx_mstate_global->__pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 2, __pyx_L1_error)
  } else {
    __Pyx_GOTREF((PyObject *)__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_data_with_key = __pyx_v_data_with_key;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_data_with_key);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_data_with_key);

  
  __pyx_t_2 = NULL;
  __pyx_t_3 = __pyx_cur_scope->__pyx_v_data_with_key;
  __Pyx_INCREF(__pyx_t_3);
  __pyx_t_4 = PyObject_Length(__pyx_t_3); if (unlikely(__pyx_t_4 == ((Py_ssize_t)-1))) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyLong_FromSsize_t(__Pyx_div_Py_ssize_t(__pyx_t_4, 2, 1)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = 1;
  {
    PyObject *__pyx_callargs[2] = {__pyx_t_2, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyObject_FastCall((PyObject*)(&PyRange_Type), __pyx_callargs+__pyx_t_5, (2-__pyx_t_5) | (__pyx_t_5*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
  }
  __pyx_t_3 = __pyx_pf_4hdcs_17wlzbi_deobfuscate_genexpr(((PyObject*)__pyx_cur_scope), __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Generator_GetInlinedResult(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyUnicode_Join(__pyx_mstate_global->__pyx_kp_u_, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_encrypted_text = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;

  
  __pyx_t_1 = NULL;
  __pyx_t_2 = __pyx_cur_scope->__pyx_v_data_with_key;
  __Pyx_INCREF(__pyx_t_2);
  __pyx_t_4 = PyObject_Length(__pyx_t_2); if (unlikely(__pyx_t_4 == ((Py_ssize_t)-1))) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyLong_FromSsize_t(__Pyx_div_Py_ssize_t(__pyx_t_4, 2, 1)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = 1;
  {
    PyObject *__pyx_callargs[2] = {__pyx_t_1, __pyx_t_2};
    __pyx_t_3 = __Pyx_PyObject_FastCall((PyObject*)(&PyRange_Type), __pyx_callargs+__pyx_t_5, (2-__pyx_t_5) | (__pyx_t_5*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 4, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
  }
  __pyx_t_2 = __pyx_pf_4hdcs_17wlzbi_deobfuscate_3genexpr(((PyObject*)__pyx_cur_scope), __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_Generator_GetInlinedResult(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyUnicode_Join(__pyx_mstate_global->__pyx_kp_u_, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_key = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __pyx_pf_4hdcs_17wlzbi_deobfuscate_6genexpr(((PyObject*)__pyx_cur_scope), __pyx_v_encrypted_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_Generator_GetInlinedResult(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyUnicode_Join(__pyx_mstate_global->__pyx_kp_u_, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("hdcs.wlzbi_deobfuscate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_encrypted_text);
  __Pyx_XDECREF(__pyx_gb_4hdcs_17wlzbi_deobfuscate_2generator);
  __Pyx_XDECREF(__pyx_gb_4hdcs_17wlzbi_deobfuscate_5generator1);
  __Pyx_XDECREF(__pyx_gb_4hdcs_17wlzbi_deobfuscate_8generator2);
  __Pyx_DECREF((PyObject *)__pyx_cur_scope);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}


static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct__wlzbi_deobfuscate > 0) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate))))
  {
    o = (PyObject*)__pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct__wlzbi_deobfuscate[--__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct__wlzbi_deobfuscate];
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(Py_TYPE(o));
    #endif
    memset(o, 0, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate));
    #if CYTHON_COMPILING_IN_LIMITED_API
    (void) PyObject_Init(o, t);
    #else
    (void) PyObject_INIT(o, t);
    #endif
    PyObject_GC_Track(o);
  } else
  #endif
  {
    o = __Pyx_AllocateExtensionType(t, 1);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(PyObject *o) {
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *p = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(__Pyx_PyObject_GetSlot(o, tp_finalize, destructor)) && !__Pyx_PyObject_GC_IsFinalized(o)) {
    if (__Pyx_PyObject_GetSlot(o, tp_dealloc, destructor) == __pyx_tp_dealloc_4hdcs___pyx_scope_struct__wlzbi_deobfuscate) {
      if (PyObject_CallFinalizerFromDealloc(o)) return;
    }
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_data_with_key);
  Py_CLEAR(p->__pyx_v_key);
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct__wlzbi_deobfuscate < 8) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(Py_TYPE(o), __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate))))
  {
    __pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct__wlzbi_deobfuscate[__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct__wlzbi_deobfuscate++] = ((struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)o);
  } else
  #endif
  {
    PyTypeObject *tp = Py_TYPE(o);
    #if CYTHON_USE_TYPE_SLOTS
    (*tp->tp_free)(o);
    #else
    {
      freefunc tp_free = (freefunc)PyType_GetSlot(tp, Py_tp_free);
      if (tp_free) tp_free(o);
    }
    #endif
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(tp);
    #endif
  }
}

static int __pyx_tp_traverse_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *p = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)o;
  {
    e = __Pyx_call_type_traverse(o, 1, v, a);
    if (e) return e;
  }
  if (p->__pyx_v_data_with_key) {
    e = (*v)(p->__pyx_v_data_with_key, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_4hdcs___pyx_scope_struct__wlzbi_deobfuscate(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *p = (struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate *)o;
  tmp = ((PyObject*)p->__pyx_v_data_with_key);
  p->__pyx_v_data_with_key = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}
#if CYTHON_USE_TYPE_SPECS
static PyType_Slot __pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate_slots[] = {
  {Py_tp_dealloc, (void *)__pyx_tp_dealloc_4hdcs___pyx_scope_struct__wlzbi_deobfuscate},
  {Py_tp_traverse, (void *)__pyx_tp_traverse_4hdcs___pyx_scope_struct__wlzbi_deobfuscate},
  {Py_tp_clear, (void *)__pyx_tp_clear_4hdcs___pyx_scope_struct__wlzbi_deobfuscate},
  {Py_tp_new, (void *)__pyx_tp_new_4hdcs___pyx_scope_struct__wlzbi_deobfuscate},
  {0, 0},
};
static PyType_Spec __pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate_spec = {
  "hdcs.__pyx_scope_struct__wlzbi_deobfuscate",
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate),
  0,
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC,
  __pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate_slots,
};
#else

static PyTypeObject __pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate = {
  PyVarObject_HEAD_INIT(0, 0)
  "hdcs.""__pyx_scope_struct__wlzbi_deobfuscate", 
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct__wlzbi_deobfuscate), 
  0, 
  __pyx_tp_dealloc_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, 
  __pyx_tp_clear_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if !CYTHON_USE_TYPE_SPECS
  0, 
  #endif
  0, 
  0, 
  __pyx_tp_new_4hdcs___pyx_scope_struct__wlzbi_deobfuscate, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if CYTHON_USE_TP_FINALIZE
  0, 
  #else
  NULL, 
  #endif
  #if !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800
  0, 
  #endif
  #if __PYX_NEED_TP_PRINT_SLOT == 1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030C0000
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030d00A4
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
  0, 
  #endif
};
#endif

static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_1_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_1_genexpr > 0) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr))))
  {
    o = (PyObject*)__pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_1_genexpr[--__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_1_genexpr];
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(Py_TYPE(o));
    #endif
    memset(o, 0, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr));
    #if CYTHON_COMPILING_IN_LIMITED_API
    (void) PyObject_Init(o, t);
    #else
    (void) PyObject_INIT(o, t);
    #endif
    PyObject_GC_Track(o);
  } else
  #endif
  {
    o = __Pyx_AllocateExtensionType(t, 1);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4hdcs___pyx_scope_struct_1_genexpr(PyObject *o) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(__Pyx_PyObject_GetSlot(o, tp_finalize, destructor)) && !__Pyx_PyObject_GC_IsFinalized(o)) {
    if (__Pyx_PyObject_GetSlot(o, tp_dealloc, destructor) == __pyx_tp_dealloc_4hdcs___pyx_scope_struct_1_genexpr) {
      if (PyObject_CallFinalizerFromDealloc(o)) return;
    }
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_genexpr_arg_0);
  Py_CLEAR(p->__pyx_v_i);
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_1_genexpr < 8) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(Py_TYPE(o), __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr))))
  {
    __pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_1_genexpr[__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_1_genexpr++] = ((struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)o);
  } else
  #endif
  {
    PyTypeObject *tp = Py_TYPE(o);
    #if CYTHON_USE_TYPE_SLOTS
    (*tp->tp_free)(o);
    #else
    {
      freefunc tp_free = (freefunc)PyType_GetSlot(tp, Py_tp_free);
      if (tp_free) tp_free(o);
    }
    #endif
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(tp);
    #endif
  }
}

static int __pyx_tp_traverse_4hdcs___pyx_scope_struct_1_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr *)o;
  {
    e = __Pyx_call_type_traverse(o, 1, v, a);
    if (e) return e;
  }
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_genexpr_arg_0) {
    e = (*v)(p->__pyx_genexpr_arg_0, a); if (e) return e;
  }
  if (p->__pyx_v_i) {
    e = (*v)(p->__pyx_v_i, a); if (e) return e;
  }
  return 0;
}
#if CYTHON_USE_TYPE_SPECS
static PyType_Slot __pyx_type_4hdcs___pyx_scope_struct_1_genexpr_slots[] = {
  {Py_tp_dealloc, (void *)__pyx_tp_dealloc_4hdcs___pyx_scope_struct_1_genexpr},
  {Py_tp_traverse, (void *)__pyx_tp_traverse_4hdcs___pyx_scope_struct_1_genexpr},
  {Py_tp_new, (void *)__pyx_tp_new_4hdcs___pyx_scope_struct_1_genexpr},
  {0, 0},
};
static PyType_Spec __pyx_type_4hdcs___pyx_scope_struct_1_genexpr_spec = {
  "hdcs.__pyx_scope_struct_1_genexpr",
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr),
  0,
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC,
  __pyx_type_4hdcs___pyx_scope_struct_1_genexpr_slots,
};
#else

static PyTypeObject __pyx_type_4hdcs___pyx_scope_struct_1_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "hdcs.""__pyx_scope_struct_1_genexpr", 
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_1_genexpr), 
  0, 
  __pyx_tp_dealloc_4hdcs___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4hdcs___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if !CYTHON_USE_TYPE_SPECS
  0, 
  #endif
  0, 
  0, 
  __pyx_tp_new_4hdcs___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if CYTHON_USE_TP_FINALIZE
  0, 
  #else
  NULL, 
  #endif
  #if !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800
  0, 
  #endif
  #if __PYX_NEED_TP_PRINT_SLOT == 1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030C0000
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030d00A4
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
  0, 
  #endif
};
#endif

static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_2_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_2_genexpr > 0) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr))))
  {
    o = (PyObject*)__pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_2_genexpr[--__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_2_genexpr];
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(Py_TYPE(o));
    #endif
    memset(o, 0, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr));
    #if CYTHON_COMPILING_IN_LIMITED_API
    (void) PyObject_Init(o, t);
    #else
    (void) PyObject_INIT(o, t);
    #endif
    PyObject_GC_Track(o);
  } else
  #endif
  {
    o = __Pyx_AllocateExtensionType(t, 1);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4hdcs___pyx_scope_struct_2_genexpr(PyObject *o) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(__Pyx_PyObject_GetSlot(o, tp_finalize, destructor)) && !__Pyx_PyObject_GC_IsFinalized(o)) {
    if (__Pyx_PyObject_GetSlot(o, tp_dealloc, destructor) == __pyx_tp_dealloc_4hdcs___pyx_scope_struct_2_genexpr) {
      if (PyObject_CallFinalizerFromDealloc(o)) return;
    }
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_genexpr_arg_0);
  Py_CLEAR(p->__pyx_v_i);
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_2_genexpr < 8) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(Py_TYPE(o), __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr))))
  {
    __pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_2_genexpr[__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_2_genexpr++] = ((struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)o);
  } else
  #endif
  {
    PyTypeObject *tp = Py_TYPE(o);
    #if CYTHON_USE_TYPE_SLOTS
    (*tp->tp_free)(o);
    #else
    {
      freefunc tp_free = (freefunc)PyType_GetSlot(tp, Py_tp_free);
      if (tp_free) tp_free(o);
    }
    #endif
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(tp);
    #endif
  }
}

static int __pyx_tp_traverse_4hdcs___pyx_scope_struct_2_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr *)o;
  {
    e = __Pyx_call_type_traverse(o, 1, v, a);
    if (e) return e;
  }
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_genexpr_arg_0) {
    e = (*v)(p->__pyx_genexpr_arg_0, a); if (e) return e;
  }
  if (p->__pyx_v_i) {
    e = (*v)(p->__pyx_v_i, a); if (e) return e;
  }
  return 0;
}
#if CYTHON_USE_TYPE_SPECS
static PyType_Slot __pyx_type_4hdcs___pyx_scope_struct_2_genexpr_slots[] = {
  {Py_tp_dealloc, (void *)__pyx_tp_dealloc_4hdcs___pyx_scope_struct_2_genexpr},
  {Py_tp_traverse, (void *)__pyx_tp_traverse_4hdcs___pyx_scope_struct_2_genexpr},
  {Py_tp_new, (void *)__pyx_tp_new_4hdcs___pyx_scope_struct_2_genexpr},
  {0, 0},
};
static PyType_Spec __pyx_type_4hdcs___pyx_scope_struct_2_genexpr_spec = {
  "hdcs.__pyx_scope_struct_2_genexpr",
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr),
  0,
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC,
  __pyx_type_4hdcs___pyx_scope_struct_2_genexpr_slots,
};
#else

static PyTypeObject __pyx_type_4hdcs___pyx_scope_struct_2_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "hdcs.""__pyx_scope_struct_2_genexpr", 
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_2_genexpr), 
  0, 
  __pyx_tp_dealloc_4hdcs___pyx_scope_struct_2_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4hdcs___pyx_scope_struct_2_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if !CYTHON_USE_TYPE_SPECS
  0, 
  #endif
  0, 
  0, 
  __pyx_tp_new_4hdcs___pyx_scope_struct_2_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if CYTHON_USE_TP_FINALIZE
  0, 
  #else
  NULL, 
  #endif
  #if !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800
  0, 
  #endif
  #if __PYX_NEED_TP_PRINT_SLOT == 1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030C0000
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030d00A4
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
  0, 
  #endif
};
#endif

static PyObject *__pyx_tp_new_4hdcs___pyx_scope_struct_3_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_3_genexpr > 0) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(t, __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr))))
  {
    o = (PyObject*)__pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_3_genexpr[--__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_3_genexpr];
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(Py_TYPE(o));
    #endif
    memset(o, 0, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr));
    #if CYTHON_COMPILING_IN_LIMITED_API
    (void) PyObject_Init(o, t);
    #else
    (void) PyObject_INIT(o, t);
    #endif
    PyObject_GC_Track(o);
  } else
  #endif
  {
    o = __Pyx_AllocateExtensionType(t, 1);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4hdcs___pyx_scope_struct_3_genexpr(PyObject *o) {
  struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(__Pyx_PyObject_GetSlot(o, tp_finalize, destructor)) && !__Pyx_PyObject_GC_IsFinalized(o)) {
    if (__Pyx_PyObject_GetSlot(o, tp_dealloc, destructor) == __pyx_tp_dealloc_4hdcs___pyx_scope_struct_3_genexpr) {
      if (PyObject_CallFinalizerFromDealloc(o)) return;
    }
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_genexpr_arg_0);
  Py_CLEAR(p->__pyx_v_c);
  Py_CLEAR(p->__pyx_v_i);
  #if CYTHON_USE_FREELISTS
  if (likely((int)(__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_3_genexpr < 8) & __PYX_CHECK_FINAL_TYPE_FOR_FREELISTS(Py_TYPE(o), __pyx_mstate_global->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr, sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr))))
  {
    __pyx_mstate_global->__pyx_freelist_4hdcs___pyx_scope_struct_3_genexpr[__pyx_mstate_global->__pyx_freecount_4hdcs___pyx_scope_struct_3_genexpr++] = ((struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)o);
  } else
  #endif
  {
    PyTypeObject *tp = Py_TYPE(o);
    #if CYTHON_USE_TYPE_SLOTS
    (*tp->tp_free)(o);
    #else
    {
      freefunc tp_free = (freefunc)PyType_GetSlot(tp, Py_tp_free);
      if (tp_free) tp_free(o);
    }
    #endif
    #if CYTHON_USE_TYPE_SPECS
    Py_DECREF(tp);
    #endif
  }
}

static int __pyx_tp_traverse_4hdcs___pyx_scope_struct_3_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *p = (struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr *)o;
  {
    e = __Pyx_call_type_traverse(o, 1, v, a);
    if (e) return e;
  }
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_c) {
    e = (*v)(p->__pyx_v_c, a); if (e) return e;
  }
  if (p->__pyx_v_i) {
    e = (*v)(p->__pyx_v_i, a); if (e) return e;
  }
  return 0;
}
#if CYTHON_USE_TYPE_SPECS
static PyType_Slot __pyx_type_4hdcs___pyx_scope_struct_3_genexpr_slots[] = {
  {Py_tp_dealloc, (void *)__pyx_tp_dealloc_4hdcs___pyx_scope_struct_3_genexpr},
  {Py_tp_traverse, (void *)__pyx_tp_traverse_4hdcs___pyx_scope_struct_3_genexpr},
  {Py_tp_new, (void *)__pyx_tp_new_4hdcs___pyx_scope_struct_3_genexpr},
  {0, 0},
};
static PyType_Spec __pyx_type_4hdcs___pyx_scope_struct_3_genexpr_spec = {
  "hdcs.__pyx_scope_struct_3_genexpr",
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr),
  0,
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC,
  __pyx_type_4hdcs___pyx_scope_struct_3_genexpr_slots,
};
#else

static PyTypeObject __pyx_type_4hdcs___pyx_scope_struct_3_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "hdcs.""__pyx_scope_struct_3_genexpr", 
  sizeof(struct __pyx_obj_4hdcs___pyx_scope_struct_3_genexpr), 
  0, 
  __pyx_tp_dealloc_4hdcs___pyx_scope_struct_3_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4hdcs___pyx_scope_struct_3_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if !CYTHON_USE_TYPE_SPECS
  0, 
  #endif
  0, 
  0, 
  __pyx_tp_new_4hdcs___pyx_scope_struct_3_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if CYTHON_USE_TP_FINALIZE
  0, 
  #else
  NULL, 
  #endif
  #if !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800
  0, 
  #endif
  #if __PYX_NEED_TP_PRINT_SLOT == 1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030C0000
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030d00A4
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
  0, 
  #endif
};
#endif

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void); 
static CYTHON_SMALL_CODE int __Pyx_InitConstants(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(__pyx_mstatetype *__pyx_mstate); 
static CYTHON_SMALL_CODE int __Pyx_CreateCodeObjects(__pyx_mstatetype *__pyx_mstate); 


static int __Pyx_modinit_global_init_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  
  #if CYTHON_USE_TYPE_SPECS
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate = (PyTypeObject *) __Pyx_PyType_FromModuleAndSpec(__pyx_m, &__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate_spec, NULL); if (unlikely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate)) __PYX_ERR(0, 2, __pyx_L1_error)
  if (__Pyx_fix_up_extension_type_from_spec(&__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate_spec, __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  #else
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate = &__pyx_type_4hdcs___pyx_scope_struct__wlzbi_deobfuscate;
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  #endif
  #if !CYTHON_USE_TYPE_SPECS
  if (__Pyx_PyType_Ready(__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  PyUnstable_Object_EnableDeferredRefcount((PyObject*)__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate);
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate->tp_dictoffset && __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate->tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct__wlzbi_deobfuscate->tp_getattro = PyObject_GenericGetAttr;
  }
  #endif
  #if CYTHON_USE_TYPE_SPECS
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr = (PyTypeObject *) __Pyx_PyType_FromModuleAndSpec(__pyx_m, &__pyx_type_4hdcs___pyx_scope_struct_1_genexpr_spec, NULL); if (unlikely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr)) __PYX_ERR(0, 3, __pyx_L1_error)
  if (__Pyx_fix_up_extension_type_from_spec(&__pyx_type_4hdcs___pyx_scope_struct_1_genexpr_spec, __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr) < (0)) __PYX_ERR(0, 3, __pyx_L1_error)
  #else
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr = &__pyx_type_4hdcs___pyx_scope_struct_1_genexpr;
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  #endif
  #if !CYTHON_USE_TYPE_SPECS
  if (__Pyx_PyType_Ready(__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr) < (0)) __PYX_ERR(0, 3, __pyx_L1_error)
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  PyUnstable_Object_EnableDeferredRefcount((PyObject*)__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr);
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr->tp_dictoffset && __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr->tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_1_genexpr->tp_getattro = PyObject_GenericGetAttr;
  }
  #endif
  #if CYTHON_USE_TYPE_SPECS
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr = (PyTypeObject *) __Pyx_PyType_FromModuleAndSpec(__pyx_m, &__pyx_type_4hdcs___pyx_scope_struct_2_genexpr_spec, NULL); if (unlikely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr)) __PYX_ERR(0, 4, __pyx_L1_error)
  if (__Pyx_fix_up_extension_type_from_spec(&__pyx_type_4hdcs___pyx_scope_struct_2_genexpr_spec, __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr) < (0)) __PYX_ERR(0, 4, __pyx_L1_error)
  #else
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr = &__pyx_type_4hdcs___pyx_scope_struct_2_genexpr;
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  #endif
  #if !CYTHON_USE_TYPE_SPECS
  if (__Pyx_PyType_Ready(__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr) < (0)) __PYX_ERR(0, 4, __pyx_L1_error)
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  PyUnstable_Object_EnableDeferredRefcount((PyObject*)__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr);
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr->tp_dictoffset && __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr->tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_2_genexpr->tp_getattro = PyObject_GenericGetAttr;
  }
  #endif
  #if CYTHON_USE_TYPE_SPECS
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr = (PyTypeObject *) __Pyx_PyType_FromModuleAndSpec(__pyx_m, &__pyx_type_4hdcs___pyx_scope_struct_3_genexpr_spec, NULL); if (unlikely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr)) __PYX_ERR(0, 5, __pyx_L1_error)
  if (__Pyx_fix_up_extension_type_from_spec(&__pyx_type_4hdcs___pyx_scope_struct_3_genexpr_spec, __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr) < (0)) __PYX_ERR(0, 5, __pyx_L1_error)
  #else
  __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr = &__pyx_type_4hdcs___pyx_scope_struct_3_genexpr;
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  #endif
  #if !CYTHON_USE_TYPE_SPECS
  if (__Pyx_PyType_Ready(__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr) < (0)) __PYX_ERR(0, 5, __pyx_L1_error)
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  PyUnstable_Object_EnableDeferredRefcount((PyObject*)__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr);
  #endif
  #if !CYTHON_COMPILING_IN_LIMITED_API
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr->tp_dictoffset && __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr->tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_mstate->__pyx_ptype_4hdcs___pyx_scope_struct_3_genexpr->tp_getattro = PyObject_GenericGetAttr;
  }
  #endif
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); 
static int __pyx_pymod_exec_hdcs(PyObject* module); 
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_hdcs},
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
  {Py_mod_gil, Py_MOD_GIL_USED},
  #endif
  #if PY_VERSION_HEX >= 0x030C0000 && CYTHON_USE_MODULE_STATE
  {Py_mod_multiple_interpreters, Py_MOD_MULTIPLE_INTERPRETERS_NOT_SUPPORTED},
  #endif
  {0, NULL}
};
#endif

#ifdef __cplusplus
namespace {
  struct PyModuleDef __pyx_moduledef =
  #else
  static struct PyModuleDef __pyx_moduledef =
  #endif
  {
      PyModuleDef_HEAD_INIT,
      "hdcs",
      0, 
    #if CYTHON_USE_MODULE_STATE
      sizeof(__pyx_mstatetype), 
    #else
      (CYTHON_PEP489_MULTI_PHASE_INIT) ? 0 : -1, 
    #endif
      __pyx_methods ,
    #if CYTHON_PEP489_MULTI_PHASE_INIT
      __pyx_moduledef_slots, 
    #else
      NULL, 
    #endif
    #if CYTHON_USE_MODULE_STATE
      __pyx_m_traverse, 
      __pyx_m_clear, 
      NULL 
    #else
      NULL, 
      NULL, 
      NULL 
    #endif
  };
  #ifdef __cplusplus
} 
#endif


#ifndef CYTHON_NO_PYINIT_EXPORT
  #define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#else
  #ifdef __cplusplus
  #define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
  #else
  #define __Pyx_PyMODINIT_FUNC PyObject *
  #endif
#endif

__Pyx_PyMODINIT_FUNC PyInit_hdcs(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC PyInit_hdcs(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}

#if CYTHON_COMPILING_IN_LIMITED_API && (__PYX_LIMITED_VERSION_HEX < 0x03090000\
      || ((defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)) && __PYX_LIMITED_VERSION_HEX < 0x030A0000))
static PY_INT64_T __Pyx_GetCurrentInterpreterId(void) {
    {
        PyObject *module = PyImport_ImportModule("_interpreters"); // 3.13+ I think
        if (!module) {
            PyErr_Clear(); // just try the 3.8-3.12 version
            module = PyImport_ImportModule("_xxsubinterpreters");
            if (!module) goto bad;
        }
        PyObject *current = PyObject_CallMethod(module, "get_current", NULL);
        Py_DECREF(module);
        if (!current) goto bad;
        if (PyTuple_Check(current)) {
            PyObject *new_current = PySequence_GetItem(current, 0);
            Py_DECREF(current);
            current = new_current;
            if (!new_current) goto bad;
        }
        long long as_c_int = PyLong_AsLongLong(current);
        Py_DECREF(current);
        return as_c_int;
    }
  bad:
    PySys_WriteStderr("__Pyx_GetCurrentInterpreterId failed. Try setting the C define CYTHON_PEP489_MULTI_PHASE_INIT=0\n");
    return -1;
}
#endif
#if !CYTHON_USE_MODULE_STATE
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    static PY_INT64_T main_interpreter_id = -1;
#if CYTHON_COMPILING_IN_GRAAL && defined(GRAALPY_VERSION_NUM) && GRAALPY_VERSION_NUM > 0x19000000
    PY_INT64_T current_id = GraalPyInterpreterState_GetIDFromThreadState(PyThreadState_Get());
#elif CYTHON_COMPILING_IN_GRAAL
    PY_INT64_T current_id = PyInterpreterState_GetIDFromThreadState(PyThreadState_Get());
#elif CYTHON_COMPILING_IN_LIMITED_API && (__PYX_LIMITED_VERSION_HEX < 0x03090000\
      || ((defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)) && __PYX_LIMITED_VERSION_HEX < 0x030A0000))
    PY_INT64_T current_id = __Pyx_GetCurrentInterpreterId();
#elif CYTHON_COMPILING_IN_LIMITED_API
    PY_INT64_T current_id = PyInterpreterState_GetID(PyInterpreterState_Get());
#else
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
#endif
    if (unlikely(current_id == -1)) {
        return -1;
    }
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return 0;
    } else if (unlikely(main_interpreter_id != current_id)) {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
#endif
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none)
{
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    CYTHON_UNUSED_VAR(def);
    #if !CYTHON_USE_MODULE_STATE
    if (__Pyx_check_single_interpreter())
        return NULL;
    #endif
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_hdcs(PyObject *__pyx_pyinit_module)
#endif
{
  int stringtab_initialized = 0;
  #if CYTHON_USE_MODULE_STATE
  int pystate_addmodule_run = 0;
  #endif
  __pyx_mstatetype *__pyx_mstate = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  size_t __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'hdcs' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #else
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_t_1 = __pyx_pyinit_module;
  Py_INCREF(__pyx_t_1);
  #else
  __pyx_t_1 = PyModule_Create(&__pyx_moduledef); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  #endif
  #if CYTHON_USE_MODULE_STATE
  {
    int add_module_result = __Pyx_State_AddModule(__pyx_t_1, &__pyx_moduledef);
    __pyx_t_1 = 0; 
    if (unlikely((add_module_result < 0))) __PYX_ERR(0, 2, __pyx_L1_error)
    pystate_addmodule_run = 1;
  }
  #else
  __pyx_m = __pyx_t_1;
  #endif
  #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
  PyUnstable_Module_SetGIL(__pyx_m, Py_MOD_GIL_USED);
  #endif
  __pyx_mstate = __pyx_mstate_global;
  CYTHON_UNUSED_VAR(__pyx_t_1);
  __pyx_mstate->__pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_mstate->__pyx_d)) __PYX_ERR(0, 2, __pyx_L1_error)
  Py_INCREF(__pyx_mstate->__pyx_d);
  __pyx_mstate->__pyx_b = __Pyx_PyImport_AddModuleRef(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_mstate->__pyx_b)) __PYX_ERR(0, 2, __pyx_L1_error)
  __pyx_mstate->__pyx_cython_runtime = __Pyx_PyImport_AddModuleRef("cython_runtime"); if (unlikely(!__pyx_mstate->__pyx_cython_runtime)) __PYX_ERR(0, 2, __pyx_L1_error)
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_mstate->__pyx_b) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  
  #if CYTHON_REFNANNY
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
  if (!__Pyx_RefNanny) {
    PyErr_Clear();
    __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
    if (!__Pyx_RefNanny)
        Py_FatalError("failed to import 'refnanny' module");
  }
  #endif
  
__Pyx_RefNannySetupContext("PyInit_hdcs", 0);
  __Pyx_init_runtime_version();
  if (__Pyx_check_binary_version(__PYX_LIMITED_VERSION_HEX, __Pyx_get_runtime_version(), CYTHON_COMPILING_IN_LIMITED_API) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  __pyx_mstate->__pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_mstate->__pyx_empty_tuple)) __PYX_ERR(0, 2, __pyx_L1_error)
  __pyx_mstate->__pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_mstate->__pyx_empty_bytes)) __PYX_ERR(0, 2, __pyx_L1_error)
  __pyx_mstate->__pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_mstate->__pyx_empty_unicode)) __PYX_ERR(0, 2, __pyx_L1_error)
  
  
  if (__Pyx_InitConstants(__pyx_mstate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  stringtab_initialized = 1;
  if (__Pyx_InitGlobals() < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  if (__pyx_module_is_main_hdcs) {
    if (PyObject_SetAttr(__pyx_m, __pyx_mstate_global->__pyx_n_u_name, __pyx_mstate_global->__pyx_n_u_main) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  }
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 2, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "hdcs")) {
      if (unlikely((PyDict_SetItemString(modules, "hdcs", __pyx_m) < 0))) __PYX_ERR(0, 2, __pyx_L1_error)
    }
  }
  
  if (__Pyx_InitCachedBuiltins(__pyx_mstate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  
  if (__Pyx_InitCachedConstants(__pyx_mstate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  if (__Pyx_CreateCodeObjects(__pyx_mstate) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  
  (void)__Pyx_modinit_global_init_code(__pyx_mstate);
  (void)__Pyx_modinit_variable_export_code(__pyx_mstate);
  (void)__Pyx_modinit_function_export_code(__pyx_mstate);
  if (unlikely((__Pyx_modinit_type_init_code(__pyx_mstate) < 0))) __PYX_ERR(0, 2, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code(__pyx_mstate);
  (void)__Pyx_modinit_variable_import_code(__pyx_mstate);
  (void)__Pyx_modinit_function_import_code(__pyx_mstate);
  

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_4hdcs_1wlzbi_deobfuscate, 0, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate, NULL, __pyx_mstate_global->__pyx_n_u_hdcs, __pyx_mstate_global->__pyx_d, ((PyObject *)__pyx_mstate_global->__pyx_codeobj_tab[3])); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030E0000
  PyUnstable_Object_EnableDeferredRefcount(__pyx_t_2);
  #endif
  if (PyDict_SetItem(__pyx_mstate_global->__pyx_d, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate, __pyx_t_2) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  if (PyDict_SetItem(__pyx_mstate_global->__pyx_d, __pyx_mstate_global->__pyx_n_u_Layers, __pyx_mstate_global->__pyx_int_3) < (0)) __PYX_ERR(0, 7, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_mstate_global->__pyx_d, __pyx_mstate_global->__pyx_n_u_Encrypted_Code, __pyx_mstate_global->__pyx_kp_u__2) < (0)) __PYX_ERR(0, 8, __pyx_L1_error)

  
  __pyx_t_3 = NULL;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_mstate_global->__pyx_n_u_wlzbi_deobfuscate); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_mstate_global->__pyx_n_u_Encrypted_Code); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_mstate_global->__pyx_n_u_Layers); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = 1;
  {
    PyObject *__pyx_callargs[3] = {__pyx_t_3, __pyx_t_5, __pyx_t_6};
    __pyx_t_2 = __Pyx_PyObject_FastCall((PyObject*)__pyx_t_4, __pyx_callargs+__pyx_t_7, (3-__pyx_t_7) | (__pyx_t_7*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET));
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
  }
  if (PyDict_SetItem(__pyx_mstate_global->__pyx_d, __pyx_mstate_global->__pyx_n_u_decoded_code, __pyx_t_2) < (0)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_4 = NULL;
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_mstate_global->__pyx_n_u_decoded_code); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = 1;
  {
    PyObject *__pyx_callargs[2 + ((CYTHON_VECTORCALL) ? 2 : 0)] = {__pyx_t_4, __pyx_t_6};
    __pyx_t_5 = __Pyx_MakeVectorcallBuilderKwds(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 10, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__Pyx_VectorcallBuilder_AddArg(__pyx_mstate_global->__pyx_n_u_filename, __pyx_mstate_global->__pyx_kp_u_wlzbi, __pyx_t_5, __pyx_callargs+2, 0) < (0)) __PYX_ERR(0, 10, __pyx_L1_error)
    if (__Pyx_VectorcallBuilder_AddArg(__pyx_mstate_global->__pyx_n_u_mode, __pyx_mstate_global->__pyx_n_u_exec, __pyx_t_5, __pyx_callargs+2, 1) < (0)) __PYX_ERR(0, 10, __pyx_L1_error)
    __pyx_t_2 = __Pyx_Object_Vectorcall_CallFromBuilder((PyObject*)__pyx_builtin_compile, __pyx_callargs+__pyx_t_7, (2-__pyx_t_7) | (__pyx_t_7*__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET), __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
  }
  __pyx_t_5 = __Pyx_PyExecGlobals(__pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_mstate_global->__pyx_d, __pyx_mstate_global->__pyx_n_u_test, __pyx_t_5) < (0)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  if (__pyx_m) {
    if (__pyx_mstate->__pyx_d && stringtab_initialized) {
      __Pyx_AddTraceback("init hdcs", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    #if !CYTHON_USE_MODULE_STATE
    Py_CLEAR(__pyx_m);
    #else
    Py_DECREF(__pyx_m);
    if (pystate_addmodule_run) {
      PyObject *tp, *value, *tb;
      PyErr_Fetch(&tp, &value, &tb);
      PyState_RemoveModule(&__pyx_moduledef);
      PyErr_Restore(tp, value, tb);
    }
    #endif
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init hdcs");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #else
  return __pyx_m;
  #endif
}



static int __Pyx_InitCachedBuiltins(__pyx_mstatetype *__pyx_mstate) {
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __pyx_builtin_compile = __Pyx_GetBuiltinName(__pyx_mstate->__pyx_n_u_compile); if (!__pyx_builtin_compile) __PYX_ERR(0, 10, __pyx_L1_error)
  __pyx_builtin_enumerate = __Pyx_GetBuiltinName(__pyx_mstate->__pyx_n_u_enumerate); if (!__pyx_builtin_enumerate) __PYX_ERR(0, 5, __pyx_L1_error)

  
  __pyx_mstate->__pyx_umethod_PyDict_Type_items.type = (PyObject*)&PyDict_Type;
  __pyx_mstate->__pyx_umethod_PyDict_Type_items.method_name = &__pyx_mstate->__pyx_n_u_items;
  __pyx_mstate->__pyx_umethod_PyDict_Type_pop.type = (PyObject*)&PyDict_Type;
  __pyx_mstate->__pyx_umethod_PyDict_Type_pop.method_name = &__pyx_mstate->__pyx_n_u_pop;
  __pyx_mstate->__pyx_umethod_PyDict_Type_values.type = (PyObject*)&PyDict_Type;
  __pyx_mstate->__pyx_umethod_PyDict_Type_values.method_name = &__pyx_mstate->__pyx_n_u_values;
  return 0;
  __pyx_L1_error:;
  return -1;
}


static int __Pyx_InitCachedConstants(__pyx_mstatetype *__pyx_mstate) {
  __Pyx_RefNannyDeclarations
  CYTHON_UNUSED_VAR(__pyx_mstate);
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);
  __Pyx_RefNannyFinishContext();
  return 0;
}


static int __Pyx_InitConstants(__pyx_mstatetype *__pyx_mstate) {
  CYTHON_UNUSED_VAR(__pyx_mstate);
  {
    const struct { const unsigned int length: 17; } index[] = {{0},{94918},{1},{7},{6},{2},{9},{7},{18},{14},{6},{20},{18},{12},{1},{17},{18},{5},{7},{13},{12},{14},{9},{4},{8},{8},{7},{4},{1},{13},{5},{3},{8},{4},{10},{8},{4},{3},{12},{4},{12},{10},{8},{5},{5},{6},{17},{34},{35},{2},{2},{2}};
    #if (CYTHON_COMPRESS_STRINGS) == 2 
const char* const cstring = "BZh91AY&SYl2\232\326\000\235\263\377\373\344\030\002\0014!\220\005\216\005R\000\277\357\377\360\177\377\377\377\377\377\377\377\200D0\001@\000`\"\240\037}\365\000\000\000\000\000\276\371O\237>\035\323\254\252\026\362\rk@\n\320\320\273\223-\317\027y\253\000@\364:\032\006\206\330\006v\346xw:\304c\323\201\210\350\032\014\212\003\340\000\000\006\232 \232\001\000\004\322z4\322\237\246I\264\324\323OI\241M\032\000\000\000\000\017P0\207\250\365\004\2412\004\t\240I\350\rS$\333*= \323\324\r4\000\000\000\000\000\000hb=A)\221\024\304\325=)\266\211\251\260\247\250h\320z\215\006\324\031\032\000\000\000\000\0004\032hz\200\n\232\252I\244\000\2310\021\223\023\023\000\0012`\324\300\230\t\200\t\200\000\023\001\030)S\325T\223\020\300\232\032bbd\r2\030\214\t\200\230\206\206\203 a\0320M\030\001\030\022$\020\320&BhdI\2652\030\243Bf\211\3512\000\000\000\000\000\000\000h\311\346\377h\364\372?\244{\027\342\003W^>\337\241\277\342\022\311\262\035q\271\340#K}\242;\355{N\357K\n\014\312<\275\314\264y\330\\3\231\304\200iX\030+\333\314\344\201@\306\006m\357Y\217\243\205|l\360\020\003\217}O\221n\030E\334\343\304\013\211tR\353\201\320w\026\200\360z\223\311\001`\302\360\3051\n\006B1\310pf\226\014jR|\031\235v\021b\241W\212\264\\\217\255\305o\007@O\\\316\313\021\025i\236=\014\267\303\205w3\206\\\006<3\254\022\243\337\313\242\314\323\340\222V\330\025\254\361j\240\262\2539\005\250\357U{\224L\004\246`\036\241\263\030\002\233\253|2q\200\212\020\365RD8\347\250\023|\207aGToh\025\014\225k\017\252\231\r-Pq\252\247r[\214\336\023\255I+\230$\r\327S;\336M@\312Feb\306\2014`\357\027\014\231efd\264j\243\256=\245\267\276\357\031\213\356\362\203;\272\024\330#\377D\222H\001#\357\244\r$\225H~H\226\3428\243\377\335\001\212\272\010\256q[F5m[\275\357\277\307\207\306\334\250;\371\263\255[p\214r\372\252\341q\021\023\227\247\3079F\221\"p,l\014\2638\3237a\312\360\274O\027\273\344\3467\355m\215#l\246c\177nWM\3549\014\343\266\034\336\265d\2653\377p\341\267\024\317\376F\334\023\007<,MF\264\305\260\324\t\246\252\254\264b\214\226""\332\226AiMFV\332\265\005\220\261,(\263j\325\263$\333,i\254V\324\260\304[i\014\240\211Ye\2411mlZh\313J\323ejK#L\246Z\262\225\014V\330\253hYV\315\242\240\262\232kHYEm\241)\244\202Y6mA\"V\321\222\262\331\2216\321lX\265d\232bS\023U\220\253fUj\215%\244\315jJ,\251\261[\005\005aaj\324\332\265\226\315,\230\226\311\225\266\231%\021\244Y\266\2324c$\034\224pk\004\222md\212\310\312\332\325l\232\332\025\255\205\265\tR5\242\333j\332MMcb\260\266\254\264\324%+X\202\304V\326Rm[6\252\n\242FL\2156\265\266\326\333\n6\2469o\357\304\342jc16\324mB\333\"+TKh\3243em\231Laf\254\305\212\233D\230\266\266\263\030\317j\333m\267\010\255\250kE\232L\245\022[jB\212l\313l\222M\225\nbM!X\253b\245m[M\263\r4\2630\223m\262\3330h\014\262\266I\266\231\223T\255\013lmY\266P\260\265\202\251\254\226m%4M\"\261Y\245$+mY\253QL\325\266\325l\226\312\263\022\324\323X\222)\266\251K\025d\332E\031UJ\331\253* \232LP\265\255Z\315\264\254Z\312e\241BXY\262\223(\315i\263ef\3116\302 \311V)$A\213kf\324\331-\262\244\314&\264,\264d\260KF\215\264XQkl\265\230\245\253h\302\333Yi\265#F\264R\264\3266\262m\264\266\253i\2335\255\266\315kc\025\215,\rY\2708Tu\037\207\312\362<\203\234\374\371\3169J\260\253*]\037\367\373\272\020\272\346u?\013\037T\321\311EB_\322\n\267\343g\326,\211I\022\307\325\353(\212:@\241\344i\315\344d\315ODZV\213\312\222F*\354\353%\2347\371\212\204\253\016\301\345\366\333dQ\361\277\271F\3111R\312R\261\243\310T\366EZz\031$\370Q\350\265\020\256\243\257\006q\242\362\371\031&\322\007\217\372\034\231\347\003\344\214\3603\243\014A\241P\032\244\366\270:\263\311\305\020\302\236\327\004w\375I;\364\256\315_\255\010.d\232\031\3175\\\255\r8\210V6\244\324s:9!\016\r*9\222\325\325\332?\243O\332\016K\353\201\370D\370\350f\202\324B\265-mkM\003\366\237\341\033\346\323\357\246H/\345\244\243\232\343\262\373\204\277\346\017m\037-\300\037#\213\233T\366\0348\304\303\031\255\001a\004\316\331\256OF\202\000\210\366@\311\020\022p>CK&\221\003<\272s\337{\033\356[\006M\360iI\303\235\323\000AL!%\361\264$\2304\304\320!\203\005iO\220\344Z\312\241Z""\233)he\224\226U\233\022V\265T\211JB\262-d\233fRX\220\264\246\252\312\243P\306\254\322Z\306svb\310el\373 \316\032\255\n\244\202\256p\274\267g\223gN=tw\350\263\313\216\023\340v\367Vu5\362m#\333b*\243\3338\344\277\357\366\3278\323>\005\242\261\264Uo\310)1\025j\246\364\362\205\352y\257\335|\013\352\224\231u\3522\332>|\274RN\345.\273[\260\266\026}H\031\343\021\252:\230c$%\250\253V\252T\273\315si\326\371\301\232B\016U\224Z\"\255\336WK\312P\2548\214\027\\\252iYQ_(\033\314\300\"\007\031\226\211)\304\\b\310J\336\277~\204\207J\030\342Ip0\222\027\034\215\211\213\311\240\242\277\202ln\256}\370\356\215\262\361\331\261\350\032\211=$*]\2610\032)\272\021Y\314\240k\317\316\316G\252\313\372\266\032+*\324\020/\220\201-\007\243\002\032m\306\223\032\013\325\332\276\000\255\322\3073\245\226#=t\021\020\227\231\003;\363D\206daD\266\334\207\354\335\256K]\373\363:\365'(6\367\031x\027\253\340l\347\354\253h\023]\264\207\007 \312*\016\017`\264L6w{\277\310\3718 Q\256Q\371M#\177g\226t+\362f\027\265\214<\331s\307\\\245p{0\032]\362\177 \251\024\366\024\263\333\334\237gRy\333jUj\340\262\217!H\317\325\241\230\034\340?\246$D((B\225\345\255\343\035\361\317\027Oc\017;\372:Vr\034\017P)o<\327^\027:$\030\005\272\243u(\347t<6\330M\"\252\213<\351i\235$:\322vg/ih\250v\254\335\203\265=\375\203\034\027~X\001\262\342&\336d\352\207!]\212\203t\307sd\004\2201\0363n\301M\344\247\376\320\235C\007\205;\206\\\0149\261\362+*\2507s\022$(x\316t\363\242x\272\273\322\340zv*p\306\351D\005\316\013}\252\002\222B\265u5[\237T{\032f\326\001`\200`g\004?v\232had(\0164v\233\030\255&\264pJu=\330\211\322,\242\021\022+H\240\244\311h\305\223\262T\223#c\231\245Z\212\222Y\025 V\263\210\306(\271\334\214\006^\223\226\034\023\006T\016\201B\030\361C\005}\314\234\022\205 \211 \030\317E\356C\300\202\r\020\264\022\203\275\213\325;\333I\264\035JQ\003gT?y/\300\035\002\3431x\213\300/Ap\374Q\300\201-c\t\360\361;\355\252\325G9_\344\260JH2U\032u\035\024\022]\370Z \217t]CK\201m\n\333\221U\362\205\355>\240\030\035\025\033\030\323\300P\027\3115D\236""\275\335\232\225\337\301\003]UJ\235\300>\":\201U(\2428\273\276+\001$\264>\203b\273c^B\357Q\256\226+\007\003,\007\203\231\2172I\255\342@\031\240\272\341\026hH\324\000\224\r\342P\224l\334h&)4\254a\r\004#\002$Q\004\306.\207\025&\325\213\377\003\255\307\257.\222e\311\031\202I\266,\271h8\305\332t\025\275&\255M\312\345z'8\024\254\302\344\0275\203\214^\306\312\215w}\312\001\302\364\221\351*\235E\321\215ao\304\205y\320\213\345\001\315kE\272h\334\016\002%\2515$u\016A\276\331\231q\224%x\213O\024Ilf\264L\270\202\013\265]\232\315\027\375\206\035M\037E\231+\206\350\320w\211\243P\241F\006(\026f\254i\215\2348\200\313>\014\333\312:\027(9`\274f\275An\034\034\333\275\207\034H\016\325b\312 \316\013\244GW\001\231J.<\306\226e.K\330\302\277x\350\273\005\307J\004\000\374P\215\230v\017\\\271,\300\310\346r/!p2\351B\241\307\002\242\3659\314\354\275\027\242<\3170\344\265\252\\$2\331\243\222Q\240k%A\207\014\317\270\310\272\213U\325X-\3641\230\270\033\006\306\2577\371R\257\r\026\0030eQc\342r\026C\230\027\212\033\033f\351\214\226\203S\276\210\252\322\304'\361#yc$\303\316X\222z\245Bw\302\n\r%/\302f{G\251\207ky\025\253\245\024\261\2639/\177\250\205\347\246\212\241\007\232Xm\263\030\341\362\\J|E\341\246\241\207\273\306\003\316\316s`n\n2\340\331Q\272\373e\016\001\024\320\241\024\2277i\323\322\323\023!\357B\234\025\312\363H\274\"\370\274\220c\304\214e\315\330X\264_*\344C%k\352\332\346\003\014\235\021(!\201r\232!1\231\242\010F\005R\225FZ!oy\306\311\034\214\256sK\355\256X\030\227\334D\360\331\251\001\2342\205u8]^\260\007#\274\271yf\213\211v(@W:\2206y\334HY\251\007\023{\317\201E\013\034\245\245\344\355q5\014\030s\024\343\260\240\205\n\235\003a\216\022\224\004C\006\370\350\005\270\243\016d\320TVAbtH\232\302h\360_\006*\201,\006\007GV\221\2329/=\312\2059o\026E\007\230Xc\222\370\361Jhll&\370\236$\371\\Cl\217\216\246\226\347I\326\3123\224\302N#\231\"&`\230\266Si\033\366\333\271\220\005k\017\031#[\207R\312 n\336\033(x\241*\251\020uy\203r*\222\245v\006y\241|35 \203\020\214\004\003\010\200\310\210\362\210\2051""\201\2635\035\203\3348\366Z\010\324\3422Z\n\276R\270%f\227{\343\"\224s\214\205a\272\272vV\024K\n\\\271\032Tc\214T\024\220%Q(\223\236\260\234\002\355i\334\337\225n\0318\212\013s\215C\337Yz\242S\212\226^\206\031\270\301P\301k =\316\r\343\t\356 ]=\370f\310\022V3\227\236\275\245F\033o\210\351\251\205\000i\304\356\220\324B\24009\000\347dZB\031\035\030i\235\312\253c\332_\0270\022gR\344\262e\266\376\335\332H\214\366\255\t\302:\303\214\243\266\345\300t\330\325=ob7X\336b\345\360\355]\276\013\270,l\323x\322\216\202D$\205.\260Y\033\346`P\007*\315\026\014\217\003\233e\332\353\300\026\272t_\365W3\352\267\276\304\262\331\371XaM\233\245\024\216f\002R7\203a\224\247\302\312&\"\204%V\032\365\214@\332/.\222'i\314\233d\032U \\\332\002lB\017j\360\234\201Hb@6\233\032\006\002\253A\023\204\222\206\333\026\331\022\324\266\026J\322\225\253-\230\264\222Jh\225UT\265$\2666R[j\325\253-l\25264L\226\246\220\320\nL\000\354\320\td\361\263\302+6\230\307\214C\017\030K\347kK\315\313\243\241\372`R\351X:\246b\377\374jGS\001k\2058\304\033O)\370=+$\377\021\3007\306\276\211K\rsN\"\265\276\006\342f\0365\022\210\263\275\226m\3219\216\336^\201\351\215mI\242\nx\310\333\333;!b\251\201bh\362\205\276\034\236\270\r\ri\"lWJ\204A^\322\361>b*\301z\307\231l\tK,\3561\rj\202M\326 \340:H+;H\315%\246\326p\306\354nQ*\244\030s\335\251n7TM\016\022\364\355\341\245t\341w/_\237w\245k^H\357*\004\342M\261\231\216c$\3529\264y4\004\3030\2307@\255 \253\254sQx]w\317\350j#1'\n\332\3459@Qj\331\234g!\331\224%\341,e\221#\303\016kg\036e\033l\014 \302\331\007]R\016)\\\330\004\222\231sI\224T\362\035\221^\035@\227\016^\277\037\027\343\351\207\004\214<;$\034\016O\t\252\001S\331W\257\223\262\241\020%=6:\257\205`\217\350\014\202\310\243\232\336\372\"\340;\022^\313\034+Z[ \326\227\230\n\364\371o\213-\202|#\304BG\252\2606r\023\2517s%d\352X<4\353\027/\rS\0137Y\261\234\263\034RVed\261\301\223\024\025\036[\205Dox\265T\254\361\002\020*\200\310\262\257\224oz3\222\223\0007\272hy\230%>i\230\372\260\013\270\022>B\027J\257u\260\210\027W M.\352A\322\364""\347Q\233Nw\325?\227[\274\016\365^\314\261\360\233f\330\213{a\223s\371:\3230!3\202\231\307\177@|\020G\225IA\006\324s\010u\241D\356.u\013\350i\010\240bj\254n\361\220\32461\235\rg_\231w\353\221\3601\265\014\363\312\211\"\3521\037\010\202\304i\362\025*z\371\027\211v\372\032/\307s\002\260\261\n\036S\003\340\007\336=\276\345a\\\270\014\033\024\027\364\372\222\332 [\213\352\004\r\031\302Z!\026\024x\010\352\020\214\037Z\257\013-\321\221\343\267Dy\316\240\363^S.D\200x\3222I\321w\354\365\346\211\004\202\220\302L\031\003$E\231\370\314\tN<\024\223\222\331^vE\0314\260E\237@\247\257*\331<J\004\207\003\034E&T@Hh/\024\022Av!XCM\265\023\334\316##\230\321\267z\350\323\032M3+\307`\3067\034W\016G\332\257\216\340z\235\323\303\220H\227\223s@v\304\204\\f}#;h\254A\260\252\n1\023\205\353\010gxh\316\256\037u\226a<|\313O\\zU>\341\243\341\206\267DH\232\3652\354\357\r\310D\313\232\033$/Y\031H]:\231\231\242\306\004(/\003\251E\341\267M\261X\024\351\202\004\036c\265\031\2505\031\345\327\003J\204\251)\311\313+\250Q\312\034\361+u&pC1\036\t\221#\275\007\222sFe|\307\342\313\236D\23407\343\226@z\200\305\002\257%\307\306rA\240\212\236\331\233\234R\242Vo\312\002\0269\024\356\3568\246\270\005\333\321`\203#\352&\202\300\302\305\312)\326rm\031\243\361\375]Qy\302\344\253,\027]\225\r\261\340\267\270\n7\3204\204\rJ\024%\000\260Q\231S\204\225\003\202`\335*\027\r:xQI\014\356H\204jD\027g\220\214\243]\311\0010\301\\ArQ\013\261\023r8$(\014\304j\257Li\263\356\345zU\232\266\375\246\242\363\211U\350`e\314!\244\361\357A\017\001\330\371\017%D-\004r`[\301\036\304\273\245\342P\3573\300\371\270,\247\227\233\331\224W\254-\314D\275\003/$\243\227$H\272\022\341/\235\230(\251\214\313\\\035Lo\363P@\355\342\005\216\006\r`\361\266\242\247\226(x\225:\272\205\345\303\302Q\004\021\020\202\316\322\202iCo4\325%\277\253\024\016\006%T\217X\030\3369u f]\220\247\177xKg1E\033\033\322\3743@\354\340\264\303d\305\017\226|\326\034\347Q\312\244\347\233\360\231\323\261\\\206DQ\rw\235\026\275\375\305k7\226^\363\344!\032\035-\264H\343\363\351\013""\215=\365\250\375F\213\271\032\263\350:\200T\364\307\223\257yq\320\356\352\271Y{Y)\222\211\314x*\241\241\235~\254\240\357P\220\363%\321\235G\024\203E\273m\266\235\256*\31405\226\n\024\022\207\232J\242\342xG5;\032\2224)\230\270\014\252\276\027\007\233\017EI\320\321\007s\244\200\343\231Sb\216f1\246I\201\"H,\223\314:\230\222w\005C/\033\305\347S\241\362\021`f\rY\034\315x\321\372\033\025[2Q\301F\220\264\360\220H\t%c\206!\217\206\026EPhZ0Y&:R9\271\263\275\3204\322\327N\220N\263s\262z\252\205Z\264$x\347\256\210=\240\350\265*\244\325\370\222\223\027Ez\335\220\3544\231\010\334\336c\372\347\0246\344\225[\260c\2641&\216P-S\3312\224~z\204\363\265\t.c\034\241^\232\325\270\2009$1G\200z\006\345\215\300\2501t\230\254Yr\214\256F;\004\356e\241\033\251\0108\263\033\203\003\010\023\023a\330\352q\232\016s\357\372\337$}!C\357\345\311\266\317\r\276\253\244\352\014e\343\237\215F\264\204\254\207\027\336\233\024[S\254i\251\032\215\335\252\230\361-%\321Y\254\245\210\247g\262\346+9k\245\313\211V7\362\333Z\362V\223\231\207\025\017\276z\204\227\215\345\014\004\353;R\031\262C\227T\246\017$\315_,\216\204j,\222kp\214A\032\245\2537U\2118\253\200\035\360\027P:\3754+\336{/\257\247\\\036\375\274x.\311\032\3276\200\223]\254\032\207\004j4yL\372J\020i^\215\303\210h\013U##Y\2015\321F\277\017JJ\241\276\214\263\031\217\020K\221\206\304\215\256A*\260\331\371h\302/u\255\225\360\234\211\211G\272%4\035Wh\306\253i\250\221\212\365\373;\257\356 P\0103\215\270\355Ko\016[m\2068\242e\212\220\335\014\310\216\320\310H\250k/\014\036\207\257\231v)\307\177-%\303\207\004\263g_fP5l\026%6\326&u\227!\301\305\305\250\225\010\261\253lR\262\264\226\244\331\225\"\331j\332++k\031\224V\226\325\224\305\251\014\t\260\006\230\014hm\260H\324\273>\261\357\242IY\240\022\340\311\333\2001\212\335\271\317\016\306hF\353\346\364\2068\315X\370\376\274d\244\326\231\025\276\n\272vV\006\2411T}\033g\273\363\370\353\226'*l\310\323\375\324i\237 \365\341\340\253(gF\007\001\223]\006\253\273\227\026\225x\022*0-2LL\007XxP\347\345s\2545\317KY9\330x\352""\211l\245R\213/6\336t\314Nh\301RUNW\314\230\2536\025\241[t\225\302\316\203m\352\340\224\034\030\260\231\003\334\300\221O\220w\006\004_\265L\231:\220\202V\202\261\010(\335\034Hz\334EJX\317\r\270\226\333\225\373\343\270:\320\203\321\323c\207\303\022~Z\344k\0340V-}\034\200\366MrRM\374\303\321\233\342$5\033#\177\017VF\231k\253\027\345\306]\023S,\023\217\0074D\251\336\242\n\255\306R5\333\257A\255}\341\231}\320\320YS2\362\222 OV\215\210\360\203\330\301c~WY\350\343v\247\007R\016A\0231Q\372pE\335K\234q\360:r\313\201\255u<#\274x\r\036\276w\247v\276\177>n\240<\3604\007c\033\253\236\265\014E(C\270\n \234|e0\322\252()\016(\n\335\263\205\300\256\265>t\230\\\033Tb\343\276\177C\3463\017F\035\351\001|j\212h/\332P\036z\022%\007\263\2759A\307\313\331G\222\256gk\334S\265\244\310\352\303\202\261\014RG\002\336I\364;\307U\036\0034\304\274\002\270\3720\255=\023\013\232 [h2\321\307gL(!\002\206x\307l\266\016\035\276\234>rR\3211\250\202\010\"[\372\262\333\251\211\352\242\033C\304K\374%\316\275&\017\365F.|U\275z\217>$rp\226\336\335\302\216\371\251\032\265\224T+\357\007\331\000\216\241\363\036\205osO\206\001XU@\337eC\354\242E\2116G\207\303\346\002w|\022=\264\236e=\311\203\001\340f\034K\227\200\320{>\036\344\321\216\314Z\013\2253\357sG\334G%\305|\246\307\025\241\360\242\3609\264\301\243\030\320\255\333\360\016_`\214\022\270^\007O\213\032,\220P\027\002C\016 \313\250\330\324}\230RhW\327\203\360h;\001\211\002\257\222<v:\n\242*\227\271\237J\354\215\376\277z\372J\335\316\000j\355\tT\262\330\361X\275\222\274\3576\221n\246\302\345'#\204\265&8\034\214~F\355X\340B\025\244M\306\201k&\013D\"C\201\205\351N)\033-\314Yx \326\023\000\226N\247\031\201\nT$9\245\"\220\204\030\214\020\204\215\201\312H\r\214\254\3044\360\027\326M)\214\302\010\255\301\000J\351,h\020\232hm\020\235\252\004z\031,\370\351d\255\020\204HLN\346\352yJ]3\333$\t\322\177\035MG\335\354\036Wh\r\321\201mDe\253\345\244\344H\204\034]\246\244\311\265\250\332\024\024\277%\242:@\306\025\301\030\304\240_\335#\030\026`\365(\204\214-#\272s\312!\330pi""\341}/\007\3555\374&>\016\032\210^\264[\022\362\220\221\272:\263\243\325n0\241\227\275TZ\320=\215.\312iq\004\337\255\370\213\206\351`\202\361G\222\326\213\013\364&+\271\235N2\262\273\344\365\257huYj\306x]\344J\366Q\206R\021E\241\301py\230k\206\017\347k\035pUh\251%\276\311\370\001\314\030,\237Z\r;\337\232\032!\310\355\036\217\276\206\343u\340\307:h\222%f\332h\350+\332{&\214\023\t\216\377\216\342%:\360-\234Dc\335\177K\347u%0\016\233[\216\365D\303.4\230L\355\212'\013h\271m6\276\341\221h.\260\367r\353\265\246M!@\252s\316\211g\201\263\"\005T^m\363Z\343:\232W\013\020\241\2035D2\013r\002jGe2b\236\225\366f\260Wb\005\310\251\210A\024\345P\223\027\304\273\202\206e*\322w\232\330o\210w\031%\366\332[\350{\330\033\236\353*\217\243P\343b/ bR\224\241\035F\240\216\004 \360\221\240\034\305\260\315\207R\202$t\271x3\317L\372\337c\271\203\027\235\271L\230mD^\344\270\310\234C;\351\246\241\352\030\236\376-\275*\334y\355;\tks\247\225\243Yws\344AZ\035\032qD\205\200\362I\005\\\245\316\033&\207\321\366\241\0107d8Y\036HX\251\245S\020\234a\001S\200\322\032~!/\027\312a\323\351/IMb\213%w\r\323Z\223\202j\315\343BjG\312\313\321$\025\354\240Ax0\300\031\310d\207&\306\256\210\223\310\023G\221\251\352\346\202\314$\tkYPb\210\246\212`\212\001\265i\235(9\007si\275J\241Ff\2402\033\360\363/\255\0301\205\007E\366L\024\226\306\234e\335\0019\24351\030b\267f\030Q\017'\020|\013\305]N\241D-\247\222g\026\247\203\214\303\332^L2TZ\013N\005:\352x\311\004\222\342\246q\334\212<\032\267s\033(#\030\031\275/y\2638\204\016j=\nD\231\r\350e\335\003\234\271\023\206\023&\235C\211#F\350\354\345W\342p\361\226\271Z\343W\215\270_]F\252\306\326\231WaE\312\214\224\001B\202\234Q\314ud\001\256\tH\224\200\2746\301\214\326\305\313\030}\335j{\220\221\362\244\276\304$\241\010!$\210\024b\260Z\226\t\210\312\255*\322\032\026\252d\341\312\226\336WAI\271\305G\024\202\350$r\023\211!g\034\251\005\3008Cm\013%a\\\034Z\330\323JaX\331\202\326\261\223VYZ\314\254cZ\232\254b\324\323&\265\255\033SV\326\255,\264fi\243j\265Y79\246\315\014eh\324\313\026""\246\266Zk\032\031\243L2\311\215,\265Vj\254jY\255\240\270\205\202\271\271\306\2134\255\252i\2145\245\226\215\262\314[K\034\346\2314e\251\245\226\006Pj\243U\202b\014D\321&P\264\246\240\264T\300Z\026J\231TeI\2525#K\025\225F+#\n\262\252\310SU4\t\224\254\250\261F\023\210\270\244\3029H\270#(\\\002r\245\225-T\265%\244\264\271'%\244\315I\245\212\342\034V\206\246\2234ZY\n\320,C$\230V\245L41\031+)\241\2515#L\030e\014\225\200\262\242\300YT\265\024\345\216>qw$S\205\t\006\303)\255`";
    PyObject *data = __Pyx_DecompressString(cstring, 6642, 2);
    if (unlikely(!data)) __PYX_ERR(0, 2, __pyx_L1_error)
    const char* const bytes = __Pyx_PyBytes_AsString(data);
    #if !CYTHON_ASSUME_SAFE_MACROS
    if (likely(bytes)); else { Py_DECREF(data); __PYX_ERR(0, 2, __pyx_L1_error) }
    #endif
    #elif (CYTHON_COMPRESS_STRINGS) != 0 
const char* const cstring = "x\332\355]Ko\034\331uF\000\257\222u\266\001\034d\223\315\030\310\332\260\027\211w\201\021\030\310\232\340P\034[\260F\222E*\236\311\252\251'\365\226IZ#\215\036\354W\261\037\354\007)\361\321\305nv\375\215Y\314\306\372\001\201\177B\330U\327\252\357\326W\347\366\255\256\256b\223\"`\3233\327\325U\367q\3569\337y\177,\324?\026\036},\264>\026\036\177\\Y\375Xx\362q\345\356hd\345\231?r\313\037y\346\217<\030\215\024\332\376\310\003\177\344\3170\362\306\037)\370\277\372\016\236\271\013\317\034\302\267\236\300\257\212\376\310\241?\322\360G\034\177d\337\037\331\364G*\376H\331\037\251\371\357\271\347\217T\375\221-\377\231\001<\343\372#=\370z\325\037\361\374\221\3734R\361Gz\376\310\276\377\236\241?\342\371#\r\177\2448\032\031=y\362\365m\177\244\023\316G=\323\n\277\036<\243\276^\366\237i\n\363\t\276\356\370#\355\360[\243\367\377m\307\n\376\233\013\0070\322\204_\365\302\221\321w?\315\247\004\353j\204_\037\275\341d\244\033}F\315\331\337\325\302J8\347\321<?\315\271\004\253\250\3033\345\350|\202=T\363q`]}8S/\334gE\033^\270\366\321;\037\3733\37742\204\023,\207\363Y9\206\031\372\317\214N\341\323\327{D-\215\211\336S\201u\255L\264\256&\255\013w5\351||\372Y\331\203\023\014\356\305S\177\344\016\334\312\340.\277\362G\326\351\231\025\177\344\031\214l\002\265\000\325\255\274\010\327\256\350\260\035\316G{&\240\261m:\323\2002+\3413\205\"Qfp\007\353p\277\212@c\003\270\203\317\375_\001O\340\371(Z}\016\277*\302Yl\303\267\220z[\306\031\016\341W\335\324\363\351\302J\335\360\315\342\327\273p\356@Q\212'\274\200_\335\217\377\272\242\237\357\340W\376\256\216(\355\323M\001\356\247xK\215\370\017\356F\300\375\336\247\336\r\244\226\272\361\353[\3003\233\3047\334p\177R\315g\017\336\\\004\236\031\334\312\276\365\376\324\2433\324\316\353\036\314p%|\263\372\326\256?\322\201\323\331\000J\000\311\250\361\237^\224~\324)K27\315\233q\347;)\336\343\021E\225a\316k w*t\026\303\250\334)\354\302\233]\240\226Jxs\325{\002\371\356\000_m\021\272(\201\\\256N\225\323\226`\316=\222\302\257\375_\255\370\277\372\223?\362\324\037""\271c\\i\203V\332\010w^C2w\000\373\371\363\031\315\377d\344!\240\002\230\241\325\231\372\363Y9\202g\016\200\327\225a\177:p\202EBq\036}\275\rgQ\006\036^\001i\205\010\215y\002b\t\272\271\243\267}\232\017\374J{s\227\326\036|\253(\354X\007(*\240\336\032p-\027\336\323\003I\024p\277\035\340\374\035X{\023\316b\013\344\205\003X\342\251\377\314-\240\303\340V\276\364G6\303S\016\260z@cS\240\250\307\3763\253\2416\021\263\3176\347\2763U\336\322\204oU\201?\227i\237\273\002*\250\023\302\307S\026\220\260x\202U\341\004q\316\r\240y\2401\rYU\0019\300\351\250\023l\302{\212\361t\250N\247\014\222\350\025\360\261'\300%\356\203\214\333\201\265\017i\307\352\264cU\230O@\033\357@\367|\010\224\t\\\024\367\331\212\363\037\300y!\352v\340W\t\351G\355X\r\336\003\372\227\266\317u\272)\036\335\024>\3456|\035~%\236`Y8A\274_\335x.\241a\222\340=\303\250V\"\362\272\266\300\353\254\245\325\350d\247B?\233\244\347v\350^4A\267:\204o=\366\237\371\336$\233\324\036\356\302\257\356\301\216\225\201o\004'\370\310\037y\023\265\003(j\t\344N\005F*p\026^j\016\231\035\256\263\347\231Cz\246\n\322s2\232\257\3233=\342\000\235\031\223\271}\332\r\224\005\216\205\305\014o\323\000N\247L\230\244\022Z\347Vn\003_]\267\340\341I\347\274\t\034\373qx\227\203U$\236\263\r\227p&\262\212 '9\212\352\324\212~z),9.\315\247>\321{jD\317\225\231\261,\rS\254\253E\326\324\n\334A'\344?\023\276\271\014\3178 a{\341\272\254\254\227CXi\211\344{\027\364\301\001qu\017\366'\251\205\023\271\3151\214T\2438\323j\025m\220\313[ \007\327\341\315\275(\0021\333\2764\253\265\r\265\274\002\2339\350V\212K\264\342\021\221\302\231\333\304\215\213D\207U\240\237*\330\314\355\245C+\241\277`\325\372\315\351W\341\301\tv\243>\205\304g\361\022h\025\021\243=E!n\351\204\270%\361\036\232e\n\242\013\217\276n\226 I\371F\231,\344\366\253\030\000\365vaW\207Q\2134\362\004\205W\357\221\237\250\r7\245\00734c\321\003\013[.\242\3456\274y\r\260\037\"\3172p\033xF\331\265\206d\363\334&t\352\002\375\324\242\234DCz@\363\2122=\340QU\320X\035\300\352F/\203h\271\355\221^\020\354F\231\020u""\031VZ\245\233\3026\020{\236P\215\"\242)\257\242\007\226m\326\244&\343\306Y\317\331L-\274\212\036\334\257\"y\216\262\243\215\n\334S\227\356NC\240\r{\n\277\227l\316\232\247\017=bM\220 \250\225t\004\213\220'X\\]\243\245\202VZ8\232|\025\352W\223\3611\366\357\324\311\252\357Z\343\037\311\333n\346~\326\334X\364\215Z`u\305\2151\256\300\215?\035\224 xw\224.\334\004\004\273%\330.\234\204\236\221.\240\356*\341\204\016Hs\0074h\3046\365\370SVX\324\201\031n\001\246\255\301\376T\340\353\201\354\036\0202w\001\341\037\201'\342\003h%\207\202]\242\010\376\013\033\335\252b\334CG\340\264\373\3441\364WQpA\016V\243V\331\to\\.\277\322|vh\301+\003\326Z\207\335\030\302\231vIZ\t^<u^\333\260\363%\240U\300\231\352.\333\237 \362p\274)\335\250\365\000\355\220\005\037y\026|=\256\020\360\314\036x\361|\3763\372\177\037\371O~:\367\367\202\315\252\0066=\373[)\355\274`\311)\014)\256\340\303\231\245:W@;\225\250\005X\304u\201\224\351\214\367W*\234p`{:\n9\000\252\324,\025u\342Z\301\271\357du\233V\016\302\225N&\277RI\275\016\254\275\007k/\223M\2064)us[\361\021\\c\342\2210~\254IQ\213F\233\271\262UJ\350+xf7\277\375I\314\375^\220\315\023|\265\232\276\334\205_u\200\0038\202\305\336\213\306\003h\226\n\234\263\277\253\205!p\310\0170\322\013\237\031\331\201#:\2109J\007}\320\3330\237\327\306\310\231\362\271;\345\214e\234zs\007\220\036\355\274\346\361\251\302\234kp\026[0\3032\330m\216\243\230V\333\237c\210\206\332\017c\314\002\376\\8\006\255$\240\250\0009\004X\313\227\016#\311\373\304\307W'#{\376\310\336x\354\247\336\303x,\027\312T\310\\\322X\235\250O3\025fC\331\344F\265$\214gS;V\006\377E5\212r\325m\262\220_1zw\205,\245\r@\203\034a\362\000\342\325\037@\304\313C\177\344\241?r\033\342[\002?H\001\274o\005\210}\272\355\217\274\365G\276\007o\327;\360\177\005\326\225\327 A6\374\221\215\320\223U\030\020\236\017t\"\027\320\227\257\225\024\216\200\037\356\223\345\266\033/\277\224.\214\336\344\032\330I\212\200@\034\330\325c\360\210\r)\312=8\367>\3303\367 \372qw<^U+\335\0230\344dZ\177-\312\221\254t\363v\n\033\221Kz\3670""\212*1\332\247\320\r1\333\205\336\235@\357\316LoR\277\002\216\255p\357A\210\336/$\354LH\330~\024g\006\032P\200\265Ft2\203rg\226\371s\n\271\023\023}\264\005\221`n\224\253\257\354\206\334/\025\"\362\204\270\2575\262yZDy\251_mEOP\321<e\n$\360v\025\243\234V\375\212<\3511\222\210\345\316d\262\211\"\026\306X3\204\350\010\305\177\202\031\006\221\030U\330\237c\262x\270\264?u!\373\003\357\027zT\267\303o\251\273S\2017\357X\3708<\370\325\026\371\002v`\025\022E\025\254O\260\221\002Q\327\311\007\324\026r\251\016@\363E\371\336$\317l\031\"\323\272QmT\244^'\341\233\221\242:t\356{\340\177oD)<\301\215+F-\003\346\350\032eC+\001E\001'\341\335Px\3546\304B\024 \346\255\003\324\222\036\037\016\340V6\210ccvg?\232?\210\276\000\315\016P$l#Q\324\016\354F\2332\236\234\324\366\261\026!as\024A\225\342E9[\007\375\271N<\"\312\320\373\306\373L\267R\321O\005\326\345\302\tz\240w\373\334\246P\001\224;\200\214\260\n\305\256\014)\332\247IZ\000c~\304-\025\212h\355\nQ\334.\354j\005\366\0313\346\252\300i\275\370\370^\265c\375\360=\232\304Ozw*\224+\335\265\365i\"\032\034\351\343\261\3616%\2138\207m\212\0067\313\235!\334\270\212\265\345\377`J6\231\036E(9\361\361\207b\266\216=\217\242\373\256\0205Z\204j\204\347\355\317t\027$Q\007\366\260!\370\376\312y\330\2654\253\254G\361u\345(G\212\211#BLR&\335!\r6n\200F\306y\221u\222\346uX\205\007:\376\272E\004\216=\022\266_{z\216\275\035\215u\324\342m\2142E\213\313\255\010\331\213\270\033U\262\245\244\210C\023)\323\241S\266\230\217\242:\033\237&\305\201\250\363\352\001\375l\217G\324J\037\334M\341\317\315\316\362f\277c}\302$\275h\354n\206\274\305\214\314'\362R%\300u\3068\3741\330\257N+m\222\347z\2032\302\352BNM/\241Gc2t\201\034r/+\352\265\322\266XR\227)\256\273b\235w\203\032\375\013\322\240K\340\275\305\274?\227r\025+\202\274\330'\213\331\237\240\216\307\021xf1\016V\242\r\\\3056\235N\303\030\263\335\244\023\334\246_Q.g\260\363\301}W\273\372\034po\227\342{\033\224#\346Q.\271#\304L\276'\354\367\002b*\252\031\310\013\363\332Q.\233\021\376\372DQ\270m\320n\232\321|F+\374\3148""\274CH\006ic\315H-\353\343W\232>\2229\201\354FK\227g{\026i\020\321\224#\207\3553h\312\200\215]Sd\243\332\237FXafjw\220*\303\004\365R\324}?\206\n*\333\340\027F\355\230\277.\235`\2070\t\321\252V\371\244\024_\261D\263\344P\025\021-\037\244C\271\025n\310\237\265|\231m\372\026p?\344\207\212\207Wa\237Q\022\325\251\316\2001\207WI|\252}\244\244C7u\334`v\210\361!e\361{\321\254\250\354\356`\232\250\241\314\363\\\034\353\214]\364w?\237*Ea\2065Z*\302\333\375\343\032]\356\007F\301\210\212\202G\027\316\245\022S\207QS\323\030q\272\233\331\3652n\2062\275;\031\020\224\275\231\226a\202=\004\310\321\220\234\t\004\350\302er\301\345\273f\241R\263\013\310\254L\344o\376Ij\332\231\256j\205\312\350\221\340\220g\267U\322]M\030\202\227\311J\207\202+\262Lp\314&\371\314,\nj\271\334\213-\240\314]X\005\025]\310\342\274\264um\347\"\314\323\247;\344\003\023\222\006\324'=\035.!\300e\006\330h\2244i\243\222\231\324\373\274`T\234\222\364j\222\004\232T\310*aR\346\371\303ZS\346\275\0032\367z`\266\301B\021\rcR]_H\321\330\207\360L\027\002\312\336C\270_3\203u5\341\0049\310t#\031\037S7\316\230\364\223\306\271-\256\242H\247\203\230\315\\\366{\207Br\336\222\241\024\213\365V\343M\260\n\2635r\227\214\231\321\374\224\361X7Z\214D\223VU2u\327\343\023\370\304 \257|\014\014g$8\302\246\000\363\324FZa\360Z\241h\324\222\314\005'Z\024\362\226F\333*\236%S\2238\262\035\352\247\205-\322\350{\321b\352b\270(\232NK@?\373\361;\257\370\3301\004\247c\352\311>\004;\017 \024}\000\301\316\335S\242\303\212`\352\306\204\003\272\203\023\006\363\366\243\201i\n\323V\3119\351\222i\231\313g\262\273\240\010gQ\314\235\352<\n\272\257\223I\3303\321\217\206\006=\300QCp\035W ly\020\335U\205\371'\243y\326/J\360-\373\202.\036\374\312\350\210\320,\014\333\2248>\000\3729\2553\345\300\306:\270\376z\300\303k$eZ\260?\255\250\214\323\202Y\020\r\002\216Ro\016JZ\276\205\222\303\370\314A\230\242\241\360\3631\270\\\366\341Wh\367+\202\\\336\264x\317\236\360\036\363\257\372\331r\266\225\235S\262\256\264f^\377\262\t([\007\013'&\204\271\202Mo\207\332\225\224""\251!\306nj\333i)\203`\261\226\361=\033\026X\213\333h \327Z\243\342:\r\001\241aXe_H\305#\373\352\312\301y\323n2\261(\016\251\230z[(UU$\036~v\203\356\373`+(\207\251\223\n\213\226\343\013Fj\311U\026\201r\n\201 \212\253\203\245b\3356<A\335\224&\331\347?\320\272\270,\r\226\306ta\347;\031PT\037\366g\217\n\223cP\371z\3029K|5O\314\337\240\022\310\353\200\336\233\344\003\032\010\245YX7\007Kr\320\312O\225\237\377\036\032\367\255\217o\3602*]\037i\006\262\002\364\363\000\n!\334\002\033\332&\264nx\005\274\3678\232\302+\0066zT\306\265CI\207e\243/@H\357\326(\n\323\321\372\224\230X\007lsZ\270\327\034,\306\347n\035\022\250\244g[\210ah\200\324\333 \317\032\224\302U\272g\227\356\351\006\265kC\313\344\232EP\260\204\314w(\311XZ\227#\244\266\233\355\253\302m\232\320\332\3148*i\341I\236OR\037Y\376\326\214.5bj\010\005G\253F>\206\326\324c\241\270\005\277\207\333\342yD\207%\n\270CN\273A\2155Z\244\321o\320\272\232\3449\352\230\220\271\242\336#\220\236L-\345(F\322\260:\027\320]\2470s\016\236\205dn\321\006\3224\206\305\235\026?\344\273\263F+=\202\323\361\340W-\362J\367\010't-\n\304\232\357\273\304\2650J\007\023M\244s\257\001E\035\300\231v\242\374'F\273AK\351!\320\006%\371]\330\001r\262\003X\373\2114d\336#\2779\226\371\367\204\210\273\016y\025\361\246\330'e\262\035r\000\351\027\331\305]X\31701\346w@z\036\013)\362X\374\343@\360\023\261\036\267ER\246G\311\323U\262\373\231\3556i\"\301\030\021\255Z\244E\262,\010F\016i\304\246\334\316w\020\021\324\002\314\277\005\310|\027\220\3711\340\272\246\320:\317\245\"4\230\346\322O\235\334i\266\3059\324\266\013o\3450z/T\254\010\026\305\251^p\310\351\244\266\247\267,i~\242\343\250\\\326\020~\217\322\\\252$\205\205\204\370\304<\252F\226\333&\265\236>\240\330\236\367\204W\233T0\311^\246\344\222\304\237\370\004\263\210M\235\375\024(c\233\364 \305\320\177\317\217\353\220s\330\002\003L;\236\211\252M\r\225\255\037_&\214\24536\260\216\211\223\273\260\217\233\355\343M\222C\035\272\201\330^S\212\003\233\315h\000\251\214X\005$\367\021Y\360;!\035\026\312\306;\311\021K""\225\361{\250q\347\026a\345\216\320\340\322\241v\325E\212\267\333'\257\371tu-\264\021\357S\323\3336\331\357\246DcZ\261\035\262\372\211\0219C\210\rm\0106\232R|\213\344\025\307:\326Gz\263`\205\024-2.D\010a\024\321\251\352\352\nA\336\317,MrH\251\367\025A\207\344\026\201\033TP\256C\355P\247U\214(a\301\264Ts\316\032\215\245\231\217}\271\244\203\214m\020\237g\366\205\005\376\t\022T\327)\261bS\020\247Bu\"M!\252GS\374\264\200\300\035\177$\000\220\373!\310\214\251\257\311\325A\232t)\353\321\312\037Z&\367E DR\240g\256h{L\212U\031\260\373\236\220\240qVB\026\007P\257\250\032\006#\251\232\304i\002!R\357\252\346\312\221\234\247\263\023\3440$f\203@\357\210\230:\324&\tD\223\025\254K\030\0345\255 \253\030\323\245\271\212\006\033N\315Ns\206\207\366\t\252\374-k\350\227\246\356\243U\337\030\213\n\205\031\322O\322\316\352\016\231\370z\024\004\222\035\027\315\016\326\2612\2127\267O\000\255\n6\232}\252\nc\237^\264\223\261\353$\353T\367\263^/-\005\030\374\336\366\302)\203\236\271t\324h\233\377r{5!\364\233\352B\255\254~g\021\326\235\247\214\360}\262|\027\251myX\354\357\377\336lS\261\2777D\207\036A\310\226E\301V3\303\306X\3656E\377U\214^\276n\224Id^\000\313zW\263+\2115F\310`\374\024\027gD\352\345\030\275\206)\013y\312\005\001]kH\202\240\262Et\210\002\204[\\\327\243\321\243f%\300*G!\2133\255R\373+l\271\324\233\376m\322\254Q|\233\016\363\313]>W0\301\245\350\332\320\203\367\227\333O\311\205\367\2242\374\370\353\022%p\t<\227jb\035S\311\302|\270\361E\351\303\213\322\207\237'BKSXY\220\302\232\031\000\215+e\222\236]2\322\354\344'a\003\023H\002\255\344\224\n+OYvK\036\251:\251\370u\210JK\210\276\316\225\357\177\262666\236~\346\000H\341C\302~\223a\343\324\355p\254\3529\331\230\243\246Jc\232\221X\372\025\347p\344\203\336\331l|a\306>+f\354\354b\006\251\216E\214\271\027\265?\244\360\017P\201\206\243\221\212\20470\233\220\250W\275\307\234\355d\326\216K\324\312\227#\213g!&\327\030\3010F\257<\335(\335\244\022D\340?Sv)\244\341\341\027\221\274g/\222W\271\304E;@\235BE\236\031c\206B>\377\343\273\204=P,\246\254""\301\360\213\304\006&\314\036\354\341\373\334{|L\306\302\355;\325\326\3502\201\271EdlC\352\312\235\247\220\251\020\213\332\3176\230m\014\3232\366\326\034#v\314A\225\366!\235R\257\3302\205\r\203\241T1\277\364\253h\304\367\377\315P\305?\273\306f\213(=\321\214\364\222L\324\224\022\031\323\037\207\r\377X\262\331\242x\234\031\244$.\342\234\324\005=]\023#\366\274\3062\004\030-\221go\304\3317y\232\234\036q`\347\235E9B\263Y4T\337\177|\223\320\346(4\222\312\260\342w\216\302Ac\253\347(2c\312\220M\322\017\267\351Z\200\357\3443\315\307\232\254\036)e\320k\220\315\334;`\335X\023xv\302t\023R\213\262=\345_]\n\241\315\332$5\262b\354\211\240\033\027\272P\235>\340\306\253\360\255\240\252\352-`\374\233\376\310\023\177\344aXCL\215\024\200Z\236Bu\262;\320\021&x\317\323\260:\231\202-}\252\006&\2118\264\373o\t\252\003W'\303^3h\233;\004O[\302\216\014\312\336\212\231gyV\214\237n\206\2379\300\236-\357\326\355\023\025=o\013Q;\035\262\2515\250>\030vIhPn\345\032X\353\320\202\346\nR\330\035_?_I\207\003\341\224y]e\262\273a\035-\251\366\027\357j\232\332h\371W|*\022\200uCk\246\264\253*\251\244o\334\325\323\252\303\206\367K\240(q]\036\254k\000#\322\215\233\205:lyR\313\220\220C\221\252\032\016)\014\0363\247\251\352\276\326X\030i\243\033_/qL\246\262T\261\320\243\254V)\366Q\252)$U\036s\341\315GFj\341\"\021\354\343\224\264\222\265dJ\277\350\375J\243\357\344_\347\320\334\207q#YU\250\230*\334YW\205\262\257\024\307\347e\357o\236.\016?8%'\303\354\367*\232,\035,\251\236\222g\252W\223\270q[hq?]\237k\233<\177M\241q\367E\212\326yK\321\212\353\204\370\320H\207)<\254\366\035\356\263\316\316\377\034\030d\n\341\251\3011\014\231v\215\336\270\273\364\346Nf!\246R\251Zs\213\340\\f8e\010\200Pk/w\217\213Q8\214\361\247\2628\335\"\257\014\244-\210&F\010\003\233\320\343k\026q3\343#\317\351L!\311e\n\247l\366\232\267\022\326\272@EjHp\203\312W+\250^\262N\364(\347\035\225r\312\315\t\263\340\242YS\213dj\222T\306\034\023\216D7\032\204y\253\2212\300Co\362\235\347&\242\232Rk}S\314\205\336\013-J\300t(\235YP\233\264B\302\254\224\354""\236\376\351\314\332-P.\372\014NPac!\305\270\000\206d\245.\027\201\213\346\030{\224\023\242N-\031cZjx\020\342\216\3069l\nW\246&\tR\241\356\311\"\002\315\246\002'\241\262~8\003\347\236\246\251\240g\021N?-\023Q9a\270\370s\301`\337\243V\314\026\345\352\325\355\276?[\\4&6\313\230\036\242\366\231S\317 %\301l\212+8B\243\233!\275\247J\034\322\336D\215\356\235]\320A\2028\2605hF\032Dt\325\200\213\266(%\301\342\224U\230\2143\303\247\314\272\303t\317\375`v\327n\225\216\221\320\351\241\325\361\002\036\216\305ac8\033\352M\230(T\025R\275\222\316p\213p\013$\346h\350bH)\253\003\300\363G\321&u\247,\337\271\310u;\027ya\201\023\224\003\301\006\363\333\3378N\366\224\020\376,\254}\2265\205\374\255\251\331Y\272\354%\221\215\266>\231<\235\035\215\343Tmq\347\320Ie,d!\306\301\277\024\264\332\200\037\336\365G\036\010\215\222\206\321\352\236Z\020\301\001<\343\221\006D\201<\21134\214EN\362/\211s\206\223F\273\020n\334\264vWnZ7\"kC\020\356\2521\303'3>\177f\312\302H\374\247.\330\325w/(\334\202\302\205\302Yb\016\333C\333\204\003\215Z&+\241\326\240\362h\366^\030\310\230U\001\354\326\270%\346\016f\207E]\312js'\272\225\271'NYe\342\005{\370\000<\230u8\213cS\301\031\265.\010\325\307\373~\221\343\227*\307o3\031=\3074=\032\n\317 \222\031R\353H.}\326\010[\327&\210\333\261/\3677\313\211n\247+\035\236\3033\247S\334\370\207U\330\214'Pic\0252\227\016,\256\240}\305\262\r\213g\320d\276C\260\356%\244\276>\203\272\340/\341\231G\376\310;\177\244\340\217\254\370#kTS\344\0250\310\307\220\177\365 \242^\374\360\340\364\213&\217\376~\342\316Y\227\377\233\356\275\255\303\306\277\245\215/\000\n\177\025\216\250c\177\003\207s\027~\265\002\317\274\204g\036\300\261\257fV\321\244\005\247\\4Zm6MI\023\312n\222gu\207J4!B\321\241\205wP\225Fz\005\234\316\025\022|\362I\022\267\361h\256S\312\330>q\360]\220\367\323\n\270\335\022\032\017\226)\002&\367\364FM\272\017\005o\345\032\005\264\357\021\365\356\200<\263\217\345\355\n\026\317F\336iSZ\242\253Gw\031\322\022Gm*N\236\271\357?\363\302\037y\026r-\265\253w\374\221\3070\3628*\254\264""\312\r\357@|=\004>v+\344\220\247@\033\035\352Z%\025\271\306\375yF\002\366\t\244<\007\334\370;\340\317wa7\016\341W\367\205\246\352\301y=\006\t\362\020\366\360\016p\332;0\022\310\213GaZt\026\315H5)<\335\310f\214\020\352\010\270\023\343b\353B\352\031z\020K\321V\365\352\004q\307\036\206t\310\351r\211yBz\214$\330\0019\235PI4\364\247b\302\354.$\215\272\231i\346\236Q\342WHZ5\004h\214\034\262\010\330\257\n\322\352-\200\367\025\200\275\017\204\375\231\226\034<\002\251\347D\301{\014:\235\375x\372\311\316k\030\305\352\332\351$\265\326\335\016\237\341\304m\255\354\211\013Z\245\331\0034Y\244\265\364\014\242\301\314\274\370c0\266CQV\030\r\351\301>\367\251Z\333CX\027h[Z6\010'\277\363Y\240\205h\207\"\360\\:\257\r\262BnE\355/\232\305\263\004T\227\364=\215\231\344l\346\233\362N\360\306\t+\215\341lh[yl\341\347;\177{\370\324X0\204w\314\\b\373l\255\375u\302\242=\274\033\307t\343\206`\201\251\000o\351\236\237\373\245i.\317\022\312\035\373X\371\262\261\231S\322\374\0074C\366(*\256\021\226TR\236\233\207\331Z\3142\224Vi<\331\022\366\3138b)&\357%\227hH\r\377\220_D\335\202\273\340\341x\234qa\303\263\356\2530\353\236\263\277c%\201\352Z\321L\230\230h\332m*\027\331\215\3522\267}\213Pa+\314\375\010b\367q$x\306\312\006r+\264Th\236\376g\241\263B\253M\273\t\022\377\tXe\357\204V\021\233\031\006#\267\337D,\377\377J6,\013\347\216\232\337\255\360\231\230\263\331\025N\353\36045\031U\250.\272\362\333B!\253\244\253JQ\300\014\313\275(<[#\244c\377\236\321\t\377\014\346\367*a\t/\373\225\247G\340\243\273\366\005\334\0073\272e^p(`\254\035\213F\227\361\273\365&Y\361\302\304t\222\020\201\nT\2330n2\301\374\222\3424F\002\366y\27462\275)\310\364\226aw\336\331b\240)\354\327\347\214\267l\317F\304\001\267_\233$V0\022<sZ\276\031\233\031\"\016@\364\220\306_\242y\010v\005.\347\177k$\301t\313\276\366\255\327\200\0366\001\205\004+\275K\005j\037\206\201\026\n+tS\227\325\236eT\335\243\222\221\250\271\271t\013\352\224\005\205\262m=jU\324x\002\226\261\306<-{\024;\373\255 O\313N\035\314g+\212\362U\231\324\354\232\206yTN\035#+""\245(\212\0318A\255\346\215\0201\252V\261\0326\213\323\312e\366M\r$\265\306\305^T\246d\221\361y\306cH\343\232cc\220[\240\023\336\003\234\274\032\217R\024\"\237\254\363\2100\303\014-k\366\267\351\021\325\333\030R5/#Ei\032\325{8\323\216P\010\270M]i0\276\007\365\034\251\210\277Ke\276\217\001\373\231\313\205W\214\362\253\2326F\233\213\341\252\225\256Y\324\256\300\234'\222h\005o:3\034\223\217\"x5\264j\2026\347\005Z]\214\235h\325\370\255GT\247\260Am*z\264\317\325\314n\223Y\347M\332\373\254\005\272i;\032G\225\371Yp=\233\ni\225\255h\0257l\034:e\252c\257\206\315\332\245\nI\306\234\3574oV1\376\003\312\231\313\356[\230\237\227g\326\210\033\255u\244\225\331\255L\351^L\204R\264l\241\036\265IG\214\364\2044q\364x\331W\271\263\210\302\321,O{\321\346(1\355\240\267\251Wf\235\354\221}\272\225U\312J\357\244n9n\216\203\251QD\035\326\r\002\376\254\345\307\364\242\375+\323W\n\274\220M\t\332\255\267\301\266\332\214\306\231%\270\271\333\023\255T\250s\020\023\333\215\273\212\370\371\003\371\322$\252K\341K\213\221;R{\200,\260\326iUlz\016\021\022\337\301J}\355\246p\014\332\315\237B\257|LeP\251Gj\026\350\213\355\264%\222)\320\327uFe\245y\316\0165c\253R\207\315\n\264oI\303I\354\347|\213j`4\340\306\031\277\256y{\366\001#\325\251\370~G\250\203\325\243\206I\366um\331r\342\030\255\031N\332\352}\n\317W\211\2635(\243i\030mG\237\241\335\306%\333 \325:\232P\202\330\304U\230\363\3357\222Y/\263\323A\246\274\363R]7\233\263\310\263\307\367\354\327x\260\317\360\3743\374\3525y\272{\324\334\213\355\352\\\357\247N\265\304\036\301\272\260\006\330\203\370\246J\232F\337\245\214s7Z\315K\243\226R<\367\363\237\371\353\333\227#\347\326_\337:\217g&\325\330\t\277U\250$\314\212\267>\347\374k\000\211M\033\321\332]\243\356\032}@\375Hw\331\325\263`\333\355\005/\311\216\227\004k\037\246\340%\333\002/i\234./\321j,\317BlY%\312]\022\370]\336\023G\254Q\016\367iU\177\302\334\320\222\240\335a\033\322\006i\002\356lU\032\327\232FR,\226VQG\262;<\266\266JCL\227\215\276'Z\337\326)\232\247L\231\315\360L\346\336#3\037\245vgR\253v-\023""\324\003\317+V\007\255P;\356A\270vE\207R\324 \366y)Q\234\357t}\314\326\025\302cjH\354d\200\024\272\020\355T\241\266\250\324(U\325\267\177\005\034i@\271\373\324\366Sk\261\336\247Z\273u\262ir\034^\325\330'\250\233Y\353Ks\336L\tb\310Z\302\216u\204\246\307\005X\305\001i\332E\360\003U\201CV\242\270_\331\002\336\020\276\350\222t\350QT\363&\305\301\364\001\371\006\374y\007~\365}\224\267\024|\313~!X\351!\320j`\367<\202\206\330\345\264M\351!\"x\312\021c\251\354;\023y\0373\264\335\330\370o\006\224\261]\241\335\300;\350P\003\306c\340\253\317,\032,\333\34709\311ZD\252j4f\\g\337\363\242\032\037\013\2224\2466\213\336\031\350\205\nxo\256Z\221MdL\237\360Fu\222\216\000\346\372\322Z\345a\033k\001zU\213\300I\320;R\026<:\200`\271\263dL]D\241F\345L\324A\235nT\207\264R\307(\251\235\274m\036cv\303x\3561\326da\017\225\036\207xu\017\270\3260\332\367J\213\350\335\002\355\017\321E\207\252\034\017h\244Cz6\243\\\300HJC\274\227#\3370\347\352\034D\263\005T?\202\340\346\326\204:@\025!\316\214\316T\213\354\304\232g\325\250\345Z\313\270=\006\324\204\322\334\005\356\347\022\347\037\020\226\250C\346\027V\265\251Au\375\"4\036\307\010\332>d\022\227CMS\313U\305\216c\025\312\362Y';~\231<g\355\250\345F\333\215\240O\307\020$c\231b\251\021\323>\201\031\3223V7.\037;h?a\235\200\013Z=\273\264z\357\354e\244\210z\n\346\006b\335\246j\324\236 Z\017:B\2650/>#\2055z\261RH\221\264\376A\302LI\376V\302{\232JCLz\0266:\343Q\324\326\256\"$\222j\023\025\252\227>4\372\020ll\335\030C_\003\0335\332\320,jVi\330\030c\354j\344\033\201z\201\032m\274'\017\006\350hc42\241O\342,\364.\214\361\235\013\275{4\377\233G\326\260!u3l\222\245\324\205x\232\301\314wM\232\311\310\327\251\235{z\013\214u\316\260\226\211T\216\306\033e\242/\367\250?\024X{b\352D\226\250\337\220\003v\033{\211vv\365n\216\371\223\270VE\210\030\363\242y\363\352[\355\250~\252\360\3171\330rg\270sb\202\350=\363\355\256%\314\001;-J0\336\235Lro\316\272\225\306>\367O\312\221\263\216\373\037\223\215\343\304g8h\365\325<\352f\330!/Uf}1>\243^0\247\3057\362\311\035M\223c0\373\331/""\351\365\2466iIB\204\200\222\247\253\344q\346\032\374/\255}\023\325\204~\374\203P#+\370:Q\241d\021\035a\357\377b\275\373\t\2408\360\302h\372\262\003\226\034s\254y\227\262\307Q\323|*dnpu\311\203\361\034\022\253\256*mt\226\375qh\331\376\000\022\244E\336R\264\363c5}!f=\310\226,\3642\230s\233n\nfOa\275\006!\nE\241\312Y\216Y\267\311^@\232\2272\360=\322\273\017\005\274\261\007\034;\351\233\017s\267Y%\245\314\\j\246\214\231\263\031\345\032e\n\362\360Y\216H\304\332\272\301*f\302\212\225\2775C\300\330S\266pn\t\022\237{\365\234\013\357\177\202\334Q\263\316\350Q]\330^\264.\240\372V\213\370\206\007\022df\354\264\023\366\306\251\022\206\304\230\333\336\254\330\034\306\234\273#h\023\223\345\321\231\355Z\222%\260:3\261\337\251\253\010\213\261\273H\033\230\333\261'\3241q\2513\217\003ze=\232\273\036hdZ]\271R4\273B\325\010`O\315\013\210\014qf\330Z\310\376\224\244<\374,r\233\222\220q\332\023l\005^\270\366\030:L\270c*\256\251\017Yk\367g}\307bn\356\020\356\327:p\277\256\300\353\212\361\261\2731\225\226\213\260\207\333\024\t\346D\275\333gr\017\317k\344gR\256^\005\344\311\347\316Utw\204\030\030\256x\350\316\272\247fZ\25021\206\3349\237\0302=\037K\203\320\316:\036;5\357\022\334w+\314\346\222_\306\215\367\222k\325\223\363\2649\324\307Wn\325*\357\033\275K1\032\375,\370\3379\203\271G\032Pf\265w\023\320\330m\322+9v\345\276\200\2047,\272?lD#-\025_\345\214\313u\243\007\312\241L\322\206\255\374\032\023=b\326\233\216\301\323\207UTZ\340\211\270\025\315k\323:\242\334\207\232hw\251KD\313V\003\302jG\232\374\022:\030h^{\334\303A\324S\243xo\023\262\0167a\316\257\204n]\346n\004\326\353\032\223wl\256\203CUb5\331\364\032\020\332.\330\034\252\020#m\246\215\032Y`*\344\321\220z\216\245\250x\210\276$\205*\275h\035\021\205N\355\367G\212\367\363H\277\350\220\277\273e\364\321W#\361\317\277\274tyi\376\313+\213\213WG\177\177\273py)\370\247K?\377\343\225\377\375\362\362/\374\277s\313\213__\377\331\357.-,}q\375\333_]]\270\361\355\365\345\305Ks\377~\355\322\342\177\316\177\273xcin\356\277\276\375\346\344\277\377qyay""\356\327\213\337,\377f\361\253\371\245o\257.\\\276\366\305\302\265\033\327n._\276\272x\362\324\2277/_9\371\307\223\177Z8\371\317\225\371\245\245\271\337.._>y\375\350_O\236\231\273|un\371\306\374\302\342\227\363\013\277_\270rmiq\341\332\327\327/\237\314g~y~\356\217\227\227\1777\367\373\305o/\235\214^:\231\300\350\357\342\247\351,\237|w\361\352\315\257\027o\314//.~\263\270\360\325\311\357\256\316\177\27587\367\325\315\253'\037\374\355\342\325\305o\256\337\030\255\343\362\334\345\245\271O3\033M`\351\344\275ss_\317\237L`\356\353\223\367\372\177o^9\371\337\271\271\340%'?^\276~\355\372\334\334\037n\316_\t\206N6\353\322\350\357\362\334\337\376}\371\322\311\312o^Y\236;\231\316\322\350\357\357n\\\373\343\377\314_\271\271\350\377Y\n\366\363\322\342\265/\277\272\271\264p2Q\032\370\342\347W\256-\314_Y\372\305\027j\276\205\277\373\341'\377\370\3747\317o\276\374u\375\247?\374\344\357W\377y\365W\317\377\351\345\037~\370\311?\254\376\333\352\177?\377\227\347\363\365\237>\237\177\371\207\377\007\232\030\260\302";
    PyObject *data = __Pyx_DecompressString(cstring, 9451, 1);
    if (unlikely(!data)) __PYX_ERR(0, 2, __pyx_L1_error)
    const char* const bytes = __Pyx_PyBytes_AsString(data);
    #if !CYTHON_ASSUME_SAFE_MACROS
    if (likely(bytes)); else { Py_DECREF(data); __PYX_ERR(0, 2, __pyx_L1_error) }
    #endif
    #else 
const char* const bytes = "\342\200\250\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\205\342\200\213\342\201\217\342\200\214\342\201\202\342\200\215\342\201\217\342\200\213\342\201\211\342\200\214\342\200\255\342\200\215\342\201\211\342\200\213\342\201\225\342\200\214\342\200\255\342\200\215\342\201\234\342\200\213\342\201\200\342\200\214\342\201\227\342\200\215\342\201\211\342\200\213\342\201\205\342\200\214\342\200\255\342\200\215\342\201\267\342\200\213\342\200\254\342\200\214\342\201\215\342\200\215\342\201\234\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\201\265\342\200\215\342\201\237\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\200\206\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\244\342\200\213\342\201\277\342\200\214\342\200\207\342\200\215\342\201\244\342\200\213\342\201\277\342\200\214\342\200\243\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\256\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\200\253\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\244\342\200\213\342\201\277\342\200\214\342\200\243\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\254\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\252\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342""\200\255\342\200\215\342\200\254\342\200\213\342\201\257\342\200\214\342\201\241\342\200\215\342\201\270\342\200\213\342\200\253\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\201\252\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\243\342\200\214\342\201\276\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\270\342\200\213\342\200\206\342\200\214\342\201\216\342\200\215\342\201\204\342\200\213\342\201""\200\342\200\214\342\201\202\342\200\215\342\201\231\342\200\213\342\201\223\342\200\214\342\201\216\342\200\215\342\201\204\342\200\213\342\201\201\342\200\214\342\201\217\342\200\215\342\201\204\342\200\213\342\201\237\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\226\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\226\342\200\215\342\200\254\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\253\342\200\214\342\201\220\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\220\342\200\213\342\200\253\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\201\220\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\220\342\200\213\342\200\253\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\257\342\200\214\342\201\264\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\201\226""\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\227\342\200\214\342\200\252\342\200\215\342\201\274\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\200\253\342\200\214\342\201\220\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\220\342\200\213\342\200\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\253\342\200\214\342\201\220\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\220\342\200\213\342\200\253\342\200\214\342\201\264\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\273\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\201\226\342\200\213\342\200\206\342\200\214\342\201\220\342\200\215\342\200\201\342\200\213\342\201\273\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342""\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\201\244\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\201\216\342\200\215\342\201\204\342\200\213\342\201\200\342\200\214\342\201\202\342\200\215\342\201\231\342\200\213\342\201\223\342\200\214\342\201\216\342\200\215\342\201\204\342\200\213\342\201\201\342\200\214\342\201\217\342\200\215\342\201\204\342\200\213\342\201\237\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\270\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\201\233\342\200\214\342\201\201\342\200\215\342\201\221\342\200\213\342\201\216\342\200""\214\342\201\204\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\204\342\200\215\342\201\205\342\200\213\342\201\237\342\200\214\342\201\231\342\200\215\342\201\212\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\261\342\200\214\342\201\272\342\200\215\342\201\247\342\200\213\342\201\266\342\200\214\342\201\257\342\200\215\342\201\242\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\243\342\200\215\342\200\266\342\200\213\342\200\253\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\266\342\200\213\342\200\253\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\200\260\342\200\215\342\200\254\342\200\213""\342\201\256\342\200\214\342\201\241\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\254\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\201\216\342\200\213\342\201\202\342\200\214\342\201\216\342\200\215\342\201\224\342\200\213\342\201\230\342\200\214\342\201\237\342\200\215\342\201\212\342\200\213\342\201\205\342\200\214\342\201\201\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\214\342\200\215\342\201\210\342\200\213\342\201\217\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\260\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\200\260\342\200\215\342\200\254\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\260\342\200\215\342\200\254\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342""\201\251\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\200\261\342\200\214\342\200\252\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\200\252\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\201\231\342\200\215\342\201\231\342\200\213\342\201\215\342\200\214\342\201\204\342\200\215\342\201\207\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\201\210\342\200\213\342\201\236\342\200\214\342\201\210\342\200\215\342\201\212\342\200\213\342\201\230\342\200\214\342\201\202\342\200\215\342\201\231\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\266\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\245\342\200\213\342\200\261\342\200\214\342\200\252\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\243\342\200\214\342\201""\243\342\200\215\342\201\277\342\200\213\342\200\261\342\200\214\342\200\252\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\200\266\342\200\213\342\200\253\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\200\253\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\201\233\342\200\214\342\201\201\342\200\215\342\201\221\342\200\213\342\201\216\342\200\214\342\201\204\342\200\215\342\201\202\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\201\237\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\214\342\200\214\342\201\232\342\200\215\342\201\247\342\200\213\342\201\266\342\200\214\342\201\257\342\200\215\342\201\242\342\200\213\342\200\254\342\200\214\342\201\261\342\200\215\342\200\253\342\200\213\342\201\206\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\213\342\200\213\342\201\234\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\201\277""\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\260\342\200\215\342\201\274\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\201\244\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\200\260\342\200\215\342\200\254\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\261\342\200\214\342\200\252\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\200\260\342\200\215\342\200\254\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\254\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\234\342""\200\213\342\201\200\342\200\214\342\201\227\342\200\215\342\201\211\342\200\213\342\201\205\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\211\342\200\214\342\201\203\342\200\215\342\201\210\342\200\213\342\201\223\342\200\214\342\201\231\342\200\215\342\201\231\342\200\213\342\201\215\342\200\214\342\201\204\342\200\215\342\201\207\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\237\342\200\213\342\201\236\342\200\214\342\201\214\342\200\215\342\201\202\342\200\213\342\201\200\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\233\342\200\214\342\201\201\342\200\215\342\201\221\342\200\213\342\201\216\342\200\214\342\201\204\342\200\215\342\201\202\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\272\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200""\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\200\201\342\200\213\342\201\252\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\247\342\200\213\342\201\245\342\200\214\342\201\257\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214""\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\275\342\200\214\342\201\270\342\200\215\342\201\244\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\201\252\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\255\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\231\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\214\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\206\342\200\214\342\201\253\342\200\215\342\201\271\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\201\253\342\200\215\342\201\271\342\200\213\342""\201\243\342\200\214\342\201\240\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\230\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\201\252\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\201\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\242\342\200\215\342\201\270\342\200\213\342\200\206\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\251\342\200\214\342\201\257\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201""\274\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\206\342\200\214\342\201\256\342\200\215\342\201\247\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\232\342\200\215\342\201\247\342\200\213\342\201\266\342\200\214\342\201\257\342\200\215\342\201\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\222\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\224\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\245\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\243""\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\270\342\200\215\342\201\252\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\231\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\214\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\245\342""\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\272\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200""\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\201\222\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\200\252\342\200\215\342\200\245\342\200\213\342\201\246\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\250\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\242\342\200\213\342\201\246\342\200\214\342\201\246\342\200\215\342\201\247\342\200\213\342\201\241\342\200\214\342\201\243\342\200\215\342\201\244\342\200\213\342\201\274\342\200\214\342\201\274\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\272\342\200\214\342\201\272\342\200\215\342\201\263\342\200\213\342\201\265\342\200\214\342\201\267\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215""\342\201\240\342\200\213\342\200\261\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\200\265\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\274\342\200\215\342\200\271\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\276\342\200\213\342\201\241\342\200\214\342\201\257\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\253\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342""\200\243\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\200\273\342\200\213\342\200\275\342\200\214\342\200\277\342\200\215\342\200\270\342\200\213\342\200\270\342\200\214\342\200\270\342\200\215\342\200\275\342\200\213\342\200\273\342\200\214\342\200\265\342\200\215\342\200\262\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\247\342\200\214\342\200\260\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\276\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\263\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200""\261\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\272\342\200\215\342\201\247\342\200\213\342\201\266\342\200\214\342\201\257\342\200\215\342\201\242\342\200\213\342\200\242\342\200\214\342\201\266\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\201\224\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\260\342\200\215\342\201\260\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\276\342\200\213\342\201\241\342\200\214\342\201\257\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\266\342\200\213\342\200\256\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\207\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256""\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\234\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\201\244\342\200\215\342\200\243\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\244\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\253\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\226\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\200\243\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\257\342\200\213\342\200\244\342\200\214\342\201\256\342\200\215\342\200\242\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\276\342\200\214\342\200\277\342\200\215\342\200\263\342\200\213\342\200\276\342\200\214\342\200\270\342\200\215\342\200\251\342\200\213\342\201\221\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\233\342\200\214\342\201\241\342""\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\242\342\200\213\342\201\245\342\200\214\342\201\244\342\200\215\342\200\243\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\244\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\253\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\201\252\342\200\213\342\201\256\342\200\214\342\201\256\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\241\342\200\213\342\201\247\342\200\214\342\201\241\342\200\215\342\201\246\342\200\213\342\201\242\342\200\214\342\201\242\342\200\215\342\201\273\342\200\213\342\201\275\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\275\342\200\213\342\201\273\342\200\214\342\201\265\342\200\215\342\201\262\342\200\213\342\201\266\342\200\214\342\200\275\342\200\215\342\200\272\342\200\213\342\200\276\342\200""\214\342\200\276\342\200\215\342\200\277\342\200\213\342\200\271\342\200\214\342\200\273\342\200\215\342\200\274\342\200\213\342\200\264\342\200\214\342\200\264\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\240\342\200\213\342\200\261\342\200\214\342\200\276\342\200\215\342\200\271\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\233\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\242\342\200\213\342\201\245\342\200\214\342\200\245\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\245\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\200\254\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\214\342\200\215\342\201\211\342\200\213""\342\201\217\342\200\214\342\201\211\342\200\215\342\201\216\342\200\213\342\201\212\342\200\214\342\201\212\342\200\215\342\201\203\342\200\213\342\201\205\342\200\214\342\201\207\342\200\215\342\201\200\342\200\213\342\201\200\342\200\214\342\201\200\342\200\215\342\201\205\342\200\213\342\201\203\342\200\214\342\201\235\342\200\215\342\201\232\342\200\213\342\201\236\342\200\214\342\201\236\342\200\215\342\201\237\342\200\213\342\201\231\342\200\214\342\201\233\342\200\215\342\201\234\342\200\213\342\201\224\342\200\214\342\201\224\342\200\215\342\201\221\342\200\213\342\200\274\342\200\214\342\200\274\342\200\215\342\200\271\342\200\213\342\200\277\342\200\214\342\200\271\342\200\215\342\200\276\342\200\213\342\200\272\342\200\214\342\200\272\342\200\215\342\200\263\342\200\213\342\200\265\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\257\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\245\342\200\214\342\201\247\342\200\215\342\201\240\342\200\213\342\201\240\342\200\214\342\201\240\342\200\215\342\201\245\342\200\213\342\201\243\342\200\214\342\201\275\342\200\215\342\201\272\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\273\342\200\215\342\201\274\342\200\213\342\201\264\342\200\214\342\201\264\342\200\215\342\201\261\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\247\342\200\214\342\200\260\342\200\215\342\200\271\342\200\213\342\200\264\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342""\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\260\342\200\213\342\200\253\342\200\214\342\200\252\342\200\215\342\200\245\342\200\213\342\201\246\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\250\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\242\342\200\213\342\201\246\342\200\214\342\201\246\342\200\215\342\201\247\342\200\213\342\201\241\342\200\214\342\201\243\342\200\215\342\201\244\342\200\213\342\201\274\342\200\214\342\201\274\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\272\342\200\214\342\201\272\342\200\215\342\201\263\342\200\213\342\201\265\342\200\214\342\201\267\342\200\215\342\200\273\342\200\213\342\200\275\342\200\214\342\200\277\342\200\215\342\200\270\342\200\213\342\200\270\342\200\214\342\200\270\342\200\215\342\200\275\342\200\213\342\200\273\342\200\214\342\200""\265\342\200\215\342\200\262\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\247\342\200\214\342\200\260\342\200\215\342\200\275\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\201\266\342\200\213\342\200\266\342\200\214\342\201\266\342\200\215\342\200\254\342\200\213\342\200\253\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\242\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\201\252\342\200\213\342\201\256\342\200\214\342\201\256\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\241\342\200\213\342\201\247\342\200\214\342\201\241\342\200\215\342\201\246\342\200\213\342\201\242\342\200\214\342\201\242\342\200\215\342\201\273\342\200\213\342\201\275\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\275\342\200\213\342\201\273\342\200\214\342\201\265\342\200\215\342\201\262\342\200\213\342\201\266\342\200\214\342\200\275\342\200\215\342\200\272\342\200\213\342\200\276\342\200\214\342\200\276\342\200\215\342\200\277\342\200\213\342\200\271\342\200\214\342\200\273\342\200\215\342\200\274\342\200\213\342\200\264\342\200\214\342\200\264\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\240\342\200\213\342\200\261\342\200\214\342\200\273\342\200\215\342\200\242\342\200\213\342\200\245\342\200\214\342\201\260\342\200\215\342\200\261\342\200\213\342\201\267""\342\200\214\342\200\252\342\200\215\342\200\254\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\257\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\245\342\200\214\342\201\247\342\200\215\342\201\240\342\200\213\342\201\240\342\200\214\342\201\240\342\200\215\342\201\245\342\200\213\342\201\243\342\200\214\342\201\275\342\200\215\342\201\272\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\273\342\200\215\342\201\274\342\200\213\342\201\264\342\200\214\342\201\264\342\200\215\342\201\261\342\200\213\342\200\274\342\200\214\342\200\274\342\200\215\342\200\271\342\200\213\342\200\277\342\200\214\342\200\271\342\200\215\342\200\276\342\200\213\342\200\272\342\200\214\342\200\272\342\200\215\342\200\263\342\200\213\342\200\265\342\200\214\342\200\252\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\246\342\200\215\342\200\266\342\200\213\342\200\271\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\201\261\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\245\342""\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\242\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\201\242\342\200\213\342\200\242\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\253\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\271\342\200""\215\342\201\260\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\260\342\200\215\342\200\244\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\200\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\200\251\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\200\251\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\257\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\271\342\200\215\342\200\251\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\200\240\342\200\214""\342\200\255\342\200\215\342\200\251\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\241\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\257\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\203\342\200\213\342\201\230\342\200\214\342\201\200\342\200\215\342\201\207\342\200\213\342\200\256\342\200\214\342\201\260\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\274\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\260\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342""\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\273\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\244\342\200\213\342\200\243\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\201\273\342\200\214\342\200\243\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\243\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\270\342\200\213\342\200\243\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\273\342\200\213\342\200\243\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200""\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\200\252\342\200\215\342\201\236\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\241\342\200\214\342\201\214\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\276\342\200\213\342\201\255\342\200\214\342\200\243\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\201\266\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\274\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254""\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\261\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\277\342\200\214\342\201\277\342\200\215\342\201\255\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342""\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\256\342\200\215\342\201\270\342\200\213\342\201\276\342\200\214\342\201\253\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\273\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\233\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\242\342\200\213\342\201\245\342\200\214\342\201\244\342\200\215\342\200\243\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215""\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\245\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\264\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\265\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342""\201\226\342\200\215\342\200\272\342\200\213\342\201\221\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\253\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\264\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\200\243\342\200\215\342\201\220\342\200\213\342\200\243\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\262\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200""\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\223\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\242\342\200\214\342\201\242\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250""\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\275\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\217\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\242\342\200\214\342\201\242\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\274\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\201\265\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\243\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342""\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200""\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\334\222\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\211\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\261\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342""\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\276\342\200\215\342\201\271\342\200\213\342\201\252\342\200\214\342\201\222\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201""\250\342\200\213\342\201\277\342\200\214\342\201\277\342\200\215\342\201\255\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\272\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\233\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\242\342\200\213\342\201\245\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255""\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\270\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\246\342\200\214\342\201\254\342\200\215\342\201\261\342\200\213\342\201\243\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\233\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\242\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342""\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200""\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\275\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\231\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\201\261\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215""\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\272\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\273\342\200\214\342\200\277\342\200\215\342\200\263\342\200\213\342\200\276\342\200\214\342\200\265\342\200\215\342\200\270\342\200\213\342\200\271\342\200\214\342\200\271\342\200\215\342\200\262\342\200\213\342\200\264\342\200\214\342\200\252\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\234\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\240\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342""\201\240\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\235\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\253\342\200\214\342\201\276\342\200\215\342\200\251\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200""\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\236\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\241\342\200\214\342\201\214\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\276\342\200\213\342\201\255\342\200\214\342\200\243\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\264\342\200\214\342\200\240\342\200\215\342\201\250\342\200\213\342\201\277\342\200\214\342\201\277\342\200\215\342\201\255\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\277\342\200\214\342\201\277\342\200\215\342\201\255\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245""\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\265\342\200\215\342\200\246\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\200\241\342\200\214\342\201\254\342\200\215\342\201\241\342\200\213\342\201\255\342\200\214\342\201\265\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\275\342\200\214\342\200\275\342\200\215\342\200\271\342\200\213\342\200\264\342\200\214\342\200\265\342\200\215\342\200\276\342\200\213\342\200\274\342\200\214\342\200\264\342\200\215\342\200\274\342\200\213\342\200\265\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342""\200\215\342\200\254\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\242\342\200\215\342\200\244\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\200\242\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\274\342\200\214\342\201\276\342\200\215\342\200\261\342\200\213\342\200\243\342\200\214\342\200\242\342\200\215\342\201\274\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\200\245\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\270\342\200""\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\242\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\242\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\243\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\200\242\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\240\342\200\215\342\201\247\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\201\271\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\200\240\342\200\215\342\201\202\342\200\213\342\201\235\342\200\214\342\200\241\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\200\266\342\200\215\342\201\272\342\200\213\342\200\261\342\200\214\342\200\275\342\200\215\342\200\245\342\200\213""\342\200\265\342\200\214\342\200\241\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\240\342\200\215\342\201\236\342\200\213\342\201\237\342\200\214\342\200\266\342\200\215\342\201\272\342\200\213\342\200\261\342\200\214\342\200\275\342\200\215\342\200\245\342\200\213\342\200\264\342\200\214\342\200\241\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\266\342\200\215\342\201\272\342\200\213\342\200\261\342\200\214\342\200\275\342\200\215\342\200\245\342\200\213\342\200\273\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\260\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342""\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\200\253\342\200\214\342\201\240\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\272\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\256\342\200\215\342\201\270\342\200\213\342\201\276\342\200\214\342\201\253\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\270\342\200\213\342\201\276\342\200\214\342\201\253\342\200\215\342\201\224\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\273\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\266\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200""\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\273\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\244\342\200\213\342\200\243\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\201\273\342\200\214\342\200\243\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\243""\342\200\214\342\201\254\342\200\215\342\201\273\342\200\213\342\201\245\342\200\214\342\200\242\342\200\215\342\201\275\342\200\213\342\200\275\342\200\214\342\200\242\342\200\215\342\201\274\342\200\213\342\201\251\342\200\214\342\201\257\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\244\342\200\213\342\201\273\342\200\214\342\201\250\342\200\215\342\201\251\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\246\342\200\214\342\201\254\342\200\215\342\201\263\342\200\213\342\200\243\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\244\342\200\213\342\200\256\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\264\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342""\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\201\223\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\274\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\200\250\342\200\213\342\201\234\342\200\214\342\201\232\342\200\215\342\201\217\342\200\213\342\201\223\342\200\214\342\201\204\342\200\215\342\201\205\342\200\213\342\201\237\342\200\214\342\201\231\342\200\215\342\201\212\342\200\213\342\201\213\342\200\214\342\201\237\342\200\215\342\201\212\342\200\213\342\201\201\342\200\214\342\201\222\342\200\215\342\201\211\342\200\213\342\201\236\342\200\214\342\201\202\342\200\215\342\201\234\342\200\213\342\201\237\342\200\214\342\201\210\342\200\215\342\201\231\342\200\213\342\200\266\342\200\214\342\200\275\342\200\215\342\200\261\342\200\213\342\201\267\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\201\266\342\200\213\342\200\266\342\200\214\342\201\266\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\273\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\250\342\200\214\342\201\260\342\200""\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\255\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\201\245\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\264\342\200\215\342\201\224\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\260\342\200\213\342\201\261\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214""\342\200\267\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\257\342\200\214\342\201\241\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\275\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342""\201\277\342\200\214\342\201\276\342\200\215\342\201\224\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\254\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\200\272\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\242\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\223\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\252\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\272\342\200\215\342\201\224\342\200\213\342\201\277\342\200\214\342\201\270\342\200\215\342\201\254\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201""\270\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\247\342\200\215\342\201\252\342\200\213\342\201\266\342\200\214\342\201\242\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\241\342\200\213\342\201\255\342\200\214\342\201\267\342\200\215\342\201\244\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\260\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255""\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\274\342\200\214\342\201\264\342\200\215\342\200\243\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342""\200\214\342\201\271\342\200\215\342\200\245\342\200\213\342\201\271\342\200\214\342\201\275\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\201\266\342\200\215\342\200\254\342\200\213\342\201\264\342\200\214\342\200\240\342\200\215\342\201\274\342\200\213\342\201\251\342\200\214\342\201\257\342\200\215\342\200\246\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\240\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\267\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\201\227\342\200\214\342\201\253\342\200\215\342\200\254\342\200\213\342\201\267\342\200\214\342\201\246\342\200\215\342\201\266\342\200\213\342\200\261\342\200\214\342\201\266\342\200\215\342\201\275\342\200\213\342\201\261\342\200\214\342\200\252\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\201\246\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\273\342\200\215\342\200\253\342\200""\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\271\342\200\215\342\200\245\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\276\342\200\215\342\200\243\342\200\213\342\200\245\342\200\214\342\201\220\342\200\215\342\200\242\342\200\213\342\201\261\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215""\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\275\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\270\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\261\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342""\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\334\223\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\255\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\334\230\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342""\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\242\342\200\215\342\200\244\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\200\242\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\201\242\342\200\213\342\200\243\342\200\214\342\201\273\342\200\215\342\200\272\342\200\213\342\200\243\342\200\214\342\201\272\342\200\215\342\201\256\342\200""\213\342\201\256\342\200\214\342\200\242\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\243\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\245\342\200\214\342\201\257\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\265\342\200\214\342\200\242\342\200\215\342\200\251\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\265\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\200\252\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\264\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\276\342\200\214\342\200\271\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\241\342\200\214\342\201\242\342\200\215""\342\201\245\342\200\213\342\201\270\342\200\214\342\201\245\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\275\342\200\214\342\200\275\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\200\271\342\200\213\342\200\274\342\200\214\342\200\275\342\200\215\342\200\271\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\247\342\200\215\342\201\252\342\200\213\342\201\266\342\200\214\342\201\242\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\241\342\200\213\342\201\255\342\200\214\342\201\267\342\200\215\342\201\244\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\261\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342""\201\274\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\266\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200""\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\334\223\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\237\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\250\342\200\215\342\201\250\342\200\213\342\201\270\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\260\342\200\214\342\200\251\342\200\215\342\200\265\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342""\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\264\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\274\342\200\214\342\201\276\342\200\215\342\200\261\342\200\213\342\200\243\342\200\214\342\200\242\342\200\215\342\201\274\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\200\245\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\200\242\342\200""\215\342\201\252\342\200\213\342\201\274\342\200\214\342\201\244\342\200\215\342\200\244\342\200\213\342\201\272\342\200\214\342\200\274\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\244\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\264\342\200\215\342\201\224\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\244\342\200\213\342\200\256\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\264\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\262\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\200\252\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\273\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214""\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\273\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\246\342\200\214\342\201\254\342\200\215\342\201\261\342\200\213\342\201\243\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\252\342\200\213\342\201\266\342\200\214\342\201\242\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\266\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\262\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342""\201\276\342\200\214\342\201\250\342\200\215\342\201\272\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\264\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\273\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\201\265\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\260\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200""\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\334\223\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\232\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\262\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\341\203\210\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342""\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200""\214\342\201\226\342\200\215\356\234\253\342\200\213\342\201\221\342\200\214\342\200\255\342\200\215\342\201\234\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\200\255\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\273\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213""\342\201\242\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\243\342\200\215\342\201\244\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342""\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\341\203\216\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\216\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\243\342\200\215\342\201\244\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201""\250\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\275\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\274\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\201\265\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\243\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276""\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\265\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342\201\226\342\200\215\342\200\272\342\200\213\342\201\221\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\242\342""\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\266\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\262\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\245\342\200""\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\242\342\200\215\342\200\244\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\200\242\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\201\242\342\200\213\342\200\243\342\200\214\342\201\273\342\200\215\342\200\272\342\200\213\342\200\243\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\270\342\200\213\342\200\243\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\276\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\243\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214""\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\200\252\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\273\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\273\342\200\215\342\201\242\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342""\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\246\342\200\214\342\201\254\342\200\215\342\201\261\342\200\213\342\201\243\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\252\342\200\213\342\201\266\342\200\214\342\201\242\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\266\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\243\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\201\267\342\200\214\342\200\252\342\200\215\342\201\263\342\200\213\342\200\241\342\200\214\342\201\272\342\200\215\342\201\256\342\200\213\342\201\256\342\200\214\342\200\240\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\241\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201""\241\342\200\213\342\201\277\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\201\261\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\275\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\270\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\256\342\200\215\342\201\240\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222""\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\250\342\200\213\342\201\247\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\261\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\201\227\342""\200\214\342\200\274\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\216\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\217\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\334\236\342\200\215\342\201\220\342\200\213\342\200\243\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\201\262\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213""\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\245\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\276\342\200\215\342\200\243\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\246\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\277\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342""\200\253\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\273\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\251\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\273\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201""\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342\201\226\342\200\215\342\200\272\342\200\213\342\201\221\342\200\214\342\200\255\342\200\215\342\201\230\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\245\342\200\213\342\201\271\342\200\214\342\201\275\342\200\215\342\200\253\342\200\213\342\201\217\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\243\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\261\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\261\342\200\213\342\200\206""\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\342\200\274\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\236\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\243\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\334\234\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\273\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\256\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215""\342\201\247\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\242\342\200\215\342\200\244\342\200\213\342\201\273\342\200\214\342\201\272\342\200\215\342\201\274\342\200\213\342\200\242\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\240\342\200\215\342\200\244\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\201\242\342\200\213\342\200\243\342\200\214\342\201\273\342\200\215\342\200\272\342\200\213\342\200\243\342\200\214\342\201\272\342\200\215\342\201\256\342\200\213\342\201\256\342\200\214\342\200\242\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\242\342\200\215\342\201\274\342\200\213\342\201\251\342\200\214\342\201\257\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\241\342\200\213\342\201\255\342\200\214\342\201\265\342\200\215\342\200\244\342\200\213\342\200\256\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342""\201\264\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\201\222\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\273\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\200\257\342\200\214\342\201\235\342\200\215\342\201\234\342\200\213\342\201\210\342\200\214\342\201\222\342\200\215\342\201\202\342\200\213\342\201\202\342\200\214\342\201\236\342\200\215\342\201\237\342\200\213\342\201\215\342\200\214\342\201\212\342\200\215\342\201\231\342\200\213\342\201\215\342\200\214\342\201\200\342\200\215\342\201\224\342\200\213\342\201\216\342\200\214\342\201\237\342\200\215\342\201\204\342\200\213\342\201\233\342\200\214\342\201\236\342\200\215\342\201\216\342\200\213\342\201\236\342\200\214\342\200\267\342\200\215\342\200\273\342\200\213\342\200\266\342\200\214\342\201\266\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\246\342\200\213\342\201""\251\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\201\261\342\200\214\342\200\267\342\200\215\342\201\260\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\272\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\251\342\200\215\342\201\266\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\264\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\276\342\200\214\342\200\271\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\253\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\251\342\200\213\342\201\245\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\201\244\342\200\214\342\201\251\342\200\215\342\201\252""\342\200\213\342\201\265\342\200\214\342\201\222\342\200\215\342\201\262\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\266\342\200\215\342\201\266\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\240\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\200\274\342\200\215\342\200\273\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342""\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\262\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\200\277\342\200\215\342\200\273\342\200\213\342\200\274\342\200\214\342\200\277\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\257\342\200\214\342\201\241\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\275\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\253\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\223\342\200""\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\253\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\200\254\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\275\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\276\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\271\342\200\213\342\201\243\342\200\214\342\201\272\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\273\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213""\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\277\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\224\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\241\342\200\213\342\201\255\342\200\214\342\201\267\342\200\215\342\201\244\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\200\253\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\246\342\200\214\342\201\254\342\200\215\342\201\261\342\200\213\342\201\243\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\266\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342""\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\272\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201""\254\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\260\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245""\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\275\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\334\236\342\200\215\342\201\220\342\200\213\342\200\243\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\256\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\252\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\205\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\205\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215""\342\201\277\342\200\213\342\201\276\342\200\214\342\201\264\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\246\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\243\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\277\342\200\214\342\200\245\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\277\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342""\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200""\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\252\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\242\342\200\214\342\201\242\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\270""\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\222\342\200\215\342\201\257\342\200\213\342\201\255\342\200\214\342\201\271\342""\200\215\342\201\252\342\200\213\342\201\227\342\200\214\342\200\252\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\201\221\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\200\253\342\200\214\342\201\275\342\200\215\342\201\240\342\200\213\342\200\253\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\200\241\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200""\214\342\200\252\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\200\245\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\200\242\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213""\342\201\276\342\200\214\342\201\276\342\200\215\342\201\220\342\200\213\342\200\253\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\240\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\200\254\342\200\213\342\201\221\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\244\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\261\342\200\214\342\200\245\342\200\215\342\201\220\342\200\213\342\201\222\342\200\214\342\200\266\342\200\215\342""\201\226\342\200\213\342\200\247\342\200\214\342\200\244\342\200\215\342\200\254\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200""\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\275\342\200\214\342\201\270\342\200\215\342\201\244\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\250\342\200\213\342\201\244\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\274\342\200\214\342\200\245\342\200\215\342\200\272\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242""\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\254\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342""\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\222\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\245\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\253\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200""\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\226\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\262\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\342\200\274\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\230\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\201\205\342\200\214\342\201\211\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\251\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\223\342\200\214""\342\201\244\342\200\215\342\201\257\342\200\213\342\201\261\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\265\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\264\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\275\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\237\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\202\342\200\213\342""\201\210\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\201\266\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\262\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201""\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\221\342\200\214\342\201\226\342\200\215\342\200\272\342\200\213\342\201\221\342\200\214\342\200\255\342\200\215\342\201\212\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\243\342\200\215\342\201\244\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\200\255\342\200\214\342\200\255\342\200\215\342\201\231\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\254""\342\200\215\342\201\247\342\200\213\342\200\242\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\271\342\200\215\342\201\266\342\200\213\342\201\227\342\200\214\342\200\242\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\250\342\200\214\342\201\220\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\211\342\200\214\342\201\265\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342""\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\342\200\274\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\237\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\201\251\342\200\214\342\201\260\342\200\215\342\201\220\342\200\213\342\200\243\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\257\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\220\342\200\214\342\201\243\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\330\210\342\200\215\342\200\253\342\200\213\342\201\215\342\200\214\342\201\216\342\200\215\342\201\210\342\200\213\342\200\257\342\200\214\342\201\266\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\260\342\200\215\342\200\253\342\200\213\342\201\237\342\200\214\342\201\230\342\200\215\342\201\210\342\200\213\342\201\217\342\200\214\342\201\210\342\200\215\342""\201\230\342\200\213\342\201\237\342\200\214\342\201\213\342\200\215\342\201\236\342\200\213\342\201\200\342\200\214\342\201\201\342\200\215\342\201\222\342\200\213\342\200\254\342\200\214\342\201\216\342\200\215\342\201\231\342\200\213\342\201\211\342\200\214\342\201\214\342\200\215\342\201\237\342\200\213\342\201\211\342\200\214\342\201\211\342\200\215\342\200\253\342\200\213\330\211\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\342\201\221\342\200\215\342\201\245\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\250\342\200\213\342\200\254\342\200\214\342\201\235\342\200\215\342\201\231\342\200\213\342\201\211\342\200\214\342\201\200\342\200\215\342\201\202\342\200\213\342\201\231\342\200\214\342\201\200\342\200\215\342\200\253\342\200\213\342\201\234\342\200\214\342\201\214\342\200\215\342\201\205\342\200\213\342\201\211\342\200\214\342\201\201""\342\200\215\342\200\253\342\200\213\342\201\230\342\200\214\342\201\214\342\200\215\342\201\211\342\200\213\342\201\200\342\200\214\342\201\210\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\237\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\243\342\200\213\342\201\243\342\200\214\342\201\272\342\200\215\342\201\224\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\261\342\200\214\342\201\231\342\200\215\342\201\271\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342""\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\244\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\223\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\265\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\261\342\200\214\342\200\257\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\252\342\200\215\342\201\243\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\222\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\264\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\260\342\200\215\342\200\251\342\200\213\342\201\256\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\253\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\207\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\266\342\200\213\342\200\256\342\200\214\342\201\232\342\200\215\342\201\207\342\200\213\342\201\226\342\200\214\342\201\217\342\200\215\342\201\202\342\200\213\342\200\254\342\200\214\342\201\204\342\200\215\342\201\214\342\200\213\342\200\254\342\200\214\342\201\214\342\200\215\342\201\210\342\200\213\342\201\217\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\236\342\200\214\342\201\210\342\200\215\342\201\212\342\200\213\342\201\230\342\200\214\342\201\202\342\200\215\342\201\231\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\252\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\266\342\200\213\342\200\256\342\200\214\342\201\217\342\200\215\342\201\222\342\200\213\342\200\254\342\200\214\342\201\215\342\200\215\342\201\234\342\200\213\342\201\200\342\200\214\342\201\227\342\200\215\342\201\211\342\200\213\342\201\205\342\200\214\342\200\255\342\200\215\342\201\267\342\200\213\342\200\254\342\200\214\342\201\207\342\200\215""\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\214\342\200\214\342\201\235\342\200\215\342\201\212\342\200\213\342\201\236\342\200\214\342\201\204\342\200\215\342\201\237\342\200\213\342\201\204\342\200\214\342\201\204\342\200\215\342\201\205\342\200\213\342\201\213\342\200\214\342\201\236\342\200\215\342\200\251\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\256\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\241\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\200\256\342\200\214\342\201\204\342\200\215\342\201\205\342\200\213\342\201\212\342\200\214\342\201\202\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\264\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\260\342\200\215\342\200\251\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\251\342\200\213\342\201\276\342\200\214\342""\201\244\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\264\342\200\215\342\201\252\342\200\213\342\201\242\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\272\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\200\261\342\200\214\342\200\277\342\200\215\342\200\271\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\240\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\235\342\200\213\342\201\215\342\200\214\342\201\201\342\200\215\342\201\236\342\200\213\342\201\211\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\265\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\261\342\200\214\342\200\257\342\200\215\342\201\251\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\272\342\200\215\342\201\243\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200""\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\212\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\203\342\200\215\342\201\244\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\245\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253""\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\273\342\200\214\342\200\245\342\200\215\342\200\251\342\200\213\342\201\212\342\200\214\342\201\270\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\200\255\342\200\215\342\201\205\342\200\213\342\201\255\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\260\342\200\213\342\201\252\342\200\214\342\201\244\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\260\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\241\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\260\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342""\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\236\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\214\342\200\214\342\201\266\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\260\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\216\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200""\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\233\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\273\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\250\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\274\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\257\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\257\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\243\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\276\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\236\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\201\204\342\200\215\342\201\217\342\200\213\342\200\256\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213""\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\202\342\200\214\342\200\242\342\200\215\342\201\212\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\251\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\273\342\200\214\342\200\245\342\200\215\342\200\251\342\200\213\342\201\237\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\202\342\200\213\342\201\210\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\254\342\200\215\342""\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\205\342\200\213\342\200\243\342\200\214\342\201\214\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\256\342\200\214\342\201""\241\342\200\215\342\201\256\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\200\256\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\203\232\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\203\232\342\200\215\342\201\234\342\200\213\342\201\200\342\200\214\342\201\227\342\200\215\342\201\211\342\200\213\342\201\205\342\200\214\342\200\255\342\200\215\342\201\202\342\200\213\342\201\213\342\200\214\342\200\255\342\200\215\342\201\212\342\200\213\342\201\217\342\200\214\342\201\216\342\200\215\342\200\253\342\200\213\342\201\217\342\200\214\342\201\237\342\200\215\342\201\216\342\200\213\342\201\215\342\200\214\342\201\231\342\200\215\342\201\204\342\200\213\342\201\236\342\200\214\342\203\232\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\200\240\342\200\215\342\203\234\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215)\342\200\213\342\200\254\342\200\214""\342\201\214\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\202\342\200\214\342\201\242\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\261\342\200\214\342\200\207\342\200\215)\342\200\213\342\200\254\342\200\214\342\201\203\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\253\342\200\215\342\201\242\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\266\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\201\247\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\266\342\200\213\342\200\206\342\200\214/\342\200\215\342\200\253\342\200\213\342\201\231\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342""\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\214\342\200\214\342\201\266\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\260\342\200\215\342\200\201\342\200\213.\342\200\214\342\200\255\342\200\215\342\201\216\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\266\342\200\213\342\200\206\342\200\214/\342\200\215\342\200\253\342\200\213\342\201\234\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\272\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\274\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\201\257\342\200\213\342\201\261\342\200\214\342\200\207\342\200\215)\342\200\213\342\200\254\342\200\214\342\201\230\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\201\205\342\200\214\342\201\211\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200""\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\205\342\200\213\342\200\243\342\200\214\342\201\214\342\200\215\342\200\254\342\200\213\342\201\261\342\200\214\342\200\207\342\200\215)\342\200\213\342\200\254\342\200\214\342\201\236\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\205\342\200\214\342\201\211\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\201\224\342\200\213\342\201\272\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222""\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\201\222\342\200\215\342\201\275\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\276\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\201\205\342\200\213\342\200\243\342\200\214\342\201\214\342\200\215\342\200\254\342\200\213\342\201\261\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\203\233\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\203\233\342\200\214\342\201\232\342\200\215\342\201\207\342\200\213\342\201\226\342\200\214\342\201\217\342\200\215\342\201\202\342\200\213\342\200\254\342\200\214\342\201\204\342\200\215\342\201\214\342\200\213\342\200\254\342\200\214\342\201\214\342\200\215\342\201\210\342\200\213\342\201\217\342\200\214\342\200\255\342\200\215\342\201\210\342\200\213\342\201\236\342\200\214\342\201\210\342\200\215\342\201\212\342\200\213\342\201\230\342\200\214\342\201\202\342\200\215\342\201\231\342\200\213\342\203\233\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\200\240\342\200\215\342\200\246\342\200\213\342\200\241\342\200\214\342\203\232\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\201\217\342\200\215\342\201\222\342\200\213\342\200\254\342\200\214\342\201\215\342\200\215\342\201\234\342\200\213\342\201\200\342\200\214\342\201\227\342\200\215\342\201\211\342\200\213\342\201\205\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\261\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\201\342\200\213\342\201\203\342\200\214\342\201\204\342\200\215\342\201\205\342\200\213\342\200\254\342""\200\214\342\201\215\342\200\215\342\201\233\342\200\213\342\201\215\342\200\214\342\201\237\342\200\215\342\201\202\342\200\213\342\201\230\342\200\214\342\201\205\342\200\215\342\201\202\342\200\213\342\201\202\342\200\214\342\201\212\342\200\215\342\201\230\342\200\213\342\200\206\342\200\214\342\200\257\342\200\215\342\200\251\342\200\213\342\200\256\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\201\254\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\246\342\200\213\342\201\223\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\252\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200""\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\200\246\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\274\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\231\342\200\215\342\201\271\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215""\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\265\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\263\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\277\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\201\252\342\200\214\342\200\257\342\200\215\342\201\220\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\226\342\200\213\342\201\227\342\200\214\341\203\216\342\200\215\342\201\226\342\200\213\342\200\254\342\200\214\342\201\213\342\200\215\342\201\236\342\200\213\342\201\217\342\200\214\342""\201\206\342\200\215\342\201\216\342\200\213\342\201\210\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\201\256\342\200\213\342\201\261\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\251\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\213\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\262\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\223\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\224\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\243\342\200\213\342\201""\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\244\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\252\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\201\222\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\200\243\342\200\213\342\200\277\342\200\214\342\200\244\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\213\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253""\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\274\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\243\342""\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\220\342\200\213\342\200\274\342\200\214\342\201\220\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\220\342\200\213\342\200\275\342\200\214\342\201\220\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\242\342\200""\214\342\200\255\342\200\215\342\201\215\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\273\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\201\245\342\200\214\342\201\256\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213""\342\201\223\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\210\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\213\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\224\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\263\342\200\213\342\200\244\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342""\201\245\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\200\244\342\200\214\342\201\277\342\200\215\342\200\254\342\200\213\342\201\220\342\200\214\342\201\257\342\200\215\342\201\227\342\200\213\342\201\250\342\200\214\342\201\266\342\200\215\342\200\275\342\200\213\342\201\261\342\200\214\342\201\221\342\200\215\342\201\251\342\200\213\342\200\253\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201""\253\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\200\245\342\200\213\342\201\253\342\200\214\342\201\277\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\275\342\200\215\342\200\243\342\200\213\342\200\274\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\202\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\251\342\200\214\342\200\207\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\270""\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\245\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\237\342\200\213\342\201\276\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\271\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342""\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\271\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200""\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\342\201\225\342\200\215\342\200\253\342\200\213\342\201\233\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\200\274\342\200\215\342\200\273\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\213\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\200\254\342\200\214\342\201\211\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\360\235\230\211\342\200\213\360\235\245\214\342\200\214\342\201\266\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\254\342\200\215\342\201\250\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\260\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\200\243\342\200\215\342\201\220\342\200\213\342\200\243\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342""\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\276\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\201\250\342\200\215\342\201\273\342\200\213\342\200\244\342\200\214\342\200\274\342\200\215\342\200\273\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\250\342\200""\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\200\242\342\200\214\342\201\275\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\227\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\240\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\201\265\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\242\342\200\215\342\201\274\342\200\213\342\201\221\342\200\214\342\201\225\342\200\215\342\200\253\342\200\213\342\201\233\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\200\276\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\253\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\252\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\257\342\200\215\342\201\256\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\243\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\271\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\360\235\230\211\342\200\213\360\235\245\214\342\200\214\342\200\252\342\200\215\342\200\253\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\255\342\200\214\342\201\256\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342""\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\250\342\200\213\342\201\243\342\200\214\342\201\270\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\261\342\200\214\342\200\243\342\200\215\342\200\245\342\200\213\342\200\242\342\200\214\342\201\226\342\200\215\342\200\244\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\247\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\201\262\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\247\342\200\213\342\201\243\342\200\214\342\201\272\342\200\215\342\201\226\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\275\342\200\215\342\200\243\342\200\213\342\200\271\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\201\257\342\200""\214\342\201\241\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\211\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\201\214\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\223\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\222\342\200\215\342\200\243\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\244\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\241\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\274\342\200\214\342\201\276\342\200\215\342\200\261\342\200\213\342\200\243\342\200\214\342\200\242\342\200\215\342\201\252\342\200\213\342\201\274\342\200\214\342\201\244\342\200\215\342\200\245\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\243\342\200\215\342\201\277\342\200\213""\342\201\241\342\200\214\342\200\257\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\210\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\241\342\200\214\342\201\231\342\200\215\342\201\262\342\200\213\342\201\274\342\200\214\342\201\250\342\200\215\342\200\251\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\255\342\200\214\342\201\275\342\200\215\342\201\273\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\244\342\200\213\342\201\246\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342""\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\257\342\200\215\342\201\236\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\241\342\200\214\342\201\214\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\200\256\342\200\214\342\200\267\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\200\342\200\215\342\201\244\342\200\213\342\201\266\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\240\342\200\214\342\201\254\342\200\215\342\200\244\342\200\213\342\200\271\342\200\214\342\200\243\342\200\215\342\200\273\342\200\213\342\200\254\342\200\214\342\200\245\342\200\215\342\201\234\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\201\257\342\200\213\342\201\243\342\200\214\342\201\272\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\203\342\200\215\342\201\237\342\200\213\342\200\254\342\200\214\342\200\274\342\200\215\342\200\273\342\200\213\342\200\242\342\200\214\342\200\275\342\200\215\342\200\260\342\200\213\342\200\254\342\200\214\342\201\232\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\273\342\200\215\342\200\277\342\200\213\342\200\267\342\200\214\342\200\255\342\200\215\342\201\263\342\200\213\342\200\272\342\200\214\342\200\271\342\200\215\342\200\242\342\200\213\342\200\256\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\260\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200""\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\200\254\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\245\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\245\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\275\342\200\215\342\200\245\342\200\213\342\201\217\342\200\214\342\201\241\342\200\215\342\201\242\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\237\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\261\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\244""\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\201\277\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\201\262\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\262\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\200\253\342\200\213\342\201\273\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\244\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\266\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342""\200\213\342\200\242\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\201\260\342\200\215\342\200\244\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\277\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\274\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\245\342\200\213\342\201\246\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200""\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\226\342\200\215\342\200\251\342\200\213\342\201\244\342\200\214\342\201\264\342\200\215\342\201\257\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\200\261\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\256\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\256\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\274\342\200\214\342\201\220\342\200\215\342\201\220\342\200\213\342\200\256\342\200\214\342\201\251\342\200\215\342\201\244\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\257\342\200\215\342\201\226\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\242\342\200\213\342\201\240\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\200\254\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\201\276\342\200\214""\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\251\342\200\213\342\201\275\342\200\214\342\201\272\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\201\262\342\200\213\342\201\271\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\250\342\200\214\342\201\253\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\247\342\200\215\342\201\240\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\263\342\200\213\342\201\257\342\200\214\342\201\273\342\200\215\342\201\251\342\200\213\342\201\242\342\200\214\342\201\240\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\201\223\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\272\342\200\213\342\200\276\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\200\246\342\200\215\342\200\253\342\200\213\342\200\256\342\200\214\342\201\215\342\200\215\342\200\251\342\200\213\342\200\254\342\200\214\342\200\246\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342""\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\273\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\252\342\200\215\342\200\254\342\200\213\342\200\242\342\200\214\342\201\247\342\200\215\342\201\244\342\200\213\342\201\245\342\200\214\342\201\243\342\200\215\342\200\243\342\200\213\342\201\276\342\200\214\342\201\254\342\200\215\342\201\245\342\200\213\342\201\250\342\200\214\342\201\242\342\200\215\342\201\246\342\200\213\342\200\242\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\243\342\200\214\342\201\244\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\251\342\200\213\342\201\275\342\200\214\342\201\272\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\271\342\200\215\342\201\262\342\200\213\342\201\271\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\250\342\200\214\342\201\253\342\200\215\342\201\254\342\200\213\342\201\244\342\200\214\342\201\247\342\200\215\342\201\240\342\200\213\342\201\240\342\200\214\342\201\267\342\200\215\342\201\263\342\200\213\342\201\257\342\200\214\342\201\273\342\200\215\342\201\251\342\200\213\342\201\242\342\200\214\342\201\240\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\201\255\342\200\213\342\201\243\342\200\214\342\201\277\342\200\215\342\200\253\342\200\213\342\201\223\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201""\271\342\200\213\342\201\255\342\200\214\342\201\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\200\245\342\200\215\342\200\272\342\200\213\342\200\276\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\265\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\260\342\200\213\342\200\256\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\250\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\200\251\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\272\342\200\215\342\201\244\342\200\213\342\201\276\342\200\214\342\201\251\342\200\215\342\200\251\342\200\213\342\200\266\342\200\214\342\200\255""\342\200\215\342\201\273\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\273\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\250\342\200\214\342\201\260\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\200\254\342\200\214\342\201\272\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\201\245\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\243\342\200\215\342\201\273\342\200\213\342\201\243\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\201\261\342\200\214\342\200\242\342\200\215\342\201\252\342\200\213\342\201\257\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\271\342\200\214\342\201\243\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\247\342\200\215\342\201\270\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\266\342\200\213\342\201\274\342\200\214\342\201\254\342\200\215\342\201\262\342\200\213\342\201\240\342""\200\214\342\201\242\342\200\215\342\201\252\342\200\213\342\201\250\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\273\342\200\213\342\200\242\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\200\252\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\271\342\200\213\342\200\274\342\200\214\342\200\274\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200""\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\242\342\200\214\342\200\255\342\200\215\342\201\215\342\200\213\342\201\255\342\200\214\342\201\241\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\200\241\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\245\342\200\213\342\201\274\342\200\214\342\201\242\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\266\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\201\260\342\200\215\342\200\244\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\201\241\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215""\342\201\245\342\200\213\342\200\261\342\200\214\342\201\275\342\200\215\342\201\252\342\200\213\342\201\265\342\200\214\342\201\241\342\200\215\342\201\244\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\245\342\200\214\342\201\253\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\200\243\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\200\255\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\276\342\200\214\342\200\275\342\200\215\342\200\273\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342""\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\213\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\201\224\342\200\213\342\201\250\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\274\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\245\342\200\213\342\201\246\342\200\214\342\201\276\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200""\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\241\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\251\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\254\342\200\215\342\200\245\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\200\257\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\211\342\200\214\342\201\265\342\200\215\342\201\250\342\200\213\342\201\251\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\200\261""\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\201\276\342\200\213\342\201\276\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\201\212\342\200\214\342\201\254\342\200\215\342\201\247\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\213\342\200\215\342\201\252\342\200\213\342\201\240\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\262\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\200\253\342\200\213\342\201\250\342\200\214\342\201\250\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\263\342\200\213\342\200\244\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\244\342\200\213\342\201\247\342\200\214\342\201\250\342\200\215\342\201\245\342\200\213\342\200\266\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\277\342\200\215\342\200\242\342\200\213\342\200\266\342\200\214\342\200\207\342""\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\200\254\342\200\214\342\201\272\342\200\215\342\201\242\342\200\213\342\201\270\342\200\214\342\201\245\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\244\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\274\342\200\214\342\200\243\342\200\215\342\201\210\342\200\213\342\201\240\342\200\214\342\201\244\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\230\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\201\245\342\200\215\342\201\256\342\200\213\342\201\255\342\200\214\342\201\251\342\200\215\342\201\256\342\200\213\342\201\276\342\200\214\342\201\276\342\200\215\342\200\266\342\200\213\342\201\267\342\200\214\342\200\247\342\200\215\342\200\241\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\247\342\200\213\342\201\252\342\200\214\342\200\243\342\200\215\342\201\243\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\257\342\200\213\342\201\251\342\200\214\342\201\277\342\200\215\342\201\270\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\215\342\200\214\342\201\270\342\200\215\342\201\277\342\200\213\342\201\244\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\201\245\342\200\214\342\201\267\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\257\342\200\215\342\200\261\342\200\213\342\200\254\342\200""\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\216\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\201\266\342\200\215\342\201\277\342\200\213\342\201\243\342\200\214\342\201\246\342\200\215\342\201\256\342\200\213\342\201\242\342\200\214\342\201\260\342\200\215\342\200\251\342\200\213\342\201\261\342\200\214\342\200\244\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\201\277\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\254\342\200\215\342\201\263\342\200\213\342\201\223\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\200\275\342\200\214\342\200\270\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\240\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213""\342\200\261\342\200\214\342\200\255\342\200\215\342\200\273\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\244\342\200\214\342\201\244\342\200\215\342\201\247\342\200\213\342\201\251\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\200\267\342\200\213\342\200\254\342\200\214\342\201\240\342\200\215\342\201\252\342\200\213\342\201\264\342\200\214\342\201\222\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\275\342\200\215\342\201\277\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\246\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342""\201\270\342\200\213\342\200\254\342\200\214\342\200\246\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\274\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\274\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\201\265\342\200\214\342\201\243\342\200\215\342\201\250\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\241\342\200\215\342\201\256\342\200\213\342\201\251\342\200\214\342\201\275\342\200\215\342\200\243\342\200\213\342\200\271\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\271\342\200\215\342\201\271\342\200\213\342\201\265\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200""\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\200\255\342\200\215\342\201\274\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\201\243\342\200\213\342\200\254\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\276\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\245\342\200\213\342\201\253\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\200\244\342\200\214\342\201\253\342\200\215\342\200\251\342\200\213\342\201\267\342\200\214\342\201\276\342\200\215\342\201\256\342\200\213\342\201\240\342\200\214\342\201\253\342\200\215\342\200\245\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\247\342\200\213\342\201\261\342\200\214\342\200\242\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\257\342\200\215\342\200\242\342\200\213\342\200\254\342\200\214\342\201\254\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254""\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\275\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\254\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\277\342\200\215\342\200\273\342\200\213\342\200\274\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\244\342\200\213\342\201\242\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\270\342\200\215\342\201\256\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342""\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\256\342\200\214\342\201\242\342\200\215\342\201\263\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\274\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\257\342\200\215\342\201\244\342\200\213\342\201\264\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\200\256\342\200\214\342\201\245\342\200\215\342\201\262\342\200\213\342\201\250\342\200\214\342\201\277\342\200\215\342\201\252\342\200\213\342\200\266\342\200\214\342\201\240\342\200\215\342\201\256\342\200\213\342\201\241\342\200\214\342\201\257\342\200""\215\342\201\256\342\200\213\342\201\276\342\200\214\342\200\257\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\226\342\200\215\342\201\226\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\241\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\277\342\200\214""\342\201\252\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\246\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\255\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\277\342\200\214\342\201\226\342\200\215\342\200\273\342\200\213\342\201\221\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\276\342\200\215\342\201\254\342\200\213\342\201\223\342\200\214\342\201\244\342\200\215\342\201\257\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\240\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\240\342\200\215\342\201\270\342\200\213\342\201\253\342\200\214\342\201\226\342\200\215\342\200\251\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\251\342\200\213\342\201\221\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342""\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\276\342\200\215\342\201\262\342\200\213\342\201\242\342\200\214\342\201\256\342\200\215\342\200\253\342\200\213\342\201\273\342\200\214\342\201\244\342\200\215\342\201\277\342\200\213\342\201\244\342\200\214\342\200\255\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\201\270\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\242\342\200\214\342\201\252\342\200\215\342\201\256\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\201\255\342\200\213\342\200\256\342\200\214\342\201\266\342\200\215\342\201\270\342\200\213\342\201\251\342\200\214\342\201\241\342\200\215\342\201\255\342\200\213\342\200\242\342\200\214\342\201\270\342\200\215\342\201\271\342\200\213\342\201\240\342\200\214\342\201\260\342\200\215\342\200\244\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\270\342\200\213\342\201\277\342\200\214\342\201\254\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\276\342\200\215\342\200\244\342\200\213\342\201\267\342\200\214\342\201\240\342\200\215\342\201\270\342\200\213\342\201\253\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\201\260\342\200\215\342\200\251\342\200\213\342\200\245\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\200\255\342\200\215\342\201\271\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200""\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\255\342\200\213\342\200\254\342\200\214\342\201\277\342\200\215\342\200\245\342\200\213\342\201\277\342\200\214\342\201\271\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\270\342\200\215\342\201\270\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\200\277\342\200\215\342\200\273\342\200\213\342\200\274\342\200\214\342\200\267\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\241\342\200\214\342\201\276""\342\200\215\342\201\254\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\255\342\200\214\342\201\272\342\200\215\342\201\252\342\200\213\342\201\245\342\200\214\342\201\271\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\200\243\342\200\215\342\201\241\342\200\213\342\201\277\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\240\342\200\215\342\201\270\342\200\213\342\201\253\342\200\214\342\200\243\342\200\215\342\201\254\342\200\213\342\201\251\342\200\214\342\201\271\342\200\215\342\200\243\342\200\213\342\200\256\342\200\214\342\201\271\342\200\215\342\201\256\342\200\213\342\201\264\342\200\214\342\201\271\342\200\215\342\200\251\342\200\213\342\200\240\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\200\256\342\200\214\342\200\244\342\200\215\342\200\201\342\200\213\342\200\254\342""\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\201\250\342\200\215\342\201\263\342\200\213\342\201\257\342\200\214\342\201\250\342\200\215\342\201\273\342\200\213\342\201\270\342\200\214\342\200\255\342\200\215\342\201\216\342\200\213\342\201\264\342\200\214\342\201\256\342\200\215\342\201\256\342\200\213\342\201\274\342\200\214\342\201\271\342\200\215\342\201\242\342\200\213\342\201\243\342\200\214\342\201\243\342\200\215\342\200\261\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\201\270\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\271\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\277\342\200\213\342\201\271\342\200\214\342\201\277\342\200\215\342\201\245\342\200\213\342\200\254\342\200\214\342\201\203\342\200\215\342\201\244\342\200""\213\342\201\242\342\200\214\342\201\250\342\200\215\342\200\201\342\200\213\342\200\206\342\200\214\342\200\207\342\200\215\342\201\242\342\200\213\342\201\252\342\200\214\342\200\255\342\200\215\342\201\224\342\200\213\342\201\223\342\200\214\342\201\243\342\200\215\342\201\252\342\200\213\342\201\241\342\200\214\342\201\250\342\200\215\342\201\224\342\200\213\342\201\223\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\200\251\342\200\213\342\201\223\342\200\214\342\201\222\342\200\215\342\201\246\342\200\213\342\201\255\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\223\342\200\214\342\201\222\342\200\215\342\200\251\342\200\213\342\200\266\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\253\342\200\213\342\200\261\342\200\214\342\200\255\342\200\215\342\201\242\342\200\213\342\201\242\342\200\214\342\201\275\342\200\215\342\201\276\342\200\213\342\201\270\342\200\214\342\200\245\342\200\215\342\200\254\342\200\213\342\201\216\342\200\214\342\201\202\342\200\215\342\201\237\342\200\213\342\200\254\342\200\214\342\201\231\342\200\215\342\201\204\342\200\213\342\201\207\342\200\214\342\201\210\342\200\215\342\201\205\342\200\213\342\200\254\342\200\214\342\200\267\342\200\215\342\200\254\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\201\257\342\200\214\342\201\245\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\222\342\200\215\342\201\242\342\200\213\342\201\250\342\200\214\342\200\255\342\200\215\342\200\266\342\200\213\342\200\254\342\200\214\342\201\244\342\200\215\342\201\245\342\200\213\342\201\274\342\200\214\342\201\270\342\200\215""\342\201\277\342\200\213\342\200\244\342\200\214\342\200\252\342\200\215\342\201\236\342\200\213\342\201\237\342\200\214\342\201\210\342\200\215\342\201\231\342\200\213\342\200\254\342\200\214\342\201\204\342\200\215\342\201\217\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\261\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\254\342\200\213\342\200\245\342\200\214\342\200\207\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\254\342\200\214\342\200\260\342\200\215\342\200\253\342\200\213\342\201\233\342\200\214\342\201\241\342\200\215\342\201\261\342\200\213\342\201\256\342\200\214\342\201\244\342\200\215\342\200\243\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\240\342\200\213\342\201\251\342\200\214\342\201\243\342\200\215\342\200\247\342\200\213\342\200\254\342\200\214\342\201\256\342\200\215\342\201\243\342\200\213\342\201\255\342\200\214\342\201\271\342\200\215\342\201\224\342\200\213\342\201\245\342\200\214\342\201\251\342\200\215\342\200\242\342\200\213\342\200\206\342\200\214\342\200\255\342\200\215\342\200\253\342\200\213\342\200\254\342\200\214\342\200\255\342\200\215\342\201\252\342\200\213\342\201\277\342\200\214\342\201\264\342\200\215\342\201\245\342\200\213\342\201\257\342\200\214\342\201\244\342\200\215\342\201\244\342\200\213\342\200\242\342\200\214\342\201\277\342\200\215\342\201\276\342\200\213\342\201\242\342\200\214\342\200\245\342\200\215\342\201\250\342\200\213\342\201\276\342\200\214\342\201\250\342\200\215\342\201\252\342\200\213\342\201\270\342\200\214\342\201\242\342\200\215\342\201\271\342\200\213\342\200\242\342\200\214\342""\201\276\342\200\215\342\201\277\342\200\213\342\201\255\342\200\214\342\201\277\342\200\215\342\201\277\342\200\213\342\201\223\342\200\214\342\201\256\342\200\215\342\201\271\342\200\213\342\201\251\342\200\214\342\201\254\342\200\215\342\201\277\342\200\213\342\201\245\342\200\214\342\201\242\342\200\215\342\201\245\342\200\213\342\200\244\342\200\214\342\200\244\342\200\215\342\200\242\342\200\213?disableenablegcisenabled<wlzbi>wlzbi_temp/hdcs.pyEncrypted_CodeLayers__Pyx_PyDict_NextRefasyncio.coroutines__builtins__c__class_getitem__cline_in_tracebackclosecompiledata_with_keydecoded_codeencrypted_textenumerateexecfilename__func__genexprhdcsi_is_coroutineitemskey__main__mode__module____name__nextpop__qualname__send__set_name__setdefault__test__throwvaluevalueswlzbi_deobfuscatewlzbi_deobfuscate.<locals>.genexpr\200\001\330\004\025\220R\220u\230N\250!\330\004\n\210\"\210E\220\036\230q\330\004\013\2102\210U\220$\220a\250!\220a\230q";
    PyObject *data = NULL;
    CYTHON_UNUSED_VAR(__Pyx_DecompressString);
    #endif
    PyObject **stringtab = __pyx_mstate->__pyx_string_tab;
    Py_ssize_t pos = 0;
    for (int i = 0; i < 48; i++) {
      Py_ssize_t bytes_length = index[i].length;
      PyObject *string = PyUnicode_DecodeUTF8(bytes + pos, bytes_length, NULL);
      if (likely(string) && i >= 9) PyUnicode_InternInPlace(&string);
      if (unlikely(!string)) {
        Py_XDECREF(data);
        __PYX_ERR(0, 2, __pyx_L1_error)
      }
      stringtab[i] = string;
      pos += bytes_length;
    }
    for (int i = 48; i < 52; i++) {
      Py_ssize_t bytes_length = index[i].length;
      PyObject *string = PyBytes_FromStringAndSize(bytes + pos, bytes_length);
      stringtab[i] = string;
      pos += bytes_length;
      if (unlikely(!string)) {
        Py_XDECREF(data);
        __PYX_ERR(0, 2, __pyx_L1_error)
      }
    }
    Py_XDECREF(data);
    for (Py_ssize_t i = 0; i < 52; i++) {
      if (unlikely(PyObject_Hash(stringtab[i]) == -1)) {
        __PYX_ERR(0, 2, __pyx_L1_error)
      }
    }
    #if CYTHON_IMMORTAL_CONSTANTS
    {
      PyObject **table = stringtab + 48;
      for (Py_ssize_t i=0; i<4; ++i) {
        #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
        Py_SET_REFCNT(table[i], _Py_IMMORTAL_REFCNT_LOCAL);
        #else
        Py_SET_REFCNT(table[i], _Py_IMMORTAL_INITIAL_REFCNT);
        #endif
      }
    }
    #endif
  }
  {
    PyObject **numbertab = __pyx_mstate->__pyx_number_tab + 0;
    int8_t const cint_constants_1[] = {0,1,2,3};
    for (int i = 0; i < 4; i++) {
      numbertab[i] = PyLong_FromLong(cint_constants_1[i - 0]);
      if (unlikely(!numbertab[i])) __PYX_ERR(0, 2, __pyx_L1_error)
    }
  }
  #if CYTHON_IMMORTAL_CONSTANTS
  {
    PyObject **table = __pyx_mstate->__pyx_number_tab;
    for (Py_ssize_t i=0; i<4; ++i) {
      #if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
      Py_SET_REFCNT(table[i], _Py_IMMORTAL_REFCNT_LOCAL);
      #else
      Py_SET_REFCNT(table[i], _Py_IMMORTAL_INITIAL_REFCNT);
      #endif
    }
  }
  #endif
  return 0;
  __pyx_L1_error:;
  return -1;
}

typedef struct {
    unsigned int argcount : 2;
    unsigned int num_posonly_args : 1;
    unsigned int num_kwonly_args : 1;
    unsigned int nlocals : 4;
    unsigned int flags : 10;
    unsigned int first_line : 3;
} __Pyx_PyCode_New_function_description;

static PyObject* __Pyx_PyCode_New(
        const __Pyx_PyCode_New_function_description descr,
        PyObject * const *varnames,
        PyObject *filename,
        PyObject *funcname,
        PyObject *line_table,
        PyObject *tuple_dedup_map
);


static int __Pyx_CreateCodeObjects(__pyx_mstatetype *__pyx_mstate) {
  PyObject* tuple_dedup_map = PyDict_New();
  if (unlikely(!tuple_dedup_map)) return -1;
  {
    const __Pyx_PyCode_New_function_description descr = {0, 0, 0, 1, (unsigned int)(CO_OPTIMIZED|CO_NEWLOCALS|CO_GENERATOR), 3};
    PyObject* const varnames[] = {__pyx_mstate->__pyx_n_u_i};
    __pyx_mstate_global->__pyx_codeobj_tab[0] = __Pyx_PyCode_New(descr, varnames, __pyx_mstate->__pyx_kp_u_wlzbi_temp_hdcs_py, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_kp_b_iso88591__4, tuple_dedup_map); if (unlikely(!__pyx_mstate_global->__pyx_codeobj_tab[0])) goto bad;
  }
  {
    const __Pyx_PyCode_New_function_description descr = {0, 0, 0, 1, (unsigned int)(CO_OPTIMIZED|CO_NEWLOCALS|CO_GENERATOR), 4};
    PyObject* const varnames[] = {__pyx_mstate->__pyx_n_u_i};
    __pyx_mstate_global->__pyx_codeobj_tab[1] = __Pyx_PyCode_New(descr, varnames, __pyx_mstate->__pyx_kp_u_wlzbi_temp_hdcs_py, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_kp_b_iso88591_q, tuple_dedup_map); if (unlikely(!__pyx_mstate_global->__pyx_codeobj_tab[1])) goto bad;
  }
  {
    const __Pyx_PyCode_New_function_description descr = {0, 0, 0, 2, (unsigned int)(CO_OPTIMIZED|CO_NEWLOCALS|CO_GENERATOR), 5};
    PyObject* const varnames[] = {__pyx_mstate->__pyx_n_u_i, __pyx_mstate->__pyx_n_u_c};
    __pyx_mstate_global->__pyx_codeobj_tab[2] = __Pyx_PyCode_New(descr, varnames, __pyx_mstate->__pyx_kp_u_wlzbi_temp_hdcs_py, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_kp_b_iso88591_a, tuple_dedup_map); if (unlikely(!__pyx_mstate_global->__pyx_codeobj_tab[2])) goto bad;
  }
  {
    const __Pyx_PyCode_New_function_description descr = {2, 0, 0, 8, (unsigned int)(CO_OPTIMIZED|CO_NEWLOCALS), 2};
    PyObject* const varnames[] = {__pyx_mstate->__pyx_n_u_data_with_key, __pyx_mstate->__pyx_n_u_Layers, __pyx_mstate->__pyx_n_u_encrypted_text, __pyx_mstate->__pyx_n_u_key, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_n_u_genexpr, __pyx_mstate->__pyx_n_u_genexpr};
    __pyx_mstate_global->__pyx_codeobj_tab[3] = __Pyx_PyCode_New(descr, varnames, __pyx_mstate->__pyx_kp_u_wlzbi_temp_hdcs_py, __pyx_mstate->__pyx_n_u_wlzbi_deobfuscate, __pyx_mstate->__pyx_kp_b_iso88591_RuN_E_q_2U_a, tuple_dedup_map); if (unlikely(!__pyx_mstate_global->__pyx_codeobj_tab[3])) goto bad;
  }
  Py_DECREF(tuple_dedup_map);
  return 0;
  bad:
  Py_DECREF(tuple_dedup_map);
  return -1;
}


static int __Pyx_InitGlobals(void) {
  
  if (likely(__Pyx_init_co_variables() == 0)); else
  
  if (unlikely(PyErr_Occurred())) __PYX_ERR(0, 2, __pyx_L1_error)

  
  if (likely(__pyx_CommonTypesMetaclass_init(__pyx_m) == 0)); else
  
  if (unlikely(PyErr_Occurred())) __PYX_ERR(0, 2, __pyx_L1_error)

  
  #if CYTHON_COMPILING_IN_LIMITED_API
  {
      PyObject *typesModule=NULL;
      typesModule = PyImport_ImportModule("types");
      if (typesModule) {
          __pyx_mstate_global->__Pyx_CachedMethodType = PyObject_GetAttrString(typesModule, "MethodType");
          Py_DECREF(typesModule);
      }
  } // error handling follows
  #endif
  
  if (unlikely(PyErr_Occurred())) __PYX_ERR(0, 2, __pyx_L1_error)

  
  if (likely(__pyx_CyFunction_init(__pyx_m) == 0)); else
  
  if (unlikely(PyErr_Occurred())) __PYX_ERR(0, 2, __pyx_L1_error)

  
  if (likely(__pyx_Generator_init(__pyx_m) == 0)); else
  
  if (unlikely(PyErr_Occurred())) __PYX_ERR(0, 2, __pyx_L1_error)

  return 0;
  __pyx_L1_error:;
  return -1;
}




#ifdef _MSC_VER
#pragma warning( push )

#pragma warning( disable : 4127 )
#endif







#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    int result;
    PyObject *exc_type;
#if PY_VERSION_HEX >= 0x030C00A6
    PyObject *current_exception = tstate->current_exception;
    if (unlikely(!current_exception)) return 0;
    exc_type = (PyObject*) Py_TYPE(current_exception);
    if (exc_type == err) return 1;
#else
    exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
#endif
    #if CYTHON_AVOID_BORROWED_REFS
    Py_INCREF(exc_type);
    #endif
    if (unlikely(PyTuple_Check(err))) {
        result = __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    } else {
        result = __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
    }
    #if CYTHON_AVOID_BORROWED_REFS
    Py_DECREF(exc_type);
    #endif
    return result;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
#if PY_VERSION_HEX >= 0x030C00A6
    PyObject *tmp_value;
    assert(type == NULL || (value != NULL && type == (PyObject*) Py_TYPE(value)));
    if (value) {
        #if CYTHON_COMPILING_IN_CPYTHON
        if (unlikely(((PyBaseExceptionObject*) value)->traceback != tb))
        #endif
            PyException_SetTraceback(value, tb);
    }
    tmp_value = tstate->current_exception;
    tstate->current_exception = value;
    Py_XDECREF(tmp_value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
#else
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#endif
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
#if PY_VERSION_HEX >= 0x030C00A6
    PyObject* exc_value;
    exc_value = tstate->current_exception;
    tstate->current_exception = 0;
    *value = exc_value;
    *type = NULL;
    *tb = NULL;
    if (exc_value) {
        *type = (PyObject*) Py_TYPE(exc_value);
        Py_INCREF(*type);
        #if CYTHON_COMPILING_IN_CPYTHON
        *tb = ((PyBaseExceptionObject*) exc_value)->traceback;
        Py_XINCREF(*tb);
        #else
        *tb = PyException_GetTraceback(exc_value);
        #endif
    }
#else
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#endif
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
    return PyObject_GetAttr(obj, attr_name);
}
#endif


#if __PYX_LIMITED_VERSION_HEX < 0x030d0000
static void __Pyx_PyObject_GetAttrStr_ClearAttributeError(void) {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    if (likely(__Pyx_PyErr_ExceptionMatches(PyExc_AttributeError)))
        __Pyx_PyErr_Clear();
}
#endif
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStrNoError(PyObject* obj, PyObject* attr_name) {
    PyObject *result;
#if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
    (void) PyObject_GetOptionalAttr(obj, attr_name, &result);
    return result;
#else
#if CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_TYPE_SLOTS
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro == PyObject_GenericGetAttr)) {
        return _PyObject_GenericGetAttrWithDict(obj, attr_name, NULL, 1);
    }
#endif
    result = __Pyx_PyObject_GetAttrStr(obj, attr_name);
    if (unlikely(!result)) {
        __Pyx_PyObject_GetAttrStr_ClearAttributeError();
    }
    return result;
#endif
}


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStrNoError(__pyx_mstate_global->__pyx_b, name);
    if (unlikely(!result) && !PyErr_Occurred()) {
        PyErr_Format(PyExc_NameError,
            "name '%U' is not defined", name);
    }
    return result;
}


#if !CYTHON_COMPILING_IN_CPYTHON && CYTHON_METH_FASTCALL
static CYTHON_INLINE PyObject *
__Pyx_PyTuple_FromArray(PyObject *const *src, Py_ssize_t n)
{
    PyObject *res;
    Py_ssize_t i;
    if (n <= 0) {
        return __Pyx_NewRef(__pyx_mstate_global->__pyx_empty_tuple);
    }
    res = PyTuple_New(n);
    if (unlikely(res == NULL)) return NULL;
    for (i = 0; i < n; i++) {
        if (unlikely(__Pyx_PyTuple_SET_ITEM(res, i, src[i]) < (0))) {
            Py_DECREF(res);
            return NULL;
        }
        Py_INCREF(src[i]);
    }
    return res;
}
#elif CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE void __Pyx_copy_object_array(PyObject *const *CYTHON_RESTRICT src, PyObject** CYTHON_RESTRICT dest, Py_ssize_t length) {
    PyObject *v;
    Py_ssize_t i;
    for (i = 0; i < length; i++) {
        v = dest[i] = src[i];
        Py_INCREF(v);
    }
}
static CYTHON_INLINE PyObject *
__Pyx_PyTuple_FromArray(PyObject *const *src, Py_ssize_t n)
{
    PyObject *res;
    if (n <= 0) {
        return __Pyx_NewRef(__pyx_mstate_global->__pyx_empty_tuple);
    }
    res = PyTuple_New(n);
    if (unlikely(res == NULL)) return NULL;
    __Pyx_copy_object_array(src, ((PyTupleObject*)res)->ob_item, n);
    return res;
}
static CYTHON_INLINE PyObject *
__Pyx_PyList_FromArray(PyObject *const *src, Py_ssize_t n)
{
    PyObject *res;
    if (n <= 0) {
        return PyList_New(0);
    }
    res = PyList_New(n);
    if (unlikely(res == NULL)) return NULL;
    __Pyx_copy_object_array(src, ((PyListObject*)res)->ob_item, n);
    return res;
}
#endif


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_GRAAL ||\
        !(CYTHON_ASSUME_SAFE_SIZE && CYTHON_ASSUME_SAFE_MACROS)
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS && (PY_VERSION_HEX < 0x030B0000)
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_GRAAL
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length, length2;
        int kind;
        void *data1, *data2;
        #if !CYTHON_COMPILING_IN_LIMITED_API
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        #endif
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        #if !CYTHON_ASSUME_SAFE_SIZE
        if (unlikely(length < 0)) return -1;
        #endif
        length2 = __Pyx_PyUnicode_GET_LENGTH(s2);
        #if !CYTHON_ASSUME_SAFE_SIZE
        if (unlikely(length2 < 0)) return -1;
        #endif
        if (length != length2) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    return (equals == Py_EQ);
return_ne:
    return (equals == Py_NE);
#endif
}


#if CYTHON_METH_FASTCALL
static CYTHON_INLINE PyObject * __Pyx_GetKwValue_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues, PyObject *s)
{
    Py_ssize_t i, n = __Pyx_PyTuple_GET_SIZE(kwnames);
    #if !CYTHON_ASSUME_SAFE_SIZE
    if (unlikely(n == -1)) return NULL;
    #endif
    for (i = 0; i < n; i++)
    {
        PyObject *namei = __Pyx_PyTuple_GET_ITEM(kwnames, i);
        #if !CYTHON_ASSUME_SAFE_MACROS
        if (unlikely(!namei)) return NULL;
        #endif
        if (s == namei) return kwvalues[i];
    }
    for (i = 0; i < n; i++)
    {
        PyObject *namei = __Pyx_PyTuple_GET_ITEM(kwnames, i);
        #if !CYTHON_ASSUME_SAFE_MACROS
        if (unlikely(!namei)) return NULL;
        #endif
        int eq = __Pyx_PyUnicode_Equals(s, namei, Py_EQ);
        if (unlikely(eq != 0)) {
            if (unlikely(eq < 0)) return NULL;
            return kwvalues[i];
        }
    }
    return NULL;
}
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030d0000 || CYTHON_COMPILING_IN_LIMITED_API
CYTHON_UNUSED static PyObject *__Pyx_KwargsAsDict_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues) {
    Py_ssize_t i, nkwargs;
    PyObject *dict;
#if !CYTHON_ASSUME_SAFE_SIZE
    nkwargs = PyTuple_Size(kwnames);
    if (unlikely(nkwargs < 0)) return NULL;
#else
    nkwargs = PyTuple_GET_SIZE(kwnames);
#endif
    dict = PyDict_New();
    if (unlikely(!dict))
        return NULL;
    for (i=0; i<nkwargs; i++) {
#if !CYTHON_ASSUME_SAFE_MACROS
        PyObject *key = PyTuple_GetItem(kwnames, i);
        if (!key) goto bad;
#else
        PyObject *key = PyTuple_GET_ITEM(kwnames, i);
#endif
        if (unlikely(PyDict_SetItem(dict, key, kwvalues[i]) < 0))
            goto bad;
    }
    return dict;
bad:
    Py_DECREF(dict);
    return NULL;
}
#endif
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = Py_TYPE(func)->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall(" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = __Pyx_CyOrPyCFunction_GET_FUNCTION(func);
    self = __Pyx_CyOrPyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall(" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if PY_VERSION_HEX < 0x03090000 || CYTHON_COMPILING_IN_LIMITED_API
static PyObject* __Pyx_PyObject_FastCall_fallback(PyObject *func, PyObject * const*args, size_t nargs, PyObject *kwargs) {
    PyObject *argstuple;
    PyObject *result = 0;
    size_t i;
    argstuple = PyTuple_New((Py_ssize_t)nargs);
    if (unlikely(!argstuple)) return NULL;
    for (i = 0; i < nargs; i++) {
        Py_INCREF(args[i]);
        if (__Pyx_PyTuple_SET_ITEM(argstuple, (Py_ssize_t)i, args[i]) != (0)) goto bad;
    }
    result = __Pyx_PyObject_Call(func, argstuple, kwargs);
  bad:
    Py_DECREF(argstuple);
    return result;
}
#endif
#if CYTHON_VECTORCALL && !CYTHON_COMPILING_IN_LIMITED_API
  #if PY_VERSION_HEX < 0x03090000
    #define __Pyx_PyVectorcall_Function(callable) _PyVectorcall_Function(callable)
  #elif CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE vectorcallfunc __Pyx_PyVectorcall_Function(PyObject *callable) {
    PyTypeObject *tp = Py_TYPE(callable);
    #if defined(__Pyx_CyFunction_USED)
    if (__Pyx_CyFunction_CheckExact(callable)) {
        return __Pyx_CyFunction_func_vectorcall(callable);
    }
    #endif
    if (!PyType_HasFeature(tp, Py_TPFLAGS_HAVE_VECTORCALL)) {
        return NULL;
    }
    assert(PyCallable_Check(callable));
    Py_ssize_t offset = tp->tp_vectorcall_offset;
    assert(offset > 0);
    vectorcallfunc ptr;
    memcpy(&ptr, (char *) callable + offset, sizeof(ptr));
    return ptr;
}
  #else
    #define __Pyx_PyVectorcall_Function(callable) PyVectorcall_Function(callable)
  #endif
#endif
static CYTHON_INLINE PyObject* __Pyx_PyObject_FastCallDict(PyObject *func, PyObject *const *args, size_t _nargs, PyObject *kwargs) {
    Py_ssize_t nargs = __Pyx_PyVectorcall_NARGS(_nargs);
#if CYTHON_COMPILING_IN_CPYTHON
    if (nargs == 0 && kwargs == NULL) {
        if (__Pyx_CyOrPyCFunction_Check(func) && likely( __Pyx_CyOrPyCFunction_GET_FLAGS(func) & METH_NOARGS))
            return __Pyx_PyObject_CallMethO(func, NULL);
    }
    else if (nargs == 1 && kwargs == NULL) {
        if (__Pyx_CyOrPyCFunction_Check(func) && likely( __Pyx_CyOrPyCFunction_GET_FLAGS(func) & METH_O))
            return __Pyx_PyObject_CallMethO(func, args[0]);
    }
#endif
    if (kwargs == NULL) {
        #if CYTHON_VECTORCALL
          #if CYTHON_COMPILING_IN_LIMITED_API
            return PyObject_Vectorcall(func, args, _nargs, NULL);
          #else
            vectorcallfunc f = __Pyx_PyVectorcall_Function(func);
            if (f) {
                return f(func, args, _nargs, NULL);
            }
          #endif
        #endif
    }
    if (nargs == 0) {
        return __Pyx_PyObject_Call(func, __pyx_mstate_global->__pyx_empty_tuple, kwargs);
    }
    #if PY_VERSION_HEX >= 0x03090000 && !CYTHON_COMPILING_IN_LIMITED_API
    return PyObject_VectorcallDict(func, args, (size_t)nargs, kwargs);
    #else
    return __Pyx_PyObject_FastCall_fallback(func, args, (size_t)nargs, kwargs);
    #endif
}


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *args[2] = {NULL, arg};
    return __Pyx_PyObject_FastCall(func, args+1, 1 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET);
}


#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030C0000
static PyObject *__Pyx_SelflessCall(PyObject *method, PyObject *args, PyObject *kwargs) {
    PyObject *result;
    PyObject *selfless_args = PyTuple_GetSlice(args, 1, PyTuple_Size(args));
    if (unlikely(!selfless_args)) return NULL;
    result = PyObject_Call(method, selfless_args, kwargs);
    Py_DECREF(selfless_args);
    return result;
}
#elif CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x03090000
static PyObject *__Pyx_SelflessCall(PyObject *method, PyObject **args, Py_ssize_t nargs, PyObject *kwnames) {
        return _PyObject_Vectorcall
            (method, args ? args+1 : NULL, nargs ? nargs-1 : 0, kwnames);
}
#else
static PyObject *__Pyx_SelflessCall(PyObject *method, PyObject *const *args, Py_ssize_t nargs, PyObject *kwnames) {
    return
#if PY_VERSION_HEX < 0x03090000
    _PyObject_Vectorcall
#else
    PyObject_Vectorcall
#endif
        (method, args ? args+1 : NULL, nargs ? (size_t) nargs-1 : 0, kwnames);
}
#endif
static PyMethodDef __Pyx_UnboundCMethod_Def = {
     "CythonUnboundCMethod",
     __PYX_REINTERPRET_FUNCION(PyCFunction, __Pyx_SelflessCall),
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030C0000
     METH_VARARGS | METH_KEYWORDS,
#else
     METH_FASTCALL | METH_KEYWORDS,
#endif
     NULL
};
static int __Pyx_TryUnpackUnboundCMethod(__Pyx_CachedCFunction* target) {
    PyObject *method, *result=NULL;
    method = __Pyx_PyObject_GetAttrStr(target->type, *target->method_name);
    if (unlikely(!method))
        return -1;
    result = method;
#if CYTHON_COMPILING_IN_CPYTHON
    if (likely(__Pyx_TypeCheck(method, &PyMethodDescr_Type)))
    {
        PyMethodDescrObject *descr = (PyMethodDescrObject*) method;
        target->func = descr->d_method->ml_meth;
        target->flag = descr->d_method->ml_flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_STACKLESS);
    } else
#endif
#if CYTHON_COMPILING_IN_PYPY
#else
    if (PyCFunction_Check(method))
#endif
    {
        PyObject *self;
        int self_found;
#if CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_PYPY
        self = PyObject_GetAttrString(method, "__self__");
        if (!self) {
            PyErr_Clear();
        }
#else
        self = PyCFunction_GET_SELF(method);
#endif
        self_found = (self && self != Py_None);
#if CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_PYPY
        Py_XDECREF(self);
#endif
        if (self_found) {
            PyObject *unbound_method = PyCFunction_New(&__Pyx_UnboundCMethod_Def, method);
            if (unlikely(!unbound_method)) return -1;
            Py_DECREF(method);
            result = unbound_method;
        }
    }
#if !CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    if (unlikely(target->method)) {
        Py_DECREF(result);
    } else
#endif
    target->method = result;
    return 0;
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self) {
    int was_initialized = __Pyx_CachedCFunction_GetAndSetInitializing(cfunc);
    if (likely(was_initialized == 2 && cfunc->func)) {
        if (likely(cfunc->flag == METH_NOARGS))
            return __Pyx_CallCFunction(cfunc, self, NULL);
        if (likely(cfunc->flag == METH_FASTCALL))
            return __Pyx_CallCFunctionFast(cfunc, self, NULL, 0);
        if (cfunc->flag == (METH_FASTCALL | METH_KEYWORDS))
            return __Pyx_CallCFunctionFastWithKeywords(cfunc, self, NULL, 0, NULL);
        if (likely(cfunc->flag == (METH_VARARGS | METH_KEYWORDS)))
            return __Pyx_CallCFunctionWithKeywords(cfunc, self, __pyx_mstate_global->__pyx_empty_tuple, NULL);
        if (cfunc->flag == METH_VARARGS)
            return __Pyx_CallCFunction(cfunc, self, __pyx_mstate_global->__pyx_empty_tuple);
        return __Pyx__CallUnboundCMethod0(cfunc, self);
    }
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    else if (unlikely(was_initialized == 1)) {
        __Pyx_CachedCFunction tmp_cfunc = {
#ifndef __cplusplus
            0
#endif
        };
        tmp_cfunc.type = cfunc->type;
        tmp_cfunc.method_name = cfunc->method_name;
        return __Pyx__CallUnboundCMethod0(&tmp_cfunc, self);
    }
#endif
    PyObject *result = __Pyx__CallUnboundCMethod0(cfunc, self);
    __Pyx_CachedCFunction_SetFinishedInitializing(cfunc);
    return result;
}
#endif
static PyObject* __Pyx__CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self) {
    PyObject *result;
    if (unlikely(!cfunc->method) && unlikely(__Pyx_TryUnpackUnboundCMethod(cfunc) < 0)) return NULL;
    result = __Pyx_PyObject_CallOneArg(cfunc->method, self);
    return result;
}


static CYTHON_INLINE PyObject* __Pyx_PyDict_Items(PyObject* d) {
    return __Pyx_CallUnboundCMethod0(&__pyx_mstate_global->__pyx_umethod_PyDict_Type_items, d);
}


static CYTHON_INLINE PyObject* __Pyx_PyDict_Values(PyObject* d) {
    return __Pyx_CallUnboundCMethod0(&__pyx_mstate_global->__pyx_umethod_PyDict_Type_values, d);
}


#if CYTHON_AVOID_BORROWED_REFS
static int __Pyx_PyDict_NextRef(PyObject *p, PyObject **ppos, PyObject **pkey, PyObject **pvalue) {
    PyObject *next = NULL;
    if (!*ppos) {
        if (pvalue) {
            PyObject *dictview = pkey ? __Pyx_PyDict_Items(p) : __Pyx_PyDict_Values(p);
            if (unlikely(!dictview)) goto bad;
            *ppos = PyObject_GetIter(dictview);
            Py_DECREF(dictview);
        } else {
            *ppos = PyObject_GetIter(p);
        }
        if (unlikely(!*ppos)) goto bad;
    }
    next = PyIter_Next(*ppos);
    if (!next) {
        if (PyErr_Occurred()) goto bad;
        return 0;
    }
    if (pkey && pvalue) {
        *pkey = __Pyx_PySequence_ITEM(next, 0);
        if (unlikely(*pkey)) goto bad;
        *pvalue = __Pyx_PySequence_ITEM(next, 1);
        if (unlikely(*pvalue)) goto bad;
        Py_DECREF(next);
    } else if (pkey) {
        *pkey = next;
    } else {
        assert(pvalue);
        *pvalue = next;
    }
    return 1;
  bad:
    Py_XDECREF(next);
#if !CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x030d0000
    PyErr_FormatUnraisable("Exception ignored in __Pyx_PyDict_NextRef");
#else
    PyErr_WriteUnraisable(__pyx_mstate_global->__pyx_n_u_Pyx_PyDict_NextRef);
#endif
    if (pkey) *pkey = NULL;
    if (pvalue) *pvalue = NULL;
    return 0;
}
#else // !CYTHON_AVOID_BORROWED_REFS
static int __Pyx_PyDict_NextRef(PyObject *p, Py_ssize_t *ppos, PyObject **pkey, PyObject **pvalue) {
    int result = PyDict_Next(p, ppos, pkey, pvalue);
    if (likely(result == 1)) {
        if (pkey) Py_INCREF(*pkey);
        if (pvalue) Py_INCREF(*pvalue);
    }
    return result;
}
#endif


static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject *__Pyx_CallUnboundCMethod2(__Pyx_CachedCFunction *cfunc, PyObject *self, PyObject *arg1, PyObject *arg2) {
    int was_initialized = __Pyx_CachedCFunction_GetAndSetInitializing(cfunc);
    if (likely(was_initialized == 2 && cfunc->func)) {
        PyObject *args[2] = {arg1, arg2};
        if (cfunc->flag == METH_FASTCALL) {
            return __Pyx_CallCFunctionFast(cfunc, self, args, 2);
        }
        if (cfunc->flag == (METH_FASTCALL | METH_KEYWORDS))
            return __Pyx_CallCFunctionFastWithKeywords(cfunc, self, args, 2, NULL);
    }
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    else if (unlikely(was_initialized == 1)) {
        __Pyx_CachedCFunction tmp_cfunc = {
#ifndef __cplusplus
            0
#endif
        };
        tmp_cfunc.type = cfunc->type;
        tmp_cfunc.method_name = cfunc->method_name;
        return __Pyx__CallUnboundCMethod2(&tmp_cfunc, self, arg1, arg2);
    }
#endif
    PyObject *result = __Pyx__CallUnboundCMethod2(cfunc, self, arg1, arg2);
    __Pyx_CachedCFunction_SetFinishedInitializing(cfunc);
    return result;
}
#endif
static PyObject* __Pyx__CallUnboundCMethod2(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg1, PyObject* arg2){
    if (unlikely(!cfunc->func && !cfunc->method) && unlikely(__Pyx_TryUnpackUnboundCMethod(cfunc) < 0)) return NULL;
#if CYTHON_COMPILING_IN_CPYTHON
    if (cfunc->func && (cfunc->flag & METH_VARARGS)) {
        PyObject *result = NULL;
        PyObject *args = PyTuple_New(2);
        if (unlikely(!args)) return NULL;
        Py_INCREF(arg1);
        PyTuple_SET_ITEM(args, 0, arg1);
        Py_INCREF(arg2);
        PyTuple_SET_ITEM(args, 1, arg2);
        if (cfunc->flag & METH_KEYWORDS)
            result = __Pyx_CallCFunctionWithKeywords(cfunc, self, args, NULL);
        else
            result = __Pyx_CallCFunction(cfunc, self, args);
        Py_DECREF(args);
        return result;
    }
#endif
    {
        PyObject *args[4] = {NULL, self, arg1, arg2};
        return __Pyx_PyObject_FastCall(cfunc->method, args+1, 3 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET);
    }
}


static int __Pyx_ValidateDuplicatePosArgs(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject ** const *first_kw_arg,
    const char* function_name)
{
    PyObject ** const *name = argnames;
    while (name != first_kw_arg) {
        PyObject *key = **name;
        int found = PyDict_Contains(kwds, key);
        if (unlikely(found)) {
            if (found == 1) __Pyx_RaiseDoubleKeywordsError(function_name, key);
            goto bad;
        }
        name++;
    }
    return 0;
bad:
    return -1;
}
#if CYTHON_USE_UNICODE_INTERNALS
static CYTHON_INLINE int __Pyx_UnicodeKeywordsEqual(PyObject *s1, PyObject *s2) {
    int kind;
    Py_ssize_t len = PyUnicode_GET_LENGTH(s1);
    if (len != PyUnicode_GET_LENGTH(s2)) return 0;
    kind = PyUnicode_KIND(s1);
    if (kind != PyUnicode_KIND(s2)) return 0;
    const void *data1 = PyUnicode_DATA(s1);
    const void *data2 = PyUnicode_DATA(s2);
    return (memcmp(data1, data2, (size_t) len * (size_t) kind) == 0);
}
#endif
static int __Pyx_MatchKeywordArg_str(
    PyObject *key,
    PyObject ** const argnames[],
    PyObject ** const *first_kw_arg,
    size_t *index_found,
    const char *function_name)
{
    PyObject ** const *name;
    #if CYTHON_USE_UNICODE_INTERNALS
    Py_hash_t key_hash = ((PyASCIIObject*)key)->hash;
    if (unlikely(key_hash == -1)) {
        key_hash = PyObject_Hash(key);
        if (unlikely(key_hash == -1))
            goto bad;
    }
    #endif
    name = first_kw_arg;
    while (*name) {
        PyObject *name_str = **name;
        #if CYTHON_USE_UNICODE_INTERNALS
        if (key_hash == ((PyASCIIObject*)name_str)->hash && __Pyx_UnicodeKeywordsEqual(name_str, key)) {
            *index_found = (size_t) (name - argnames);
            return 1;
        }
        #else
        #if CYTHON_ASSUME_SAFE_SIZE
        if (PyUnicode_GET_LENGTH(name_str) == PyUnicode_GET_LENGTH(key))
        #endif
        {
            int cmp = PyUnicode_Compare(name_str, key);
            if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
            if (cmp == 0) {
                *index_found = (size_t) (name - argnames);
                return 1;
            }
        }
        #endif
        name++;
    }
    name = argnames;
    while (name != first_kw_arg) {
        PyObject *name_str = **name;
        #if CYTHON_USE_UNICODE_INTERNALS
        if (unlikely(key_hash == ((PyASCIIObject*)name_str)->hash)) {
            if (__Pyx_UnicodeKeywordsEqual(name_str, key))
                goto arg_passed_twice;
        }
        #else
        #if CYTHON_ASSUME_SAFE_SIZE
        if (PyUnicode_GET_LENGTH(name_str) == PyUnicode_GET_LENGTH(key))
        #endif
        {
            if (unlikely(name_str == key)) goto arg_passed_twice;
            int cmp = PyUnicode_Compare(name_str, key);
            if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
            if (cmp == 0) goto arg_passed_twice;
        }
        #endif
        name++;
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
bad:
    return -1;
}
static int __Pyx_MatchKeywordArg_nostr(
    PyObject *key,
    PyObject ** const argnames[],
    PyObject ** const *first_kw_arg,
    size_t *index_found,
    const char *function_name)
{
    PyObject ** const *name;
    if (unlikely(!PyUnicode_Check(key))) goto invalid_keyword_type;
    name = first_kw_arg;
    while (*name) {
        int cmp = PyObject_RichCompareBool(**name, key, Py_EQ);
        if (cmp == 1) {
            *index_found = (size_t) (name - argnames);
            return 1;
        }
        if (unlikely(cmp == -1)) goto bad;
        name++;
    }
    name = argnames;
    while (name != first_kw_arg) {
        int cmp = PyObject_RichCompareBool(**name, key, Py_EQ);
        if (unlikely(cmp != 0)) {
            if (cmp == 1) goto arg_passed_twice;
            else goto bad;
        }
        name++;
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
bad:
    return -1;
}
static CYTHON_INLINE int __Pyx_MatchKeywordArg(
    PyObject *key,
    PyObject ** const argnames[],
    PyObject ** const *first_kw_arg,
    size_t *index_found,
    const char *function_name)
{
    return likely(PyUnicode_CheckExact(key)) ?
        __Pyx_MatchKeywordArg_str(key, argnames, first_kw_arg, index_found, function_name) :
        __Pyx_MatchKeywordArg_nostr(key, argnames, first_kw_arg, index_found, function_name);
}
static void __Pyx_RejectUnknownKeyword(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject ** const *first_kw_arg,
    const char *function_name)
{
    #if CYTHON_AVOID_BORROWED_REFS
    PyObject *pos = NULL;
    #else
    Py_ssize_t pos = 0;
    #endif
    PyObject *key = NULL;
    __Pyx_BEGIN_CRITICAL_SECTION(kwds);
    while (
        #if CYTHON_AVOID_BORROWED_REFS
        __Pyx_PyDict_NextRef(kwds, &pos, &key, NULL)
        #else
        PyDict_Next(kwds, &pos, &key, NULL)
        #endif
    ) {
        PyObject** const *name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (!*name) {
            size_t index_found = 0;
            int cmp = __Pyx_MatchKeywordArg(key, argnames, first_kw_arg, &index_found, function_name);
            if (cmp != 1) {
                if (cmp == 0) {
                    PyErr_Format(PyExc_TypeError,
                        "%s() got an unexpected keyword argument '%U'",
                        function_name, key);
                }
                #if CYTHON_AVOID_BORROWED_REFS
                Py_DECREF(key);
                #endif
                break;
            }
        }
        #if CYTHON_AVOID_BORROWED_REFS
        Py_DECREF(key);
        #endif
    }
    __Pyx_END_CRITICAL_SECTION();
    #if CYTHON_AVOID_BORROWED_REFS
    Py_XDECREF(pos);
    #endif
    assert(PyErr_Occurred());
}
static int __Pyx_ParseKeywordDict(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject *values[],
    Py_ssize_t num_pos_args,
    Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs)
{
    PyObject** const *name;
    PyObject** const *first_kw_arg = argnames + num_pos_args;
    Py_ssize_t extracted = 0;
#if !CYTHON_COMPILING_IN_PYPY || defined(PyArg_ValidateKeywordArguments)
    if (unlikely(!PyArg_ValidateKeywordArguments(kwds))) return -1;
#endif
    name = first_kw_arg;
    while (*name && num_kwargs > extracted) {
        PyObject * key = **name;
        PyObject *value;
        int found = 0;
        #if __PYX_LIMITED_VERSION_HEX >= 0x030d0000
        found = PyDict_GetItemRef(kwds, key, &value);
        #else
        value = PyDict_GetItemWithError(kwds, key);
        if (value) {
            Py_INCREF(value);
            found = 1;
        } else {
            if (unlikely(PyErr_Occurred())) goto bad;
        }
        #endif
        if (found) {
            if (unlikely(found < 0)) goto bad;
            values[name-argnames] = value;
            extracted++;
        }
        name++;
    }
    if (num_kwargs > extracted) {
        if (ignore_unknown_kwargs) {
            if (unlikely(__Pyx_ValidateDuplicatePosArgs(kwds, argnames, first_kw_arg, function_name) == -1))
                goto bad;
        } else {
            __Pyx_RejectUnknownKeyword(kwds, argnames, first_kw_arg, function_name);
            goto bad;
        }
    }
    return 0;
bad:
    return -1;
}
static int __Pyx_ParseKeywordDictToDict(
    PyObject *kwds,
    PyObject ** const argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject** const *name;
    PyObject** const *first_kw_arg = argnames + num_pos_args;
    Py_ssize_t len;
#if !CYTHON_COMPILING_IN_PYPY || defined(PyArg_ValidateKeywordArguments)
    if (unlikely(!PyArg_ValidateKeywordArguments(kwds))) return -1;
#endif
    if (PyDict_Update(kwds2, kwds) < 0) goto bad;
    name = first_kw_arg;
    while (*name) {
        PyObject *key = **name;
        PyObject *value;
#if !CYTHON_COMPILING_IN_LIMITED_API && (PY_VERSION_HEX >= 0x030d00A2 || defined(PyDict_Pop))
        int found = PyDict_Pop(kwds2, key, &value);
        if (found) {
            if (unlikely(found < 0)) goto bad;
            values[name-argnames] = value;
        }
#elif __PYX_LIMITED_VERSION_HEX >= 0x030d0000
        int found = PyDict_GetItemRef(kwds2, key, &value);
        if (found) {
            if (unlikely(found < 0)) goto bad;
            values[name-argnames] = value;
            if (unlikely(PyDict_DelItem(kwds2, key) < 0)) goto bad;
        }
#else
    #if CYTHON_COMPILING_IN_CPYTHON
        value = _PyDict_Pop(kwds2, key, kwds2);
    #else
        value = __Pyx_CallUnboundCMethod2(&__pyx_mstate_global->__pyx_umethod_PyDict_Type_pop, kwds2, key, kwds2);
    #endif
        if (value == kwds2) {
            Py_DECREF(value);
        } else {
            if (unlikely(!value)) goto bad;
            values[name-argnames] = value;
        }
#endif
        name++;
    }
    len = PyDict_Size(kwds2);
    if (len > 0) {
        return __Pyx_ValidateDuplicatePosArgs(kwds, argnames, first_kw_arg, function_name);
    } else if (unlikely(len == -1)) {
        goto bad;
    }
    return 0;
bad:
    return -1;
}
static int __Pyx_ParseKeywordsTuple(
    PyObject *kwds,
    PyObject * const *kwvalues,
    PyObject ** const argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs)
{
    PyObject *key = NULL;
    PyObject** const * name;
    PyObject** const *first_kw_arg = argnames + num_pos_args;
    for (Py_ssize_t pos = 0; pos < num_kwargs; pos++) {
#if CYTHON_AVOID_BORROWED_REFS
        key = __Pyx_PySequence_ITEM(kwds, pos);
#else
        key = __Pyx_PyTuple_GET_ITEM(kwds, pos);
#endif
#if !CYTHON_ASSUME_SAFE_MACROS
        if (unlikely(!key)) goto bad;
#endif
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            PyObject *value = kwvalues[pos];
            values[name-argnames] = __Pyx_NewRef(value);
        } else {
            size_t index_found = 0;
            int cmp = __Pyx_MatchKeywordArg(key, argnames, first_kw_arg, &index_found, function_name);
            if (cmp == 1) {
                PyObject *value = kwvalues[pos];
                values[index_found] = __Pyx_NewRef(value);
            } else {
                if (unlikely(cmp == -1)) goto bad;
                if (kwds2) {
                    PyObject *value = kwvalues[pos];
                    if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
                } else if (!ignore_unknown_kwargs) {
                    goto invalid_keyword;
                }
            }
        }
        #if CYTHON_AVOID_BORROWED_REFS
        Py_DECREF(key);
        key = NULL;
        #endif
    }
    return 0;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    goto bad;
bad:
    #if CYTHON_AVOID_BORROWED_REFS
    Py_XDECREF(key);
    #endif
    return -1;
}


static int __Pyx_ParseKeywords(
    PyObject *kwds,
    PyObject * const *kwvalues,
    PyObject ** const argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    Py_ssize_t num_kwargs,
    const char* function_name,
    int ignore_unknown_kwargs)
{
    if (CYTHON_METH_FASTCALL && likely(PyTuple_Check(kwds)))
        return __Pyx_ParseKeywordsTuple(kwds, kwvalues, argnames, kwds2, values, num_pos_args, num_kwargs, function_name, ignore_unknown_kwargs);
    else if (kwds2)
        return __Pyx_ParseKeywordDictToDict(kwds, argnames, kwds2, values, num_pos_args, function_name);
    else
        return __Pyx_ParseKeywordDict(kwds, argnames, values, num_pos_args, num_kwargs, function_name, ignore_unknown_kwargs);
}


static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


static void __Pyx_RaiseUnboundLocalError(const char *varname) {
    PyErr_Format(PyExc_UnboundLocalError, "local variable '%s' referenced before assignment", varname);
}


static void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_Fallback___Pyx_PyLong_MultiplyObjC(PyObject *op1, PyObject *op2, int inplace) {
    return (inplace ? PyNumber_InPlaceMultiply : PyNumber_Multiply)(op1, op2);
}
#if CYTHON_USE_PYLONG_INTERNALS
static PyObject* __Pyx_Unpacked___Pyx_PyLong_MultiplyObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check) {
    CYTHON_MAYBE_UNUSED_VAR(inplace);
    CYTHON_UNUSED_VAR(zerodivision_check);
    const long b = intval;
    long a;
    const PY_LONG_LONG llb = intval;
    PY_LONG_LONG lla;
    if (unlikely(__Pyx_PyLong_IsZero(op1))) {
        return __Pyx_NewRef(op1);
    }
    const int is_positive = __Pyx_PyLong_IsPos(op1);
    const digit* digits = __Pyx_PyLong_Digits(op1);
    const Py_ssize_t size = __Pyx_PyLong_DigitCount(op1);
    if (likely(size == 1)) {
        a = (long) digits[0];
        if (!is_positive) a *= -1;
    } else {
        switch (size) {
            case 2:
                if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT+30) {
                    a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT+30) {
                    lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
            case 3:
                if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT+30) {
                    a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT+30) {
                    lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
            case 4:
                if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT+30) {
                    a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT+30) {
                    lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
        }
        return PyLong_Type.tp_as_number->nb_multiply(op1, op2);
    }
    calculate_long:
        CYTHON_UNUSED_VAR(a);
        CYTHON_UNUSED_VAR(b);
        lla = a;
        goto calculate_long_long;
    calculate_long_long:
        {
            PY_LONG_LONG llx;
            llx = lla * llb;
            return PyLong_FromLongLong(llx);
        }
    
}
#endif
static PyObject* __Pyx_Float___Pyx_PyLong_MultiplyObjC(PyObject *float_val, long intval, int zerodivision_check) {
    CYTHON_UNUSED_VAR(zerodivision_check);
    const long b = intval;
    double a = __Pyx_PyFloat_AS_DOUBLE(float_val);
        double result;
        
        result = ((double)a) * (double)b;
        return PyFloat_FromDouble(result);
}
static CYTHON_INLINE PyObject* __Pyx_PyLong_MultiplyObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check) {
    CYTHON_MAYBE_UNUSED_VAR(intval);
    CYTHON_UNUSED_VAR(zerodivision_check);
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        return __Pyx_Unpacked___Pyx_PyLong_MultiplyObjC(op1, op2, intval, inplace, zerodivision_check);
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        return __Pyx_Float___Pyx_PyLong_MultiplyObjC(op1, intval, zerodivision_check);
    }
    return __Pyx_Fallback___Pyx_PyLong_MultiplyObjC(op1, op2, inplace);
}
#endif


static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (unlikely(!j)) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck, int unsafe_shared) {
    CYTHON_MAYBE_UNUSED_VAR(unsafe_shared);
#if CYTHON_ASSUME_SAFE_SIZE
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((CYTHON_AVOID_BORROWED_REFS || CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS || !CYTHON_ASSUME_SAFE_MACROS)) {
        return __Pyx_PyList_GetItemRefFast(o, wrapped_i, unsafe_shared);
    } else
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        return __Pyx_NewRef(PyList_GET_ITEM(o, wrapped_i));
    }
    return __Pyx_GetItemInt_Generic(o, PyLong_FromSsize_t(i));
#else
    (void)wraparound;
    (void)boundscheck;
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck, int unsafe_shared) {
    CYTHON_MAYBE_UNUSED_VAR(unsafe_shared);
#if CYTHON_ASSUME_SAFE_SIZE && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        return __Pyx_NewRef(PyTuple_GET_ITEM(o, wrapped_i));
    }
    return __Pyx_GetItemInt_Generic(o, PyLong_FromSsize_t(i));
#else
    (void)wraparound;
    (void)boundscheck;
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     int wraparound, int boundscheck, int unsafe_shared) {
    CYTHON_MAYBE_UNUSED_VAR(unsafe_shared);
#if CYTHON_ASSUME_SAFE_MACROS && CYTHON_ASSUME_SAFE_SIZE
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((CYTHON_AVOID_BORROWED_REFS || CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS)) {
            return __Pyx_PyList_GetItemRefFast(o, n, unsafe_shared);
        } else if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            return __Pyx_NewRef(PyList_GET_ITEM(o, n));
        }
    } else
    #if !CYTHON_AVOID_BORROWED_REFS
    if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            return __Pyx_NewRef(PyTuple_GET_ITEM(o, n));
        }
    } else
    #endif
#endif
#if CYTHON_USE_TYPE_SLOTS && !CYTHON_COMPILING_IN_PYPY
    {
        PyMappingMethods *mm = Py_TYPE(o)->tp_as_mapping;
        PySequenceMethods *sm = Py_TYPE(o)->tp_as_sequence;
        if (!is_list && mm && mm->mp_subscript) {
            PyObject *r, *key = PyLong_FromSsize_t(i);
            if (unlikely(!key)) return NULL;
            r = mm->mp_subscript(o, key);
            Py_DECREF(key);
            return r;
        }
        if (is_list || likely(sm && sm->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(sm->sq_length)) {
                Py_ssize_t l = sm->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return sm->sq_item(o, i);
        }
    }
#else
    if (is_list || !PyMapping_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    (void)wraparound;
    (void)boundscheck;
    return __Pyx_GetItemInt_Generic(o, PyLong_FromSsize_t(i));
}


#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject *index) {
    PyObject *runerr = NULL;
    Py_ssize_t key_value;
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        __Pyx_TypeName index_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(index));
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError,
            "cannot fit '" __Pyx_FMT_TYPENAME "' into an index-sized integer", index_type_name);
        __Pyx_DECREF_TypeName(index_type_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem_Slow(PyObject *obj, PyObject *key) {
    __Pyx_TypeName obj_type_name;
    if (likely(PyType_Check(obj))) {
        PyObject *meth = __Pyx_PyObject_GetAttrStrNoError(obj, __pyx_mstate_global->__pyx_n_u_class_getitem);
        if (!meth) {
            PyErr_Clear();
        } else {
            PyObject *result = __Pyx_PyObject_CallOneArg(meth, key);
            Py_DECREF(meth);
            return result;
        }
    }
    obj_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(obj));
    PyErr_Format(PyExc_TypeError,
        "'" __Pyx_FMT_TYPENAME "' object is not subscriptable", obj_type_name);
    __Pyx_DECREF_TypeName(obj_type_name);
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject *key) {
    PyTypeObject *tp = Py_TYPE(obj);
    PyMappingMethods *mm = tp->tp_as_mapping;
    PySequenceMethods *sm = tp->tp_as_sequence;
    if (likely(mm && mm->mp_subscript)) {
        return mm->mp_subscript(obj, key);
    }
    if (likely(sm && sm->sq_item)) {
        return __Pyx_PyObject_GetIndex(obj, key);
    }
    return __Pyx_PyObject_GetItem_Slow(obj, key);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type = NULL, *local_value, *local_tb = NULL;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
  #if PY_VERSION_HEX >= 0x030C0000
    local_value = tstate->current_exception;
    tstate->current_exception = 0;
  #else
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
  #endif
#elif __PYX_LIMITED_VERSION_HEX > 0x030C0000
    local_value = PyErr_GetRaisedException();
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
#if __PYX_LIMITED_VERSION_HEX > 0x030C0000
    if (likely(local_value)) {
        local_type = (PyObject*) Py_TYPE(local_value);
        Py_INCREF(local_type);
        local_tb = PyException_GetTraceback(local_value);
    }
#else
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
#endif // __PYX_LIMITED_VERSION_HEX > 0x030C0000
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
      #if PY_VERSION_HEX >= 0x030B00a4
        tmp_value = exc_info->exc_value;
        exc_info->exc_value = local_value;
        tmp_type = NULL;
        tmp_tb = NULL;
        Py_XDECREF(local_type);
        Py_XDECREF(local_tb);
      #else
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
      #endif
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#elif __PYX_LIMITED_VERSION_HEX >= 0x030b0000
    PyErr_SetHandledException(local_value);
    Py_XDECREF(local_value);
    Py_XDECREF(local_type);
    Py_XDECREF(local_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
#if __PYX_LIMITED_VERSION_HEX <= 0x030C0000
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
#endif
}


static void __Pyx_Generator_Replace_StopIteration(int in_async_gen) {
    PyObject *exc, *val, *tb, *cur_exc, *new_exc;
    __Pyx_PyThreadState_declare
    int is_async_stopiteration = 0;
    CYTHON_MAYBE_UNUSED_VAR(in_async_gen);
    __Pyx_PyThreadState_assign
    cur_exc = __Pyx_PyErr_CurrentExceptionType();
    if (likely(!__Pyx_PyErr_GivenExceptionMatches(cur_exc, PyExc_StopIteration))) {
        if (in_async_gen && unlikely(__Pyx_PyErr_GivenExceptionMatches(cur_exc, PyExc_StopAsyncIteration))) {
            is_async_stopiteration = 1;
        } else {
            return;
        }
    }
    __Pyx_GetException(&exc, &val, &tb);
    Py_XDECREF(exc);
    Py_XDECREF(tb);
    new_exc = PyObject_CallFunction(PyExc_RuntimeError, "s",
        is_async_stopiteration ? "async generator raised StopAsyncIteration" :
        in_async_gen ? "async generator raised StopIteration" :
        "generator raised StopIteration");
    if (!new_exc) {
        Py_XDECREF(val);
        return;
    }
    PyException_SetCause(new_exc, val); // steals ref to val
    PyErr_SetObject(PyExc_RuntimeError, new_exc);
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_Fallback___Pyx_PyLong_AddObjC(PyObject *op1, PyObject *op2, int inplace) {
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#if CYTHON_USE_PYLONG_INTERNALS
static PyObject* __Pyx_Unpacked___Pyx_PyLong_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check) {
    CYTHON_MAYBE_UNUSED_VAR(inplace);
    CYTHON_UNUSED_VAR(zerodivision_check);
    const long b = intval;
    long a;
    const PY_LONG_LONG llb = intval;
    PY_LONG_LONG lla;
    if (unlikely(__Pyx_PyLong_IsZero(op1))) {
        return __Pyx_NewRef(op2);
    }
    const int is_positive = __Pyx_PyLong_IsPos(op1);
    const digit* digits = __Pyx_PyLong_Digits(op1);
    const Py_ssize_t size = __Pyx_PyLong_DigitCount(op1);
    if (likely(size == 1)) {
        a = (long) digits[0];
        if (!is_positive) a *= -1;
    } else {
        switch (size) {
            case 2:
                if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                    a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                    lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
            case 3:
                if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                    a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                    lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
            case 4:
                if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                    a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if (!is_positive) a *= -1;
                    goto calculate_long;
                } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                    lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                    if (!is_positive) lla *= -1;
                    goto calculate_long_long;
                }
                break;
        }
        return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    calculate_long:
        {
            long x;
            x = a + b;
            return PyLong_FromLong(x);
        }
    calculate_long_long:
        {
            PY_LONG_LONG llx;
            llx = lla + llb;
            return PyLong_FromLongLong(llx);
        }
    
}
#endif
static PyObject* __Pyx_Float___Pyx_PyLong_AddObjC(PyObject *float_val, long intval, int zerodivision_check) {
    CYTHON_UNUSED_VAR(zerodivision_check);
    const long b = intval;
    double a = __Pyx_PyFloat_AS_DOUBLE(float_val);
        double result;
        
        result = ((double)a) + (double)b;
        return PyFloat_FromDouble(result);
}
static CYTHON_INLINE PyObject* __Pyx_PyLong_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check) {
    CYTHON_MAYBE_UNUSED_VAR(intval);
    CYTHON_UNUSED_VAR(zerodivision_check);
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        return __Pyx_Unpacked___Pyx_PyLong_AddObjC(op1, op2, intval, inplace, zerodivision_check);
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        return __Pyx_Float___Pyx_PyLong_AddObjC(op1, intval, zerodivision_check);
    }
    return __Pyx_Fallback___Pyx_PyLong_AddObjC(op1, op2, inplace);
}
#endif


static CYTHON_INLINE int __Pyx_init_unicode_iteration(
    PyObject* ustring, Py_ssize_t *length, void** data, int *kind) {
#if CYTHON_COMPILING_IN_LIMITED_API
    *kind   = 0;
    *length = PyUnicode_GetLength(ustring);
    *data   = (void*)ustring;
#else
    if (unlikely(__Pyx_PyUnicode_READY(ustring) < 0)) return -1;
    *kind   = PyUnicode_KIND(ustring);
    *length = PyUnicode_GET_LENGTH(ustring);
    *data   = PyUnicode_DATA(ustring);
#endif
    return 0;
}


static void __Pyx_PyUnicode_AsPy_UCS4_error(Py_ssize_t length) {
    if (likely(length >= 0)) {
        PyErr_Format(PyExc_ValueError,
                     "only single character unicode strings can be converted to Py_UCS4, "
                     "got length %" CYTHON_FORMAT_SSIZE_T "d", length);
    }
}
static CYTHON_INLINE Py_UCS4 __Pyx_PyUnicode_AsPy_UCS4(PyObject* x) {
    Py_ssize_t length = __Pyx_PyUnicode_GET_LENGTH(x);
    if (unlikely(length != 1)) {
        __Pyx_PyUnicode_AsPy_UCS4_error(length);
        return (Py_UCS4)-1;
    }
    return __Pyx_PyUnicode_READ_CHAR(x, 0);
}


static long __Pyx__PyObject_Ord(PyObject* c) {
    Py_ssize_t size;
    if (PyBytes_Check(c)) {
        size = __Pyx_PyBytes_GET_SIZE(c);
        if (likely(size == 1)) {
#if CYTHON_ASSUME_SAFE_MACROS
            return (unsigned char) PyBytes_AS_STRING(c)[0];
#else
            char *data = PyBytes_AsString(c);
            if (unlikely(!data)) return -1;
            return (unsigned char) data[0];
#endif
        }
#if !CYTHON_ASSUME_SAFE_SIZE
        else if (unlikely(size < 0)) return -1;
#endif
    } else if (PyByteArray_Check(c)) {
        size = __Pyx_PyByteArray_GET_SIZE(c);
        if (likely(size == 1)) {
#if CYTHON_ASSUME_SAFE_MACROS
            return (unsigned char) PyByteArray_AS_STRING(c)[0];
#else
            char *data = PyByteArray_AsString(c);
            if (unlikely(!data)) return -1;
            return (unsigned char) data[0];
#endif
        }
#if !CYTHON_ASSUME_SAFE_SIZE
        else if (unlikely(size < 0)) return -1;
#endif
    } else {
        __Pyx_TypeName c_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(c));
        PyErr_Format(PyExc_TypeError,
            "ord() expected string of length 1, but " __Pyx_FMT_TYPENAME " found",
            c_type_name);
        __Pyx_DECREF_TypeName(c_type_name);
        return (long)(Py_UCS4)-1;
    }
    PyErr_Format(PyExc_TypeError,
        "ord() expected a character, but string of length %zd found", size);
    return (long)(Py_UCS4)-1;
}


static CYTHON_INLINE Py_ssize_t __Pyx_div_Py_ssize_t(Py_ssize_t a, Py_ssize_t b, int b_is_constant) {
    Py_ssize_t q = a / b;
    Py_ssize_t r = a - q*b;
    Py_ssize_t adapt_python = (b_is_constant ?
        ((r != 0) & ((r < 0) ^ (b < 0))) :
        ((r != 0) & ((r ^ b) < 0))
    );
    return q - adapt_python;
}


static PyObject *__Pyx_AllocateExtensionType(PyTypeObject *t, int is_final) {
    if (is_final || likely(!__Pyx_PyType_HasFeature(t, Py_TPFLAGS_IS_ABSTRACT))) {
        allocfunc alloc_func = __Pyx_PyType_GetSlot(t, tp_alloc, allocfunc);
        return alloc_func(t, 0);
    } else {
        newfunc tp_new = __Pyx_PyType_TryGetSlot(&PyBaseObject_Type, tp_new, newfunc);
    #if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
        if (!tp_new) {
            PyObject *new_str = PyUnicode_FromString("__new__");
            if (likely(new_str)) {
                PyObject *o = PyObject_CallMethodObjArgs((PyObject *)&PyBaseObject_Type, new_str, t, NULL);
                Py_DECREF(new_str);
                return o;
            } else
                return NULL;
        } else
    #endif
        return tp_new(t, __pyx_mstate_global->__pyx_empty_tuple, 0);
    }
}


#if !CYTHON_USE_TYPE_SPECS || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX < 0x03090000)
#else
static int __Pyx_call_type_traverse(PyObject *o, int always_call, visitproc visit, void *arg) {
    #if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x03090000
    if (__Pyx_get_runtime_version() < 0x03090000) return 0;
    #endif
    if (!always_call) {
        PyTypeObject *base = __Pyx_PyObject_GetSlot(o, tp_base, PyTypeObject*);
        unsigned long flags = PyType_GetFlags(base);
        if (flags & Py_TPFLAGS_HEAPTYPE) {
            return 0;
        }
    }
    Py_VISIT((PyObject*)Py_TYPE(o));
    return 0;
}
#endif


#if CYTHON_COMPILING_IN_LIMITED_API
static Py_ssize_t __Pyx_GetTypeDictOffset(void) {
    PyObject *tp_dictoffset_o;
    Py_ssize_t tp_dictoffset;
    tp_dictoffset_o = PyObject_GetAttrString((PyObject*)(&PyType_Type), "__dictoffset__");
    if (unlikely(!tp_dictoffset_o)) return -1;
    tp_dictoffset = PyLong_AsSsize_t(tp_dictoffset_o);
    Py_DECREF(tp_dictoffset_o);
    if (unlikely(tp_dictoffset == 0)) {
        PyErr_SetString(
            PyExc_TypeError,
            "'type' doesn't have a dictoffset");
        return -1;
    } else if (unlikely(tp_dictoffset < 0)) {
        PyErr_SetString(
            PyExc_TypeError,
            "'type' has an unexpected negative dictoffset. "
            "Please report this as Cython bug");
        return -1;
    }
    return tp_dictoffset;
}
static PyObject *__Pyx_GetTypeDict(PyTypeObject *tp) {
    static Py_ssize_t tp_dictoffset = 0;
    if (unlikely(tp_dictoffset == 0)) {
        tp_dictoffset = __Pyx_GetTypeDictOffset();
        if (unlikely(tp_dictoffset == -1 && PyErr_Occurred())) {
            tp_dictoffset = 0; // try again next time?
            return NULL;
        }
    }
    return *(PyObject**)((char*)tp + tp_dictoffset);
}
#endif


static int __Pyx__SetItemOnTypeDict(PyTypeObject *tp, PyObject *k, PyObject *v) {
    int result;
    PyObject *tp_dict;
#if CYTHON_COMPILING_IN_LIMITED_API
    tp_dict = __Pyx_GetTypeDict(tp);
    if (unlikely(!tp_dict)) return -1;
#else
    tp_dict = tp->tp_dict;
#endif
    result = PyDict_SetItem(tp_dict, k, v);
    if (likely(!result)) {
        PyType_Modified(tp);
        if (unlikely(PyObject_HasAttr(v, __pyx_mstate_global->__pyx_n_u_set_name))) {
            PyObject *setNameResult = PyObject_CallMethodObjArgs(v, __pyx_mstate_global->__pyx_n_u_set_name,  (PyObject *) tp, k, NULL);
            if (!setNameResult) return -1;
            Py_DECREF(setNameResult);
        }
    }
    return result;
}


static int __Pyx_fix_up_extension_type_from_spec(PyType_Spec *spec, PyTypeObject *type) {
#if __PYX_LIMITED_VERSION_HEX > 0x030900B1
    CYTHON_UNUSED_VAR(spec);
    CYTHON_UNUSED_VAR(type);
    CYTHON_UNUSED_VAR(__Pyx__SetItemOnTypeDict);
#else
    const PyType_Slot *slot = spec->slots;
    int changed = 0;
#if !CYTHON_COMPILING_IN_LIMITED_API
    while (slot && slot->slot && slot->slot != Py_tp_members)
        slot++;
    if (slot && slot->slot == Py_tp_members) {
#if !CYTHON_COMPILING_IN_CPYTHON
        const
#endif  // !CYTHON_COMPILING_IN_CPYTHON)
            PyMemberDef *memb = (PyMemberDef*) slot->pfunc;
        while (memb && memb->name) {
            if (memb->name[0] == '_' && memb->name[1] == '_') {
                if (strcmp(memb->name, "__weaklistoffset__") == 0) {
                    assert(memb->type == T_PYSSIZET);
                    assert(memb->flags == READONLY);
                    type->tp_weaklistoffset = memb->offset;
                    changed = 1;
                }
                else if (strcmp(memb->name, "__dictoffset__") == 0) {
                    assert(memb->type == T_PYSSIZET);
                    assert(memb->flags == READONLY);
                    type->tp_dictoffset = memb->offset;
                    changed = 1;
                }
#if CYTHON_METH_FASTCALL
                else if (strcmp(memb->name, "__vectorcalloffset__") == 0) {
                    assert(memb->type == T_PYSSIZET);
                    assert(memb->flags == READONLY);
                    type->tp_vectorcall_offset = memb->offset;
                    changed = 1;
                }
#endif  // CYTHON_METH_FASTCALL
#if !CYTHON_COMPILING_IN_PYPY
                else if (strcmp(memb->name, "__module__") == 0) {
                    PyObject *descr;
                    assert(memb->type == T_OBJECT);
                    assert(memb->flags == 0 || memb->flags == READONLY);
                    descr = PyDescr_NewMember(type, memb);
                    if (unlikely(!descr))
                        return -1;
                    int set_item_result = PyDict_SetItem(type->tp_dict, PyDescr_NAME(descr), descr);
                    Py_DECREF(descr);
                    if (unlikely(set_item_result < 0)) {
                        return -1;
                    }
                    changed = 1;
                }
#endif  // !CYTHON_COMPILING_IN_PYPY
            }
            memb++;
        }
    }
#endif  // !CYTHON_COMPILING_IN_LIMITED_API
#if !CYTHON_COMPILING_IN_PYPY
    slot = spec->slots;
    while (slot && slot->slot && slot->slot != Py_tp_getset)
        slot++;
    if (slot && slot->slot == Py_tp_getset) {
        PyGetSetDef *getset = (PyGetSetDef*) slot->pfunc;
        while (getset && getset->name) {
            if (getset->name[0] == '_' && getset->name[1] == '_' && strcmp(getset->name, "__module__") == 0) {
                PyObject *descr = PyDescr_NewGetSet(type, getset);
                if (unlikely(!descr))
                    return -1;
                #if CYTHON_COMPILING_IN_LIMITED_API
                PyObject *pyname = PyUnicode_FromString(getset->name);
                if (unlikely(!pyname)) {
                    Py_DECREF(descr);
                    return -1;
                }
                int set_item_result = __Pyx_SetItemOnTypeDict(type, pyname, descr);
                Py_DECREF(pyname);
                #else
                CYTHON_UNUSED_VAR(__Pyx__SetItemOnTypeDict);
                int set_item_result = PyDict_SetItem(type->tp_dict, PyDescr_NAME(descr), descr);
                #endif
                Py_DECREF(descr);
                if (unlikely(set_item_result < 0)) {
                    return -1;
                }
                changed = 1;
            }
            ++getset;
        }
    }
#else
    CYTHON_UNUSED_VAR(__Pyx__SetItemOnTypeDict);
#endif  // !CYTHON_COMPILING_IN_PYPY
    if (changed)
        PyType_Modified(type);
#endif  // PY_VERSION_HEX > 0x030900B1
    return 0;
}


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
    PyObject *arg[2] = {NULL, NULL};
    return __Pyx_PyObject_FastCall(func, arg + 1, 0 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET);
}


#if !(CYTHON_VECTORCALL && (__PYX_LIMITED_VERSION_HEX >= 0x030C0000 || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x03090000)))
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    __Pyx_TypeName type_name;
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if defined(Py_TPFLAGS_METHOD_DESCRIPTOR) && Py_TPFLAGS_METHOD_DESCRIPTOR
        if (__Pyx_PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_METHOD_DESCRIPTOR))
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_IS_TYPE(descr, &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || __Pyx_IS_TYPE(descr, &PyMethodDescr_Type)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (likely(descr != NULL)) {
        *method = descr;
        return 0;
    }
    type_name = __Pyx_PyType_GetFullyQualifiedName(tp);
    PyErr_Format(PyExc_AttributeError,
                 "'" __Pyx_FMT_TYPENAME "' object has no attribute '%U'",
                 type_name, name);
    __Pyx_DECREF_TypeName(type_name);
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}
#endif


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name) {
#if CYTHON_VECTORCALL && (__PYX_LIMITED_VERSION_HEX >= 0x030C0000 || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x03090000))
    PyObject *args[1] = {obj};
    (void) __Pyx_PyObject_CallOneArg;
    (void) __Pyx_PyObject_CallNoArg;
    return PyObject_VectorcallMethod(method_name, args, 1 | PY_VECTORCALL_ARGUMENTS_OFFSET, NULL);
#else
    PyObject *method = NULL, *result = NULL;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_CallOneArg(method, obj);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) goto bad;
    result = __Pyx_PyObject_CallNoArg(method);
    Py_DECREF(method);
bad:
    return result;
#endif
}


#if CYTHON_COMPILING_IN_CPYTHON || CYTHON_COMPILING_IN_LIMITED_API || CYTHON_USE_TYPE_SPECS
static int __Pyx_validate_bases_tuple(const char *type_name, Py_ssize_t dictoffset, PyObject *bases) {
    Py_ssize_t i, n;
#if CYTHON_ASSUME_SAFE_SIZE
    n = PyTuple_GET_SIZE(bases);
#else
    n = PyTuple_Size(bases);
    if (unlikely(n < 0)) return -1;
#endif
    for (i = 1; i < n; i++)
    {
        PyTypeObject *b;
#if CYTHON_AVOID_BORROWED_REFS
        PyObject *b0 = PySequence_GetItem(bases, i);
        if (!b0) return -1;
#elif CYTHON_ASSUME_SAFE_MACROS
        PyObject *b0 = PyTuple_GET_ITEM(bases, i);
#else
        PyObject *b0 = PyTuple_GetItem(bases, i);
        if (!b0) return -1;
#endif
        b = (PyTypeObject*) b0;
        if (!__Pyx_PyType_HasFeature(b, Py_TPFLAGS_HEAPTYPE))
        {
            __Pyx_TypeName b_name = __Pyx_PyType_GetFullyQualifiedName(b);
            PyErr_Format(PyExc_TypeError,
                "base class '" __Pyx_FMT_TYPENAME "' is not a heap type", b_name);
            __Pyx_DECREF_TypeName(b_name);
#if CYTHON_AVOID_BORROWED_REFS
            Py_DECREF(b0);
#endif
            return -1;
        }
        if (dictoffset == 0)
        {
            Py_ssize_t b_dictoffset = 0;
#if CYTHON_USE_TYPE_SLOTS
            b_dictoffset = b->tp_dictoffset;
#else
            PyObject *py_b_dictoffset = PyObject_GetAttrString((PyObject*)b, "__dictoffset__");
            if (!py_b_dictoffset) goto dictoffset_return;
            b_dictoffset = PyLong_AsSsize_t(py_b_dictoffset);
            Py_DECREF(py_b_dictoffset);
            if (b_dictoffset == -1 && PyErr_Occurred()) goto dictoffset_return;
#endif
            if (b_dictoffset) {
                {
                    __Pyx_TypeName b_name = __Pyx_PyType_GetFullyQualifiedName(b);
                    PyErr_Format(PyExc_TypeError,
                        "extension type '%.200s' has no __dict__ slot, "
                        "but base type '" __Pyx_FMT_TYPENAME "' has: "
                        "either add 'cdef dict __dict__' to the extension type "
                        "or add '__slots__ = [...]' to the base type",
                        type_name, b_name);
                    __Pyx_DECREF_TypeName(b_name);
                }
#if !CYTHON_USE_TYPE_SLOTS
              dictoffset_return:
#endif
#if CYTHON_AVOID_BORROWED_REFS
                Py_DECREF(b0);
#endif
                return -1;
            }
        }
#if CYTHON_AVOID_BORROWED_REFS
        Py_DECREF(b0);
#endif
    }
    return 0;
}
#endif


CYTHON_UNUSED static int __Pyx_PyType_HasMultipleInheritance(PyTypeObject *t) {
    while (t) {
        PyObject *bases = __Pyx_PyType_GetSlot(t, tp_bases, PyObject*);
        if (bases) {
            return 1;
        }
        t = __Pyx_PyType_GetSlot(t, tp_base, PyTypeObject*);
    }
    return 0;
}
static int __Pyx_PyType_Ready(PyTypeObject *t) {
#if CYTHON_USE_TYPE_SPECS || !CYTHON_COMPILING_IN_CPYTHON || defined(PYSTON_MAJOR_VERSION)
    (void)__Pyx_PyObject_CallMethod0;
#if CYTHON_USE_TYPE_SPECS
    (void)__Pyx_validate_bases_tuple;
#endif
    return PyType_Ready(t);
#else
    int r;
    if (!__Pyx_PyType_HasMultipleInheritance(t)) {
        return PyType_Ready(t);
    }
    PyObject *bases = __Pyx_PyType_GetSlot(t, tp_bases, PyObject*);
    if (bases && unlikely(__Pyx_validate_bases_tuple(t->tp_name, t->tp_dictoffset, bases) == -1))
        return -1;
#if !defined(PYSTON_MAJOR_VERSION)
    {
        int gc_was_enabled;
    #if PY_VERSION_HEX >= 0x030A00b1
        gc_was_enabled = PyGC_Disable();
        (void)__Pyx_PyObject_CallMethod0;
    #else
        PyObject *ret, *py_status;
        PyObject *gc = NULL;
        #if (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM+0 >= 0x07030400) &&\
                !CYTHON_COMPILING_IN_GRAAL
        gc = PyImport_GetModule(__pyx_mstate_global->__pyx_kp_u_gc);
        #endif
        if (unlikely(!gc)) gc = PyImport_Import(__pyx_mstate_global->__pyx_kp_u_gc);
        if (unlikely(!gc)) return -1;
        py_status = __Pyx_PyObject_CallMethod0(gc, __pyx_mstate_global->__pyx_kp_u_isenabled);
        if (unlikely(!py_status)) {
            Py_DECREF(gc);
            return -1;
        }
        gc_was_enabled = __Pyx_PyObject_IsTrue(py_status);
        Py_DECREF(py_status);
        if (gc_was_enabled > 0) {
            ret = __Pyx_PyObject_CallMethod0(gc, __pyx_mstate_global->__pyx_kp_u_disable);
            if (unlikely(!ret)) {
                Py_DECREF(gc);
                return -1;
            }
            Py_DECREF(ret);
        } else if (unlikely(gc_was_enabled == -1)) {
            Py_DECREF(gc);
            return -1;
        }
    #endif
        t->tp_flags |= Py_TPFLAGS_HEAPTYPE;
#if PY_VERSION_HEX >= 0x030A0000
        t->tp_flags |= Py_TPFLAGS_IMMUTABLETYPE;
#endif
#else
        (void)__Pyx_PyObject_CallMethod0;
#endif
    r = PyType_Ready(t);
#if !defined(PYSTON_MAJOR_VERSION)
        t->tp_flags &= ~Py_TPFLAGS_HEAPTYPE;
    #if PY_VERSION_HEX >= 0x030A00b1
        if (gc_was_enabled)
            PyGC_Enable();
    #else
        if (gc_was_enabled) {
            PyObject *tp, *v, *tb;
            PyErr_Fetch(&tp, &v, &tb);
            ret = __Pyx_PyObject_CallMethod0(gc, __pyx_mstate_global->__pyx_kp_u_enable);
            if (likely(ret || r == -1)) {
                Py_XDECREF(ret);
                PyErr_Restore(tp, v, tb);
            } else {
                Py_XDECREF(tp);
                Py_XDECREF(v);
                Py_XDECREF(tb);
                r = -1;
            }
        }
        Py_DECREF(gc);
    #endif
    }
#endif
    return r;
#endif
}


static CYTHON_INLINE PyObject *__Pyx_PyDict_SetDefault(PyObject *d, PyObject *key, PyObject *default_value) {
    PyObject* value;
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX >= 0x030C0000
    PyObject *args[] = {d, key, default_value};
    value = PyObject_VectorcallMethod(__pyx_mstate_global->__pyx_n_u_setdefault, args, 3 | PY_VECTORCALL_ARGUMENTS_OFFSET, NULL);
#elif CYTHON_COMPILING_IN_LIMITED_API
    value = PyObject_CallMethodObjArgs(d, __pyx_mstate_global->__pyx_n_u_setdefault, key, default_value, NULL);
#elif PY_VERSION_HEX >= 0x030d0000
    PyDict_SetDefaultRef(d, key, default_value, &value);
#else
    value = PyDict_SetDefault(d, key, default_value);
    if (unlikely(!value)) return NULL;
    Py_INCREF(value);
#endif
    return value;
}


#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
  static PyObject *__Pyx_PyImport_AddModuleObjectRef(PyObject *name) {
      PyObject *module_dict = PyImport_GetModuleDict();
      PyObject *m;
      if (PyMapping_GetOptionalItem(module_dict, name, &m) < 0) {
          return NULL;
      }
      if (m != NULL && PyModule_Check(m)) {
          return m;
      }
      Py_XDECREF(m);
      m = PyModule_NewObject(name);
      if (m == NULL)
          return NULL;
      if (PyDict_CheckExact(module_dict)) {
          PyObject *new_m;
          (void)PyDict_SetDefaultRef(module_dict, name, m, &new_m);
          Py_DECREF(m);
          return new_m;
      } else {
           if (PyObject_SetItem(module_dict, name, m) != 0) {
                Py_DECREF(m);
                return NULL;
            }
            return m;
      }
  }
  static PyObject *__Pyx_PyImport_AddModuleRef(const char *name) {
      PyObject *py_name = PyUnicode_FromString(name);
      if (!py_name) return NULL;
      PyObject *module = __Pyx_PyImport_AddModuleObjectRef(py_name);
      Py_DECREF(py_name);
      return module;
  }
#elif __PYX_LIMITED_VERSION_HEX >= 0x030d0000
  #define __Pyx_PyImport_AddModuleRef(name) PyImport_AddModuleRef(name)
#else
  static PyObject *__Pyx_PyImport_AddModuleRef(const char *name) {
      PyObject *module = PyImport_AddModule(name);
      Py_XINCREF(module);
      return module;
  }
#endif


static PyObject *__Pyx_FetchSharedCythonABIModule(void) {
    return __Pyx_PyImport_AddModuleRef(__PYX_ABI_MODULE_NAME);
}


#if __PYX_LIMITED_VERSION_HEX < 0x030C0000
static PyObject* __Pyx_PyType_FromMetaclass(PyTypeObject *metaclass, PyObject *module, PyType_Spec *spec, PyObject *bases) {
    PyObject *result = __Pyx_PyType_FromModuleAndSpec(module, spec, bases);
    if (result && metaclass) {
        PyObject *old_tp = (PyObject*)Py_TYPE(result);
    Py_INCREF((PyObject*)metaclass);
#if __PYX_LIMITED_VERSION_HEX >= 0x03090000
        Py_SET_TYPE(result, metaclass);
#else
        result->ob_type = metaclass;
#endif
        Py_DECREF(old_tp);
    }
    return result;
}
#else
#define __Pyx_PyType_FromMetaclass(me, mo, s, b) PyType_FromMetaclass(me, mo, s, b)
#endif
static int __Pyx_VerifyCachedType(PyObject *cached_type,
                               const char *name,
                               Py_ssize_t expected_basicsize) {
    Py_ssize_t basicsize;
    if (!PyType_Check(cached_type)) {
        PyErr_Format(PyExc_TypeError,
            "Shared Cython type %.200s is not a type object", name);
        return -1;
    }
    if (expected_basicsize == 0) {
        return 0; // size is inherited, nothing useful to check
    }
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *py_basicsize;
    py_basicsize = PyObject_GetAttrString(cached_type, "__basicsize__");
    if (unlikely(!py_basicsize)) return -1;
    basicsize = PyLong_AsSsize_t(py_basicsize);
    Py_DECREF(py_basicsize);
    py_basicsize = NULL;
    if (unlikely(basicsize == (Py_ssize_t)-1) && PyErr_Occurred()) return -1;
#else
    basicsize = ((PyTypeObject*) cached_type)->tp_basicsize;
#endif
    if (basicsize != expected_basicsize) {
        PyErr_Format(PyExc_TypeError,
            "Shared Cython type %.200s has the wrong size, try recompiling",
            name);
        return -1;
    }
    return 0;
}
static PyTypeObject *__Pyx_FetchCommonTypeFromSpec(PyTypeObject *metaclass, PyObject *module, PyType_Spec *spec, PyObject *bases) {
    PyObject *abi_module = NULL, *cached_type = NULL, *abi_module_dict, *new_cached_type, *py_object_name;
    int get_item_ref_result;
    const char* object_name = strrchr(spec->name, '.');
    object_name = object_name ? object_name+1 : spec->name;
    py_object_name = PyUnicode_FromString(object_name);
    if (!py_object_name) return NULL;
    abi_module = __Pyx_FetchSharedCythonABIModule();
    if (!abi_module) goto done;
    abi_module_dict = PyModule_GetDict(abi_module);
    if (!abi_module_dict) goto done;
    get_item_ref_result = __Pyx_PyDict_GetItemRef(abi_module_dict, py_object_name, &cached_type);
    if (get_item_ref_result == 1) {
        if (__Pyx_VerifyCachedType(
              cached_type,
              object_name,
              spec->basicsize) < 0) {
            goto bad;
        }
        goto done;
    } else if (unlikely(get_item_ref_result == -1)) {
        goto bad;
    }
    cached_type = __Pyx_PyType_FromMetaclass(
        metaclass,
        CYTHON_USE_MODULE_STATE ? module : abi_module,
        spec, bases);
    if (unlikely(!cached_type)) goto bad;
    if (unlikely(__Pyx_fix_up_extension_type_from_spec(spec, (PyTypeObject *) cached_type) < 0)) goto bad;
    new_cached_type = __Pyx_PyDict_SetDefault(abi_module_dict, py_object_name, cached_type);
    if (unlikely(new_cached_type != cached_type)) {
        if (unlikely(!new_cached_type)) goto bad;
        Py_DECREF(cached_type);
        cached_type = new_cached_type;
        if (__Pyx_VerifyCachedType(
                cached_type,
                object_name,
                spec->basicsize) < 0) {
            goto bad;
        }
        goto done;
    } else {
        Py_DECREF(new_cached_type);
    }
done:
    Py_XDECREF(abi_module);
    Py_DECREF(py_object_name);
    assert(cached_type == NULL || PyType_Check(cached_type));
    return (PyTypeObject *) cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


static PyObject* __pyx_CommonTypesMetaclass_get_module(CYTHON_UNUSED PyObject *self, CYTHON_UNUSED void* context) {
    return PyUnicode_FromString(__PYX_ABI_MODULE_NAME);
}
#if __PYX_LIMITED_VERSION_HEX < 0x030A0000
static PyObject* __pyx_CommonTypesMetaclass_call(CYTHON_UNUSED PyObject *self, CYTHON_UNUSED PyObject *args, CYTHON_UNUSED PyObject *kwds) {
    PyErr_SetString(PyExc_TypeError, "Cannot instantiate Cython internal types");
    return NULL;
}
static int __pyx_CommonTypesMetaclass_setattr(CYTHON_UNUSED PyObject *self, CYTHON_UNUSED PyObject *attr, CYTHON_UNUSED PyObject *value) {
    PyErr_SetString(PyExc_TypeError, "Cython internal types are immutable");
    return -1;
}
#endif
static PyGetSetDef __pyx_CommonTypesMetaclass_getset[] = {
    {"__module__", __pyx_CommonTypesMetaclass_get_module, NULL, NULL, NULL},
    {0, 0, 0, 0, 0}
};
static PyType_Slot __pyx_CommonTypesMetaclass_slots[] = {
    {Py_tp_getset, (void *)__pyx_CommonTypesMetaclass_getset},
    #if __PYX_LIMITED_VERSION_HEX < 0x030A0000
    {Py_tp_call, (void*)__pyx_CommonTypesMetaclass_call},
    {Py_tp_new, (void*)__pyx_CommonTypesMetaclass_call},
    {Py_tp_setattro, (void*)__pyx_CommonTypesMetaclass_setattr},
    #endif
    {0, 0}
};
static PyType_Spec __pyx_CommonTypesMetaclass_spec = {
    __PYX_TYPE_MODULE_PREFIX "_common_types_metatype",
    0,
    0,
    Py_TPFLAGS_IMMUTABLETYPE |
    Py_TPFLAGS_DISALLOW_INSTANTIATION |
    Py_TPFLAGS_DEFAULT,
    __pyx_CommonTypesMetaclass_slots
};
static int __pyx_CommonTypesMetaclass_init(PyObject *module) {
    __pyx_mstatetype *mstate = __Pyx_PyModule_GetState(module);
    PyObject *bases = PyTuple_Pack(1, &PyType_Type);
    if (unlikely(!bases)) {
        return -1;
    }
    mstate->__pyx_CommonTypesMetaclassType = __Pyx_FetchCommonTypeFromSpec(NULL, module, &__pyx_CommonTypesMetaclass_spec, bases);
    Py_DECREF(bases);
    if (unlikely(mstate->__pyx_CommonTypesMetaclassType == NULL)) {
        return -1;
    }
    return 0;
}


#if CYTHON_COMPILING_IN_LIMITED_API
static PyObject *__Pyx_PyMethod_New(PyObject *func, PyObject *self, PyObject *typ) {
    PyObject *result;
    CYTHON_UNUSED_VAR(typ);
    if (!self)
        return __Pyx_NewRef(func);
    #if __PYX_LIMITED_VERSION_HEX >= 0x030C0000
    {
        PyObject *args[] = {func, self};
        result = PyObject_Vectorcall(__pyx_mstate_global->__Pyx_CachedMethodType, args, 2, NULL);
    }
    #else
    result = PyObject_CallFunctionObjArgs(__pyx_mstate_global->__Pyx_CachedMethodType, func, self, NULL);
    #endif
    return result;
}
#else
static PyObject *__Pyx_PyMethod_New(PyObject *func, PyObject *self, PyObject *typ) {
    CYTHON_UNUSED_VAR(typ);
    if (!self)
        return __Pyx_NewRef(func);
    return PyMethod_New(func, self);
}
#endif


#if CYTHON_METH_FASTCALL && CYTHON_VECTORCALL
static PyObject *__Pyx_PyVectorcall_FastCallDict_kw(PyObject *func, __pyx_vectorcallfunc vc, PyObject *const *args, size_t nargs, PyObject *kw)
{
    PyObject *res = NULL;
    PyObject *kwnames;
    PyObject **newargs;
    PyObject **kwvalues;
    Py_ssize_t i;
    #if CYTHON_AVOID_BORROWED_REFS
    PyObject *pos;
    #else
    Py_ssize_t pos;
    #endif
    size_t j;
    PyObject *key, *value;
    unsigned long keys_are_strings;
    #if !CYTHON_ASSUME_SAFE_SIZE
    Py_ssize_t nkw = PyDict_Size(kw);
    if (unlikely(nkw == -1)) return NULL;
    #else
    Py_ssize_t nkw = PyDict_GET_SIZE(kw);
    #endif
    newargs = (PyObject **)PyMem_Malloc((nargs + (size_t)nkw) * sizeof(args[0]));
    if (unlikely(newargs == NULL)) {
        PyErr_NoMemory();
        return NULL;
    }
    for (j = 0; j < nargs; j++) newargs[j] = args[j];
    kwnames = PyTuple_New(nkw);
    if (unlikely(kwnames == NULL)) {
        PyMem_Free(newargs);
        return NULL;
    }
    kwvalues = newargs + nargs;
    pos = 0;
    i = 0;
    keys_are_strings = Py_TPFLAGS_UNICODE_SUBCLASS;
    while (__Pyx_PyDict_NextRef(kw, &pos, &key, &value)) {
        keys_are_strings &=
        #if CYTHON_COMPILING_IN_LIMITED_API
            PyType_GetFlags(Py_TYPE(key));
        #else
            Py_TYPE(key)->tp_flags;
        #endif
        #if !CYTHON_ASSUME_SAFE_MACROS
        if (unlikely(PyTuple_SetItem(kwnames, i, key) < 0)) goto cleanup;
        #else
        PyTuple_SET_ITEM(kwnames, i, key);
        #endif
        kwvalues[i] = value;
        i++;
    }
    if (unlikely(!keys_are_strings)) {
        PyErr_SetString(PyExc_TypeError, "keywords must be strings");
        goto cleanup;
    }
    res = vc(func, newargs, nargs, kwnames);
cleanup:
    #if CYTHON_AVOID_BORROWED_REFS
    Py_DECREF(pos);
    #endif
    Py_DECREF(kwnames);
    for (i = 0; i < nkw; i++)
        Py_DECREF(kwvalues[i]);
    PyMem_Free(newargs);
    return res;
}
static CYTHON_INLINE PyObject *__Pyx_PyVectorcall_FastCallDict(PyObject *func, __pyx_vectorcallfunc vc, PyObject *const *args, size_t nargs, PyObject *kw)
{
    Py_ssize_t kw_size =
        likely(kw == NULL) ?
        0 :
#if !CYTHON_ASSUME_SAFE_SIZE
        PyDict_Size(kw);
#else
        PyDict_GET_SIZE(kw);
#endif
    if (kw_size == 0) {
        return vc(func, args, nargs, NULL);
    }
#if !CYTHON_ASSUME_SAFE_SIZE
    else if (unlikely(kw_size == -1)) {
        return NULL;
    }
#endif
    return __Pyx_PyVectorcall_FastCallDict_kw(func, vc, args, nargs, kw);
}
#endif


#if CYTHON_COMPILING_IN_LIMITED_API
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunctionNoMethod(PyObject *func, void (*cfunc)(void)) {
    if (__Pyx_CyFunction_Check(func)) {
        return PyCFunction_GetFunction(((__pyx_CyFunctionObject*)func)->func) == (PyCFunction) cfunc;
    } else if (PyCFunction_Check(func)) {
        return PyCFunction_GetFunction(func) == (PyCFunction) cfunc;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(PyObject *func, void (*cfunc)(void)) {
    if ((PyObject*)Py_TYPE(func) == __pyx_mstate_global->__Pyx_CachedMethodType) {
        int result;
        PyObject *newFunc = PyObject_GetAttr(func, __pyx_mstate_global->__pyx_n_u_func);
        if (unlikely(!newFunc)) {
            PyErr_Clear(); // It's only an optimization, so don't throw an error
            return 0;
        }
        result = __Pyx__IsSameCyOrCFunctionNoMethod(newFunc, cfunc);
        Py_DECREF(newFunc);
        return result;
    }
    return __Pyx__IsSameCyOrCFunctionNoMethod(func, cfunc);
}
#else
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(PyObject *func, void (*cfunc)(void)) {
    if (PyMethod_Check(func)) {
        func = PyMethod_GET_FUNCTION(func);
    }
    return __Pyx_CyOrPyCFunction_Check(func) && __Pyx_CyOrPyCFunction_GET_FUNCTION(func) == (PyCFunction) cfunc;
}
#endif
static CYTHON_INLINE void __Pyx__CyFunction_SetClassObj(__pyx_CyFunctionObject* f, PyObject* classobj) {
#if PY_VERSION_HEX < 0x030900B1 || CYTHON_COMPILING_IN_LIMITED_API
    __Pyx_Py_XDECREF_SET(
        __Pyx_CyFunction_GetClassObj(f),
            ((classobj) ? __Pyx_NewRef(classobj) : NULL));
#else
    __Pyx_Py_XDECREF_SET(
        ((PyCMethodObject *) (f))->mm_class,
        (PyTypeObject*)((classobj) ? __Pyx_NewRef(classobj) : NULL));
#endif
}
static PyObject *
__Pyx_CyFunction_get_doc_locked(__pyx_CyFunctionObject *op)
{
    if (unlikely(op->func_doc == NULL)) {
#if CYTHON_COMPILING_IN_LIMITED_API
        op->func_doc = PyObject_GetAttrString(op->func, "__doc__");
        if (unlikely(!op->func_doc)) return NULL;
#else
        if (((PyCFunctionObject*)op)->m_ml->ml_doc) {
            op->func_doc = PyUnicode_FromString(((PyCFunctionObject*)op)->m_ml->ml_doc);
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
#endif
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, void *closure) {
    PyObject *result;
    CYTHON_UNUSED_VAR(closure);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    result = __Pyx_CyFunction_get_doc_locked(op);
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->func_doc, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name_locked(__pyx_CyFunctionObject *op)
{
    if (unlikely(op->func_name == NULL)) {
#if CYTHON_COMPILING_IN_LIMITED_API
        op->func_name = PyObject_GetAttrString(op->func, "__name__");
#else
        op->func_name = PyUnicode_InternFromString(((PyCFunctionObject*)op)->m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, void *context)
{
    PyObject *result = NULL;
    CYTHON_UNUSED_VAR(context);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    result = __Pyx_CyFunction_get_name_locked(op);
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(value == NULL || !PyUnicode_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    Py_INCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->func_name, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, void *context)
{
    CYTHON_UNUSED_VAR(context);
    PyObject *result;
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    Py_INCREF(op->func_qualname);
    result = op->func_qualname;
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(value == NULL || !PyUnicode_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    Py_INCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->func_qualname, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
#endif
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, void *context)
{
    CYTHON_UNUSED_VAR(context);
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(__pyx_CyFunctionObject *op, void *context)
{
    CYTHON_UNUSED_VAR(op);
    CYTHON_UNUSED_VAR(context);
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    CYTHON_UNUSED_VAR(context);
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = __Pyx_PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = __Pyx_PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (!value) {
        value = Py_None;
    } else if (unlikely(value != Py_None && !PyTuple_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    PyErr_WarnEx(PyExc_RuntimeWarning, "changes to cyfunction.__defaults__ will not "
                 "currently affect the values used in function calls", 1);
    Py_INCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->defaults_tuple, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults_locked(__pyx_CyFunctionObject *op) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (unlikely(__Pyx_CyFunction_init_defaults(op) < 0)) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, void *context) {
    PyObject* result = NULL;
    CYTHON_UNUSED_VAR(context);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    result = __Pyx_CyFunction_get_defaults_locked(op);
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (!value) {
        value = Py_None;
    } else if (unlikely(value != Py_None && !PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    PyErr_WarnEx(PyExc_RuntimeWarning, "changes to cyfunction.__kwdefaults__ will not "
                 "currently affect the values used in function calls", 1);
    Py_INCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->defaults_kwdict, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults_locked(__pyx_CyFunctionObject *op) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (unlikely(__Pyx_CyFunction_init_defaults(op) < 0)) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, void *context) {
    PyObject* result;
    CYTHON_UNUSED_VAR(context);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    result = __Pyx_CyFunction_get_kwdefaults_locked(op);
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (!value || value == Py_None) {
        value = NULL;
    } else if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    __Pyx_Py_XDECREF_SET(op->func_annotations, value);
    __Pyx_END_CRITICAL_SECTION();
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations_locked(__pyx_CyFunctionObject *op) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, void *context) {
    PyObject *result;
    CYTHON_UNUSED_VAR(context);
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    result = __Pyx_CyFunction_get_annotations_locked(op);
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static PyObject *
__Pyx_CyFunction_get_is_coroutine_value(__pyx_CyFunctionObject *op) {
    int is_coroutine = op->flags & __Pyx_CYFUNCTION_COROUTINE;
    if (is_coroutine) {
        PyObject *is_coroutine_value, *module, *fromlist, *marker = __pyx_mstate_global->__pyx_n_u_is_coroutine;
        fromlist = PyList_New(1);
        if (unlikely(!fromlist)) return NULL;
        Py_INCREF(marker);
#if CYTHON_ASSUME_SAFE_MACROS
        PyList_SET_ITEM(fromlist, 0, marker);
#else
        if (unlikely(PyList_SetItem(fromlist, 0, marker) < 0)) {
            Py_DECREF(marker);
            Py_DECREF(fromlist);
            return NULL;
        }
#endif
        module = PyImport_ImportModuleLevelObject(__pyx_mstate_global->__pyx_n_u_asyncio_coroutines, NULL, NULL, fromlist, 0);
        Py_DECREF(fromlist);
        if (unlikely(!module)) goto ignore;
        is_coroutine_value = __Pyx_PyObject_GetAttrStr(module, marker);
        Py_DECREF(module);
        if (likely(is_coroutine_value)) {
            return is_coroutine_value;
        }
ignore:
        PyErr_Clear();
    }
    return __Pyx_PyBool_FromLong(is_coroutine);
}
static PyObject *
__Pyx_CyFunction_get_is_coroutine(__pyx_CyFunctionObject *op, void *context) {
    PyObject *result;
    CYTHON_UNUSED_VAR(context);
    if (op->func_is_coroutine) {
        return __Pyx_NewRef(op->func_is_coroutine);
    }
    result = __Pyx_CyFunction_get_is_coroutine_value(op);
    if (unlikely(!result))
        return NULL;
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    if (op->func_is_coroutine) {
        Py_DECREF(result);
        result = __Pyx_NewRef(op->func_is_coroutine);
    } else {
        op->func_is_coroutine = __Pyx_NewRef(result);
    }
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static void __Pyx_CyFunction_raise_argument_count_error(__pyx_CyFunctionObject *func, const char* message, Py_ssize_t size) {
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *py_name = __Pyx_CyFunction_get_name(func, NULL);
    if (!py_name) return;
    PyErr_Format(PyExc_TypeError,
        "%.200S() %s (%" CYTHON_FORMAT_SSIZE_T "d given)",
        py_name, message, size);
    Py_DECREF(py_name);
#else
    const char* name = ((PyCFunctionObject*)func)->m_ml->ml_name;
    PyErr_Format(PyExc_TypeError,
        "%.200s() %s (%" CYTHON_FORMAT_SSIZE_T "d given)",
        name, message, size);
#endif
}
static void __Pyx_CyFunction_raise_type_error(__pyx_CyFunctionObject *func, const char* message) {
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *py_name = __Pyx_CyFunction_get_name(func, NULL);
    if (!py_name) return;
    PyErr_Format(PyExc_TypeError,
        "%.200S() %s",
        py_name, message);
    Py_DECREF(py_name);
#else
    const char* name = ((PyCFunctionObject*)func)->m_ml->ml_name;
    PyErr_Format(PyExc_TypeError,
        "%.200s() %s",
        name, message);
#endif
}
#if CYTHON_COMPILING_IN_LIMITED_API
static PyObject *
__Pyx_CyFunction_get_module(__pyx_CyFunctionObject *op, void *context) {
    CYTHON_UNUSED_VAR(context);
    return PyObject_GetAttrString(op->func, "__module__");
}
static int
__Pyx_CyFunction_set_module(__pyx_CyFunctionObject *op, PyObject* value, void *context) {
    CYTHON_UNUSED_VAR(context);
    return PyObject_SetAttrString(op->func, "__module__", value);
}
#endif
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {"func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {"__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {"func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {"__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {"__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
    {"func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)PyObject_GenericSetDict, 0, 0},
    {"__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)PyObject_GenericSetDict, 0, 0},
#else
    {"func_dict", (getter)PyObject_GenericGetDict, (setter)PyObject_GenericSetDict, 0, 0},
    {"__dict__", (getter)PyObject_GenericGetDict, (setter)PyObject_GenericSetDict, 0, 0},
#endif
    {"func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {"__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {"func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {"__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {"func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {"__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {"func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {"__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {"__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {"__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {"_is_coroutine", (getter)__Pyx_CyFunction_get_is_coroutine, 0, 0, 0},
#if CYTHON_COMPILING_IN_LIMITED_API
    {"__module__", (getter)__Pyx_CyFunction_get_module, (setter)__Pyx_CyFunction_set_module, 0, 0},
#endif
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
#if !CYTHON_COMPILING_IN_LIMITED_API
    {"__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), 0, 0},
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    {"__dictoffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_dict), READONLY, 0},
#endif
#if CYTHON_METH_FASTCALL
#if CYTHON_COMPILING_IN_LIMITED_API
    {"__vectorcalloffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_vectorcall), READONLY, 0},
#else
    {"__vectorcalloffset__", T_PYSSIZET, offsetof(PyCFunctionObject, vectorcall), READONLY, 0},
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
    {"__weaklistoffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_weakreflist), READONLY, 0},
#else
    {"__weaklistoffset__", T_PYSSIZET, offsetof(PyCFunctionObject, m_weakreflist), READONLY, 0},
#endif
#endif
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, PyObject *args)
{
    PyObject *result = NULL;
    CYTHON_UNUSED_VAR(args);
    __Pyx_BEGIN_CRITICAL_SECTION(m);
    Py_INCREF(m->func_qualname);
    result = m->func_qualname;
    __Pyx_END_CRITICAL_SECTION();
    return result;
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) (((PyCFunctionObject*)cyfunc)->m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
#if !CYTHON_COMPILING_IN_LIMITED_API
    PyCFunctionObject *cf = (PyCFunctionObject*) op;
#endif
    if (unlikely(op == NULL))
        return NULL;
#if CYTHON_COMPILING_IN_LIMITED_API
    op->func = PyCFunction_NewEx(ml, (PyObject*)op, module);
    if (unlikely(!op->func)) return NULL;
#endif
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
#if !CYTHON_COMPILING_IN_LIMITED_API
    cf->m_ml = ml;
    cf->m_self = (PyObject *) op;
#endif
    Py_XINCREF(closure);
    op->func_closure = closure;
#if !CYTHON_COMPILING_IN_LIMITED_API
    Py_XINCREF(module);
    cf->m_module = module;
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    op->func_dict = NULL;
#endif
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
#if PY_VERSION_HEX < 0x030900B1 || CYTHON_COMPILING_IN_LIMITED_API
    op->func_classobj = NULL;
#else
    ((PyCMethodObject*)op)->mm_class = NULL;
#endif
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    op->func_is_coroutine = NULL;
#if CYTHON_METH_FASTCALL
    switch (ml->ml_flags & (METH_VARARGS | METH_FASTCALL | METH_NOARGS | METH_O | METH_KEYWORDS | METH_METHOD)) {
    case METH_NOARGS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_NOARGS;
        break;
    case METH_O:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_O;
        break;
    case METH_METHOD | METH_FASTCALL | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD;
        break;
    case METH_FASTCALL | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS;
        break;
    case METH_VARARGS | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = NULL;
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags for CyFunction");
        Py_DECREF(op);
        return NULL;
    }
#endif
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
#if CYTHON_COMPILING_IN_LIMITED_API
    Py_CLEAR(m->func);
#else
    Py_CLEAR(((PyCFunctionObject*)m)->m_module);
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    Py_CLEAR(m->func_dict);
#elif PY_VERSION_HEX < 0x030d0000
    _PyObject_ClearManagedDict((PyObject*)m);
#else
    PyObject_ClearManagedDict((PyObject*)m);
#endif
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
#if !CYTHON_COMPILING_IN_LIMITED_API
#if PY_VERSION_HEX < 0x030900B1
    Py_CLEAR(__Pyx_CyFunction_GetClassObj(m));
#else
    {
        PyObject *cls = (PyObject*) ((PyCMethodObject *) (m))->mm_class;
        ((PyCMethodObject *) (m))->mm_class = NULL;
        Py_XDECREF(cls);
    }
#endif
#endif
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    Py_CLEAR(m->func_is_coroutine);
    Py_CLEAR(m->defaults);
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    __Pyx_PyHeapTypeObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    {
        int e = __Pyx_call_type_traverse((PyObject*)m, 1, visit, arg);
        if (e) return e;
    }
    Py_VISIT(m->func_closure);
#if CYTHON_COMPILING_IN_LIMITED_API
    Py_VISIT(m->func);
#else
    Py_VISIT(((PyCFunctionObject*)m)->m_module);
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    Py_VISIT(m->func_dict);
#else
    {
        int e =
#if PY_VERSION_HEX < 0x030d0000
            _PyObject_VisitManagedDict
#else
            PyObject_VisitManagedDict
#endif
                ((PyObject*)m, visit, arg);
        if (e != 0) return e;
    }
#endif
    __Pyx_VISIT_CONST(m->func_name);
    __Pyx_VISIT_CONST(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    __Pyx_VISIT_CONST(m->func_code);
#if !CYTHON_COMPILING_IN_LIMITED_API
    Py_VISIT(__Pyx_CyFunction_GetClassObj(m));
#endif
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    Py_VISIT(m->func_is_coroutine);
    Py_VISIT(m->defaults);
    return 0;
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
    PyObject *repr;
    __Pyx_BEGIN_CRITICAL_SECTION(op);
    repr = PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
    __Pyx_END_CRITICAL_SECTION();
    return repr;
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *f = ((__pyx_CyFunctionObject*)func)->func;
    PyCFunction meth;
    int flags;
    meth = PyCFunction_GetFunction(f);
    if (unlikely(!meth)) return NULL;
    flags = PyCFunction_GetFlags(f);
    if (unlikely(flags < 0)) return NULL;
#else
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    int flags = f->m_ml->ml_flags;
#endif
    Py_ssize_t size;
    switch (flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void(*)(void))meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
#if CYTHON_ASSUME_SAFE_SIZE
            size = PyTuple_GET_SIZE(arg);
#else
            size = PyTuple_Size(arg);
            if (unlikely(size < 0)) return NULL;
#endif
            if (likely(size == 0))
                return (*meth)(self, NULL);
            __Pyx_CyFunction_raise_argument_count_error(
                (__pyx_CyFunctionObject*)func,
                "takes no arguments", size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
#if CYTHON_ASSUME_SAFE_SIZE
            size = PyTuple_GET_SIZE(arg);
#else
            size = PyTuple_Size(arg);
            if (unlikely(size < 0)) return NULL;
#endif
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = __Pyx_PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            __Pyx_CyFunction_raise_argument_count_error(
                (__pyx_CyFunctionObject*)func,
                "takes exactly one argument", size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags for CyFunction");
        return NULL;
    }
    __Pyx_CyFunction_raise_type_error(
        (__pyx_CyFunctionObject*)func, "takes no keyword arguments");
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *self, *result;
#if CYTHON_COMPILING_IN_LIMITED_API
    self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)func)->func);
    if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
    self = ((PyCFunctionObject*)func)->m_self;
#endif
    result = __Pyx_CyFunction_CallMethod(func, self, arg, kw);
    return result;
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
#if CYTHON_METH_FASTCALL && CYTHON_VECTORCALL
     __pyx_vectorcallfunc vc = __Pyx_CyFunction_func_vectorcall(cyfunc);
    if (vc) {
#if CYTHON_ASSUME_SAFE_MACROS && CYTHON_ASSUME_SAFE_SIZE
        return __Pyx_PyVectorcall_FastCallDict(func, vc, &PyTuple_GET_ITEM(args, 0), (size_t)PyTuple_GET_SIZE(args), kw);
#else
        (void) &__Pyx_PyVectorcall_FastCallDict;
        return PyVectorcall_Call(func, args, kw);
#endif
    }
#endif
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
#if CYTHON_ASSUME_SAFE_SIZE
        argc = PyTuple_GET_SIZE(args);
#else
        argc = PyTuple_Size(args);
        if (unlikely(argc < 0)) return NULL;
#endif
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            PyErr_Format(PyExc_TypeError,
                         "unbound method %.200S() needs an argument",
                         cyfunc->func_qualname);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
#if CYTHON_METH_FASTCALL && CYTHON_VECTORCALL
static CYTHON_INLINE int __Pyx_CyFunction_Vectorcall_CheckArgs(__pyx_CyFunctionObject *cyfunc, Py_ssize_t nargs, PyObject *kwnames)
{
    int ret = 0;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        if (unlikely(nargs < 1)) {
            __Pyx_CyFunction_raise_type_error(
                cyfunc, "needs an argument");
            return -1;
        }
        ret = 1;
    }
    if (unlikely(kwnames) && unlikely(__Pyx_PyTuple_GET_SIZE(kwnames))) {
        __Pyx_CyFunction_raise_type_error(
            cyfunc, "takes no keyword arguments");
        return -1;
    }
    return ret;
}
static PyObject * __Pyx_CyFunction_Vectorcall_NOARGS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
    PyObject *self;
#if CYTHON_COMPILING_IN_LIMITED_API
    PyCFunction meth = PyCFunction_GetFunction(cyfunc->func);
    if (unlikely(!meth)) return NULL;
#else
    PyCFunction meth = ((PyCFunctionObject*)cyfunc)->m_ml->ml_meth;
#endif
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
#if CYTHON_COMPILING_IN_LIMITED_API
        self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)cyfunc)->func);
        if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
        self = ((PyCFunctionObject*)cyfunc)->m_self;
#endif
        break;
    default:
        return NULL;
    }
    if (unlikely(nargs != 0)) {
        __Pyx_CyFunction_raise_argument_count_error(
            cyfunc, "takes no arguments", nargs);
        return NULL;
    }
    return meth(self, NULL);
}
static PyObject * __Pyx_CyFunction_Vectorcall_O(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
    PyObject *self;
#if CYTHON_COMPILING_IN_LIMITED_API
    PyCFunction meth = PyCFunction_GetFunction(cyfunc->func);
    if (unlikely(!meth)) return NULL;
#else
    PyCFunction meth = ((PyCFunctionObject*)cyfunc)->m_ml->ml_meth;
#endif
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
#if CYTHON_COMPILING_IN_LIMITED_API
        self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)cyfunc)->func);
        if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
        self = ((PyCFunctionObject*)cyfunc)->m_self;
#endif
        break;
    default:
        return NULL;
    }
    if (unlikely(nargs != 1)) {
        __Pyx_CyFunction_raise_argument_count_error(
            cyfunc, "takes exactly one argument", nargs);
        return NULL;
    }
    return meth(self, args[0]);
}
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
    PyObject *self;
#if CYTHON_COMPILING_IN_LIMITED_API
    PyCFunction meth = PyCFunction_GetFunction(cyfunc->func);
    if (unlikely(!meth)) return NULL;
#else
    PyCFunction meth = ((PyCFunctionObject*)cyfunc)->m_ml->ml_meth;
#endif
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, NULL)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
#if CYTHON_COMPILING_IN_LIMITED_API
        self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)cyfunc)->func);
        if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
        self = ((PyCFunctionObject*)cyfunc)->m_self;
#endif
        break;
    default:
        return NULL;
    }
    return ((__Pyx_PyCFunctionFastWithKeywords)(void(*)(void))meth)(self, args, nargs, kwnames);
}
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    PyTypeObject *cls = (PyTypeObject *) __Pyx_CyFunction_GetClassObj(cyfunc);
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
    PyObject *self;
#if CYTHON_COMPILING_IN_LIMITED_API
    PyCFunction meth = PyCFunction_GetFunction(cyfunc->func);
    if (unlikely(!meth)) return NULL;
#else
    PyCFunction meth = ((PyCFunctionObject*)cyfunc)->m_ml->ml_meth;
#endif
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, NULL)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
#if CYTHON_COMPILING_IN_LIMITED_API
        self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)cyfunc)->func);
        if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
        self = ((PyCFunctionObject*)cyfunc)->m_self;
#endif
        break;
    default:
        return NULL;
    }
    #if PY_VERSION_HEX < 0x030e00A6
    size_t nargs_value = (size_t) nargs;
    #else
    Py_ssize_t nargs_value = nargs;
    #endif
    return ((__Pyx_PyCMethod)(void(*)(void))meth)(self, cls, args, nargs_value, kwnames);
}
#endif
static PyType_Slot __pyx_CyFunctionType_slots[] = {
    {Py_tp_dealloc, (void *)__Pyx_CyFunction_dealloc},
    {Py_tp_repr, (void *)__Pyx_CyFunction_repr},
    {Py_tp_call, (void *)__Pyx_CyFunction_CallAsMethod},
    {Py_tp_traverse, (void *)__Pyx_CyFunction_traverse},
    {Py_tp_clear, (void *)__Pyx_CyFunction_clear},
    {Py_tp_methods, (void *)__pyx_CyFunction_methods},
    {Py_tp_members, (void *)__pyx_CyFunction_members},
    {Py_tp_getset, (void *)__pyx_CyFunction_getsets},
    {Py_tp_descr_get, (void *)__Pyx_PyMethod_New},
    {0, 0},
};
static PyType_Spec __pyx_CyFunctionType_spec = {
    __PYX_TYPE_MODULE_PREFIX "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
#ifdef Py_TPFLAGS_METHOD_DESCRIPTOR
    Py_TPFLAGS_METHOD_DESCRIPTOR |
#endif
#if CYTHON_METH_FASTCALL
#if defined(Py_TPFLAGS_HAVE_VECTORCALL)
    Py_TPFLAGS_HAVE_VECTORCALL |
#elif defined(_Py_TPFLAGS_HAVE_VECTORCALL)
    _Py_TPFLAGS_HAVE_VECTORCALL |
#endif
#endif // CYTHON_METH_FASTCALL
#if PY_VERSION_HEX >= 0x030C0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_TPFLAGS_MANAGED_DICT |
#endif
    Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_DISALLOW_INSTANTIATION |
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE,
    __pyx_CyFunctionType_slots
};
static int __pyx_CyFunction_init(PyObject *module) {
    __pyx_mstatetype *mstate = __Pyx_PyModule_GetState(module);
    mstate->__pyx_CyFunctionType = __Pyx_FetchCommonTypeFromSpec(
        mstate->__pyx_CommonTypesMetaclassType, module, &__pyx_CyFunctionType_spec, NULL);
    if (unlikely(mstate->__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_InitDefaults(PyObject *func, PyTypeObject *defaults_type) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_CallObject((PyObject*)defaults_type, NULL); // _PyObject_New(defaults_type);
    if (unlikely(!m->defaults))
        return NULL;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_mstate_global->__pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if CYTHON_COMPILING_IN_LIMITED_API
    if (unlikely(!__pyx_m)) {
        if (!PyErr_Occurred())
            PyErr_SetNone(PyExc_NameError);
        return NULL;
    }
    result = PyObject_GetAttr(__pyx_m, name);
    if (likely(result)) {
        return result;
    }
    PyErr_Clear();
#elif CYTHON_AVOID_BORROWED_REFS || CYTHON_AVOID_THREAD_UNSAFE_BORROWED_REFS
    if (unlikely(__Pyx_PyDict_GetItemRef(__pyx_mstate_global->__pyx_d, name, &result) == -1)) PyErr_Clear();
    __PYX_UPDATE_DICT_CACHE(__pyx_mstate_global->__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return result;
    }
#else
    result = _PyDict_GetItem_KnownHash(__pyx_mstate_global->__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_mstate_global->__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


static CYTHON_INLINE PyObject* __Pyx_PyExec2(PyObject* o, PyObject* globals) {
    return __Pyx_PyExec3(o, globals, NULL);
}
static PyObject* __Pyx_PyExec3(PyObject* o, PyObject* globals, PyObject* locals) {
    PyObject* result;
#if !CYTHON_COMPILING_IN_LIMITED_API
    PyObject* s = 0;
    char *code = 0;
#endif
    if (!globals || globals == Py_None) {
        globals = __pyx_mstate_global->__pyx_d;
    }
#if !CYTHON_COMPILING_IN_LIMITED_API
    else if (unlikely(!PyDict_Check(globals))) {
        __Pyx_TypeName globals_type_name =
            __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(globals));
        PyErr_Format(PyExc_TypeError,
                     "exec() arg 2 must be a dict, not " __Pyx_FMT_TYPENAME,
                     globals_type_name);
        __Pyx_DECREF_TypeName(globals_type_name);
        goto bad;
    }
#endif
    if (!locals || locals == Py_None) {
        locals = globals;
    }
#if !CYTHON_COMPILING_IN_LIMITED_API
    if (__Pyx_PyDict_GetItemStr(globals, __pyx_mstate_global->__pyx_n_u_builtins) == NULL) {
        if (unlikely(PyDict_SetItem(globals, __pyx_mstate_global->__pyx_n_u_builtins, PyEval_GetBuiltins()) < 0))
            goto bad;
    }
    if (PyCode_Check(o)) {
        if (unlikely(__Pyx_PyCode_HasFreeVars((PyCodeObject *)o))) {
            PyErr_SetString(PyExc_TypeError,
                "code object passed to exec() may not contain free variables");
            goto bad;
        }
        #if CYTHON_COMPILING_IN_PYPY && PYPY_VERSION_NUM < 0x07030400
        result = PyEval_EvalCode((PyCodeObject *)o, globals, locals);
        #else
        result = PyEval_EvalCode(o, globals, locals);
        #endif
    } else {
        PyCompilerFlags cf;
        cf.cf_flags = 0;
        cf.cf_feature_version = PY_MINOR_VERSION;
        if (PyUnicode_Check(o)) {
            cf.cf_flags = PyCF_SOURCE_IS_UTF8;
            s = PyUnicode_AsUTF8String(o);
            if (unlikely(!s)) goto bad;
            o = s;
        } else if (unlikely(!PyBytes_Check(o))) {
            __Pyx_TypeName o_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(o));
            PyErr_Format(PyExc_TypeError,
                "exec: arg 1 must be string, bytes or code object, got " __Pyx_FMT_TYPENAME,
                o_type_name);
            __Pyx_DECREF_TypeName(o_type_name);
            goto bad;
        }
        code = PyBytes_AS_STRING(o);
        if (PyEval_MergeCompilerFlags(&cf)) {
            result = PyRun_StringFlags(code, Py_file_input, globals, locals, &cf);
        } else {
            result = PyRun_String(code, Py_file_input, globals, locals);
        }
        Py_XDECREF(s);
    }
    return result;
bad:
    Py_XDECREF(s);
    return 0;
#else // CYTHON_COMPILING_IN_LIMITED_API
    {
        PyObject *builtins, *exec, *exec_str;
        builtins = PyEval_GetBuiltins();
        if (!builtins) return NULL;
        exec_str = PyUnicode_FromStringAndSize("exec", 4);
        if (!exec_str) return NULL;
        exec = PyObject_GetItem(builtins, exec_str);
        Py_DECREF(exec_str);
        if (!exec) return NULL;
        result = PyObject_CallFunctionObjArgs(exec, o, globals, locals, NULL);
        Py_DECREF(exec);
        return result;
    }
#endif
}


static PyObject* __Pyx_PyExecGlobals(PyObject* code) {
    return __Pyx_PyExec2(code, __pyx_mstate_global->__pyx_d);
}


#if CYTHON_VECTORCALL
static int __Pyx_VectorcallBuilder_AddArg(PyObject *key, PyObject *value, PyObject *builder, PyObject **args, int n) {
    (void)__Pyx_PyObject_FastCallDict;
    if (__Pyx_PyTuple_SET_ITEM(builder, n, key) != (0)) return -1;
    Py_INCREF(key);
    args[n] = value;
    return 0;
}
CYTHON_UNUSED static int __Pyx_VectorcallBuilder_AddArg_Check(PyObject *key, PyObject *value, PyObject *builder, PyObject **args, int n) {
    (void)__Pyx_VectorcallBuilder_AddArgStr;
    if (unlikely(!PyUnicode_Check(key))) {
        PyErr_SetString(PyExc_TypeError, "keywords must be strings");
        return -1;
    }
    return __Pyx_VectorcallBuilder_AddArg(key, value, builder, args, n);
}
static int __Pyx_VectorcallBuilder_AddArgStr(const char *key, PyObject *value, PyObject *builder, PyObject **args, int n) {
    PyObject *pyKey = PyUnicode_FromString(key);
    if (!pyKey) return -1;
    return __Pyx_VectorcallBuilder_AddArg(pyKey, value, builder, args, n);
}
#else // CYTHON_VECTORCALL
CYTHON_UNUSED static int __Pyx_VectorcallBuilder_AddArg_Check(PyObject *key, PyObject *value, PyObject *builder, CYTHON_UNUSED PyObject **args, CYTHON_UNUSED int n) {
    if (unlikely(!PyUnicode_Check(key))) {
        PyErr_SetString(PyExc_TypeError, "keywords must be strings");
        return -1;
    }
    return PyDict_SetItem(builder, key, value);
}
#endif


#if CYTHON_CLINE_IN_TRACEBACK && CYTHON_CLINE_IN_TRACEBACK_RUNTIME
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
#define __Pyx_PyProbablyModule_GetDict(o) __Pyx_XNewRef(PyModule_GetDict(o))
#elif !CYTHON_COMPILING_IN_CPYTHON || CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
#define __Pyx_PyProbablyModule_GetDict(o) PyObject_GenericGetDict(o, NULL);
#else
PyObject* __Pyx_PyProbablyModule_GetDict(PyObject *o) {
    PyObject **dict_ptr = _PyObject_GetDictPtr(o);
    return dict_ptr ? __Pyx_XNewRef(*dict_ptr) : NULL;
}
#endif
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line) {
    PyObject *use_cline = NULL;
    PyObject *ptype, *pvalue, *ptraceback;
    PyObject *cython_runtime_dict;
    CYTHON_MAYBE_UNUSED_VAR(tstate);
    if (unlikely(!__pyx_mstate_global->__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
    cython_runtime_dict = __Pyx_PyProbablyModule_GetDict(__pyx_mstate_global->__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, cython_runtime_dict,
            __Pyx_PyDict_SetDefault(cython_runtime_dict, __pyx_mstate_global->__pyx_n_u_cline_in_traceback, Py_False))
    }
    if (use_cline == NULL || use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    Py_XDECREF(use_cline);
    Py_XDECREF(cython_runtime_dict);
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static __Pyx_CachedCodeObjectType *__pyx__find_code_object(struct __Pyx_CodeObjectCache *code_cache, int code_line) {
    __Pyx_CachedCodeObjectType* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!code_cache->entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(code_cache->entries, code_cache->count, code_line);
    if (unlikely(pos >= code_cache->count) || unlikely(code_cache->entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = code_cache->entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static __Pyx_CachedCodeObjectType *__pyx_find_code_object(int code_line) {
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING && !CYTHON_ATOMICS
    (void)__pyx__find_code_object;
    return NULL; // Most implementation should have atomics. But otherwise, don't make it thread-safe, just miss.
#else
    struct __Pyx_CodeObjectCache *code_cache = &__pyx_mstate_global->__pyx_code_cache;
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    __pyx_nonatomic_int_type old_count = __pyx_atomic_incr_acq_rel(&code_cache->accessor_count);
    if (old_count < 0) {
        __pyx_atomic_decr_acq_rel(&code_cache->accessor_count);
        return NULL;
    }
#endif
    __Pyx_CachedCodeObjectType *result = __pyx__find_code_object(code_cache, code_line);
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    __pyx_atomic_decr_acq_rel(&code_cache->accessor_count);
#endif
    return result;
#endif
}
static void __pyx__insert_code_object(struct __Pyx_CodeObjectCache *code_cache, int code_line, __Pyx_CachedCodeObjectType* code_object)
{
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = code_cache->entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            code_cache->entries = entries;
            code_cache->max_count = 64;
            code_cache->count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(code_cache->entries, code_cache->count, code_line);
    if ((pos < code_cache->count) && unlikely(code_cache->entries[pos].code_line == code_line)) {
        __Pyx_CachedCodeObjectType* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_INCREF(code_object);
        Py_DECREF(tmp);
        return;
    }
    if (code_cache->count == code_cache->max_count) {
        int new_max = code_cache->max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            code_cache->entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        code_cache->entries = entries;
        code_cache->max_count = new_max;
    }
    for (i=code_cache->count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    code_cache->count++;
    Py_INCREF(code_object);
}
static void __pyx_insert_code_object(int code_line, __Pyx_CachedCodeObjectType* code_object) {
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING && !CYTHON_ATOMICS
    (void)__pyx__insert_code_object;
    return; // Most implementation should have atomics. But otherwise, don't make it thread-safe, just fail.
#else
    struct __Pyx_CodeObjectCache *code_cache = &__pyx_mstate_global->__pyx_code_cache;
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    __pyx_nonatomic_int_type expected = 0;
    if (!__pyx_atomic_int_cmp_exchange(&code_cache->accessor_count, &expected, INT_MIN)) {
        return;
    }
#endif
    __pyx__insert_code_object(code_cache, code_line, code_object);
#if CYTHON_COMPILING_IN_CPYTHON_FREETHREADING
    __pyx_atomic_sub(&code_cache->accessor_count, INT_MIN);
#endif
#endif
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
#if PY_VERSION_HEX >= 0x030b00a6 && !CYTHON_COMPILING_IN_LIMITED_API && !defined(PYPY_VERSION)
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
static PyObject *__Pyx_PyCode_Replace_For_AddTraceback(PyObject *code, PyObject *scratch_dict,
                                                       PyObject *firstlineno, PyObject *name) {
    PyObject *replace = NULL;
    if (unlikely(PyDict_SetItemString(scratch_dict, "co_firstlineno", firstlineno))) return NULL;
    if (unlikely(PyDict_SetItemString(scratch_dict, "co_name", name))) return NULL;
    replace = PyObject_GetAttrString(code, "replace");
    if (likely(replace)) {
        PyObject *result = PyObject_Call(replace, __pyx_mstate_global->__pyx_empty_tuple, scratch_dict);
        Py_DECREF(replace);
        return result;
    }
    PyErr_Clear();
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyObject *code_object = NULL, *py_py_line = NULL, *py_funcname = NULL, *dict = NULL;
    PyObject *replace = NULL, *getframe = NULL, *frame = NULL;
    PyObject *exc_type, *exc_value, *exc_traceback;
    int success = 0;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(__Pyx_PyThreadState_Current, c_line);
    }
    PyErr_Fetch(&exc_type, &exc_value, &exc_traceback);
    code_object = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!code_object) {
        code_object = Py_CompileString("_getframe()", filename, Py_eval_input);
        if (unlikely(!code_object)) goto bad;
        py_py_line = PyLong_FromLong(py_line);
        if (unlikely(!py_py_line)) goto bad;
        if (c_line) {
            py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        } else {
            py_funcname = PyUnicode_FromString(funcname);
        }
        if (unlikely(!py_funcname)) goto bad;
        dict = PyDict_New();
        if (unlikely(!dict)) goto bad;
        {
            PyObject *old_code_object = code_object;
            code_object = __Pyx_PyCode_Replace_For_AddTraceback(code_object, dict, py_py_line, py_funcname);
            Py_DECREF(old_code_object);
        }
        if (unlikely(!code_object)) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, code_object);
    } else {
        dict = PyDict_New();
    }
    getframe = PySys_GetObject("_getframe");
    if (unlikely(!getframe)) goto bad;
    if (unlikely(PyDict_SetItemString(dict, "_getframe", getframe))) goto bad;
    frame = PyEval_EvalCode(code_object, dict, dict);
    if (unlikely(!frame) || frame == Py_None) goto bad;
    success = 1;
  bad:
    PyErr_Restore(exc_type, exc_value, exc_traceback);
    Py_XDECREF(code_object);
    Py_XDECREF(py_py_line);
    Py_XDECREF(py_funcname);
    Py_XDECREF(dict);
    Py_XDECREF(replace);
    if (success) {
        PyTraceBack_Here(
            (struct _frame*)frame);
    }
    Py_XDECREF(frame);
}
#else
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = NULL;
    PyObject *py_funcname = NULL;
    if (c_line) {
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        if (!py_funcname) goto bad;
        funcname = PyUnicode_AsUTF8(py_funcname);
        if (!funcname) goto bad;
    }
    py_code = PyCode_NewEmpty(filename, funcname, py_line);
    Py_XDECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject *ptype, *pvalue, *ptraceback;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) {
            
            Py_XDECREF(ptype);
            Py_XDECREF(pvalue);
            Py_XDECREF(ptraceback);
            goto bad;
        }
        __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            
        py_code,           
        __pyx_mstate_global->__pyx_d,    
        0                  
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}
#endif


#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030d0000
static __Pyx_TypeName
__Pyx_PyType_GetFullyQualifiedName(PyTypeObject* tp)
{
    PyObject *module = NULL, *name = NULL, *result = NULL;
    #if __PYX_LIMITED_VERSION_HEX < 0x030b0000
    name = __Pyx_PyObject_GetAttrStr((PyObject *)tp,
                                               __pyx_mstate_global->__pyx_n_u_qualname);
    #else
    name = PyType_GetQualName(tp);
    #endif
    if (unlikely(name == NULL) || unlikely(!PyUnicode_Check(name))) goto bad;
    module = __Pyx_PyObject_GetAttrStr((PyObject *)tp,
                                               __pyx_mstate_global->__pyx_n_u_module);
    if (unlikely(module == NULL) || unlikely(!PyUnicode_Check(module))) goto bad;
    if (PyUnicode_CompareWithASCIIString(module, "builtins") == 0) {
        result = name;
        name = NULL;
        goto done;
    }
    result = PyUnicode_FromFormat("%U.%U", module, name);
    if (unlikely(result == NULL)) goto bad;
  done:
    Py_XDECREF(name);
    Py_XDECREF(module);
    return result;
  bad:
    PyErr_Clear();
    if (name) {
        result = name;
        name = NULL;
    } else {
        result = __Pyx_NewRef(__pyx_mstate_global->__pyx_kp_u__3);
    }
    goto done;
}
#endif


static CYTHON_INLINE PyObject* __Pyx_PyLong_From_long(long value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyLong_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#if !CYTHON_COMPILING_IN_PYPY
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyLong_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
        }
    }
    {
        unsigned char *bytes = (unsigned char *)&value;
#if !CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x030d00A4
        if (is_unsigned) {
            return PyLong_FromUnsignedNativeBytes(bytes, sizeof(value), -1);
        } else {
            return PyLong_FromNativeBytes(bytes, sizeof(value), -1);
        }
#elif !CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX < 0x030d0000
        int one = 1; int little = (int)*(unsigned char *)&one;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
#else
        int one = 1; int little = (int)*(unsigned char *)&one;
        PyObject *from_bytes, *result = NULL, *kwds = NULL;
        PyObject *py_bytes = NULL, *order_str = NULL;
        from_bytes = PyObject_GetAttrString((PyObject*)&PyLong_Type, "from_bytes");
        if (!from_bytes) return NULL;
        py_bytes = PyBytes_FromStringAndSize((char*)bytes, sizeof(long));
        if (!py_bytes) goto limited_bad;
        order_str = PyUnicode_FromString(little ? "little" : "big");
        if (!order_str) goto limited_bad;
        {
            PyObject *args[3+(CYTHON_VECTORCALL ? 1 : 0)] = { NULL, py_bytes, order_str };
            if (!is_unsigned) {
                kwds = __Pyx_MakeVectorcallBuilderKwds(1);
                if (!kwds) goto limited_bad;
                if (__Pyx_VectorcallBuilder_AddArgStr("signed", __Pyx_NewRef(Py_True), kwds, args+3, 0) < 0) goto limited_bad;
            }
            result = __Pyx_Object_Vectorcall_CallFromBuilder(from_bytes, args+1, 2 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET, kwds);
        }
        limited_bad:
        Py_XDECREF(kwds);
        Py_XDECREF(order_str);
        Py_XDECREF(py_bytes);
        Py_XDECREF(from_bytes);
        return result;
#endif
    }
}


#define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


static CYTHON_INLINE long __Pyx_PyLong_As_long(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (unlikely(!PyLong_Check(x))) {
        long val;
        PyObject *tmp = __Pyx_PyNumber_Long(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyLong_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
    if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
        if (unlikely(__Pyx_PyLong_IsNeg(x))) {
            goto raise_neg_overflow;
        } else if (__Pyx_PyLong_IsCompact(x)) {
            __PYX_VERIFY_RETURN_INT(long, __Pyx_compact_upylong, __Pyx_PyLong_CompactValueUnsigned(x))
        } else {
            const digit* digits = __Pyx_PyLong_Digits(x);
            assert(__Pyx_PyLong_DigitCount(x) > 1);
            switch (__Pyx_PyLong_DigitCount(x)) {
                case 2:
                    if ((8 * sizeof(long) > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) >= 2 * PyLong_SHIFT)) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if ((8 * sizeof(long) > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) >= 3 * PyLong_SHIFT)) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if ((8 * sizeof(long) > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) >= 4 * PyLong_SHIFT)) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
        }
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030C00A7
        if (unlikely(Py_SIZE(x) < 0)) {
            goto raise_neg_overflow;
        }
#else
        {
            int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
            if (unlikely(result < 0))
                return (long) -1;
            if (unlikely(result == 1))
                goto raise_neg_overflow;
        }
#endif
        if ((sizeof(long) <= sizeof(unsigned long))) {
            __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
        } else if ((sizeof(long) <= sizeof(unsigned PY_LONG_LONG))) {
            __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
        }
    } else {
#if CYTHON_USE_PYLONG_INTERNALS
        if (__Pyx_PyLong_IsCompact(x)) {
            __PYX_VERIFY_RETURN_INT(long, __Pyx_compact_pylong, __Pyx_PyLong_CompactValue(x))
        } else {
            const digit* digits = __Pyx_PyLong_Digits(x);
            assert(__Pyx_PyLong_DigitCount(x) > 1);
            switch (__Pyx_PyLong_SignedDigitCount(x)) {
                case -2:
                    if ((8 * sizeof(long) - 1 > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 2 * PyLong_SHIFT)) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if ((8 * sizeof(long) > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 2 * PyLong_SHIFT)) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if ((8 * sizeof(long) - 1 > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 3 * PyLong_SHIFT)) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if ((8 * sizeof(long) > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 3 * PyLong_SHIFT)) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if ((8 * sizeof(long) - 1 > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 4 * PyLong_SHIFT)) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if ((8 * sizeof(long) > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(long) - 1 > 4 * PyLong_SHIFT)) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
        }
#endif
        if ((sizeof(long) <= sizeof(long))) {
            __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
        } else if ((sizeof(long) <= sizeof(PY_LONG_LONG))) {
            __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
        }
    }
    {
        long val;
        int ret = -1;
#if PY_VERSION_HEX >= 0x030d00A6 && !CYTHON_COMPILING_IN_LIMITED_API
        Py_ssize_t bytes_copied = PyLong_AsNativeBytes(
            x, &val, sizeof(val), Py_ASNATIVEBYTES_NATIVE_ENDIAN | (is_unsigned ? Py_ASNATIVEBYTES_UNSIGNED_BUFFER | Py_ASNATIVEBYTES_REJECT_NEGATIVE : 0));
        if (unlikely(bytes_copied == -1)) {
        } else if (unlikely(bytes_copied > (Py_ssize_t) sizeof(val))) {
            goto raise_overflow;
        } else {
            ret = 0;
        }
#elif PY_VERSION_HEX < 0x030d0000 && !(CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_LIMITED_API) || defined(_PyLong_AsByteArray)
        int one = 1; int is_little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&val;
        ret = _PyLong_AsByteArray((PyLongObject *)x,
                                    bytes, sizeof(val),
                                    is_little, !is_unsigned);
#else
        PyObject *v;
        PyObject *stepval = NULL, *mask = NULL, *shift = NULL;
        int bits, remaining_bits, is_negative = 0;
        int chunk_size = (sizeof(long) < 8) ? 30 : 62;
        if (likely(PyLong_CheckExact(x))) {
            v = __Pyx_NewRef(x);
        } else {
            v = PyNumber_Long(x);
            if (unlikely(!v)) return (long) -1;
            assert(PyLong_CheckExact(v));
        }
        {
            int result = PyObject_RichCompareBool(v, Py_False, Py_LT);
            if (unlikely(result < 0)) {
                Py_DECREF(v);
                return (long) -1;
            }
            is_negative = result == 1;
        }
        if (is_unsigned && unlikely(is_negative)) {
            Py_DECREF(v);
            goto raise_neg_overflow;
        } else if (is_negative) {
            stepval = PyNumber_Invert(v);
            Py_DECREF(v);
            if (unlikely(!stepval))
                return (long) -1;
        } else {
            stepval = v;
        }
        v = NULL;
        val = (long) 0;
        mask = PyLong_FromLong((1L << chunk_size) - 1); if (unlikely(!mask)) goto done;
        shift = PyLong_FromLong(chunk_size); if (unlikely(!shift)) goto done;
        for (bits = 0; bits < (int) sizeof(long) * 8 - chunk_size; bits += chunk_size) {
            PyObject *tmp, *digit;
            long idigit;
            digit = PyNumber_And(stepval, mask);
            if (unlikely(!digit)) goto done;
            idigit = PyLong_AsLong(digit);
            Py_DECREF(digit);
            if (unlikely(idigit < 0)) goto done;
            val |= ((long) idigit) << bits;
            tmp = PyNumber_Rshift(stepval, shift);
            if (unlikely(!tmp)) goto done;
            Py_DECREF(stepval); stepval = tmp;
        }
        Py_DECREF(shift); shift = NULL;
        Py_DECREF(mask); mask = NULL;
        {
            long idigit = PyLong_AsLong(stepval);
            if (unlikely(idigit < 0)) goto done;
            remaining_bits = ((int) sizeof(long) * 8) - bits - (is_unsigned ? 0 : 1);
            if (unlikely(idigit >= (1L << remaining_bits)))
                goto raise_overflow;
            val |= ((long) idigit) << bits;
        }
        if (!is_unsigned) {
            if (unlikely(val & (((long) 1) << (sizeof(long) * 8 - 1))))
                goto raise_overflow;
            if (is_negative)
                val = ~val;
        }
        ret = 0;
    done:
        Py_XDECREF(shift);
        Py_XDECREF(mask);
        Py_XDECREF(stepval);
#endif
        if (unlikely(ret))
            return (long) -1;
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


static CYTHON_INLINE int __Pyx_PyLong_As_int(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (unlikely(!PyLong_Check(x))) {
        int val;
        PyObject *tmp = __Pyx_PyNumber_Long(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyLong_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
    if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
        if (unlikely(__Pyx_PyLong_IsNeg(x))) {
            goto raise_neg_overflow;
        } else if (__Pyx_PyLong_IsCompact(x)) {
            __PYX_VERIFY_RETURN_INT(int, __Pyx_compact_upylong, __Pyx_PyLong_CompactValueUnsigned(x))
        } else {
            const digit* digits = __Pyx_PyLong_Digits(x);
            assert(__Pyx_PyLong_DigitCount(x) > 1);
            switch (__Pyx_PyLong_DigitCount(x)) {
                case 2:
                    if ((8 * sizeof(int) > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) >= 2 * PyLong_SHIFT)) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if ((8 * sizeof(int) > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) >= 3 * PyLong_SHIFT)) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if ((8 * sizeof(int) > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) >= 4 * PyLong_SHIFT)) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
        }
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030C00A7
        if (unlikely(Py_SIZE(x) < 0)) {
            goto raise_neg_overflow;
        }
#else
        {
            int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
            if (unlikely(result < 0))
                return (int) -1;
            if (unlikely(result == 1))
                goto raise_neg_overflow;
        }
#endif
        if ((sizeof(int) <= sizeof(unsigned long))) {
            __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
        } else if ((sizeof(int) <= sizeof(unsigned PY_LONG_LONG))) {
            __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
        }
    } else {
#if CYTHON_USE_PYLONG_INTERNALS
        if (__Pyx_PyLong_IsCompact(x)) {
            __PYX_VERIFY_RETURN_INT(int, __Pyx_compact_pylong, __Pyx_PyLong_CompactValue(x))
        } else {
            const digit* digits = __Pyx_PyLong_Digits(x);
            assert(__Pyx_PyLong_DigitCount(x) > 1);
            switch (__Pyx_PyLong_SignedDigitCount(x)) {
                case -2:
                    if ((8 * sizeof(int) - 1 > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 2 * PyLong_SHIFT)) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if ((8 * sizeof(int) > 1 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 2 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 2 * PyLong_SHIFT)) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if ((8 * sizeof(int) - 1 > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 3 * PyLong_SHIFT)) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if ((8 * sizeof(int) > 2 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 3 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 3 * PyLong_SHIFT)) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if ((8 * sizeof(int) - 1 > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 4 * PyLong_SHIFT)) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if ((8 * sizeof(int) > 3 * PyLong_SHIFT)) {
                        if ((8 * sizeof(unsigned long) > 4 * PyLong_SHIFT)) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if ((8 * sizeof(int) - 1 > 4 * PyLong_SHIFT)) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
        }
#endif
        if ((sizeof(int) <= sizeof(long))) {
            __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
        } else if ((sizeof(int) <= sizeof(PY_LONG_LONG))) {
            __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
        }
    }
    {
        int val;
        int ret = -1;
#if PY_VERSION_HEX >= 0x030d00A6 && !CYTHON_COMPILING_IN_LIMITED_API
        Py_ssize_t bytes_copied = PyLong_AsNativeBytes(
            x, &val, sizeof(val), Py_ASNATIVEBYTES_NATIVE_ENDIAN | (is_unsigned ? Py_ASNATIVEBYTES_UNSIGNED_BUFFER | Py_ASNATIVEBYTES_REJECT_NEGATIVE : 0));
        if (unlikely(bytes_copied == -1)) {
        } else if (unlikely(bytes_copied > (Py_ssize_t) sizeof(val))) {
            goto raise_overflow;
        } else {
            ret = 0;
        }
#elif PY_VERSION_HEX < 0x030d0000 && !(CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_LIMITED_API) || defined(_PyLong_AsByteArray)
        int one = 1; int is_little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&val;
        ret = _PyLong_AsByteArray((PyLongObject *)x,
                                    bytes, sizeof(val),
                                    is_little, !is_unsigned);
#else
        PyObject *v;
        PyObject *stepval = NULL, *mask = NULL, *shift = NULL;
        int bits, remaining_bits, is_negative = 0;
        int chunk_size = (sizeof(long) < 8) ? 30 : 62;
        if (likely(PyLong_CheckExact(x))) {
            v = __Pyx_NewRef(x);
        } else {
            v = PyNumber_Long(x);
            if (unlikely(!v)) return (int) -1;
            assert(PyLong_CheckExact(v));
        }
        {
            int result = PyObject_RichCompareBool(v, Py_False, Py_LT);
            if (unlikely(result < 0)) {
                Py_DECREF(v);
                return (int) -1;
            }
            is_negative = result == 1;
        }
        if (is_unsigned && unlikely(is_negative)) {
            Py_DECREF(v);
            goto raise_neg_overflow;
        } else if (is_negative) {
            stepval = PyNumber_Invert(v);
            Py_DECREF(v);
            if (unlikely(!stepval))
                return (int) -1;
        } else {
            stepval = v;
        }
        v = NULL;
        val = (int) 0;
        mask = PyLong_FromLong((1L << chunk_size) - 1); if (unlikely(!mask)) goto done;
        shift = PyLong_FromLong(chunk_size); if (unlikely(!shift)) goto done;
        for (bits = 0; bits < (int) sizeof(int) * 8 - chunk_size; bits += chunk_size) {
            PyObject *tmp, *digit;
            long idigit;
            digit = PyNumber_And(stepval, mask);
            if (unlikely(!digit)) goto done;
            idigit = PyLong_AsLong(digit);
            Py_DECREF(digit);
            if (unlikely(idigit < 0)) goto done;
            val |= ((int) idigit) << bits;
            tmp = PyNumber_Rshift(stepval, shift);
            if (unlikely(!tmp)) goto done;
            Py_DECREF(stepval); stepval = tmp;
        }
        Py_DECREF(shift); shift = NULL;
        Py_DECREF(mask); mask = NULL;
        {
            long idigit = PyLong_AsLong(stepval);
            if (unlikely(idigit < 0)) goto done;
            remaining_bits = ((int) sizeof(int) * 8) - bits - (is_unsigned ? 0 : 1);
            if (unlikely(idigit >= (1L << remaining_bits)))
                goto raise_overflow;
            val |= ((int) idigit) << bits;
        }
        if (!is_unsigned) {
            if (unlikely(val & (((int) 1) << (sizeof(int) * 8 - 1))))
                goto raise_overflow;
            if (is_negative)
                val = ~val;
        }
        ret = 0;
    done:
        Py_XDECREF(shift);
        Py_XDECREF(mask);
        Py_XDECREF(stepval);
#endif
        if (unlikely(ret))
            return (int) -1;
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = __Pyx_PyType_GetSlot(a, tp_base, PyTypeObject*);
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
static CYTHON_INLINE int __Pyx_IsAnySubtype2(PyTypeObject *cls, PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (cls == a || cls == b) return 1;
    mro = cls->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            PyObject *base = PyTuple_GET_ITEM(mro, i);
            if (base == (PyObject *)a || base == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(cls, a) || __Pyx_InBases(cls, b);
}
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    if (exc_type1) {
        return __Pyx_IsAnySubtype2((PyTypeObject*)err, (PyTypeObject*)exc_type1, (PyTypeObject*)exc_type2);
    } else {
        return __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
}
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


#if __PYX_LIMITED_VERSION_HEX < 0x030b0000
void __Pyx_init_runtime_version(void) {
    if (__Pyx_cached_runtime_version == 0) {
        const char* rt_version = Py_GetVersion();
        unsigned long version = 0;
        unsigned long factor = 0x01000000UL;
        unsigned int digit = 0;
        int i = 0;
        while (factor) {
            while ('0' <= rt_version[i] && rt_version[i] <= '9') {
                digit = digit * 10 + (unsigned int) (rt_version[i] - '0');
                ++i;
            }
            version += factor * digit;
            if (rt_version[i] != '.')
                break;
            digit = 0;
            factor >>= 8;
            ++i;
        }
        __Pyx_cached_runtime_version = version;
    }
}
#endif
static unsigned long __Pyx_get_runtime_version(void) {
#if __PYX_LIMITED_VERSION_HEX >= 0x030b0000
    return Py_Version & ~0xFFUL;
#else
    return __Pyx_cached_runtime_version;
#endif
}


static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if PY_VERSION_HEX >= 0x030C00A6
        PyException_SetTraceback(value, tb);
#elif CYTHON_FAST_THREAD_STATE
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#else
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}


#if CYTHON_USE_EXC_INFO_STACK && CYTHON_FAST_THREAD_STATE
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_value == NULL || exc_info->exc_value == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
  #if CYTHON_USE_EXC_INFO_STACK && PY_VERSION_HEX >= 0x030B00a4
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    PyObject *exc_value = exc_info->exc_value;
    if (exc_value == NULL || exc_value == Py_None) {
        *value = NULL;
        *type = NULL;
        *tb = NULL;
    } else {
        *value = exc_value;
        Py_INCREF(*value);
        *type = (PyObject*) Py_TYPE(exc_value);
        Py_INCREF(*type);
        *tb = PyException_GetTraceback(exc_value);
    }
  #elif CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
  #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
  #endif
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
  #if CYTHON_USE_EXC_INFO_STACK && PY_VERSION_HEX >= 0x030B00a4
    _PyErr_StackItem *exc_info = tstate->exc_info;
    PyObject *tmp_value = exc_info->exc_value;
    exc_info->exc_value = value;
    Py_XDECREF(tmp_value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
  #else
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
  #endif
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
  #if CYTHON_USE_EXC_INFO_STACK && PY_VERSION_HEX >= 0x030B00a4
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_value = exc_info->exc_value;
    exc_info->exc_value = *value;
    if (tmp_value == NULL || tmp_value == Py_None) {
        Py_XDECREF(tmp_value);
        tmp_value = NULL;
        tmp_type = NULL;
        tmp_tb = NULL;
    } else {
        tmp_type = (PyObject*) Py_TYPE(tmp_value);
        Py_INCREF(tmp_type);
        #if CYTHON_COMPILING_IN_CPYTHON
        tmp_tb = ((PyBaseExceptionObject*) tmp_value)->traceback;
        Py_XINCREF(tmp_tb);
        #else
        tmp_tb = PyException_GetTraceback(tmp_value);
        #endif
    }
  #elif CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
  #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
  #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif


#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
static PyObject *__Pyx_GetBuiltinNext_LimitedAPI(void) {
    if (unlikely(!__pyx_mstate_global->__Pyx_GetBuiltinNext_LimitedAPI_cache))
        __pyx_mstate_global->__Pyx_GetBuiltinNext_LimitedAPI_cache = __Pyx_GetBuiltinName(__pyx_mstate_global->__pyx_n_u_next);
    return __pyx_mstate_global->__Pyx_GetBuiltinNext_LimitedAPI_cache;
}
#endif
static CYTHON_INLINE PyObject *__Pyx_PyIter_Next_Plain(PyObject *iterator) {
#if CYTHON_COMPILING_IN_LIMITED_API && __PYX_LIMITED_VERSION_HEX < 0x030A0000
    PyObject *result;
    PyObject *next = __Pyx_GetBuiltinNext_LimitedAPI();
    if (unlikely(!next)) return NULL;
    result = PyObject_CallFunctionObjArgs(next, iterator, NULL);
    return result;
#else
    (void)__Pyx_GetBuiltinName; // only for early limited API
    iternextfunc iternext = __Pyx_PyObject_GetIterNextFunc(iterator);
    assert(iternext);
    return iternext(iterator);
#endif
}


static CYTHON_INLINE PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args[3] = {NULL, arg1, arg2};
    return __Pyx_PyObject_FastCall(function, args+1, 2 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET);
}


#if !(CYTHON_VECTORCALL && (__PYX_LIMITED_VERSION_HEX >= 0x030C0000 || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x03090000)))
static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
#endif
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
#if CYTHON_VECTORCALL && (__PYX_LIMITED_VERSION_HEX >= 0x030C0000 || (!CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x03090000))
    PyObject *args[2] = {obj, arg};
    (void) __Pyx_PyObject_CallOneArg;
    (void) __Pyx_PyObject_Call2Args;
    return PyObject_VectorcallMethod(method_name, args, 2 | PY_VECTORCALL_ARGUMENTS_OFFSET, NULL);
#else
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
#endif
}


static void __Pyx__ReturnWithStopIteration(PyObject* value, int async);
static CYTHON_INLINE void __Pyx_ReturnWithStopIteration(PyObject* value, int async, int iternext) {
    if (value == Py_None) {
        if (async || !iternext)
            PyErr_SetNone(async ? PyExc_StopAsyncIteration : PyExc_StopIteration);
        return;
    }
    __Pyx__ReturnWithStopIteration(value, async);
}
static void __Pyx__ReturnWithStopIteration(PyObject* value, int async) {
#if CYTHON_COMPILING_IN_CPYTHON
    __Pyx_PyThreadState_declare
#endif
    PyObject *exc;
    PyObject *exc_type = async ? PyExc_StopAsyncIteration : PyExc_StopIteration;
#if CYTHON_COMPILING_IN_CPYTHON
    if ((PY_VERSION_HEX >= (0x030C00A6)) || unlikely(PyTuple_Check(value) || PyExceptionInstance_Check(value))) {
        if (PY_VERSION_HEX >= (0x030e00A1)) {
            exc = __Pyx_PyObject_CallOneArg(exc_type, value);
        } else {
            PyObject *args_tuple = PyTuple_New(1);
            if (unlikely(!args_tuple)) return;
            Py_INCREF(value);
            PyTuple_SET_ITEM(args_tuple, 0, value);
            exc = PyObject_Call(exc_type, args_tuple, NULL);
            Py_DECREF(args_tuple);
        }
        if (unlikely(!exc)) return;
    } else {
        Py_INCREF(value);
        exc = value;
    }
    #if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    #if CYTHON_USE_EXC_INFO_STACK
    if (!__pyx_tstate->exc_info->exc_value)
    #else
    if (!__pyx_tstate->exc_type)
    #endif
    {
        Py_INCREF(exc_type);
        __Pyx_ErrRestore(exc_type, exc, NULL);
        return;
    }
    #endif
#else
    exc = __Pyx_PyObject_CallOneArg(exc_type, value);
    if (unlikely(!exc)) return;
#endif
    PyErr_SetObject(exc_type, exc);
    Py_DECREF(exc);
}


#if !CYTHON_COMPILING_IN_LIMITED_API
#include <frameobject.h>
#if PY_VERSION_HEX >= 0x030b00a6 && !defined(PYPY_VERSION)
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
#endif // CYTHON_COMPILING_IN_LIMITED_API
static CYTHON_INLINE void
__Pyx_Coroutine_Undelegate(__pyx_CoroutineObject *gen) {
#if CYTHON_USE_AM_SEND
    gen->yieldfrom_am_send = NULL;
#endif
    Py_CLEAR(gen->yieldfrom);
}
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    CYTHON_UNUSED_VAR(__pyx_tstate);
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
        else if (likely(__Pyx_IS_TYPE(ev, (PyTypeObject*)PyExc_StopIteration))) {
            #if CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_GRAAL
            value = PyObject_GetAttr(ev, __pyx_mstate_global->__pyx_n_u_value);
            if (unlikely(!value)) goto limited_api_failure;
            #else
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            #endif
            Py_DECREF(ev);
        }
        else if (unlikely(PyTuple_Check(ev))) {
            Py_ssize_t tuple_size = __Pyx_PyTuple_GET_SIZE(ev);
            #if !CYTHON_ASSUME_SAFE_SIZE
            if (unlikely(tuple_size < 0)) {
                Py_XDECREF(tb);
                Py_DECREF(ev);
                Py_DECREF(et);
                return -1;
            }
            #endif
            if (tuple_size >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#elif CYTHON_ASSUME_SAFE_MACROS
                value = PySequence_ITEM(ev, 0);
#else
                value = PySequence_GetItem(ev, 0);
                if (!value) goto limited_api_failure;
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if CYTHON_COMPILING_IN_LIMITED_API
    value = PyObject_GetAttr(ev, __pyx_mstate_global->__pyx_n_u_value);
#else
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
#endif
    Py_DECREF(ev);
#if CYTHON_COMPILING_IN_LIMITED_API
    if (unlikely(!value)) return -1;
#endif
    *pvalue = value;
    return 0;
#if CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_GRAAL || !CYTHON_ASSUME_SAFE_MACROS
  limited_api_failure:
    Py_XDECREF(et);
    Py_XDECREF(tb);
    Py_XDECREF(ev);
    return -1;
#endif
}
static CYTHON_INLINE
__Pyx_PySendResult __Pyx_Coroutine_status_from_result(PyObject **retval) {
    if (*retval) {
        return PYGEN_NEXT;
    } else if (likely(__Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, retval) == 0)) {
        return PYGEN_RETURN;
    } else {
        return PYGEN_ERROR;
    }
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
#if PY_VERSION_HEX >= 0x030B00a4
    Py_CLEAR(exc_state->exc_value);
#else
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
#endif
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(__pyx_CoroutineObject *gen) {
    const char *msg;
    CYTHON_MAYBE_UNUSED_VAR(gen);
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
static void __Pyx_Coroutine_AlreadyTerminatedError(PyObject *gen, PyObject *value, int closing) {
    CYTHON_MAYBE_UNUSED_VAR(gen);
    CYTHON_MAYBE_UNUSED_VAR(closing);
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
__Pyx_PySendResult __Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, PyObject **result, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(__Pyx_Coroutine_get_is_running(self));  // Callers should ensure is_running
    if (unlikely(self->resume_label == -1)) {
        __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
        return PYGEN_ERROR;
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_value) {
        #if CYTHON_COMPILING_IN_LIMITED_API || CYTHON_COMPILING_IN_PYPY
        #else
        PyObject *exc_tb;
        #if PY_VERSION_HEX >= 0x030B00a4 && !CYTHON_COMPILING_IN_CPYTHON
        exc_tb = PyException_GetTraceback(exc_state->exc_value);
        #elif PY_VERSION_HEX >= 0x030B00a4
        exc_tb = ((PyBaseExceptionObject*) exc_state->exc_value)->traceback;
        #else
        exc_tb = exc_state->exc_traceback;
        #endif
        if (exc_tb) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
            PyFrameObject *f = tb->tb_frame;
            assert(f->f_back == NULL);
            #if PY_VERSION_HEX >= 0x030B00A1
            f->f_back = PyThreadState_GetFrame(tstate);
            #else
            Py_XINCREF(tstate->frame);
            f->f_back = tstate->frame;
            #endif
            #if PY_VERSION_HEX >= 0x030B00a4 && !CYTHON_COMPILING_IN_CPYTHON
            Py_DECREF(exc_tb);
            #endif
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    retval = self->body(self, tstate, value);
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    *result = retval;
    if (self->resume_label == -1) {
        return likely(retval) ? PYGEN_RETURN : PYGEN_ERROR;
    }
    return PYGEN_NEXT;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_LIMITED_API
    CYTHON_UNUSED_VAR(exc_state);
#else
    PyObject *exc_tb;
    #if PY_VERSION_HEX >= 0x030B00a4
    if (!exc_state->exc_value) return;
    exc_tb = PyException_GetTraceback(exc_state->exc_value);
    #else
    exc_tb = exc_state->exc_traceback;
    #endif
    if (likely(exc_tb)) {
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
        #if PY_VERSION_HEX >= 0x030B00a4
        Py_DECREF(exc_tb);
        #endif
    }
#endif
}
#define __Pyx_Coroutine_MethodReturnFromResult(gen, result, retval, iternext)\
    ((result) == PYGEN_NEXT ? (retval) : __Pyx__Coroutine_MethodReturnFromResult(gen, result, retval, iternext))
static PyObject *
__Pyx__Coroutine_MethodReturnFromResult(PyObject* gen, __Pyx_PySendResult result, PyObject *retval, int iternext) {
    CYTHON_MAYBE_UNUSED_VAR(gen);
    if (likely(result == PYGEN_RETURN)) {
        int is_async = 0;
        #ifdef __Pyx_AsyncGen_USED
        is_async = __Pyx_AsyncGen_CheckExact(gen);
        #endif
        __Pyx_ReturnWithStopIteration(retval, is_async, iternext);
        Py_XDECREF(retval);
    }
    return NULL;
}
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE
PyObject *__Pyx_PyGen_Send(PyGenObject *gen, PyObject *arg) {
#if PY_VERSION_HEX <= 0x030A00A1
    return _PyGen_Send(gen, arg);
#else
    PyObject *result;
    if (PyIter_Send((PyObject*)gen, arg ? arg : Py_None, &result) == PYGEN_RETURN) {
        if (PyAsyncGen_CheckExact(gen)) {
            assert(result == Py_None);
            PyErr_SetNone(PyExc_StopAsyncIteration);
        }
        else if (result == Py_None) {
            PyErr_SetNone(PyExc_StopIteration);
        }
        else {
#if PY_VERSION_HEX < 0x030d00A1
            _PyGen_SetStopIterationValue(result);
#else
            if (!PyTuple_Check(result) && !PyExceptionInstance_Check(result)) {
                PyErr_SetObject(PyExc_StopIteration, result);
            } else {
                PyObject *exc = __Pyx_PyObject_CallOneArg(PyExc_StopIteration, result);
                if (likely(exc != NULL)) {
                    PyErr_SetObject(PyExc_StopIteration, exc);
                    Py_DECREF(exc);
                }
            }
#endif
        }
        Py_DECREF(result);
        result = NULL;
    }
    return result;
#endif
}
#endif
static CYTHON_INLINE __Pyx_PySendResult
__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen, PyObject** retval) {
    __Pyx_PySendResult result;
    PyObject *val = NULL;
    assert(__Pyx_Coroutine_get_is_running(gen));
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    result = __Pyx_Coroutine_SendEx(gen, val, retval, 0);
    Py_XDECREF(val);
    return result;
}
#if CYTHON_USE_AM_SEND
static __Pyx_PySendResult
__Pyx_Coroutine_SendToDelegate(__pyx_CoroutineObject *gen, __Pyx_pyiter_sendfunc gen_am_send, PyObject *value, PyObject **retval) {
    PyObject *ret = NULL;
    __Pyx_PySendResult delegate_result, result;
    assert(__Pyx_Coroutine_get_is_running(gen));
    delegate_result = gen_am_send(gen->yieldfrom, value, &ret);
    if (delegate_result == PYGEN_NEXT) {
        assert (ret != NULL);
        *retval = ret;
        return PYGEN_NEXT;
    }
    assert (delegate_result != PYGEN_ERROR || ret == NULL);
    __Pyx_Coroutine_Undelegate(gen);
    result = __Pyx_Coroutine_SendEx(gen, ret, retval, 0);
    Py_XDECREF(ret);
    return result;
}
#endif
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval = NULL;
    __Pyx_PySendResult result = __Pyx_Coroutine_AmSend(self, value, &retval);
    return __Pyx_Coroutine_MethodReturnFromResult(self, result, retval, 0);
}
static __Pyx_PySendResult
__Pyx_Coroutine_AmSend(PyObject *self, PyObject *value, PyObject **retval) {
    __Pyx_PySendResult result;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    if (unlikely(__Pyx_Coroutine_test_and_set_is_running(gen))) {
        *retval = __Pyx_Coroutine_AlreadyRunningError(gen);
        return PYGEN_ERROR;
    }
    #if CYTHON_USE_AM_SEND
    if (gen->yieldfrom_am_send) {
        result = __Pyx_Coroutine_SendToDelegate(gen, gen->yieldfrom_am_send, value, retval);
    } else
    #endif
    if (gen->yieldfrom) {
        PyObject *yf = gen->yieldfrom;
        PyObject *ret;
      #if !CYTHON_USE_AM_SEND
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        if (PyCoro_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
      #endif
        {
            #if !CYTHON_COMPILING_IN_LIMITED_API || __PYX_LIMITED_VERSION_HEX >= 0x03080000
            if (value == Py_None && PyIter_Check(yf))
                ret = __Pyx_PyIter_Next_Plain(yf);
            else
            #endif
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_mstate_global->__pyx_n_u_send, value);
        }
        if (likely(ret)) {
            __Pyx_Coroutine_unset_is_running(gen);
            *retval = ret;
            return PYGEN_NEXT;
        }
        result = __Pyx_Coroutine_FinishDelegation(gen, retval);
    } else {
        result = __Pyx_Coroutine_SendEx(gen, value, retval, 0);
    }
    __Pyx_Coroutine_unset_is_running(gen);
    return result;
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    __Pyx_PySendResult result;
    PyObject *retval = NULL;
    CYTHON_UNUSED_VAR(gen);
    assert(__Pyx_Coroutine_get_is_running(gen));
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        result = __Pyx_Coroutine_Close(yf, &retval);
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        result = __Pyx_Coroutine_Close(yf, &retval);
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        result = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf);
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
        result = PYGEN_RETURN;
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
        result = PYGEN_RETURN;
    } else
    #endif
    {
        PyObject *meth;
        result = PYGEN_RETURN;
        meth = __Pyx_PyObject_GetAttrStrNoError(yf, __pyx_mstate_global->__pyx_n_u_close);
        if (unlikely(!meth)) {
            if (unlikely(PyErr_Occurred())) {
                PyErr_WriteUnraisable(yf);
            }
        } else {
            retval = __Pyx_PyObject_CallNoArg(meth);
            Py_DECREF(meth);
            if (unlikely(!retval)) {
                result = PYGEN_ERROR;
            }
        }
    }
    Py_XDECREF(retval);
    return result == PYGEN_ERROR ? -1 : 0;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __Pyx_PySendResult result;
    PyObject *retval = NULL;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    if (unlikely(__Pyx_Coroutine_test_and_set_is_running(gen))) {
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    }
    #if CYTHON_USE_AM_SEND
    if (gen->yieldfrom_am_send) {
        result = __Pyx_Coroutine_SendToDelegate(gen, gen->yieldfrom_am_send, Py_None, &retval);
    } else
    #endif
    if (gen->yieldfrom) {
        PyObject *yf = gen->yieldfrom;
        PyObject *ret;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && (PY_VERSION_HEX < 0x030A00A3 || !CYTHON_USE_AM_SEND)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
            ret = __Pyx_PyIter_Next_Plain(yf);
        if (likely(ret)) {
            __Pyx_Coroutine_unset_is_running(gen);
            return ret;
        }
        result = __Pyx_Coroutine_FinishDelegation(gen, &retval);
    } else {
        result = __Pyx_Coroutine_SendEx(gen, Py_None, &retval, 0);
    }
    __Pyx_Coroutine_unset_is_running(gen);
    return __Pyx_Coroutine_MethodReturnFromResult(self, result, retval, 1);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, PyObject *arg) {
    PyObject *retval = NULL;
    __Pyx_PySendResult result;
    CYTHON_UNUSED_VAR(arg);
    result = __Pyx_Coroutine_Close(self, &retval);
    if (unlikely(result == PYGEN_ERROR))
        return NULL;
    Py_XDECREF(retval);
    Py_RETURN_NONE;
}
static __Pyx_PySendResult
__Pyx_Coroutine_Close(PyObject *self, PyObject **retval) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PySendResult result;
    PyObject *yf;
    int err = 0;
    if (unlikely(__Pyx_Coroutine_test_and_set_is_running(gen))) {
        *retval = __Pyx_Coroutine_AlreadyRunningError(gen);
        return PYGEN_ERROR;
    }
    yf = gen->yieldfrom;
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    result = __Pyx_Coroutine_SendEx(gen, NULL, retval, 1);
    if (result == PYGEN_ERROR) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_Coroutine_unset_is_running(gen);
        if (!__Pyx_PyErr_Occurred()) {
            return PYGEN_RETURN;
        } else if (likely(__Pyx_PyErr_ExceptionMatches2(PyExc_GeneratorExit, PyExc_StopIteration))) {
            __Pyx_PyErr_Clear();
            return PYGEN_RETURN;
        }
        return PYGEN_ERROR;
    } else if (likely(result == PYGEN_RETURN && *retval == Py_None)) {
        __Pyx_Coroutine_unset_is_running(gen);
        return PYGEN_RETURN;
    } else {
        const char *msg;
        Py_DECREF(*retval);
        *retval = NULL;
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
            msg = "async generator ignored GeneratorExit";
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        __Pyx_Coroutine_unset_is_running(gen);
        return PYGEN_ERROR;
    }
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf;
    if (unlikely(__Pyx_Coroutine_test_and_set_is_running(gen)))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    yf = gen->yieldfrom;
    if (yf) {
        __Pyx_PySendResult result;
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                goto propagate_exception;
            goto throw_here;
        }
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStrNoError(yf, __pyx_mstate_global->__pyx_n_u_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (unlikely(PyErr_Occurred())) {
                    __Pyx_Coroutine_unset_is_running(gen);
                    return NULL;
                }
                __Pyx_Coroutine_Undelegate(gen);
                goto throw_here;
            }
            if (likely(args)) {
                ret = __Pyx_PyObject_Call(meth, args, NULL);
            } else {
                PyObject *cargs[4] = {NULL, typ, val, tb};
                ret = __Pyx_PyObject_FastCall(meth, cargs+1, 3 | __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET);
            }
            Py_DECREF(meth);
        }
        Py_DECREF(yf);
        if (ret) {
            __Pyx_Coroutine_unset_is_running(gen);
            return ret;
        }
        result = __Pyx_Coroutine_FinishDelegation(gen, &ret);
        __Pyx_Coroutine_unset_is_running(gen);
        return __Pyx_Coroutine_MethodReturnFromResult(self, result, ret, 0);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
propagate_exception:
    {
        PyObject *retval = NULL;
        __Pyx_PySendResult result = __Pyx_Coroutine_SendEx(gen, NULL, &retval, 0);
        __Pyx_Coroutine_unset_is_running(gen);
        return __Pyx_Coroutine_MethodReturnFromResult(self, result, retval, 0);
    }
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (unlikely(!PyArg_UnpackTuple(args, "throw", 1, 3, &typ, &val, &tb)))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
#if PY_VERSION_HEX >= 0x030B00a4
    Py_VISIT(exc_state->exc_value);
#else
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
#endif
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    {
        int e = __Pyx_call_type_traverse((PyObject*)gen, 1, visit, arg);
        if (e) return e;
    }
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_frame);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    #if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    if (gen->gi_weakreflist != NULL)
    #endif
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if CYTHON_USE_TP_FINALIZE
        if (unlikely(PyObject_CallFinalizerFromDealloc(self)))
#else
        {
            destructor del = __Pyx_PyObject_GetSlot(gen, tp_del, destructor);
            if (del) del(self);
        }
        if (unlikely(Py_REFCNT(self) > 0))
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    __Pyx_PyHeapTypeObject_GC_Del(gen);
}
#if CYTHON_USE_TP_FINALIZE
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *retval = NULL;
        __Pyx_PySendResult result = __Pyx_Coroutine_Close(self, &retval);
        if (result == PYGEN_ERROR) {
            PyErr_WriteUnraisable(self);
        } else {
            Py_XDECREF(retval);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
}
#endif
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, void *context)
{
    PyObject *name = self->gi_name;
    CYTHON_UNUSED_VAR(context);
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(value == NULL || !PyUnicode_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(self->gi_name, value);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, void *context)
{
    PyObject *name = self->gi_qualname;
    CYTHON_UNUSED_VAR(context);
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(value == NULL || !PyUnicode_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(self->gi_qualname, value);
    return 0;
}
static PyObject *
__Pyx__Coroutine_get_frame(__pyx_CoroutineObject *self)
{
#if !CYTHON_COMPILING_IN_LIMITED_API
    PyObject *frame;
    #if PY_VERSION_HEX >= 0x030d0000
    Py_BEGIN_CRITICAL_SECTION(self);
    #endif
    frame = self->gi_frame;
    if (!frame) {
        if (unlikely(!self->gi_code)) {
            Py_RETURN_NONE;
        }
        PyObject *globals = PyDict_New();
        if (unlikely(!globals)) return NULL;
        frame = (PyObject *) PyFrame_New(
            PyThreadState_Get(),            
            (PyCodeObject*) self->gi_code,  
            globals,                        
            0                               
        );
        Py_DECREF(globals);
        if (unlikely(!frame))
            return NULL;
        if (unlikely(self->gi_frame)) {
            Py_DECREF(frame);
            frame = self->gi_frame;
        } else {
            self->gi_frame = frame;
        }
    }
    Py_INCREF(frame);
    #if PY_VERSION_HEX >= 0x030d0000
    Py_END_CRITICAL_SECTION();
    #endif
    return frame;
#else
    CYTHON_UNUSED_VAR(self);
    Py_RETURN_NONE;
#endif
}
static PyObject *
__Pyx_Coroutine_get_frame(__pyx_CoroutineObject *self, void *context) {
    CYTHON_UNUSED_VAR(context);
    PyObject *frame = self->gi_frame;
    if (frame)
        return __Pyx_NewRef(frame);
    return __Pyx__Coroutine_get_frame(self);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->yieldfrom_am_send = NULL;
    #if PY_VERSION_HEX >= 0x030B00a4 && !CYTHON_COMPILING_IN_LIMITED_API
    gen->gi_exc_state.exc_value = NULL;
    #else
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
    #endif
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    gen->gi_weakreflist = NULL;
#endif
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    gen->gi_frame = NULL;
    PyObject_GC_Track(gen);
    return gen;
}
static char __Pyx_Coroutine_test_and_set_is_running(__pyx_CoroutineObject *gen) {
    char result;
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_BEGIN_CRITICAL_SECTION(gen);
    #endif
    result = gen->is_running;
    gen->is_running = 1;
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_END_CRITICAL_SECTION();
    #endif
    return result;
}
static void __Pyx_Coroutine_unset_is_running(__pyx_CoroutineObject *gen) {
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_BEGIN_CRITICAL_SECTION(gen);
    #endif
    assert(gen->is_running);
    gen->is_running = 0;
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_END_CRITICAL_SECTION();
    #endif
}
static char __Pyx_Coroutine_get_is_running(__pyx_CoroutineObject *gen) {
    char result;
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_BEGIN_CRITICAL_SECTION(gen);
    #endif
    result = gen->is_running;
    #if PY_VERSION_HEX >= 0x030d0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_END_CRITICAL_SECTION();
    #endif
    return result;
}
static PyObject *__Pyx_Coroutine_get_is_running_getter(PyObject *gen, void *closure) {
    CYTHON_UNUSED_VAR(closure);
    char result = __Pyx_Coroutine_get_is_running((__pyx_CoroutineObject*)gen);
    if (result) Py_RETURN_TRUE;
    else Py_RETURN_FALSE;
}
#if __PYX_HAS_PY_AM_SEND == 2
static void __Pyx_SetBackportTypeAmSend(PyTypeObject *type, __Pyx_PyAsyncMethodsStruct *static_amsend_methods, __Pyx_pyiter_sendfunc am_send) {
    Py_ssize_t ptr_offset = (char*)(type->tp_as_async) - (char*)type;
    if (ptr_offset < 0 || ptr_offset > type->tp_basicsize) {
        return;
    }
    memcpy((void*)static_amsend_methods, (void*)(type->tp_as_async), sizeof(*type->tp_as_async));
    static_amsend_methods->am_send = am_send;
    type->tp_as_async = __Pyx_SlotTpAsAsync(static_amsend_methods);
}
#endif
static PyObject *__Pyx_Coroutine_fail_reduce_ex(PyObject *self, PyObject *arg) {
    CYTHON_UNUSED_VAR(arg);
    __Pyx_TypeName self_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE((PyObject*)self));
    PyErr_Format(PyExc_TypeError, "cannot pickle '" __Pyx_FMT_TYPENAME "' object",
                         self_type_name);
    __Pyx_DECREF_TypeName(self_type_name);
    return NULL;
}


static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {"__reduce_ex__", (PyCFunction) __Pyx_Coroutine_fail_reduce_ex, METH_O, 0},
    {"__reduce__", (PyCFunction) __Pyx_Coroutine_fail_reduce_ex, METH_NOARGS, 0},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {"gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     PyDoc_STR("object being iterated by 'yield from', or None")},
    {"gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {"__module__", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_modulename), 0, 0},
#if PY_VERSION_HEX < 0x030C0000 || CYTHON_COMPILING_IN_LIMITED_API
    {"__weaklistoffset__", T_PYSSIZET, offsetof(__pyx_CoroutineObject, gi_weakreflist), READONLY, 0},
#endif
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {"__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     PyDoc_STR("name of the generator"), 0},
    {"__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     PyDoc_STR("qualified name of the generator"), 0},
    {"gi_frame", (getter)__Pyx_Coroutine_get_frame, NULL,
     PyDoc_STR("Frame of the generator"), 0},
    {"gi_running", __Pyx_Coroutine_get_is_running_getter, NULL, NULL, NULL},
    {0, 0, 0, 0, 0}
};
static PyType_Slot __pyx_GeneratorType_slots[] = {
    {Py_tp_dealloc, (void *)__Pyx_Coroutine_dealloc},
    {Py_tp_traverse, (void *)__Pyx_Coroutine_traverse},
    {Py_tp_iter, (void *)PyObject_SelfIter},
    {Py_tp_iternext, (void *)__Pyx_Generator_Next},
    {Py_tp_methods, (void *)__pyx_Generator_methods},
    {Py_tp_members, (void *)__pyx_Generator_memberlist},
    {Py_tp_getset, (void *)__pyx_Generator_getsets},
    {Py_tp_getattro, (void *) PyObject_GenericGetAttr},
#if CYTHON_USE_TP_FINALIZE
    {Py_tp_finalize, (void *)__Pyx_Coroutine_del},
#endif
#if __PYX_HAS_PY_AM_SEND == 1
    {Py_am_send, (void *)__Pyx_Coroutine_AmSend},
#endif
    {0, 0},
};
static PyType_Spec __pyx_GeneratorType_spec = {
    __PYX_TYPE_MODULE_PREFIX "generator",
    sizeof(__pyx_CoroutineObject),
    0,
#if PY_VERSION_HEX >= 0x030C0000 && !CYTHON_COMPILING_IN_LIMITED_API
    Py_TPFLAGS_MANAGED_WEAKREF |
#endif
    Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_DISALLOW_INSTANTIATION |
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | __Pyx_TPFLAGS_HAVE_AM_SEND,
    __pyx_GeneratorType_slots
};
#if __PYX_HAS_PY_AM_SEND == 2
static __Pyx_PyAsyncMethodsStruct __pyx_Generator_as_async;
#endif
static int __pyx_Generator_init(PyObject *module) {
    __pyx_mstatetype *mstate = __Pyx_PyModule_GetState(module);
    mstate->__pyx_GeneratorType = __Pyx_FetchCommonTypeFromSpec(
        mstate->__pyx_CommonTypesMetaclassType, module, &__pyx_GeneratorType_spec, NULL);
    if (unlikely(!mstate->__pyx_GeneratorType)) {
        return -1;
    }
#if __PYX_HAS_PY_AM_SEND == 2
    __Pyx_SetBackportTypeAmSend(mstate->__pyx_GeneratorType, &__pyx_Generator_as_async, &__Pyx_Coroutine_AmSend);
#endif
    return 0;
}
static PyObject *__Pyx_Generator_GetInlinedResult(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *retval = NULL;
    if (unlikely(__Pyx_Coroutine_test_and_set_is_running(gen))) {
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    }
    __Pyx_PySendResult result = __Pyx_Coroutine_SendEx(gen, Py_None, &retval, 0);
    __Pyx_Coroutine_unset_is_running(gen);
    (void) result;
    assert (result == PYGEN_RETURN || result == PYGEN_ERROR);
    assert ((result == PYGEN_RETURN && retval != NULL) || (result == PYGEN_ERROR && retval == NULL));
    return retval;
}


static int __Pyx_check_binary_version(unsigned long ct_version, unsigned long rt_version, int allow_newer) {
    const unsigned long MAJOR_MINOR = 0xFFFF0000UL;
    if ((rt_version & MAJOR_MINOR) == (ct_version & MAJOR_MINOR))
        return 0;
    if (likely(allow_newer && (rt_version & MAJOR_MINOR) > (ct_version & MAJOR_MINOR)))
        return 1;
    {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compile time Python version %d.%d "
                      "of module '%.100s' "
                      "%s "
                      "runtime version %d.%d",
                       (int) (ct_version >> 24), (int) ((ct_version >> 16) & 0xFF),
                       __Pyx_MODULE_NAME,
                       (allow_newer) ? "was newer than" : "does not match",
                       (int) (rt_version >> 24), (int) ((rt_version >> 16) & 0xFF)
       );
        return PyErr_WarnEx(NULL, message, 1);
    }
}


#if CYTHON_COMPILING_IN_LIMITED_API
    static PyObject* __Pyx__PyCode_New(int a, int p, int k, int l, int s, int f,
                                       PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                       PyObject *fv, PyObject *cell, PyObject* fn,
                                       PyObject *name, int fline, PyObject *lnos) {
        PyObject *exception_table = NULL;
        PyObject *types_module=NULL, *code_type=NULL, *result=NULL;
        #if __PYX_LIMITED_VERSION_HEX < 0x030b0000
        PyObject *version_info;
        PyObject *py_minor_version = NULL;
        #endif
        long minor_version = 0;
        PyObject *type, *value, *traceback;
        PyErr_Fetch(&type, &value, &traceback);
        #if __PYX_LIMITED_VERSION_HEX >= 0x030b0000
        minor_version = 11;
        #else
        if (!(version_info = PySys_GetObject("version_info"))) goto end;
        if (!(py_minor_version = PySequence_GetItem(version_info, 1))) goto end;
        minor_version = PyLong_AsLong(py_minor_version);
        Py_DECREF(py_minor_version);
        if (minor_version == -1 && PyErr_Occurred()) goto end;
        #endif
        if (!(types_module = PyImport_ImportModule("types"))) goto end;
        if (!(code_type = PyObject_GetAttrString(types_module, "CodeType"))) goto end;
        if (minor_version <= 7) {
            (void)p;
            result = PyObject_CallFunction(code_type, "iiiiiOOOOOOiOOO", a, k, l, s, f, code,
                          c, n, v, fn, name, fline, lnos, fv, cell);
        } else if (minor_version <= 10) {
            result = PyObject_CallFunction(code_type, "iiiiiiOOOOOOiOOO", a,p, k, l, s, f, code,
                          c, n, v, fn, name, fline, lnos, fv, cell);
        } else {
            if (!(exception_table = PyBytes_FromStringAndSize(NULL, 0))) goto end;
            result = PyObject_CallFunction(code_type, "iiiiiiOOOOOOOiOOOO", a,p, k, l, s, f, code,
                          c, n, v, fn, name, name, fline, lnos, exception_table, fv, cell);
        }
    end:
        Py_XDECREF(code_type);
        Py_XDECREF(exception_table);
        Py_XDECREF(types_module);
        if (type) {
            PyErr_Restore(type, value, traceback);
        }
        return result;
    }
#elif PY_VERSION_HEX >= 0x030B0000
  static PyCodeObject* __Pyx__PyCode_New(int a, int p, int k, int l, int s, int f,
                                         PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                         PyObject *fv, PyObject *cell, PyObject* fn,
                                         PyObject *name, int fline, PyObject *lnos) {
    PyCodeObject *result;
    result =
      #if PY_VERSION_HEX >= 0x030C0000
        PyUnstable_Code_NewWithPosOnlyArgs
      #else
        PyCode_NewWithPosOnlyArgs
      #endif
        (a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, name, fline, lnos, __pyx_mstate_global->__pyx_empty_bytes);
    #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030c00A1
    if (likely(result))
        result->_co_firsttraceable = 0;
    #endif
    return result;
  }
#elif !CYTHON_COMPILING_IN_PYPY
  #define __Pyx__PyCode_New(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_NewWithPosOnlyArgs(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx__PyCode_New(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
static PyObject* __Pyx_PyCode_New(
        const __Pyx_PyCode_New_function_description descr,
        PyObject * const *varnames,
        PyObject *filename,
        PyObject *funcname,
        PyObject *line_table,
        PyObject *tuple_dedup_map
) {
    PyObject *code_obj = NULL, *varnames_tuple_dedup = NULL, *code_bytes = NULL;
    Py_ssize_t var_count = (Py_ssize_t) descr.nlocals;
    PyObject *varnames_tuple = PyTuple_New(var_count);
    if (unlikely(!varnames_tuple)) return NULL;
    for (Py_ssize_t i=0; i < var_count; i++) {
        Py_INCREF(varnames[i]);
        if (__Pyx_PyTuple_SET_ITEM(varnames_tuple, i, varnames[i]) != (0)) goto done;
    }
    #if CYTHON_COMPILING_IN_LIMITED_API
    varnames_tuple_dedup = PyDict_GetItem(tuple_dedup_map, varnames_tuple);
    if (!varnames_tuple_dedup) {
        if (unlikely(PyDict_SetItem(tuple_dedup_map, varnames_tuple, varnames_tuple) < 0)) goto done;
        varnames_tuple_dedup = varnames_tuple;
    }
    #else
    varnames_tuple_dedup = PyDict_SetDefault(tuple_dedup_map, varnames_tuple, varnames_tuple);
    if (unlikely(!varnames_tuple_dedup)) goto done;
    #endif
    #if CYTHON_AVOID_BORROWED_REFS
    Py_INCREF(varnames_tuple_dedup);
    #endif
    if (__PYX_LIMITED_VERSION_HEX >= (0x030b0000) && line_table != NULL && !CYTHON_COMPILING_IN_GRAAL) {
        Py_ssize_t line_table_length = __Pyx_PyBytes_GET_SIZE(line_table);
        #if !CYTHON_ASSUME_SAFE_SIZE
        if (unlikely(line_table_length == -1)) goto done;
        #endif
        Py_ssize_t code_len = (line_table_length * 2 + 4) & ~3LL;
        code_bytes = PyBytes_FromStringAndSize(NULL, code_len);
        if (unlikely(!code_bytes)) goto done;
        char* c_code_bytes = PyBytes_AsString(code_bytes);
        if (unlikely(!c_code_bytes)) goto done;
        memset(c_code_bytes, 0, (size_t) code_len);
    }
    code_obj = (PyObject*) __Pyx__PyCode_New(
        (int) descr.argcount,
        (int) descr.num_posonly_args,
        (int) descr.num_kwonly_args,
        (int) descr.nlocals,
        0,
        (int) descr.flags,
        code_bytes ? code_bytes : __pyx_mstate_global->__pyx_empty_bytes,
        __pyx_mstate_global->__pyx_empty_tuple,
        __pyx_mstate_global->__pyx_empty_tuple,
        varnames_tuple_dedup,
        __pyx_mstate_global->__pyx_empty_tuple,
        __pyx_mstate_global->__pyx_empty_tuple,
        filename,
        funcname,
        (int) descr.first_line,
        (__PYX_LIMITED_VERSION_HEX >= (0x030b0000) && line_table) ? line_table : __pyx_mstate_global->__pyx_empty_bytes
    );
done:
    Py_XDECREF(code_bytes);
    #if CYTHON_AVOID_BORROWED_REFS
    Py_XDECREF(varnames_tuple_dedup);
    #endif
    Py_DECREF(varnames_tuple);
    return code_obj;
}


static PyObject *__Pyx_DecompressString(const char *s, Py_ssize_t length, int algo) {
    PyObject *module, *decompress, *compressed_bytes, *decompressed;
    const char* module_name = algo == 3 ? "compression.zstd" : algo == 2 ? "bz2" : "zlib";
    PyObject *methodname = PyUnicode_FromString("decompress");
    if (unlikely(!methodname)) return NULL;
    #if __PYX_LIMITED_VERSION_HEX >= 0x030e0000
    if (algo == 3) {
        PyObject *fromlist = Py_BuildValue("[O]", methodname);
        if (unlikely(!fromlist)) return NULL;
        module = PyImport_ImportModuleLevel("compression.zstd", NULL, NULL, fromlist, 0);
        Py_DECREF(fromlist);
    } else
    #endif
        module = PyImport_ImportModule(module_name);
    if (unlikely(!module)) goto import_failed;
    decompress = PyObject_GetAttr(module, methodname);
    if (unlikely(!decompress)) goto import_failed;
    {
        #ifdef __cplusplus
            char *memview_bytes = const_cast<char*>(s);
        #else
            #if defined(__clang__)
              #pragma clang diagnostic push
              #pragma clang diagnostic ignored "-Wcast-qual"
            #elif !defined(__INTEL_COMPILER) && defined(__GNUC__)
              #pragma GCC diagnostic push
              #pragma GCC diagnostic ignored "-Wcast-qual"
            #endif
            char *memview_bytes = (char*) s;
            #if defined(__clang__)
              #pragma clang diagnostic pop
            #elif !defined(__INTEL_COMPILER) && defined(__GNUC__)
              #pragma GCC diagnostic pop
            #endif
        #endif
        #if CYTHON_COMPILING_IN_LIMITED_API && !defined(PyBUF_READ)
        int memview_flags = 0x100;
        #else
        int memview_flags = PyBUF_READ;
        #endif
        compressed_bytes = PyMemoryView_FromMemory(memview_bytes, length, memview_flags);
    }
    if (unlikely(!compressed_bytes)) {
        Py_DECREF(decompress);
        goto bad;
    }
    decompressed = PyObject_CallFunctionObjArgs(decompress, compressed_bytes, NULL);
    Py_DECREF(compressed_bytes);
    Py_DECREF(decompress);
    Py_DECREF(module);
    Py_DECREF(methodname);
    return decompressed;
import_failed:
    PyErr_Format(PyExc_ImportError,
        "Failed to import '%.20s.decompress' - cannot initialise module strings. "
        "String compression was configured with the C macro 'CYTHON_COMPRESS_STRINGS=%d'.",
        module_name, algo);
bad:
    Py_XDECREF(module);
    Py_DECREF(methodname);
    return NULL;
}

#include <string.h>
static CYTHON_INLINE Py_ssize_t __Pyx_ssize_strlen(const char *s) {
    size_t len = strlen(s);
    if (unlikely(len > (size_t) PY_SSIZE_T_MAX)) {
        PyErr_SetString(PyExc_OverflowError, "byte string is too long");
        return -1;
    }
    return (Py_ssize_t) len;
}
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    Py_ssize_t len = __Pyx_ssize_strlen(c_str);
    if (unlikely(len < 0)) return NULL;
    return __Pyx_PyUnicode_FromStringAndSize(c_str, len);
}
static CYTHON_INLINE PyObject* __Pyx_PyByteArray_FromString(const char* c_str) {
    Py_ssize_t len = __Pyx_ssize_strlen(c_str);
    if (unlikely(len < 0)) return NULL;
    return PyByteArray_FromStringAndSize(c_str, len);
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_UTF8
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if CYTHON_COMPILING_IN_LIMITED_API
    {
        const char* result;
        Py_ssize_t unicode_length;
        CYTHON_MAYBE_UNUSED_VAR(unicode_length); // only for __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
        #if __PYX_LIMITED_VERSION_HEX < 0x030A0000
        if (unlikely(PyArg_Parse(o, "s#", &result, length) < 0)) return NULL;
        #else
        result = PyUnicode_AsUTF8AndSize(o, length);
        #endif
        #if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
        unicode_length = PyUnicode_GetLength(o);
        if (unlikely(unicode_length < 0)) return NULL;
        if (unlikely(unicode_length != *length)) {
            PyUnicode_AsASCIIString(o);
            return NULL;
        }
        #endif
        return result;
    }
#else
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
#endif
}
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_UTF8
    if (PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
    if (PyByteArray_Check(o)) {
#if (CYTHON_ASSUME_SAFE_SIZE && CYTHON_ASSUME_SAFE_MACROS) || (CYTHON_COMPILING_IN_PYPY && (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE)))
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
#else
        *length = PyByteArray_Size(o);
        if (*length == -1) return NULL;
        return PyByteArray_AsString(o);
#endif
    } else
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_LongWrongResultType(PyObject* result) {
    __Pyx_TypeName result_type_name = __Pyx_PyType_GetFullyQualifiedName(Py_TYPE(result));
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type " __Pyx_FMT_TYPENAME ").  "
                "The ability to return an instance of a strict subclass of int is deprecated, "
                "and may be removed in a future version of Python.",
                result_type_name)) {
            __Pyx_DECREF_TypeName(result_type_name);
            Py_DECREF(result);
            return NULL;
        }
        __Pyx_DECREF_TypeName(result_type_name);
        return result;
    }
    PyErr_Format(PyExc_TypeError,
                 "__int__ returned non-int (type " __Pyx_FMT_TYPENAME ")",
                 result_type_name);
    __Pyx_DECREF_TypeName(result_type_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_Long(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  PyObject *res = NULL;
  if (likely(PyLong_Check(x)))
      return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  if (likely(m && m->nb_int)) {
      res = m->nb_int(x);
  }
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
      res = PyNumber_Long(x);
  }
#endif
  if (likely(res)) {
      if (unlikely(!PyLong_CheckExact(res))) {
          return __Pyx_PyNumber_LongWrongResultType(res);
      }
  }
  else if (!PyErr_Occurred()) {
      PyErr_SetString(PyExc_TypeError,
                      "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(__Pyx_PyLong_IsCompact(b))) {
        return __Pyx_PyLong_CompactValue(b);
    } else {
      const digit* digits = __Pyx_PyLong_Digits(b);
      const Py_ssize_t size = __Pyx_PyLong_SignedDigitCount(b);
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyLong_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject* o) {
  if (sizeof(Py_hash_t) == sizeof(Py_ssize_t)) {
    return (Py_hash_t) __Pyx_PyIndex_AsSsize_t(o);
  } else {
    Py_ssize_t ival;
    PyObject *x;
    x = PyNumber_Index(o);
    if (!x) return -1;
    ival = PyLong_AsLong(x);
    Py_DECREF(x);
    return ival;
  }
}
static CYTHON_INLINE PyObject *__Pyx_Owned_Py_None(int b) {
    CYTHON_UNUSED_VAR(b);
    return __Pyx_NewRef(Py_None);
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return __Pyx_NewRef(b ? Py_True: Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyLong_FromSize_t(size_t ival) {
    return PyLong_FromSize_t(ival);
}



#if CYTHON_PEP489_MULTI_PHASE_INIT && CYTHON_USE_MODULE_STATE
#ifndef CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
#if (CYTHON_COMPILING_IN_LIMITED_API || PY_VERSION_HEX >= 0x030C0000)
  #define CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE 1
#else
  #define CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE 0
#endif
#endif
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE && !CYTHON_ATOMICS
#error "Module state with PEP489 requires atomics. Currently that's one of\
 C11, C++11, gcc atomic intrinsics or MSVC atomic intrinsics"
#endif
#if !CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
#define __Pyx_ModuleStateLookup_Lock()
#define __Pyx_ModuleStateLookup_Unlock()
#elif !CYTHON_COMPILING_IN_LIMITED_API && PY_VERSION_HEX >= 0x030d0000
static PyMutex __Pyx_ModuleStateLookup_mutex = {0};
#define __Pyx_ModuleStateLookup_Lock() PyMutex_Lock(&__Pyx_ModuleStateLookup_mutex)
#define __Pyx_ModuleStateLookup_Unlock() PyMutex_Unlock(&__Pyx_ModuleStateLookup_mutex)
#elif defined(__cplusplus) && __cplusplus >= 201103L
#include <mutex>
static std::mutex __Pyx_ModuleStateLookup_mutex;
#define __Pyx_ModuleStateLookup_Lock() __Pyx_ModuleStateLookup_mutex.lock()
#define __Pyx_ModuleStateLookup_Unlock() __Pyx_ModuleStateLookup_mutex.unlock()
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ > 201112L) && !defined(__STDC_NO_THREADS__)
#include <threads.h>
static mtx_t __Pyx_ModuleStateLookup_mutex;
static once_flag __Pyx_ModuleStateLookup_mutex_once_flag = ONCE_FLAG_INIT;
static void __Pyx_ModuleStateLookup_initialize_mutex(void) {
    mtx_init(&__Pyx_ModuleStateLookup_mutex, mtx_plain);
}
#define __Pyx_ModuleStateLookup_Lock()\
  call_once(&__Pyx_ModuleStateLookup_mutex_once_flag, __Pyx_ModuleStateLookup_initialize_mutex);\
  mtx_lock(&__Pyx_ModuleStateLookup_mutex)
#define __Pyx_ModuleStateLookup_Unlock() mtx_unlock(&__Pyx_ModuleStateLookup_mutex)
#elif defined(HAVE_PTHREAD_H)
#include <pthread.h>
static pthread_mutex_t __Pyx_ModuleStateLookup_mutex = PTHREAD_MUTEX_INITIALIZER;
#define __Pyx_ModuleStateLookup_Lock() pthread_mutex_lock(&__Pyx_ModuleStateLookup_mutex)
#define __Pyx_ModuleStateLookup_Unlock() pthread_mutex_unlock(&__Pyx_ModuleStateLookup_mutex)
#elif defined(_WIN32)
#include <Windows.h>  // synchapi.h on its own doesn't work
static SRWLOCK __Pyx_ModuleStateLookup_mutex = SRWLOCK_INIT;
#define __Pyx_ModuleStateLookup_Lock() AcquireSRWLockExclusive(&__Pyx_ModuleStateLookup_mutex)
#define __Pyx_ModuleStateLookup_Unlock() ReleaseSRWLockExclusive(&__Pyx_ModuleStateLookup_mutex)
#else
#error "No suitable lock available for CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE.\
 Requires C standard >= C11, or C++ standard >= C++11,\
 or pthreads, or the Windows 32 API, or Python >= 3.13."
#endif
typedef struct {
    int64_t id;
    PyObject *module;
} __Pyx_InterpreterIdAndModule;
typedef struct {
    char interpreter_id_as_index;
    Py_ssize_t count;
    Py_ssize_t allocated;
    __Pyx_InterpreterIdAndModule table[1];
} __Pyx_ModuleStateLookupData;
#define __PYX_MODULE_STATE_LOOKUP_SMALL_SIZE 32
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
static __pyx_atomic_int_type __Pyx_ModuleStateLookup_read_counter = 0;
#endif
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
static __pyx_atomic_ptr_type __Pyx_ModuleStateLookup_data = 0;
#else
static __Pyx_ModuleStateLookupData* __Pyx_ModuleStateLookup_data = NULL;
#endif
static __Pyx_InterpreterIdAndModule* __Pyx_State_FindModuleStateLookupTableLowerBound(
        __Pyx_InterpreterIdAndModule* table,
        Py_ssize_t count,
        int64_t interpreterId) {
    __Pyx_InterpreterIdAndModule* begin = table;
    __Pyx_InterpreterIdAndModule* end = begin + count;
    if (begin->id == interpreterId) {
        return begin;
    }
    while ((end - begin) > __PYX_MODULE_STATE_LOOKUP_SMALL_SIZE) {
        __Pyx_InterpreterIdAndModule* halfway = begin + (end - begin)/2;
        if (halfway->id == interpreterId) {
            return halfway;
        }
        if (halfway->id < interpreterId) {
            begin = halfway;
        } else {
            end = halfway;
        }
    }
    for (; begin < end; ++begin) {
        if (begin->id >= interpreterId) return begin;
    }
    return begin;
}
static PyObject *__Pyx_State_FindModule(CYTHON_UNUSED void* dummy) {
    int64_t interpreter_id = PyInterpreterState_GetID(__Pyx_PyInterpreterState_Get());
    if (interpreter_id == -1) return NULL;
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
    __Pyx_ModuleStateLookupData* data = (__Pyx_ModuleStateLookupData*)__pyx_atomic_pointer_load_relaxed(&__Pyx_ModuleStateLookup_data);
    {
        __pyx_atomic_incr_acq_rel(&__Pyx_ModuleStateLookup_read_counter);
        if (likely(data)) {
            __Pyx_ModuleStateLookupData* new_data = (__Pyx_ModuleStateLookupData*)__pyx_atomic_pointer_load_acquire(&__Pyx_ModuleStateLookup_data);
            if (likely(data == new_data)) {
                goto read_finished;
            }
        }
        __pyx_atomic_decr_acq_rel(&__Pyx_ModuleStateLookup_read_counter);
        __Pyx_ModuleStateLookup_Lock();
        __pyx_atomic_incr_relaxed(&__Pyx_ModuleStateLookup_read_counter);
        data = (__Pyx_ModuleStateLookupData*)__pyx_atomic_pointer_load_relaxed(&__Pyx_ModuleStateLookup_data);
        __Pyx_ModuleStateLookup_Unlock();
    }
  read_finished:;
#else
    __Pyx_ModuleStateLookupData* data = __Pyx_ModuleStateLookup_data;
#endif
    __Pyx_InterpreterIdAndModule* found = NULL;
    if (unlikely(!data)) goto end;
    if (data->interpreter_id_as_index) {
        if (interpreter_id < data->count) {
            found = data->table+interpreter_id;
        }
    } else {
        found = __Pyx_State_FindModuleStateLookupTableLowerBound(
            data->table, data->count, interpreter_id);
    }
  end:
    {
        PyObject *result=NULL;
        if (found && found->id == interpreter_id) {
            result = found->module;
        }
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
        __pyx_atomic_decr_acq_rel(&__Pyx_ModuleStateLookup_read_counter);
#endif
        return result;
    }
}
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
static void __Pyx_ModuleStateLookup_wait_until_no_readers(void) {
    while (__pyx_atomic_load(&__Pyx_ModuleStateLookup_read_counter) != 0);
}
#else
#define __Pyx_ModuleStateLookup_wait_until_no_readers()
#endif
static int __Pyx_State_AddModuleInterpIdAsIndex(__Pyx_ModuleStateLookupData **old_data, PyObject* module, int64_t interpreter_id) {
    Py_ssize_t to_allocate = (*old_data)->allocated;
    while (to_allocate <= interpreter_id) {
        if (to_allocate == 0) to_allocate = 1;
        else to_allocate *= 2;
    }
    __Pyx_ModuleStateLookupData *new_data = *old_data;
    if (to_allocate != (*old_data)->allocated) {
         new_data = (__Pyx_ModuleStateLookupData *)realloc(
            *old_data,
            sizeof(__Pyx_ModuleStateLookupData)+(to_allocate-1)*sizeof(__Pyx_InterpreterIdAndModule));
        if (!new_data) {
            PyErr_NoMemory();
            return -1;
        }
        for (Py_ssize_t i = new_data->allocated; i < to_allocate; ++i) {
            new_data->table[i].id = i;
            new_data->table[i].module = NULL;
        }
        new_data->allocated = to_allocate;
    }
    new_data->table[interpreter_id].module = module;
    if (new_data->count < interpreter_id+1) {
        new_data->count = interpreter_id+1;
    }
    *old_data = new_data;
    return 0;
}
static void __Pyx_State_ConvertFromInterpIdAsIndex(__Pyx_ModuleStateLookupData *data) {
    __Pyx_InterpreterIdAndModule *read = data->table;
    __Pyx_InterpreterIdAndModule *write = data->table;
    __Pyx_InterpreterIdAndModule *end = read + data->count;
    for (; read<end; ++read) {
        if (read->module) {
            write->id = read->id;
            write->module = read->module;
            ++write;
        }
    }
    data->count = write - data->table;
    for (; write<end; ++write) {
        write->id = 0;
        write->module = NULL;
    }
    data->interpreter_id_as_index = 0;
}
static int __Pyx_State_AddModule(PyObject* module, CYTHON_UNUSED void* dummy) {
    int64_t interpreter_id = PyInterpreterState_GetID(__Pyx_PyInterpreterState_Get());
    if (interpreter_id == -1) return -1;
    int result = 0;
    __Pyx_ModuleStateLookup_Lock();
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
    __Pyx_ModuleStateLookupData *old_data = (__Pyx_ModuleStateLookupData *)
            __pyx_atomic_pointer_exchange(&__Pyx_ModuleStateLookup_data, 0);
#else
    __Pyx_ModuleStateLookupData *old_data = __Pyx_ModuleStateLookup_data;
#endif
    __Pyx_ModuleStateLookupData *new_data = old_data;
    if (!new_data) {
        new_data = (__Pyx_ModuleStateLookupData *)calloc(1, sizeof(__Pyx_ModuleStateLookupData));
        if (!new_data) {
            result = -1;
            PyErr_NoMemory();
            goto end;
        }
        new_data->allocated = 1;
        new_data->interpreter_id_as_index = 1;
    }
    __Pyx_ModuleStateLookup_wait_until_no_readers();
    if (new_data->interpreter_id_as_index) {
        if (interpreter_id < __PYX_MODULE_STATE_LOOKUP_SMALL_SIZE) {
            result = __Pyx_State_AddModuleInterpIdAsIndex(&new_data, module, interpreter_id);
            goto end;
        }
        __Pyx_State_ConvertFromInterpIdAsIndex(new_data);
    }
    {
        Py_ssize_t insert_at = 0;
        {
            __Pyx_InterpreterIdAndModule* lower_bound = __Pyx_State_FindModuleStateLookupTableLowerBound(
                new_data->table, new_data->count, interpreter_id);
            assert(lower_bound);
            insert_at = lower_bound - new_data->table;
            if (unlikely(insert_at < new_data->count && lower_bound->id == interpreter_id)) {
                lower_bound->module = module;
                goto end;  // already in table, nothing more to do
            }
        }
        if (new_data->count+1 >= new_data->allocated) {
            Py_ssize_t to_allocate = (new_data->count+1)*2;
            new_data =
                (__Pyx_ModuleStateLookupData*)realloc(
                    new_data,
                    sizeof(__Pyx_ModuleStateLookupData) +
                    (to_allocate-1)*sizeof(__Pyx_InterpreterIdAndModule));
            if (!new_data) {
                result = -1;
                new_data = old_data;
                PyErr_NoMemory();
                goto end;
            }
            new_data->allocated = to_allocate;
        }
        ++new_data->count;
        int64_t last_id = interpreter_id;
        PyObject *last_module = module;
        for (Py_ssize_t i=insert_at; i<new_data->count; ++i) {
            int64_t current_id = new_data->table[i].id;
            new_data->table[i].id = last_id;
            last_id = current_id;
            PyObject *current_module = new_data->table[i].module;
            new_data->table[i].module = last_module;
            last_module = current_module;
        }
    }
  end:
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
    __pyx_atomic_pointer_exchange(&__Pyx_ModuleStateLookup_data, new_data);
#else
    __Pyx_ModuleStateLookup_data = new_data;
#endif
    __Pyx_ModuleStateLookup_Unlock();
    return result;
}
static int __Pyx_State_RemoveModule(CYTHON_UNUSED void* dummy) {
    int64_t interpreter_id = PyInterpreterState_GetID(__Pyx_PyInterpreterState_Get());
    if (interpreter_id == -1) return -1;
    __Pyx_ModuleStateLookup_Lock();
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
    __Pyx_ModuleStateLookupData *data = (__Pyx_ModuleStateLookupData *)
            __pyx_atomic_pointer_exchange(&__Pyx_ModuleStateLookup_data, 0);
#else
    __Pyx_ModuleStateLookupData *data = __Pyx_ModuleStateLookup_data;
#endif
    if (data->interpreter_id_as_index) {
        if (interpreter_id < data->count) {
            data->table[interpreter_id].module = NULL;
        }
        goto done;
    }
    {
        __Pyx_ModuleStateLookup_wait_until_no_readers();
        __Pyx_InterpreterIdAndModule* lower_bound = __Pyx_State_FindModuleStateLookupTableLowerBound(
            data->table, data->count, interpreter_id);
        if (!lower_bound) goto done;
        if (lower_bound->id != interpreter_id) goto done;
        __Pyx_InterpreterIdAndModule *end = data->table+data->count;
        for (;lower_bound<end-1; ++lower_bound) {
            lower_bound->id = (lower_bound+1)->id;
            lower_bound->module = (lower_bound+1)->module;
        }
    }
    --data->count;
    if (data->count == 0) {
        free(data);
        data = NULL;
    }
  done:
#if CYTHON_MODULE_STATE_LOOKUP_THREAD_SAFE
    __pyx_atomic_pointer_exchange(&__Pyx_ModuleStateLookup_data, data);
#else
    __Pyx_ModuleStateLookup_data = data;
#endif
    __Pyx_ModuleStateLookup_Unlock();
    return 0;
}
#endif


#ifdef _MSC_VER
#pragma warning( pop )
#endif




#endif 

#ifdef __FreeBSD__
#include <dede.h>
#endif
#if PY_MAJOR_VERSION < 3
int main(int argc, char** argv) {
#elif defined(Win32) || defined(MS_WINDOWS)
int wmain(int argc, wchar_t **argv) {
#else
static int __Pyx_main(int argc, wchar_t **argv) {
#endif
#ifdef __FreeBSD__
    fp_except_t m;
    m = fpgetmask();
    fpsetmask(m & ~FP_X_OFL);
#endif
    if (argc && argv)
        Py_SetProgramName(argv[0]);
    Py_Initialize();
    if (argc && argv)
        PySys_SetArgv(argc, argv);
    {
      PyObject* m = NULL;
      __pyx_module_is_main_hdcs = 1;
      #if PY_MAJOR_VERSION < 3
          inithdcs();
      #elif CYTHON_PEP489_MULTI_PHASE_INIT
          m = PyInit_hdcs();
          if (!PyModule_Check(m)) {
              PyModuleDef *mdef = (PyModuleDef *) m;
              PyObject *modname = PyUnicode_FromString("__main__");
              m = NULL;
              if (modname) {
                  m = PyModule_NewObject(modname);
                  Py_DECREF(modname);
                  if (m) PyModule_ExecDef(m, mdef);
              }
          }
      #else
          m = PyInit_hdcs();
      #endif
      if (PyErr_Occurred()) {
          PyErr_Print();
          #if PY_MAJOR_VERSION < 3
          if (Py_FlushLine()) PyErr_Clear();
          #endif
          return 1;
      }
      Py_XDECREF(m);
    }
#if PY_VERSION_HEX < 0x03060000
    Py_Finalize();
#else
    if (Py_FinalizeEx() < 0)
        return 2;
#endif
    return 0;
}
#if PY_MAJOR_VERSION >= 3 && !defined(Win32) && !defined(MS_WINDOWS)
#include <locale.h>
static wchar_t*
__Pyx_char2wchar(char* arg)
{
    wchar_t *res;
#ifdef HAVE_BROKEN_MBSTOWCS
    size_t argsize = strlen(arg);
#else
    size_t argsize = mbstowcs(NULL, arg, 0);
#endif
    size_t count;
    unsigned char *in;
    wchar_t *out;
#ifdef HAVE_MBRTOWC
    mbstate_t mbs;
#endif
    if (argsize != (size_t)-1) {
        res = (wchar_t *)malloc((argsize+1)*sizeof(wchar_t));
        if (!res)
            goto oom;
        count = mbstowcs(res, arg, argsize+1);
        if (count != (size_t)-1) {
            wchar_t *tmp;
            for (tmp = res; *tmp != 0 &&
                     (*tmp < 0xd800 || *tmp > 0xdfff); tmp++)
                ;
            if (*tmp == 0)
                return res;
        }
        free(res);
    }
#ifdef HAVE_MBRTOWC
    argsize = strlen(arg) + 1;
    res = (wchar_t *)malloc(argsize*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    memset(&mbs, 0, sizeof mbs);
    while (argsize) {
        size_t converted = mbrtowc(out, (char*)in, argsize, &mbs);
        if (converted == 0)
            break;
        if (converted == (size_t)-2) {
            fprintf(stderr, "unexpected mbrtowc result -2");
            free(res);
            return NULL;
        }
        if (converted == (size_t)-1) {
            *out++ = 0xdc00 + *in++;
            argsize--;
            memset(&mbs, 0, sizeof mbs);
            continue;
        }
        if (*out >= 0xd800 && *out <= 0xdfff) {
            argsize -= converted;
            while (converted--)
                *out++ = 0xdc00 + *in++;
            continue;
        }
        in += converted;
        argsize -= converted;
        out++;
    }
#else
    res = (wchar_t *)malloc((strlen(arg)+1)*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    while(*in)
        if(*in < 128)
            *out++ = *in++;
        else
            *out++ = 0xdc00 + *in++;
    *out = 0;
#endif
    return res;
oom:
    fprintf(stderr, "out of memory");
    return NULL;
}
int
main(int argc, char **argv)
{
    if (!argc) {
        return __Pyx_main(0, NULL);
    }
    else {
        int i, res;
        wchar_t **argv_copy = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        wchar_t **argv_copy2 = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        char *oldloc = strdup(setlocale(LC_ALL, NULL));
        if (!argv_copy || !argv_copy2 || !oldloc) {
            fprintf(stderr, "out of memory");
            free(argv_copy);
            free(argv_copy2);
            free(oldloc);
            return 1;
        }
        res = 0;
        setlocale(LC_ALL, "");
        for (i = 0; i < argc; i++) {
            argv_copy2[i] = argv_copy[i] = __Pyx_char2wchar(argv[i]);
            if (!argv_copy[i]) res = 1;
        }
        setlocale(LC_ALL, oldloc);
        free(oldloc);
        if (res == 0)
            res = __Pyx_main(argc, argv_copy);
        for (i = 0; i < argc; i++) {
#if PY_VERSION_HEX < 0x03050000
            free(argv_copy2[i]);
#else
            PyMem_RawFree(argv_copy2[i]);
#endif
        }
        free(argv_copy);
        free(argv_copy2);
        return res;
    }
}
#endif
