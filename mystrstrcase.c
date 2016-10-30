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
char *mystrstrcase (char *a, char *b) {
	char *p = a, *q = b;
	while(*p != '\0' && *q != '\0') {
		if((*p == *q) || ((*p - 'a' + 'A') == *q) || ((*p + 'a' - 'A') == *q)) {
			p++;
			q++;
		}
		else { 
			if(q == b)
				p++;
			else  {
				p = p - (q - b) + 1;
				q = b;
			}
		}
	}
	if(*q == '\0')
		return a;
	else 
		return NULL;
}
