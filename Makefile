.PHONY: all install clean

prefix ?= /usr/local
bindir ?= $(prefix)/bin

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm hello

install: hello
	install -d $(DESTDIR)$(bindir)
	install -m 0755 hello $(DESTDIR)$(bindir)
