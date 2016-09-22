#include<stdio.h>
#include<dirent.h>     
int main(int argc, char *argv[])
 {
   DIR *dir;
   dir=opendir(argv[1]);

  struct dirent *dent;
  if(dir!=NULL)
   {

       while((dent=readdir(dir)))
         {
            FILE *ptr;
            printf("%s", dent->d_name);

              if(ptr=fopen(dent->d_name,"r"))
                {
                     printf("\tFILE\n");
                     fclose(ptr);
                }
              else
                    printf("\t DIRECTORY\n");
        }
           closedir(dir);
    }
    else
            printf("ERROR OPENIN DIRECTORY");

}
