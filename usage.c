/*****************************************************************************
 * Copyright (C) Aditya.K.Jadhav  aj7744904623@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/



#include "header.h"
#include <stdio.h>
void usage () {
	printf("Usage: ./project [OPTION] PATTERN [FILE]...\nSearch for PATTERN in each FILE\n");
	printf("-r       traverse through directories nd grep\n");
	printf("-w       force PATTERN to match only whole words");
	printf("-m[NUM]  stop after NUM matches");
	printf("-i       ignore case distinctions\n");
	printf("-v       select non-matching lines\n");
	printf("-n       print line number with output lines\n");
	printf("-c       print only a count of matching lines per FILE\n");
	printf("-b       print the byte offset with output lines");
	printf("-l       print only names of FILEs containing matches \n");
	printf("-L       print only names of FILEs containing no match \n");
	printf("-h       suppress the file name prefix on output");
	printf("-H       print the file name for each match");
	printf("-in/-ni  ignore case distinctions & print line number with output lines\n");
	printf("-vn/-nv  select non-matching lines & print line number with output lines\n");
	printf("-cv/-vc print only a count of non-matching lines per FILE\n");
}
