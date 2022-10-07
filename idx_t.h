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

/* Unknown system!
  This limits the `idx.h` to using the standard
  library, rendering it fairly pointless since
  `fseek` and `ftell` are limited to `long int`.
  
  If you would like to use `idx.h` anyway, just
  remove or comment out the `#error` below.
  
  That said, if you're on a system with 64-bit
  support that idx.h doesn't know about, please
  drop an email or submit a patch. */
#else
	#error "System not supported. See idx_t.h for details."
	#define IDX_UNKW
	typedef unsigned long idx_t;

#endif


#ifdef __cplusplus
}
#endif
#endif /* IDX_T */

