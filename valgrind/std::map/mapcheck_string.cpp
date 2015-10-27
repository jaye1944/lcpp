#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <map>

//valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
//http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
std::string NumberToString ( int Number )
{
	std::stringstream ss;
	ss << Number;
	return ss.str();
}

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
	std::map<std::string,Object*> object_map;

	for(int j = 0; j <10 ;j++)
	{
		
		Object *o = new Object(j);
		std::string sss = NumberToString(j);
		object_map.insert(std::make_pair(sss,o));

	}

	std::cout << "Hello Wordld "<< object_map.size() << std::endl;
	for(std::map< std::string,Object*>::iterator ii=object_map.begin(); ii!=object_map.end(); ++ii)
	{
		std::cout << (*ii).first << " : " << ((*ii).second)->getA() << std::endl;
		delete (*ii).second;
	}

	return 0;
}

