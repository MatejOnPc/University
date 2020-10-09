/* file    : nthPrimalSum.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Sep 27 2020 */
/* version : 1.0 */

/* Description: This program reads form the input integer n and outputs nth prime number which has the property that sum of all the primes up to n is also a prime*/

#include <stdio.h>
#include <stdlib.h>


/* this function checks whether an input is prime*/
int isPrime(int n) {
	int bool = 1;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			bool = 0;
			break;
		}
	}
	if (n == 1) {    /* if n is equal to 1, it skips the loop, but because it's not a prime number, the function should return 0 (False) */
		bool = 0;
	}
	
	return bool;
}	

/* this function takes n as an input and outputs nth prime number that satisfies the condition given in the description */
int nthPrimalNumber(int n) {
	int sum = 0;
	int i = 1;
	int count = 0;
	
	/* each prime number gets added to the sum, if the sum is also prime, count += 1. When the count reaches n, i is the nth prime number that satisfies the condition given in the description */
	while (count < n) {
		i++;
		if (isPrime(i)) {
			sum += i;
			if (isPrime(sum)) {
				count += 1;
			}
		}
	}
	return i;
}


int main(int argc, char *argv[]) {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", nthPrimalNumber(n));
	
	return 0;
}
