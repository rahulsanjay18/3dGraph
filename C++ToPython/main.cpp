#include </usr/include/python3.6m/Python.h>
#include <iostream>
#include "pythonInvoker.h"

int main(){
	char * argv[] = {"", "multiply", "multiply", "3", "2"};
	int argc = sizeof(argv) / sizeof(char *);
	
	PyObject* pyObject = invokeFunc(argc, argv);
	
	printf("Result of call: %ld\n", PyLong_AsLong(pyObject));
	
	return 0;
	
}