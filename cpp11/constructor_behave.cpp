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
  int k = 0;
  A()
  :h(this)
  {
   std::cout << "A " << this  << std::endl;   
  }  
};


class B : public A 
{
  public:
  int k = 12;
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

