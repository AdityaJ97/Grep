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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include "header.h"
#include <string.h>
void recursive(char *dname, char *search, int FLAG) {
	int f[6], size[6], i = 0;
	char *a;	
	char s[2] = "\n";
   	char *token;
		DIR *dir;
   		dir=opendir(dname);
  		struct dirent *dent;
  		if(dir!=NULL) {
       			while((dent = readdir(dir))) {
				if(dent->d_type == DT_DIR) {
					if(strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0); 
					else  {
                                        	strcat(dname, "/");
                                                strcat(dname, dent->d_name);
						if(FLAG == 0)
                                                	recursive(dname, search, 0);
						else if(FLAG == 1)
                                                	recursive(dname, search, 1);
						else if(FLAG == 2)
                                                	recursive(dname, search, 2);
                                        }
				}
				else if(f[i] = open(dent->d_name, O_RDONLY)) { 
					size[i] = lseek(f[i], 0, SEEK_END);
					a = (char*)malloc(size[i]*sizeof(char));
					lseek(f[i], 0, 0);	
					read(f[i], a, size[i]*sizeof(char));
   					token = strtok(a, s);
 					while( token != NULL ) { 
						if((mystrstr( token, search) != NULL && FLAG == 0) || (mystrstrcase(token, search) != NULL && FLAG == 1) || (mystrstr(token, search) == NULL && FLAG == 2)) {
							printf("%s%s/%s%s:%s%s\n", KMAG, dname, dent->d_name, KBLU, KNRM, token);
						}
						token = strtok(NULL, s);
   					}
				close(f[i]);
				free (a);
				}
			i++;
			}
           		closedir(dir);
		}	
}
