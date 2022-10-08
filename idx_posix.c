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

idx_t strtoidx(const char *s, char **end, int base)
{
	return (idx_t)strtoull(s, end, base);
}

int idxtostr(idx_t i, char **buf)
{
	return sprintf(buf, "%llu", i);
}

#endif
