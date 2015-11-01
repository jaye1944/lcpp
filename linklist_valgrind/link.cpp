//g++ -ggdb link.cpp && valgrind -v --tool=memcheck --leak-check=full --log-file=valgrind.log ./a.out

#include <iostream>

class Node
{
public:
	Node(int id){this->id = id;}
	int getID(){return id;}
	void setID(int id){this->id = id;}
	Node *pNext;
private:
	int id;

};

Node* deleteNode(Node* pst,int id)
{
	Node* pprev = NULL;
	Node* pcurr = pst;
	Node* phead = pst;

	while(pcurr != NULL)
	{
		if(pcurr->getID() == id)
		{
			std::cout << "\nvalue found in " << pcurr << " @ " << id << std::endl; 
			if(pprev == NULL)//head
			{
				phead = pcurr->pNext;
				delete pcurr;
				pcurr = NULL;
				return phead;
			}
			else
			{
				pprev->pNext = pcurr->pNext;
				delete pcurr;
				pcurr = NULL;
				return phead;
			}
		}
		pprev = pcurr;
		pcurr = pcurr->pNext;	
	}
	std::cout << "\nNo value found as " << id << std::endl;
	return phead;
}

void printAll(Node *p)
{
	while(p != NULL)
	{
		std::cout << p->getID() << " " ;  
		p = p->pNext;
	}

	std::cout << std::endl;
}

void freeAll(Node *p)
{
	int count = 0;
	//std::cout << "Free all head " << p << std::endl;
	Node *temp;
	while(p != NULL)
	{
		temp = p;
		p = p->pNext;
		delete temp;
		temp = NULL;
		count++;
	}

	std::cout << "\nfree "<< count << std::endl;
}

int main()
{

   Node *n = new Node(1);
   Node *prev; 
   prev = n;
   for(int k = 1; k <= 5;k++)
   {
   		Node *temp = new Node(k*100);
   		temp->pNext = NULL;
   		prev->pNext = temp;
   		prev = temp;
   } 
   //print all for check
   printAll(n);

   //removing head
   n = deleteNode(n,1);
   printAll(n);


   //removing middle
   n = deleteNode(n,200);
   printAll(n);

   //remove end
   n = deleteNode(n,500);
   printAll(n);

   //remove nonexisting 
   n = deleteNode(n,5000);
   printAll(n);

   //free
   freeAll(n);
   return 0;
}
