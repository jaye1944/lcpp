#include <iostream>
#include <string.h>
#include <list>

//valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
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
	std::list<Object*> object_list;

	for(int j = 0; j <10 ;j++)
	{
		Object *o = new Object(j);
		object_list.push_back(o); //reference of pointer
		//delete o;
	}

	std::cout << "Hello Wordld "<< object_list.size() << std::endl;

	for (std::list<Object*>::iterator it = object_list.begin(); it != object_list.end(); it++)
    {	std::cout << (*it)->getA() << ' ';
    	delete (*it);//freeing Object alocated memory via reference [(*it) = NULL; not working]
	}   //object_list.clear(); //clear not deleting the alocate memeory only clearing reference 
	//std::cout << object_list.size() << std::endl;
	return 0;
}

/*summery 1
delete o; (38 line) 
		after delete object list can have it(read it), it have reference of object (pointer here)
		but it consider as invalid read
		
		==4827== ERROR SUMMARY: 10 errors from 1 contexts (suppressed: 0 from 0)
		==4827== 
		==4827== 10 errors in context 1 of 1:
		==4827== Invalid read of size 4
		==4827==    at 0x400E20: Object::getA() (mlist.cpp:22)
		==4827==    by 0x400CB6: main (mlist.cpp:44)
		==4827==  Address 0x5a1c040 is 0 bytes inside a block of size 4 free'd
		==4827==    at 0x4C2C2BC: operator delete(void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
		==4827==    by 0x400C4D: main (mlist.cpp:38)
*/

/*summery 2
object_list.clear() (45 line)
		clear not deleting the alocate memeory only delete reference of memeory
		(no iterator no delete o) (comment iterator and delete o)

		==4974== 40 bytes in 10 blocks are definitely lost in loss record 1 of 1
		==4974==    at 0x4C2B0E0: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
		==4974==    by 0x400B4D: main (mlist.cpp:36)

		==4974== LEAK SUMMARY:
		==4974==    definitely lost: 40 bytes in 10 blocks
		==4974==    indirectly lost: 0 bytes in 0 blocks
		==4974==      possibly lost: 0 bytes in 0 blocks
		==4974==    still reachable: 0 bytes in 0 blocks
		==4974==         suppressed: 0 bytes in 0 blocks
		==4974== 
		==4974== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/

/*summary 3
correct way
		==5173== HEAP SUMMARY:
		==5173==     in use at exit: 0 bytes in 0 blocks
		==5173==   total heap usage: 20 allocs, 20 frees, 280 bytes allocated
		==5173== 
		==5173== All heap blocks were freed -- no leaks are possible
		==5173== 
		==5173== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
		==5173== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/