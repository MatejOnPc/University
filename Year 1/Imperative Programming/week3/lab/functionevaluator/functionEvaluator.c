/* file    : functionEvaluator.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : FRI Sep 25 2020 */
/* version : 1.0 */

/* Description: This program applies certain functions to a number based on the input */

#include <stdio.h>
#include <stdlib.h>

/* This function takes a number as an input and returns reversed number, e.g. palindrome(135) -> 531 */
int palindrome(int x) {
	int rev = 0;
	while (x > 0) {
		rev = 10*rev + x%10;
		x /= 10;
	}
	return rev;
}

/* This function takes a number as an input and returns the sum of its divisors, e.g. sumOfDivisors(6) -> 1 + 2 + 3 + 6 = 12 */
int sumOfDivisors(int x) {
	int sum = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}
	return sum;
}

/* This function takes a number as an input and returns the sum of its digits, e.g. sumOfDigits(278) -> 2 + 7 + 8 = 17 */
int sumOfDigits(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	int number;    /* input number */
	char function;    /* input functions */
	
	scanf("%d", &number);
	
	/* This do while loop takes one char form input and based on the char, it calls an appropriate function */
	do {
		scanf("%c", &function);
		if (function == 'f') {
			number = palindrome(number);
		}
		if (function == 'g') {
			number = sumOfDivisors(number);
		}
		if (function == 'h') {
			number = sumOfDigits(number);
		}
	} while (function != '=');    
	
	printf("%d\n", number);
	return 0;
}
