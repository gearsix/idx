#ifdef IDX_UNKW || IDX_UNKWC99


int idxseek(FILE *stream, idx_t offset, int origin)
{
	return fseek(stream, (long int)offset, origin);
}

idx_t idxtell(FILE *stream)
{
	return (idx_t)ftell(stream);
}

idx_t strtoidx(const char *s, char **end, int base)
{
#ifdef IDX_UKWNC99
	return (idx_t)strtoull(s, end, base);
#else
	return (idx_t)strtoul(s, end, base);
#endif
}

int idxtostr(idx_t i, char **buf)
{
#ifdef IDX_UKWNC99
	return sprintf(buf, "%llu", i);
#else
	return sprintf(buf, "%lu", i);
#endif
}

#endif
