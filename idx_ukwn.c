#ifdef IDX_UNKW


int idxseek(FILE *stream, idx_t offset, int origin)
{
	return fseek(stream, (long int)offset, origin);
}

idx_t idxtell(FILE *stream)
{
	return (idx_t)ftell(stream);
}


#endif
