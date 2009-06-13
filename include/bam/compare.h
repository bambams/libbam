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

#ifndef BAM_COMPARE_H
	#define BAM_COMPARE_H

enum __bam_compare;
typedef enum __bam_compare bam_compare;

enum __bam_compare
{
	BAM_COMPARE_LT = -1,
	BAM_COMPARE_EQ = 0,
	BAM_COMPARE_GT = 1
};

#endif

