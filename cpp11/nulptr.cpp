#include <iostream>
//#include <stdio.h>
//g++ -std=c++11 <file.cpp>

int rValue(int k)
{
	int kk = k*k;
	return kk;
}

class Obj
{
public:
	Obj(){};
	~Obj(){};
};

int main (int argc, char *argv[])
{
     
	auto answ = rValue(3);
	std::cout << answ << std::endl; 
    
    Obj *bb = nullptr;//std::nullptr_t;
    Obj *aa = NULL;
    std::cout << bb << std::endl;
    std::cout << aa << std::endl;
    printf("bb-> %p aa-> %p\n", bb,aa);

    return 0;
}
