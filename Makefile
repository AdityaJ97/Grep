run : grep.o mystrstr.o mystrtok.o mystrstrcase.o dir.o 
	gcc -o project grep.o mystrstr.o mystrtok.o mystrstrcase.o dir.o
grep : grep.c header.h
	gcc -c grep.c
tok : mystrtok.c header.h
	gcc -c mystrtok.c
str : mystrstr.c mystrstrcase.c header.h
	gcc -c mystrstr.c mystrstrcase.c
dir : dir.c header.h
	gcc -c dir.c
make :
