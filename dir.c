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

void recursive(char *dname, char *search) {
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
                                                        recursive(dname, search);
                                                }
					}
					if(f[i] = open(dent->d_name, O_RDONLY)) { 
					size[i] = lseek(f[i], 0, SEEK_END);
					a = (char*)malloc(size[i]*sizeof(char));
					lseek(f[i], 0, 0);	
					read(f[i], a, size[i]*sizeof(char));
   					token = mystrtok(a, s, i);
 					while( token != NULL ) { 
						if(mystrstr( token, search) != NULL) {
							printf("%s%s/%s%s:%s%s\n", KMAG, dname, dent->d_name, KBLU, KNRM, token);
						}
						token = mystrtok(NULL, s, i);
  	 				}
				close(f[i]);
				free (a);
				}
			i++;
			}
           		closedir(dir);
	}
}
