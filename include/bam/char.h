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

#ifndef BAM_CHAR_H
    #define BAM_CHAR_H

struct bam_char__;
typedef struct bam_char__ bam_char;

/*
 * Upon proposing a UTF-8 string type, it occurred to me that a UTF-8
 * character type might also come in handy. Not necessarily to build the
 * string from, but for manipluation of individual characters. Obviously,
 * a UTF-8 string can't return all characters as a single-byte char.
 */
struct bam_char__
{
    char[4] chr;
};

/*
 * Unknown at this time what manipulation functions might be useful.
 */

#endif

