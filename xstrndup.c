#include "xmalloc.h"
#include <string.h>

char *xstrndup(const char *s, size_t n)
{
	size_t sz = strnlen(s, n);
	char *res = xmalloc(sz+1);
	if (!res) return NULL;
	memcpy(res, s, sz);
	return res;
}
