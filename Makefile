
CC=gcc
CFLAGS=-Wall -MMD

SOURCES=info.c pmod.c finfo.c pinfo.c
EXECUTABLES=$(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES) *.d *.o



