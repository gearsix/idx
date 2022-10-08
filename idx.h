#ifndef IDX
#define IDX
#ifdef __cplusplus
extern "C" {
#endif

#include "idx_t.h" /* idx_t typedef */

int idxseek(FILE *stream, idx_t offset, int origin);

idx_t idxtell(FILE *stream);

idx_t strtoidx(const char *s, char **end, int base);

int idxtostr(idx_t i, char **buf);

#ifdef __cplusplus
}
#endif
#endif /* IDX */
