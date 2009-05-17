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

#ifdef BUF_LEN
	#error BUF_LEN already defined!
#endif

#ifdef BUF_SIZE
	#error BUF_SIZE already defined!
#endif

#ifdef ERRMSG_LEN
	#error ERRMSG_LEN already defined!
#endif

#ifdef ERRMSG_SIZE
	#error ERRMSG_SIZE already defined!
#endif

#define BUF_LEN 1025
#define BUF_SIZE 1024
#define ERRMSG_LEN 255
#define ERRMSG_SIZE 256

int main(int argc, char *argv[])
{
	const char NUL = '\0';
	const int CBUF_SIZE = 50;
	const char text[] = "This is just a sample string to write (and "
	                    "therefore read) into/from the circular buffer.";
	int status = EXIT_SUCCESS;
	char errmsg[ERRMSG_SIZE];
	char buf[BUF_SIZE];
	bam_circbuf *cbuf = bam_circbuf_create(CBUF_SIZE);

	buf[BUF_LEN] = NUL;
	memset(errmsg, 0, ERRMSG_SIZE);

	bam_print_exp("%s", text);
	bam_print_exp("%lu", strlen(text));
	printf("\n");

	print_circbuf(cbuf);

	if(!cbuf)
		goto failed_to_create_cbuf;

	bam_circbuf_write(cbuf, (void *)text, 40);

	print_circbuf(cbuf);

	bam_circbuf_read(cbuf, (void *)buf, 30);

	bam_print_exp("%s", buf);
	bam_print_exp("%lu", strlen(buf));
	printf("\n");

	print_circbuf(cbuf);

	bam_circbuf_write(cbuf, (void *)text + 40, 40);

	print_circbuf(cbuf);

	bam_circbuf_destroy(&cbuf);

	print_circbuf(cbuf);

	goto cleanup;

failed_to_create_cbuf:
	snprintf(errmsg, ERRMSG_SIZE, "Failed to create circular buffer.");
	goto error;

error:
	status = EXIT_FAILURE;
	errmsg[ERRMSG_LEN] = NUL;

	if(strlen(errmsg) > 0)
		fprintf(stderr, "%s\n", errmsg);
	else
		perror("An unknown error occurred.\n");

cleanup:
	if(cbuf)
		bam_circbuf_destroy(&cbuf);

	return status;
}

void print_circbuf(const bam_circbuf * const cbuf)
{
	int wrapped;

	bam_print_exp("%ld", (long)cbuf);

	if(cbuf)
	{
		bam_print_exp("%ld", (long)cbuf->buf);
		bam_print_exp("%ld", (long)cbuf->size);
		bam_print_exp("%ld", (long)cbuf->stage);
		bam_print_exp("%ld", (long)cbuf->start);
		bam_print_exp("%ld", (long)(cbuf->start - cbuf->buf));
		bam_print_exp("%ld", (long)cbuf->end);
		bam_print_exp("%ld", (long)(cbuf->end - cbuf->buf));
		printf("\n");

		bam_print_exp("%d", bam_circbuf_empty(cbuf));
		bam_print_exp("%d", bam_circbuf_full(cbuf));
		bam_print_exp("%d", bam_circbuf_is_staged(cbuf));
		bam_print_exp("%d", bam_circbuf_is_wrapped(cbuf));

		if((wrapped = bam_circbuf_is_wrapped(cbuf)))
			bam_print_exp("%d", bam_circbuf_length_end(cbuf));

		bam_print_exp("%d", bam_circbuf_length(cbuf));
		bam_print_exp("%d", bam_circbuf_length_free(cbuf));

		if(wrapped)
			bam_print_exp("%d", bam_circbuf_length_start(cbuf));

		bam_print_exp("%d", bam_circbuf_size(cbuf));
		bam_print_exp("%ld", (long)bam_circbuf_stage(cbuf));
		printf("\n");
	}
	else
	{
		printf("\n");
	}
}

