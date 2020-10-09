#include <stdio.h>
#include <stdlib.h>


/* Write a function isMultipleOf so that the call isMultipleOf(x, y) returns true if and only if x is an integral multiple of y.
The parameters x and y are of type int. */


int isMultipleOf(int x, int y) {
	return x % y == 0;
}


int main(int argc, char *argv[]) {
	int x, y;
	
	printf("type a positive number: ");
	scanf("%d", &x);
	printf("type a positive number: ");
	scanf("%d", &y);
	
	if (isMultipleOf(x, y)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}
