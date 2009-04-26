CC = gcc
CFLAGS = -Iinclude -g -Wall
LD = ld
LIBS = -l./lib/bam
NAME = libbam.so
OUT = lib/$(NAME)

CC_COMPILE = $(CC) $(CFLAGS) -c
CC_COMPILE_LIB = $(CC_COMPILE) -fPIC
CC_LINK = $(CC) $(CFLAGS) $(LIBS)
CC_LINK_LIB = $(CC) -shared -Wl,-soname,$(NAME)

.PHONY: clean default

default: lib obj $(OUT)

lib:
	mkdir -p lib

obj:
	mkdir -p obj

$(OUT): obj/bam_free.o obj/bam_list.o
	$(CC_LINK_LIB) -o $@ obj/bam_free.o obj/bam_list.o

obj/bam_free.o: src/bam_free.c include/bam_free.h
	$(CC_COMPILE_LIB) -o $@ $<

obj/bam_list.o: src/bam_list.c include/bam_list.h
	$(CC_COMPILE_LIB) -o $@ $<

clean:
	rm -fR lib obj $(OUT)

