#include <iostream>
#include <stdio.h>
#include <map>

//valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
//http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
class Object
{
public:
	Object(int a)
	{
		std::cout << "Object" << std::endl;
		this->a = a;
	}

	~Object()
	{
		std::cout << "~Object" << std::endl;
	}

	int getA()
	{
		return a;
	}

private:
	int a;

};

int main(int argc, char *argv[])
{
	std::map<const char*,Object*> object_map;

	for(int j = 0; j <10 ;j++)
	{
		
		char *buf = new char[10];
		Object *o = new Object(j);

		int k = sprintf(buf,"key_%d",j);
		object_map.insert(std::make_pair(buf,o));
	}

	std::cout << "Hello Wordld "<< object_map.size() << std::endl;

	for(std::map< const char*,Object*>::iterator ii=object_map.begin(); ii!=object_map.end(); ++ii)
	{
		std::cout << (*ii).first << " : " << ((*ii).second)->getA() << std::endl;
		delete (*ii).second;
		delete [] (*ii).first;
	}
	return 0;
}

