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
	std::map<const char*,Object*> object_map;
	//object_map.init();

	for(int j = 1; j <11 ;j++)
	{
		
		Object *o = new Object(j);
		char key[15];
		snprintf(key,14,"%d_%d",1,j);
		printf("pointer %p \n",&key);
		object_map.insert(std::make_pair(key,o));

	}

	int n = 0;
	while(n < 10000000){
		n++;
	}

	std::cout << "Map Size "<< object_map.size() << std::endl;

	for(std::map< const char*,Object*>::iterator ii=object_map.begin(); ii!=object_map.end(); ++ii)
	{
		std::cout << (*ii).first << " : " << ((*ii).second)->getA() << std::endl;
		printf("pointer %p",&(*ii).second);
		delete (*ii).second;
	}

	return 0;
}

