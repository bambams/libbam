/*
 * bam_list_test is a unit test for a subset of the bamlib library/framework.
 * Copyright (C) 2009 Brandon McCaig
 *
 * This file is part of bam_list_test.
 *
 * bam_list_test is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * bam_list_test is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bam_list_test.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <main.h>

int main(int argc, char *argv[])
{
	int x[] = {2, 6, 7, 9, 12};
	bam_list *list;
	int *y;

	if((list = bam_list_create(&x[0])) == NULL)
		goto mem_alloc_err;

	printf("list=");
	bam_list_println(list, print_int);
	printf("size=%d\n", bam_list_size(list));

	if(!(bam_list_push_back(list, &x[3])
		&& bam_list_push_back(list, &x[2])
		&& bam_list_push_front(&list, &x[4])
		&& bam_list_push_node(&list, 1, &x[3])
		&& bam_list_push_front(&list, &x[1])
		&& bam_list_push_node(&list, 0, &x[4])
		&& bam_list_push_node(&list, bam_list_size(list), &x[3])))
	{
		goto mem_alloc_err;
	}

	printf("list=");
	bam_list_println(list, print_int);
	printf("size=%d\n", bam_list_size(list));

	if((y = (int *)bam_list_pop_back(&list)) != NULL)
		printf("back=%d\n", *y);

	printf("list=");
	bam_list_println(list, print_int);
	printf("size=%d\n", bam_list_size(list));

	if((y = (int *)bam_list_pop_node(&list, 2)) != NULL)
		printf("node2=%d\n", *y);

	printf("list=");
	bam_list_println(list, print_int);
	printf("size=%d\n", bam_list_size(list));

	if((y = (int *)bam_list_pop_front(&list)) != NULL)
		printf("front=%d\n", *y);

	printf("list=");
	bam_list_println(list, print_int);
	printf("size=%d\n", bam_list_size(list));

	bam_list_destroy(&list);

	if((list = bam_list_create(&x[0])) == NULL)
		goto mem_alloc_err;

	if((y = bam_list_pop_node(&list, 0)) != NULL)
		printf("last node=%d\n", *y);

	printf("list*=%ld\n", (long)list);
	printf("size=%d\n", bam_list_size(list));

	bam_list_destroy(&list);

	if((list = bam_list_create(&x[0])) == NULL)
		goto mem_alloc_err;

	if((y = bam_list_pop_back(&list)) != NULL)
		printf("last back=%d\n", *y);

	printf("list*=%ld\n", (long)list);
	printf("size=%d\n", bam_list_size(list));

	bam_list_destroy(&list);

	if((list = bam_list_create(&x[0])) == NULL)
		goto mem_alloc_err;

	if((y = bam_list_pop_front(&list)) != NULL)
		printf("last front=%d\n", *y);

	printf("list*=%ld\n", (long)list);
	printf("size=%d\n", bam_list_size(list));

	bam_list_destroy(&list);

	return EXIT_SUCCESS;

mem_alloc_err:
	printf("Out of memory.\n");
	return EXIT_FAILURE;
}

void print_int(void * const data)
{
	printf("%d", *(const int *)data);
}

