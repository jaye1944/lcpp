#include <iostream>
#include <string>
#include <cassert>
class A;
class H 
{
  public:
  A* keep;
  H(A* a)
  {
    keep = a;    
  }   
};

class A 
{
  public:
  A *me;
  H h;
  A()
  :h(this)
  {
   std::cout << "A " << this  << std::endl;
   assert(NULL == me);
   me = this;
  }  
};


class B : public A 
{
  public:
  B()
  {
 
   std::cout << "B " << this  << std::endl;   
  }  
};


int main()
{
  //A *onjA = new A();
  B *onjB = new B();
  std::cout << "keep " << onjB->h.keep << std::endl;
  delete onjB;
}

/*
A 0x2381320
B 0x2381320
keep 0x2381320
*/
