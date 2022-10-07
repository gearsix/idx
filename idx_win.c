#ifdef IDX_WIN

#include <stdio.h>


int idxseek(FILE *stream, idx_t offset, int origin)
{
	return _fseeki64(stream, (__int64)offset, origin);
}

idx_t idxtell(FILE *stream)
{
	return (idx_t)_ftelli64(stream);
}

#endif
