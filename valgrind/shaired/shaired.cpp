#include <iostream>
#include <string.h>
#include <memory>

class Object
{
public:
	Object()
	{
		std::cout << "Obj" << std::endl;
	}
	
	void setA(int a)
	{
		this->a = a;
	}
	
	int getA()
	{
		return a;
	}
	
	~Object()
	{
		std::cout << "~Obj" << std::endl;
	}

private:
	int a;

};

int main(int argc, char *argv[])
{
	
	//std::cout << "Hello Wordld" << std::endl;	
	std::shared_ptr<Object> smObj = std::shared_ptr<Object> (new Object());
	smObj.get()->setA(12);
	std::cout << smObj.get()->getA()<< std::endl;
	return 0;
}
