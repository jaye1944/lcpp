#include <iostream>
#include <string.h>
#include <stdio.h>

#include "TestConfig.h"

int main (int argc, char *argv[])
{
	if (argc < 2)
    {
    	fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    	fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
	printf("testing with gcov");
	return 0;
}
