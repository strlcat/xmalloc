#include "xmalloc.h"
#include <string.h>

char *xstrdup(const char *s)
{
	size_t sz = strlen(s);
	char *res = xmalloc(sz+1);
	if (!res) return NULL;
	memcpy(res, s, sz);
	return res;
}
