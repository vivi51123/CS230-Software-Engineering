#include <stdio.h>
#include <stdlib.h>

int main(){
	for(int i = 0; i < 10; i++)
	{
		int *p = (int *)malloc(sizeof(int)*10);
		p[0] = 10;
		printf("val at 0: %d\n", p[0]);
	}	
}