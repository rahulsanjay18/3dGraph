#include </usr/include/python3.6m/Python.h>
#include <iostream>
#include <string>
#include "pythonInvoker.h"
using namespace std;
int main(){
	char * types = "sif";
	string strin = "Hello World!";
	int num = 2851791;
	float point = 75.123123;

	
	string argv[] = {"", "multiply", "multiply", strin, std::to_string(num), std::to_string(point)};
	int argc = sizeof(argv) / sizeof(char *);
	
	PyObject* pyObject = invokeFunc(argc, types, argv);
	
	printf("Result of call: %ld\n", PyBytes_AsString(pyObject));
	
	return 0;
	
}
