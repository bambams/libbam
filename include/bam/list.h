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

#ifndef BAM_LIST_H
	#define BAM_LIST_H

	#include <assert.h>
	#include <stdio.h>
	#include <stdlib.h>

struct __bam_list;
typedef struct __bam_list bam_list;

	#include <bam/free.h>
	#include <bam/func.h>
	#include <bam/trace.h>

struct __bam_list
{
	void *data;
	bam_list *next;
};

const bam_list *bam_list_back(const bam_list *);
bam_list *bam_list_create(void * const);
void bam_list_destroy(bam_list **);
void bam_list_destruct(bam_list **, const bam_func_destroy);
int bam_list_find_first_index(const bam_list * const, void * const, const bam_func_compare);
bam_list *bam_list_find_first_node(const bam_list * const, void * const, const bam_func_compare);
int bam_list_find_last_index(const bam_list * const, void * const, const bam_func_compare);
bam_list *bam_list_find_last_node(const bam_list * const, void * const, const bam_func_compare);
void bam_list_foreach(bam_list * const, const bam_func_fordata);
void *bam_list_foreach_ret_sum(bam_list * const, const bam_func_fordata_ret_sum, const bam_func_destroy);
bam_list *bam_list_foreach_ret_list(bam_list * const, const bam_func_fordata_ret, const bam_func_destroy);
void bam_list_fprint(FILE *, const bam_list *, const bam_func_fprint_data);
void bam_list_fprintln(FILE *, const bam_list *, const bam_func_fprint_data);
const bam_list *bam_list_node(const bam_list *, const int i);
void *bam_list_pop_back(bam_list **);
void *bam_list_pop_front(bam_list **);
void *bam_list_pop_node(bam_list **, const int);
void bam_list_print(const bam_list *, const bam_func_print_data);
void bam_list_println(const bam_list *, const bam_func_print_data);
int bam_list_push_back(bam_list *, void * const);
int bam_list_push_front(bam_list **, void * const);
int bam_list_push_node(bam_list **, const int, void * const);
void bam_list_remove_back(bam_list **, const bam_func_destroy);
void bam_list_remove_front(bam_list **, const bam_func_destroy);
void bam_list_remove_node(bam_list **, const int, const bam_func_destroy);
int bam_list_size(const bam_list *);

#endif

