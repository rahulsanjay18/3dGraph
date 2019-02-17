#include <iostream>
#include <string.h>

#include "math.h"
using namespace std;
int main(void){
	int res = 50;
	float ** finalAnsArr = (float **)malloc(res * sizeof(float*));
	
	for (int i = 0; i < res; i++) finalAnsArr[i] = (float *) malloc(res * sizeof(float));
	
	string eqn = "x^2 + y^2";
	
	float dx = 1;
	float dy = 1;
	
	float startX = 0;
	float startY = 0;
	
	z_values(eqn, res, startX, startY, dx, dy, finalAnsArr);
	
	return 0;
	
}