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
	printf("Usage: ./project [OPTION] PATTERN [FILE]...\n Search for PATTERN in each FILE\n");
	printf("  -r       traverse through directories nd grep\n");
	printf("  -w       force PATTERN to match only whole words\n");
	printf("  -m[NUM]  stop after NUM matches\n");
	printf("  -A[NUM]  print NUM lines of trailing context\n");
	printf("  -i       ignore case distinctions\n");
	printf("  -v       select non-matching lines\n");
	printf("  -n       print line number with output lines\n");
	printf("  -c       print only a count of matching lines per FILE\n");
	printf("  -b       print the byte offset with output lines\n");
	printf("  -l       print only names of FILEs containing matches \n");
	printf("  -L       print only names of FILEs containing no match \n");
	printf("  -h       suppress the file name prefix on output\n");
	printf("  -H       print the file name for each match\n");
	printf("  -ri      traverse through directories and grep ignoring case distinctions\n");
	printf("  -rv      traverse through directories and select non matching lines\n");
	printf("  -il/-li  ignore case distinctions & print name of files contaning matches\n");
	printf("  -iL/-Li  ignore case distinctions & print name of files contaning no match\n");
	printf("  -in/-ni  ignore case distinctions & print line number with output lines\n");
	printf("  -vn/-nv  select non-matching lines & print line number with output lines\n");
	printf("  -cv/-vc  print only a count of non-matching lines per FILE\n");
	printf("Standard Input : ./project PATTERN\n");
	printf("Standard Input with options : ./project -i/-v/-iv PATTERN\n");
}
