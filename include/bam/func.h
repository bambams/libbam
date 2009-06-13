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

#ifndef BAM_FUNC_H
	#define BAM_FUNC_H

	#include <bam/compare.h>

typedef bam_compare (*bam_func_compare)(void * const, void * const);
typedef void (*bam_func_destroy)(void **);
//typedef void (*bam_func_destruct)(void **, const bam_destruct);
typedef void (*bam_func_fordata)(void *);
typedef void *(*bam_func_fordata_ret)(void *);
typedef void *(*bam_func_fordata_ret_sum)(void *, void *);
typedef void (*bam_func_fprint_data)(FILE *, void * const);
typedef void (*bam_func_print_data)(void * const);

#endif

