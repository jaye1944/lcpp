#include <iostream>
#include <string.h>

template <typename T>
class Storage
{
private:
    T m_tValue;
public:
    Storage(T tValue)
    {
         m_tValue = tValue;
    }
 
    ~Storage()
    {
    }

    Storage(char* tValue)
	{
    	// Allocate memory to hold the tValue string
    	m_tValue = new char[strlen(tValue)+1];
    	// Copy the actual tValue string into the m_tValue memory we just allocated
    	strcpy(m_tValue, tValue);
	}
 
    void Print()
    {
        std::cout << m_tValue << std::endl;;
    }

};


//Storage<char*>::

int main (int argc, char *argv[])
{
    // Define some storage units
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);
 
    // Print out some values
    nValue.Print();
    dValue.Print();

    // Dynamically allocate a temporary string
    char *strString = new char[40];
 
    // Ask user for their name
    std::cout << "Enter your name: ";
    std::cin >> strString;
 
    // Store the name
    Storage<char*> strValue(strString);
 
    // Delete the temporary string
    delete strString;
 
    // Print out our value
    strValue.Print(); // This will print garbage  
    return 0;
}
