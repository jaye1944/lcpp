#include <iostream>
//g++ -std=c++11 <file.cpp>

int rValue(int k)
{
	int kk = k*k;
	return kk;
}

int main (int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl; 
	auto answ = rValue(3);
	std::cout << answ << std::endl; 
    return 0;
}
