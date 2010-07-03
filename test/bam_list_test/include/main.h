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

#ifndef MAIN_H
	#define MAIN_H

	#include <bam/compare.h>
	#include <bam/foo.h>
	#include <bam/free.h>
	#include <bam/func.h>
	#include <bam/list.h>
	#include <stdio.h>
	#include <stdlib.h>

bam_compare compare_int(void * const lhs, void * const rhs);
void * get_foo_id(void *);
int main(int, char * []);
void print_int(void * const);
void print_int_ln(void * const);
void * sum_int(void *, void * const);

#endif

