CC = gcc
CFLAGS = -Iinclude -g -Wall
INST_INCDIR = /usr/include
INST_LIBDIR = /usr/local/lib
LD = ld
LIBS = -l./lib/bam
NAME = libbam.so
OUT = lib/$(NAME)

CC_COMPILE = $(CC) $(CFLAGS) -c
CC_COMPILE_LIB = $(CC_COMPILE) -fPIC
CC_LINK = $(CC) $(CFLAGS) $(LIBS)
CC_LINK_LIB = $(CC) -shared -Wl,-soname,$(NAME)

.PHONY: clean default install instdev veryclean

default: lib obj $(OUT)

lib:
	mkdir -p lib

obj:
	mkdir -p obj

$(OUT): obj/bam_circbuf.o obj/bam_free.o obj/bam_list.o
	$(CC_LINK_LIB) $? -o $@

obj/bam_circbuf.o: src/bam_circbuf.c include/bam/circbuf.h
	$(CC_COMPILE_LIB) -o $@ $<

obj/bam_free.o: src/bam_free.c include/bam/free.h
	$(CC_COMPILE_LIB) -o $@ $<

obj/bam_list.o: src/bam_list.c include/bam/list.h
	$(CC_COMPILE_LIB) -o $@ $<

clean:
	rm -fR lib obj $(OUT)

install:
	cp $(OUT) $(INST_LIBDIR)
	ldconfig

instdev:
	cp -R include/bam $(INST_INCDIR)

veryclean: clean
	rm -fR $(INST_LIBDIR)/$(OUT) $(INST_INCDIR)/bam

