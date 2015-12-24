#include <iostream>
#include <cstdlib>

int main (int argc, char *argv[])
{
    std::cout << argv[0] << " " << argv[1]  << std::endl;
    int k = std::atoi(argv[1]);
    int ci;
    std::cin >> ci;

    /*switch(k)
    {
	case ci:
	{
    	    std::cout<< " One " << ci  << std::endl;
	}
    }*/
    if(ci == k)
    {
		std::cout<< " One " << ci  << std::endl;
    }
    return 0;
}
