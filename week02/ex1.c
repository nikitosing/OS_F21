#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(){
	int _int = INT_MAX;
	float _float = FLT_MAX;
	double _double = DBL_MAX;
	printf("int = %d\nfloat = %f\ndouble = %f\n", _int, _float, _double);
	printf("sizeof(int) = %d\nsizeof(float) = %d\nsizeof(double) = %d\n", sizeof(_int), sizeof(_float), sizeof(_double));
	return 0;
}