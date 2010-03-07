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

#ifndef BAM_STRING_H
    #define BAM_STRING_H

    #include <stdio.h>
    #include <stdlib.h>

struct bam_string__;
typedef struct bam_string__ bam_string;

    #include <bam/compare.h>
    #include <bam/free.h>

/*
 * Intended to be a rich UTF-8 string type complete with modern
 * functionality.
 */
struct bam_string__
{
    int capacity;
    int size;
    char * cstr;
};

char * bam_string_as_cstr(
        const bam_string * const);
bam_string * bam_string_concat(
        bam_string * const,
        const bam_string * const);
bam_string * bam_string_concat_cstr(
        bam_string * const,
        const char * const);
bam_string * bam_string_copy(
        const bam_string * const);
int bam_string_compare(
        const bam_string * const,
        const bam_string * const);
int bam_string_compare_cstr(
        const bam_string * const,
        const char * const);
int bam_string_contains(
        const bam_string * const,
        const bam_string * const);
int bam_string_contains_cstr(
        const bam_string * const,
        const char * const);
int bam_string_ends_with(
        const bam_string * const,
        const bam_string * const);
int bam_string_ends_with_cstr(
        const bam_string * const,
        const char * const);
int bam_string_equals(
        const bam_string * const,
        const bam_string * const);
int bam_string_equals_cstr(
        const bam_string * const,
        const char * const);
bam_string * bam_string_from_cstr(
        bam_string * const,
        const char * const);
char bam_string_getchar(
        const bam_string * const,
        const int);
int bam_string_index_of(
        const bam_string * const,
        const bam_string * const);
int bam_string_index_of_cstr(
        const bam_string * const,
        const char * const);
int bam_string_is_empty(
        const bam_string * const);
bam_string * bam_string_join(
        const bam_string * const * const,
        const bam_string * const);
bam_string * bam_string_join_cstr(
        const bam_string * const * const,
        const char * const);
int bam_string_last_index_of(
        const bam_string * const,
        const bam_string * const);
int bam_string_last_index_of_cstr(
        const bam_string * const,
        const char * const);
int bam_string_length(
        const bam_string * const);
bam_string * bam_string_ltrim(
        bam_string * const);
int bam_string_is_null_or_empty(
        const bam_string * const);
int bam_string_is_null_or_whitespace(
        const bam_string * const);
bam_string * bam_string_padleft(
        bam_string * const,
        const int,
        const char);
bam_string * bam_string_padright(
        bam_string * const,
        const int,
        const char);
bam_string * bam_string_remove(
        bam_string * const,
        const int,
        const int);
bam_string * bam_string_replace(
        bam_string * const,
        const bam_string * const);
bam_string * bam_string_replace_cstr(
        bam_string * const,
        const char * const);
bam_string * bam_string_rtrim(
        bam_string * const);
int bam_string_printf(
        const bam_string * const,
        ...);
bam_string ** bam_string_split(
        const bam_string * const,
        const bam_string * const,
        int * const);
bam_string ** bam_string_split_cstr(
        const bam_string * const,
        const char * const,
        int * const);
bam_string * bam_string_setchar(
        bam_string * const,
        const int,
        const char);
int bam_string_sprintf(
        bam_string * const,
        const bam_string * const,
        ...);
int bam_string_sprintf_cstr(
        bam_string * const,
        const bam_string * const,
        ...);
int bam_string_starts_with(
        const bam_string * const,
        const bam_string * const);
int bam_string_starts_with_cstr(
        const bam_string * const,
        const char * const);
bam_string * bam_string_substr(
        const bam_string * const,
        const int,
        const int);
bam_string * bam_string_tolower(
        bam_string * const);
bam_string * bam_string_toupper(
        bam_string * const);
bam_string * bam_string_trim(
        bam_string * const);
int bam_string_vprintf(
        const bam_string * const,
        va_list);
int bam_string_vsprintf(
        bam_string * const,
        const bam_string * const,
        va_list);
int bam_string_vsprintf_cstr(
        bam_string * const,
        const char * const,
        va_list);

#endif

