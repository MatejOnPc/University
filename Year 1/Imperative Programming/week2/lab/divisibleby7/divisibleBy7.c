/* file    : divisibleBy7.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Sep 22 2020 */
/* version : 1.5 */

/* Description: This program finds whether the number is divisible by 7*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n, p, q;    /* n is number given in input, p and q are used in the loop */
	int steps = 0;    /* number of steps that the method makes to determine whther n is divisible by 7 */
	
	scanf("%d", &n);
	
	while (n > 7 && n != 49) {    /* repeats until n is less or equal 7 or n = 49, q becomes last digit of n, p becomes n withouth the last digit */
		q = n % 10;
		p = n / 10;
		n = p + 5 * q;
		steps += 1;
	} 
		
	printf("%d\n", steps);
	
	if (n == 7 || n == 49) {
		printf("YES\n");
	} else {
		printf("NO\n");
	};
		
	return 0;
}
