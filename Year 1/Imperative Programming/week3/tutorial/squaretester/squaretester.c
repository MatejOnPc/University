#include <stdio.h>
#include <stdlib.h>

/* Write a function with one integer parameter that tests whether the value of the parameter is the square of an integer or not */


void squareTest(int n) {
	int result = 0;
	
	for (int i = 0; i * i <= n; i++) {
		if (i*i == n) {
			result = 1;
			break;
		}
	}
	
	if (result) {
		printf("%d is a square of integer\n", n);
	} else {
		printf("%d is not a square of integer\n", n);
	}
}


int main(int argc, char *argv[]) {
	int number;
	
	printf("Type a number: ");
	scanf("%d", &number);
	
	if (number < 0) {
		printf("%d is not a square of integer\n", number);
	} else {
		squareTest(number);
	}
	
	return 0;
}
