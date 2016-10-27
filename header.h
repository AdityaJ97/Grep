#define KMAG  "\x1B[35m"
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"

void standard_options(char *, char *);
void standard_input(char *);
void usage();
void recursive(char *, char *);
char *mystrstr (char *, char *);
char *mystrstrcase (char *, char *);
char *mystrtok_multi (char *, char *, int);
