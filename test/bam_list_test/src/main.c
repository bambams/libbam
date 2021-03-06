/*
 * bam_list_test is a unit test for a subset of the libbam library/framework.
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
	bam_foo *foo = NULL;
	bam_list *list = NULL;
	bam_list *list2 = NULL;
	void *sum = NULL;
	int *y = NULL;

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
	printf("First index of %d: %d\n", x[3], bam_list_find_first_index(list, &x[3], compare_int));
	printf("Last index of %d: %d\n", x[3], bam_list_find_last_index(list, &x[3], compare_int));

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

	if((foo = bam_foo_create()) == NULL)
		goto mem_alloc_err;

	if((list = bam_list_create((void *)foo)) == NULL)
		goto mem_alloc_err_foo_list;

	if((foo = bam_foo_create()) == NULL)
		goto mem_alloc_err;

	if(!bam_list_push_back(list, (void *)foo))
		goto mem_alloc_err;

	if((foo = bam_foo_create()) == NULL)
		goto mem_alloc_err;

	if(!bam_list_push_back(list, (void *)foo))
		goto mem_alloc_err;

	// bam_list_foreach...
	bam_list_foreach(list, (bam_func_fordata)bam_foo_print);

	// bam_list_foreach_ret_list...
	if((list2 = bam_list_foreach_ret_list(list, (bam_func_fordata_ret)get_foo_id, (bam_func_destroy)bam_free)) == NULL)
		goto mem_alloc_err;
	bam_list_foreach(list2, (bam_func_fordata)print_int_ln);

	// bam_list_foreach_ret_sum...
	if((sum = bam_list_foreach_ret_sum(list, (bam_func_fordata_ret_sum)sum_int, (bam_func_destroy)bam_free)) == NULL)
		goto mem_alloc_err;
	printf("sum=%d\n", *(int *)sum);

	// bam_list_destruct...
	bam_list_destruct(&list, (bam_func_destroy)bam_foo_destroy);
	bam_list_destruct(&list2, (bam_func_destroy)bam_free);

	return EXIT_SUCCESS;

mem_alloc_err_foo_list:
	if(foo)
		bam_foo_destroy(&foo);

mem_alloc_err:
	printf("Out of memory.\n");

	if(list)
		bam_list_destruct(&list, (bam_func_destroy)bam_foo_destroy);
	if(list2)
		bam_list_destruct(&list2, (bam_func_destroy)bam_free);

	return EXIT_FAILURE;
}

bam_compare compare_int(void * const lhs, void * const rhs)
{
	int a = *(int *)lhs;
	int b = *(int *)rhs;

	if(a == b)
		return BAM_COMPARE_EQ;
	else if(a < b)
		return BAM_COMPARE_LT;
	else// if(a > b)
		return BAM_COMPARE_GT;
}

void *get_foo_id(void *data)
{
	int *id = NULL;

	assert(data);

	if((id = (int *)malloc(sizeof(int))) == NULL)
		return NULL;

	*id = ((bam_foo *)data)->id;

	return id;
}

void print_int(void * const data)
{
	printf("%d", *(const int *)data);
}

void print_int_ln(void * const data)
{
	printf("%d\n", *(const int *)data);
}

void *sum_int(void *ret, void * const data)
{
	assert(data);

	if(!ret)
	{
		if((ret = malloc(sizeof(int))) == NULL)
			return NULL;
		*(int *)ret = 0;
	}

	*(int *)ret = *(int *)ret + *(int *)data;

	return ret;
}

