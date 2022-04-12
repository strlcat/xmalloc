SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
OBJS = $(SRCS:.c=.o)

ifneq (,$(DEBUG))
override CFLAGS+=-I. -fPIC -Wall -O0 -g
else
override CFLAGS+=-I. -fPIC -O3
endif

default: $(OBJS) libxmalloc.a
all: $(OBJS) libxmalloc.a

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

libxmalloc.a: $(OBJS)
	$(AR) cru $@ $^

clean:
	rm -f libxmalloc.a $(OBJS)
