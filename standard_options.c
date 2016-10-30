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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void standard_options(char *option, char *b) {
        char c;
        char *a;
        int i = 0;
        a = (char*)malloc(128*sizeof(char));
        while(scanf("%c", &c) != -1) {
                if(c == '\n') {
                        a[i] = '\0';
			if(strcmp(option, "-i") == 0) {
                        	if(mystrstrcase(a, b) != NULL)
                                	printf("%s\n", a);
			}
			else if(strcmp(option, "-v") == 0) {
                        	if(mystrstr(a, b) == NULL)
                                	printf("%s\n", a);
			}
			else if(strcmp(option, "-iv") == 0 || strcmp(option, "-vi") == 0)
                        	if(mystrstrcase(a, b) == NULL)
                                	printf("%s\n", a);
                        free(a);
                        a = (char*)malloc(128*sizeof(char));
                        i = 0;
                }
                else
                        a[i++] = c;
        }
}

