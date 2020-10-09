#include <stdio.h>
#include <stdlib.h>

/* Write a program fragment that assigns the factorial of k (i.e. k!) to a[k] for every valid index. You do not have to worry about overflow. */

int factorial(int n) {
	int output = 1;
	for (int i = n; i != 0; i--) {
		output *= i;
	}
	return output;
}

void assignFactorial(int lenght, int a[]) {
	for (int i = 0; i < length; i++) {
		a[i] = factorial(a[i]);
	}
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
