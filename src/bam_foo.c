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

#include <bam/foo.h>

int bam_foo_last_id = -1;

bam_foo * bam_foo_create(void)
{
	bam_foo * foo = (bam_foo *)malloc(sizeof(bam_foo));

	if(foo == NULL)
		return NULL;

	foo->id = ++bam_foo_last_id;

	return foo;
}

void bam_foo_destroy(bam_foo ** foo)
{
	assert(foo);

	int id;

	if(*foo != NULL)
	{
		id = (*foo)->id;
		free(*foo);
		*foo = NULL;

		printf("Destroyed foo %d.\n", id);
	}
}

void bam_foo_print(const bam_foo * const foo)
{
	assert(foo);

	printf("{id: %d}\n", foo->id);
}

