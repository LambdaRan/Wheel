
// include <cdefs.h>

/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef	__cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif


// /* BEGIN_C_DECLS should be used at the beginning of your declarations,
//    so that C++ compilers don't mangle their names.  Use END_C_DECLS at
//    the end of C declarations. */
// #undef BEGIN_C_DECLS
// #undef END_C_DECLS
// #ifdef __cplusplus
// # define BEGIN_C_DECLS extern "C" {
// # define END_C_DECLS }
// #else
// # define BEGIN_C_DECLS /* empty */
// # define END_C_DECLS /* empty */
// #endif

//  #if defined(__cplusplus)
//     #define __BEGIN_DECLS   extern "C" {
//     #define __END_DECLS     }
//     #else
//     #define __BEGIN_DECLS
//     #define __END_DECLS