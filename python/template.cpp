#include  <Python.h>
#include <iostream>

int main (int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;  
    return 0;
}

static PyObject *my_callback = NULL;