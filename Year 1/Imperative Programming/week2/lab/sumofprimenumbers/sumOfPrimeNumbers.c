/* file    : sumOfPrimeNumbers.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Sep 21 2020 */
/* version : 1.1 */

/* Description: This program finds sum of prime numbers in a series of positive integers*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int number, sum = 0, prime;
	
	do {
		scanf("%d", &number);
		prime = 1;
		for (int i = 2; i * i <= number; i++) {    /* if the number has a divisor, the loop breaks */
			if (number % i == 0) {
				prime = 0;
				break;
			}
		}
		if (number == 1) {    /* if number = 1, it would complete the previous loop, therefore it would be considered as prime number */
			prime = 0;
		}
		if (prime) {    /* if the number didn't have a divisor, the number is added to the sum */
			sum += number;
		}
	} while (number);
	
	printf("%d\n", sum);

	return 0;
}
