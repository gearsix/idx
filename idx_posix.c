#ifdef IDX_POSIX

#include <stdio.h>


int idxseek(FILE *stream, idx_t offset, int origin)
{
	return _fseeko(stream, (off_t)offset, origin);
}

idx_t idxtell(FILE *stream)
{
	return (idx_t)ftello(stream);
}

#endif
