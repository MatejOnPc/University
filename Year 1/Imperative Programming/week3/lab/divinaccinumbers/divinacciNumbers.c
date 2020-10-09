/* file    : divinacciNumbers.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : FRI Sep 25 2020 */
/* version : 1.0 */

/* Description: This program takes n as an input and outputs D(n), where D(n) = sum of divisors of D(n-1) + sum of divisors of D(n-2) */

#include <stdio.h>
#include <stdlib.h>

/* This function takes a number as an input and returns the sum of its divisors, e.g. sumOfDivisors(4) -> 1 + 2 + 4 = 7 */
int sumOfDivisors(int x) {
	int sum = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}
	return sum;
}

/* This function takes n as an input and outputs D(n) */
int divisors(int n) {
	int x = 0, y = 1, h;    /* x = D(0), y = D(1) */
	int sum = 0;    /* sum = D(n) */

	if (n == 0) {    /* D(0) = 0 */
		sum = n;
	} else {
		for (int i = 1; i < n-1; i++) {
			h = y;
			y = sumOfDivisors(y) + sumOfDivisors(x);
			x = h;
		}
		/* y = D(n-1) */
		/* x = D(n-2) */
		sum = sumOfDivisors(y) + sumOfDivisors(x);    /* D(n) = sum of divisors of D(n-1) + sum of divisors of D(n-2) */
	}
	return sum;
}

int main(int argc, char *argv[]) {
	int n;    /* input number */
	
	scanf("%d", &n);
	if (n == 0 || n == 1) {    /* D(0) and D(1) are given values */
		printf("%d\n", n);
	} else {
		printf("%d\n", divisors(n));
	}
	
	return 0;
}
