CC = gcc
CFLAGS = -Iinclude -I../../include -g -Wall
LIBS = -lbam
OUT = bam_list_test

CC_COMPILE = $(CC) $(CFLAGS) -c
CC_LINK = $(CC) $(CFLAGS) $(LIBS)

.PHONY: clean default

default: obj $(OUT)

obj:
	mkdir -p obj

$(OUT): obj/bam_foo.o obj/main.o
	$(CC_LINK) -o $@ obj/bam_foo.o obj/main.o

obj/bam_foo.o: ../../src/bam_foo.c ../../include/bam/foo.h
	$(CC_COMPILE) -o $@ $<

obj/main.o: src/main.c include/main.h
	$(CC_COMPILE) -o $@ $<

clean:
	rm -fR obj $(OUT)

