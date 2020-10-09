#include <stdio.h>
#include <stdlib.h>

/* Write a function firstDigit that returns the first digit of a non-negative integer number */


void firstDigit(int number) {
	
	while (number >= 10) {
		number /= 10;
	}
	
	printf("%d\n", number);
}

int main(int argc, char *argv[]) {
	int number;
	
	printf("type a positive number: ");
	scanf("%d", &number);
	
	firstDigit(number);
	
	return 0;
}
