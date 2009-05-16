/*
 * bam_free_test is a unit test for a subset of the bamlib library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of bam_free_test.
 *
 * bam_free_test is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * bam_free_test is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bam_free_test.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <main.h>

int main(int argc, char *argv[])
{
	int *x = NULL;

	x = (int *)malloc(sizeof(int));

	if(x == NULL)
	{
		perror("Failed to allocate an int... :(\n");
		return EXIT_FAILURE;
	}

	printf("x=%ld\n", (long)x);

	bam_free((void *)&x);

	printf("x=%ld\n", (long)x);

	return EXIT_SUCCESS;
}

