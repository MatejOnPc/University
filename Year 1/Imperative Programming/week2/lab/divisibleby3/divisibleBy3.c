/* file    : divisibleBy3.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Sep 12 2020 */
/* version : 1.0 */

/* Description: This program finds whether the number is divisible by 3*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int number, digit;
	int sum = 0;
	
	scanf("%d", &number);
	printf("%d", number);
	
	while (number > 9) {
		while (number != 0) {    /*this while loop sums the digits of the number */
			digit = number % 10;
			sum += digit;
			number = number / 10;
		}
		number = sum;
		printf(" -> %d", number);
		sum = 0;
	}
	
	if ((number == 9) || (number == 6) || (number == 3)) {
		printf("\nYES\n");
	} else {
		printf("\nNO\n");
	};
	
	return 0;
}
