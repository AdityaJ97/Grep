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



#include<stdlib.h>
#include "header.h"
#include <stdio.h>
char *mystrtok_multi(char *a, char *de, int x) {
	static char *c;
	static int j[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	static int i[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int p = 0;
	if(a != NULL) {
		c = a;
		while(c[i[x]] != '\0') {
			if(c[i[x]] == de[0])
				c[i[x]] = '\0';
			i[x]++;
		}
		while(c[j[x]] == '\0')
			j[x]++;
		return &c[j[x]];
	}
	else {
		while(j[x] < (i[x]-1))  {
			if(c[j[x]] == '\0' && c[j[x]]+1 != '\0') { 
				j[x]++; 
				return &c[j[x]];
			}
			j[x]++;
		}
		c = NULL;
		return NULL;
	}
}
