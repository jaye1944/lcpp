#include <iostream>
#include <string>
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
  H h;
  A()
  :h(this)
  {
   std::cout << "A " << this  << std::endl;   
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
}

/*
A 0x2381320
B 0x2381320
keep 0x2381320
*/
