/*
 * bam_circbuf_test is a unit test for a subset of the bamlib library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of bam_circbuf_test.
 *
 * bam_circbuf_test is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * bam_circbuf_test is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bam_circbuf_test.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <main.h>

int main(int argc, char *argv[])
{
	bam_circbuf *cbuf = bam_circbuf_create(1024);
	bam_circbuf *x = cbuf;

	printf("cbuf=%ld\n", (long)cbuf);
	printf("cbuf->buf=%ld\n", (long)cbuf->buf);
	printf("cbuf->stage=%ld\n", (long)cbuf->stage);

	bam_circbuf_destroy(&cbuf);

	printf("cbuf=%ld\n", (long)cbuf);
	printf("x=%ld\n", (long)x);
	printf("x->buf=%ld\n", (long)x->buf);
	printf("x->stage=%ld\n", (long)x->stage);

	return EXIT_SUCCESS;
}

