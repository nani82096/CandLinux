#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s\n",crypt("bat","$6$Zsp9CSwM$"));
    exit(0);
}
