#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char *path = realpath("Extra_files", path);
	printf ("%s\n", path);
	return 0;
}
