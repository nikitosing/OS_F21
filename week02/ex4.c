#include <stdio.h>

void swap(int * a_, int * b_){
	int t = *a_;
	*a_ = *b_;
	*b_ = t;
}


int main(){
	int a = 0;
	int b = 0;

	printf("Input a number a: \n");
	scanf("%d", &a);
	printf("Input a number b: \n");
	scanf("%d", &b);
	
	swap(&a, &b);
	
	printf("a = %d; b = %d", a, b);
	
	return 0;
}

