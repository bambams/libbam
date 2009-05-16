CC = gcc
CFLAGS = -Iinclude -I../../include -g -Wall
LIBS = -lbam
OUT = bam_circbuf_test

CC_COMPILE = $(CC) $(CFLAGS) -c
CC_LINK = $(CC) $(CFLAGS) $(LIBS)

.PHONY: clean default

default: obj $(OUT)

obj:
	mkdir -p obj

$(OUT): obj/main.o
	$(CC_LINK) -o $@ obj/main.o

obj/main.o: src/main.c include/main.h
	$(CC_COMPILE) -o $@ $<

clean:
	rm -fR obj $(OUT)

