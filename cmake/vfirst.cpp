#include <iostream>
#include <string.h>
#include "TutorialConfig.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
    {
		if(strcmp(argv[1],"-V") == 0)
		{
		std::cout << "Version " << argv[0] << " " <<
		Tutorial_VERSION_MAJOR <<"." << 
		Tutorial_VERSION_MINOR << std::endl;
		}
    return 1;
    }
	
	std::cout << "Hello Wordld" << std::endl;
	
	return 0;
}
