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

idx_t strtoidx(const char *s, char **end, int base)
{
	return (idx_t)strtoi64(s, end, base);
}

int idxtostr(idx_t i, char **buf)
{
	return sprintf(buf, "%I64", i);
}

#endif
