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
int main(int argc, char *argv[]) {
	int f[6], size[6], i = 0;
	char *a;	
	char s[2] = "\n";
   	char *token;
	if(argc < 3) {
		errno = EINVAL;
		perror("Bad arguments");
		return errno; 
	}
	if(strcmp(argv[1],"-r") == 0) {
		DIR *dir;
   		dir=opendir(argv[3]);
  		struct dirent *dent;
  		if(dir!=NULL) {
       			while((dent = readdir(dir))) {
				if(f[i] = open(dent->d_name, O_RDONLY)) {
					size[i] = lseek(f[i], 0, SEEK_END);
					a = (char*)malloc(size[i]*sizeof(char));
					lseek(f[i], 0, 0);	
					read(f[i], a, size[i]*sizeof(char));
   					token = mystrtok(a, s, i);
 					while( token != NULL ) { 
						if(mystrstr( token, argv[2]) != NULL) {
							printf("%s%s/%s%s:%s%s\n", KMAG, argv[3], dent->d_name, KBLU, KNRM, token);
						}
						token = mystrtok(NULL, s, i);
  	 				}
					close(f[i]);
					free (a);
				}
				else { 
					DIR *dir_1;
					struct dirent *dent_1;
					dir_1 = opendir(dent->d_name);
					while((dent=readdir(dir_1))) {
						if(f[i] = open(dent->d_name, O_RDONLY)) {
							size[i] = lseek(f[i], 0, SEEK_END);
							a = (char*)malloc(size[i]*sizeof(char));
							lseek(f[i], 0, 0);	
							read(f[i], a, size[i]*sizeof(char));
   							token = mystrtok(a, s, i);
 							while( token != NULL ) { 
								if(mystrstr( token, argv[2]) != NULL) {
									printf("%s%s/%s%s:%s%s\n", KMAG, argv[3], dent->d_name, KBLU, KNRM, token);
								}
							token = mystrtok(NULL, s, i);
  	 						}
						close(f[i]);
						free (a);
						}
					i++;
    					}
    				}
			i++;
    			}
		}
           	closedir(dir);
		return 0;
	}
	else if(strcmp(argv[1],"-v") == 0 || strcmp(argv[1],"-vn") == 0) {
		for(i = 1; i <= 5; i++) {
			f[i] = open(argv[i+2], O_RDONLY);
			size[i] = lseek(f[i], 0, SEEK_END);
		}
		for(i = 1; i <= 5; i++) {
			int line_num = 0;
			a = (char*)malloc(size[i]*sizeof(char));
			lseek(f[i], 0, 0);	
			read(f[i], a, size[i]*sizeof(char));
   			token = mystrtok(a, s, i);
 			while( token != NULL ) { 
				line_num++;
				if(mystrstr( token, argv[2]) == NULL) {
					if(strcmp(argv[1],"-vn") == 0) {
						if(argc < 5)
							printf("%s%d%s:%s%s\n", KGRN, line_num, KBLU, KNRM, token);
						else
							printf("%s%s %s: %s%d %s: %s%s\n", KMAG, argv[i+2], KBLU, KGRN, line_num, KBLU, KNRM, token);
					}
					else {
						if(argc < 5)
							printf("%s\n", token);
						else
							printf("%s%s %s: %s%s\n", KMAG, argv[i+2], KBLU, KNRM, token);
					}
				}
				token = mystrtok(NULL, s, i);
  	 		}
			close(f[i]);
			free (a);
		}
		return 0;
	}
	else if(strcmp(argv[1],"-i") == 0 || strcmp(argv[1],"-in") == 0) {
		for(i = 1; i <= 5; i++) {
			f[i] = open(argv[i+2], O_RDONLY);
			size[i] = lseek(f[i], 0, SEEK_END);
		}
		for(i = 1; i <= 5; i++) {
			int line_num = 0;
			a = (char*)malloc(size[i]*sizeof(char));
			lseek(f[i], 0, 0);	
			read(f[i], a, size[i]*sizeof(char));
   			token = mystrtok(a, s, i);
 			while( token != NULL ) { 
				line_num++;
				if(mystrstrcase( token, argv[2]) != NULL) {
					if(strcmp(argv[1],"-in") == 0) {
						if(argc < 5)
							printf("%s%d%s:%s%s\n", KGRN, line_num, KBLU, KNRM, token);
						else
							printf("%s%s %s: %s%d %s: %s%s\n", KMAG, argv[i+2], KBLU, KGRN, line_num, KBLU, KNRM, token);
					}
					else {
						if(argc < 5)
							printf("%s\n", token);
						else
							printf("%s%s %s: %s%s\n", KMAG, argv[i+2], KBLU, KNRM, token);
					}
				}
				token = mystrtok(NULL, s, i);
  	 		}
			close(f[i]);
			free (a);
		}
		return 0;
	}
	else if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-cv") == 0) {
		int count[5];
		for(i = 0; i < 5; i++)
			count[i] = 0;
		for(i = 1; i <= 5; i++) {
			f[i] = open(argv[i+2], O_RDONLY);
			size[i] = lseek(f[i], 0, SEEK_END);
		}
		for(i = 1; i <= 5; i++) {
			a = (char*)malloc(size[i]*sizeof(char));
			lseek(f[i], 0, 0);	
			read(f[i], a, size[i]*sizeof(char));
   			token = mystrtok(a, s, i);
 			while( token != NULL ) { 
				if(strcmp(argv[1], "-c") == 0) {
					if(mystrstrcase( token, argv[2]) != NULL) {
						count[i-1]++;
					}
				}
				else {
					if(mystrstrcase( token, argv[2]) == NULL) {
						count[i-1]++;
					}
				}
				token = mystrtok(NULL, s, i);
  	 		}
			if(f[i] != -1) {
				if(argc < 5)
					printf("%d\n", count[i-1]);
				else
					printf("%s%s %s: %s%d\n", KMAG, argv[i+2], KBLU, KNRM, count[i-1]);
			}
			close(f[i]);
			free (a);
		}
		return 0;
	}
	else if(strcmp(argv[1], "-n") == 0) {
		for(i = 1; i <= 5; i++) {
			f[i] = open(argv[i+2], O_RDONLY);
			size[i] = lseek(f[i], 0, SEEK_END);
		}
		for(i = 1; i <= 5; i++) {
			int line_num = 0;
			a = (char*)malloc(size[i]*sizeof(char));
			lseek(f[i], 0, 0);	
			read(f[i], a, size[i]*sizeof(char));
   			token = mystrtok(a, s, i);
 			while( token != NULL ) { 
				line_num++;
				if(mystrstrcase( token, argv[2]) != NULL) {
					if(argc < 5)
						printf("%s%d%s:%s%s\n", KGRN, line_num, KBLU, KNRM, token);
					else
						printf("%s%s %s: %s%d %s: %s%s\n", KMAG, argv[i+2], KBLU, KGRN, line_num, KBLU, KNRM, token);
				}
				token = mystrtok(NULL, s, i);
  	 		}
			close(f[i]);
			free (a);
		}
		return 0;
	}
	else {
		for(i = 1; i <= 5; i++) {
			f[i] = open(argv[i+1], O_RDONLY);
			size[i] = lseek(f[i], 0, SEEK_END);
		}
		for(i = 1; i <= 5; i++) {
			a = (char*)malloc(size[i]*sizeof(char));
			lseek(f[i], 0, 0);	
			read(f[i], a, size[i]*sizeof(char));
   			token = mystrtok(a, s, i);
 			while( token != NULL ) { 
				if(mystrstr( token, argv[1]) != NULL) {
					if(argc < 4)
						printf("%s\n", token);
					else
						printf("%s%s : %s%s\n", KMAG, argv[i+1], KNRM, token);
				}
				token = mystrtok(NULL, s, i);
  	 		}
			close(f[i]);
			free (a);
		}
		return 0;
	}
}