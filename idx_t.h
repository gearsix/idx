#ifndef IDX_T
#define IDX_T
#ifdef __cplusplus
extern "C" {
#endif


/* Systems with POSIX support */
#ifdef __unix__ || (__APPLE__ && __MACH__)
	#include <unistd.h>
	#define IDX_POSIX
	typedef off_t idx_t
	
/* Windows... */
#elif defined(_WIN32)
	#define IDX_WIN
	typedef __int64 idx_t;

/* Unknown system, check if we at least have C99 */
#elif (__STDC_VERSION__ >= 199901L)
	#include <stdint.h>
	#define IDX_UKWNC99
	typedef uint_least64_t idx_t;

/* Unknown system and either non-standard C or pre-C99!
  This limits the `idx.h` to using the standard
  library AND being stuck with `unsigned long`,
  rendering it fairly pointless.
  
  If you would like to use `idx.h` anyway, just
  remove or comment out the `#error` below.
  
  That said, if you're on a system with 64-bit
  support that idx.h doesn't know about, please
  drop an email or submit a patch. */
#else
	#error "System not supported and C std pre-C99."
	#define IDX_UNKW
	typedef unsigned long idx_t;

#endif


#ifdef __cplusplus
}
#endif
#endif /* IDX_T */

