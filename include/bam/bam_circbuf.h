/*
 * bamlib is a software library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of bamlib.
 *
 * bamlib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * bamlib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bamlib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BAM_CIRCBUF_H
	#define BAM_CIRCBUF_H

	#include <assert.h>
	#include <malloc.h>
	#include <string.h>

const int BAM_CIRCBUF_ERR = -0x1;
const int BAM_CIRCBUF_OK = 0x0;
const int BAM_CIRCBUF_EMPTY = 0x1;
const int BAM_CIRCBUF_FULL = 0x2;

struct __bam_circbuf;
typedef struct __bam_circbuf bam_circbuf;

	#include <bam/bam_free.h>

struct __bam_circbuf
{
	void *buf;
	int empty;
	void *end;
	int size;
	void *stage;
	void *start;
};

bam_circbuf *bam_circbuf_create(const int);
bam_circbuf *bam_circbuf_create_staged(const int);
void bam_circbuf_destroy(bam_circbuf **);
int bam_circbuf_empty(const bam_circbuf * const);
int bam_circbuf_full(const bam_circbuf * const);
int bam_circbuf_is_wrapped(const bam_circbuf * const);
int bam_circbuf_length(const bam_circbuf * const);
int bam_circbuf_length_end(const bam_circbuf * const);
int bam_circbuf_length_free(const bam_circbuf * const);
int bam_circbuf_length_start(const bam_circbuf * const);
void bam_circbuf_moveahead_end(bam_circbuf * const, const int);
void bam_circbuf_moveahead_start(bam_circbuf * const, const int);
int bam_circbuf_read(bam_circbuf * const, void * const, const int);
int bam_circbuf_size(const bam_circbuf * const);
void *bam_circbuf_stage(const bam_circbuf * const);
int bam_circbuf_write(bam_circbuf * const, void * const, int);
int bam_circbuf_write_over(bam_circbuf * const, void * const, int);
int bam_circbuf_write_stage(bam_circbuf * const, int);
int bam_circbuf_write_stage_over(bam_circbuf * const, int);

#endif

