/*
 * libbam is a software library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of libbam.
 *
 * libbam is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * libbam is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libbam.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <bam/circbuf.h>

bam_circbuf * bam_circbuf_create(const int size)
{
	bam_circbuf * cbuf = (bam_circbuf *)malloc(sizeof(bam_circbuf));

	if(cbuf == NULL)
		goto error;

	memset(cbuf, 0, sizeof(bam_circbuf));

	cbuf->buf = malloc(size);

	if(cbuf->buf == NULL)
		goto error;

	//cbuf->empty = 1;
	cbuf->end = cbuf->buf;
	cbuf->size = size;
	cbuf->start = cbuf->buf;

	return cbuf;

error:
	if(cbuf != NULL)
	{
		if(cbuf->buf != NULL)
			free(cbuf->buf);

		free(cbuf);
	}

	return NULL;
}

bam_circbuf * bam_circbuf_create_staged(const int size)
{
	bam_circbuf * cbuf = bam_circbuf_create(size);

	if(cbuf == NULL)
		return NULL;

	cbuf->stage = malloc(size);

	if(cbuf->stage == NULL)
	{
		bam_circbuf_destroy(&cbuf);
		return NULL;
	}

	return cbuf;
}

void bam_circbuf_destroy(bam_circbuf ** cbuf)
{
	if(* cbuf == NULL)
		return;

	bam_free(&((*cbuf)->buf));
	bam_free(&((*cbuf)->stage));
	bam_free((void **)cbuf);
}

int bam_circbuf_empty(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->start == cbuf->end;
}

int bam_circbuf_full(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->start == cbuf->end + 1 % cbuf->size;
}

int bam_circbuf_is_staged(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->stage != NULL;
}

int bam_circbuf_is_wrapped(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->end < cbuf->start;
}

int bam_circbuf_length(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	if(bam_circbuf_is_wrapped(cbuf))
		return bam_circbuf_length_start(cbuf) + bam_circbuf_length_end(cbuf);
	else
		return cbuf->end - cbuf->start;
}

int bam_circbuf_length_end(const bam_circbuf * const cbuf)
{
	assert(cbuf);
	assert(bam_circbuf_is_wrapped(cbuf));

	return cbuf->end + 1 - cbuf->buf;
}

int bam_circbuf_length_free(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->size - bam_circbuf_length(cbuf);
}

int bam_circbuf_length_start(const bam_circbuf * const cbuf)
{
	assert(cbuf);
	assert(bam_circbuf_is_wrapped(cbuf));

	return (cbuf->buf + cbuf->size) - cbuf->start;
}

void bam_circbuf_moveahead_end(bam_circbuf * const cbuf, const int offset)
{
	assert(cbuf);
	assert(bam_circbuf_length_free(cbuf) >= offset);

	int sublen;

//sublen = (26775616 + 50) - 0 - 26775616

	if((sublen = (cbuf->buf + cbuf->size) - cbuf->end - (long)cbuf->buf) > offset)
		cbuf->end += offset;
	else
		cbuf->end = (void *)(long)(cbuf->buf + offset - sublen);
}

void bam_circbuf_moveahead_start(bam_circbuf * const cbuf, const int offset)
{
	assert(cbuf);
	assert(offset <= bam_circbuf_length(cbuf));

	int sublen;

	if((sublen = (cbuf->buf + cbuf->size) - cbuf->start - (long)cbuf->buf) > offset)
		cbuf->start += offset;
	else
		cbuf->start = (void *)(long)(cbuf->buf + offset - sublen);
}

int bam_circbuf_read(bam_circbuf * const cbuf, void * const buf, const int maxlen)
{
	assert(cbuf);
	assert(buf);

	int endlen;
	int len;
	int startlen;

	if(maxlen == 0)
		return 0;

	if(bam_circbuf_empty(cbuf))
		return BAM_CIRCBUF_ERR;

	if((len = bam_circbuf_length(cbuf)) < maxlen)
	{
		if(bam_circbuf_is_wrapped(cbuf))
		{
			memcpy(buf, cbuf->start, bam_circbuf_length_start(cbuf));
			memcpy(buf, cbuf->buf, bam_circbuf_length_end(cbuf));
		}
		else
		{
			memcpy(buf, cbuf->start, len);
		}
	}
	else
	{
		len = maxlen;

		if(bam_circbuf_is_wrapped(cbuf))
		{
			if((startlen = bam_circbuf_length_start(cbuf)) <= maxlen)
			{
				memcpy(buf, cbuf->start, startlen);

				if(startlen + (endlen = bam_circbuf_length_end(cbuf)) > maxlen)
					endlen = maxlen - startlen;

				memcpy(buf, cbuf->buf, endlen);
			}
			else
			{
				memcpy(buf, cbuf->start, startlen = maxlen);
			}
		}
		else
		{
			memcpy(buf, cbuf->start, len);
		}
	}

	bam_circbuf_moveahead_start(cbuf, len);

	return len;
}

int bam_circbuf_size(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->size;
}

void * bam_circbuf_stage(const bam_circbuf * const cbuf)
{
	assert(cbuf);

	return cbuf->stage;
}

int bam_circbuf_write(bam_circbuf * const cbuf, void * const buf, int len)
{
	assert(cbuf);
	assert(buf);

	//int endlen;
	//int startlen;

	if(len == 0)
		return 0;

	if(bam_circbuf_full(cbuf) || bam_circbuf_length_free(cbuf) < len)
		return BAM_CIRCBUF_ERR;

	return bam_circbuf_write_over(cbuf, buf, len);
}

int bam_circbuf_write_over(bam_circbuf * const cbuf, void * const buf, int len)
{
	assert(cbuf);
	assert(buf);

	int endlen;
	int startlen;

	if(len == 0)
		return 0;

	if(cbuf->size < len)
		return BAM_CIRCBUF_ERR;

	startlen = (cbuf->buf + cbuf->size) - cbuf->end - 1;

	memcpy(cbuf->end + 1, buf, startlen);

	if(len > startlen)
	{
		endlen = len - startlen;

		memcpy(cbuf->buf, buf, endlen);
	}

	bam_circbuf_moveahead_end(cbuf, len);

	return len;
}

int bam_circbuf_write_stage(bam_circbuf * const cbuf, int len)
{
	assert(cbuf);

	return bam_circbuf_write(cbuf, cbuf->stage, len);
}

int bam_circbuf_write_stage_over(bam_circbuf * const cbuf, int len)
{
	assert(cbuf);

	return bam_circbuf_write_over(cbuf, cbuf->stage, len);
}

