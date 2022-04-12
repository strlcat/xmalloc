/*
 * xmalloc -- a safe and precise memory allocation wrapper.
 *
 * xmalloc is copyrighted:
 * Copyright (C) 2018 Andrey Rys. All rights reserved.
 *
 * xmalloc is licensed to you under the terms of std. MIT/X11 license:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _XMALLOC_H
#define _XMALLOC_H

#include <stddef.h>

typedef enum {
	OOM_MALLOC = 1, OOM_REALLOC
} xmalloc_oom_caller;

/* Useful macros */
#define DYN_ARRAY_SZ(x) (xszalloc(x)/sizeof(*x))

/* External functions which library user _must_ provide */
extern void xmalloc_ub(const void *); /* Undefined Behavior handler (called with offending pointer) */
extern int xmalloc_oom(int, xmalloc_oom_caller); /* Out Of Memory handler */
extern void xmalloc_error(xmalloc_oom_caller); /* Error handler */

/* Main functions */
extern void *xmalloc(size_t);
extern void *xcalloc(size_t, size_t);
extern void *xrealloc(void *, size_t);
extern void xfree(void *);
#define pfree(p) do { xfree(p); p = NULL; } while (0)
extern size_t xszalloc(const void *);

/* String functions */
char *xstrdup(const char *s);
char *xstrndup(const char *s, size_t n);

#endif
