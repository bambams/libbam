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

typedef void (*bam_destroy_func)(void **);
//typedef void (*bam_destruct_func)(void **, const bam_destruct_func);
typedef void (*bam_fordata_func)(void *);
typedef void *(*bam_fordata_ret_func)(void *);
typedef void *(*bam_fordata_ret_sum_func)(void *, void *);
typedef void (*bam_list_fprint_data_func)(FILE *, void * const);
typedef void (*bam_list_print_data_func)(void * const);

	#include <bam/free.h>
	#include <bam/trace.h>

struct __bam_list
{
	void *data;
	bam_list *next;
};

const bam_list *bam_list_back(const bam_list *);
bam_list *bam_list_create(void * const);
void bam_list_destroy(bam_list **);
void bam_list_destruct(bam_list **, const bam_destroy_func);
void bam_list_foreach(bam_list * const, const bam_fordata_func);
void *bam_list_foreach_ret_sum(bam_list * const, const bam_fordata_ret_sum_func, const bam_destroy_func);
bam_list *bam_list_foreach_ret_list(bam_list * const, const bam_fordata_ret_func, const bam_destroy_func);
void bam_list_fprint(FILE *, const bam_list *, const bam_list_fprint_data_func);
void bam_list_fprintln(FILE *, const bam_list *, const bam_list_fprint_data_func);
const bam_list *bam_list_node(const bam_list *, const int i);
void *bam_list_pop_back(bam_list **);
void *bam_list_pop_front(bam_list **);
void *bam_list_pop_node(bam_list **, const int);
void bam_list_print(const bam_list *, const bam_list_print_data_func);
void bam_list_println(const bam_list *, const bam_list_print_data_func);
int bam_list_push_back(bam_list *, void * const);
int bam_list_push_front(bam_list **, void * const);
int bam_list_push_node(bam_list **, const int, void * const);
void bam_list_remove_back(bam_list **, const bam_destroy_func);
void bam_list_remove_front(bam_list **, const bam_destroy_func);
void bam_list_remove_node(bam_list **, const int, const bam_destroy_func);
int bam_list_size(const bam_list *);

#endif

