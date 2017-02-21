/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */


#ifndef SWIGJAVA
#define SWIGJAVA
#endif


/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "ccnx_PortalFactory.h"
#include "ccnx_PortalRTA.h"


void ccnxPortalFactory_Release1(CCNxPortalFactory *factoryPtr) {
     ccnxPortalFactory_Release(&factoryPtr);
}

CCNxPortal *ccnxPortalFactory_CreatePortal1(const CCNxPortalFactory *factory) {
    return ccnxPortalFactory_CreatePortal(factory, ccnxPortalRTA_Message);
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalRouterName_1set(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg1, 0);
    if (!arg1) return ;
  }
  {
    if (arg1) {
      CCNxPortalFactory_LocalRouterName = (char const *) malloc(strlen((const char *)arg1)+1);
      strcpy((char *)CCNxPortalFactory_LocalRouterName, (const char *)arg1);
    } else {
      CCNxPortalFactory_LocalRouterName = 0;
    }
  }
  if (arg1) (*jenv)->ReleaseStringUTFChars(jenv, jarg1, (const char *)arg1);
}


SWIGEXPORT jstring JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalRouterName_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)CCNxPortalFactory_LocalRouterName;
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalForwarder_1set(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg1, 0);
    if (!arg1) return ;
  }
  {
    if (arg1) {
      CCNxPortalFactory_LocalForwarder = (char const *) malloc(strlen((const char *)arg1)+1);
      strcpy((char *)CCNxPortalFactory_LocalForwarder, (const char *)arg1);
    } else {
      CCNxPortalFactory_LocalForwarder = 0;
    }
  }
  if (arg1) (*jenv)->ReleaseStringUTFChars(jenv, jarg1, (const char *)arg1);
}


SWIGEXPORT jstring JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalForwarder_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)CCNxPortalFactory_LocalForwarder;
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalRouterTimeout_1set(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg1, 0);
    if (!arg1) return ;
  }
  {
    if (arg1) {
      CCNxPortalFactory_LocalRouterTimeout = (char const *) malloc(strlen((const char *)arg1)+1);
      strcpy((char *)CCNxPortalFactory_LocalRouterTimeout, (const char *)arg1);
    } else {
      CCNxPortalFactory_LocalRouterTimeout = 0;
    }
  }
  if (arg1) (*jenv)->ReleaseStringUTFChars(jenv, jarg1, (const char *)arg1);
}


SWIGEXPORT jstring JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_CCNxPortalFactory_1LocalRouterTimeout_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)CCNxPortalFactory_LocalRouterTimeout;
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1Create(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  PARCIdentity *arg1 = (PARCIdentity *) 0 ;
  CCNxPortalFactory *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(PARCIdentity **)&jarg1; 
  result = (CCNxPortalFactory *)ccnxPortalFactory_Create((PARCIdentity const *)arg1);
  *(CCNxPortalFactory **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1Display(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  arg2 = (int)jarg2; 
  ccnxPortalFactory_Display((CCNxPortalFactory const *)arg1,arg2);
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1Acquire(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  CCNxPortalFactory *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  result = (CCNxPortalFactory *)ccnxPortalFactory_Acquire((CCNxPortalFactory const *)arg1);
  *(CCNxPortalFactory **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1Release(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  CCNxPortalFactory **arg1 = (CCNxPortalFactory **) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory ***)&jarg1; 
  ccnxPortalFactory_Release(arg1);
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1GetIdentity(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  PARCIdentity *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  result = (PARCIdentity *)ccnxPortalFactory_GetIdentity((CCNxPortalFactory const *)arg1);
  *(PARCIdentity **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1GetKeyId(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  PARCKeyId *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  result = (PARCKeyId *)ccnxPortalFactory_GetKeyId((CCNxPortalFactory const *)arg1);
  *(PARCKeyId **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1CreatePortal(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  CCNxStackImpl *arg2 = (CCNxStackImpl *) 0 ;
  CCNxPortal *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  arg2 = *(CCNxStackImpl **)&jarg2; 
  result = (CCNxPortal *)ccnxPortalFactory_CreatePortal((CCNxPortalFactory const *)arg1,arg2);
  *(CCNxPortal **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1GetProperties(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  PARCProperties *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  result = (PARCProperties *)ccnxPortalFactory_GetProperties((CCNxPortalFactory const *)arg1);
  *(PARCProperties **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1GetProperty(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jstring jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (char *)ccnxPortalFactory_GetProperty((CCNxPortalFactory const *)arg1,(char const *)arg2,(char const *)arg3);
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1SetProperty(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return ;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return ;
  }
  ccnxPortalFactory_SetProperty((CCNxPortalFactory const *)arg1,(char const *)arg2,(char const *)arg3);
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
}


SWIGEXPORT void JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1Release1(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  ccnxPortalFactory_Release1(arg1);
}


SWIGEXPORT jlong JNICALL Java_ccnx_api_ccnx_1Portal_CcnxPortalFactory_ccnxPortalFactory_1CreatePortal1(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  CCNxPortalFactory *arg1 = (CCNxPortalFactory *) 0 ;
  CCNxPortal *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CCNxPortalFactory **)&jarg1; 
  result = (CCNxPortal *)ccnxPortalFactory_CreatePortal1((CCNxPortalFactory const *)arg1);
  *(CCNxPortal **)&jresult = result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

