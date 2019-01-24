#include <iostream>
#include <cstring>
#include <stdlib.h>

int main(){
	int a, b, c, d;
	std::string stuff = "30 40 50 60";
	char * stuffArr = (char *) stuff.c_str();
	
	a = atoi(strtok(stuffArr, " "));
	b = atoi(strtok(NULL, " "));
	c = atoi(strtok(NULL, " "));
	d = atoi(strtok(NULL, " "));

	std::cout << a <<" "<< b << " " << c << " " << d << '\n';
	return 0;
}
