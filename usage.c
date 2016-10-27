#include "header.h"
#include <stdio.h>
void usage () {
	printf("Usage: ./project [OPTION] PATTERN [FILE]...\nSearch for PATTERN in each FILE\n-i  ignore case distinctions\n-v  select non-matching lines\n-n  print line number with output lines\n-r  traverse through directories nd grep\n-c  print only a count of matching lines per FILE\n-in/-ni  ignore case distinctions & print line number with output lines\n-vn/-nv  select non-matching lines & print line number with output lines\n-cv/-vc print only a count of non-matching lines per FILE\n");
}
