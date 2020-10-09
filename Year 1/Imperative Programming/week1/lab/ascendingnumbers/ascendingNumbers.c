/* file    : ascendingNumbers.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : WED Sep 9 2020 */
/* version : 1.0 */

/* Description: This program finds out whether an integer has digits in ascending order */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int first, second, third, fourth; /*digits*/
	int input; /*number given in input*/
	
	scanf("%d", &input);
	
	fourth = input%10;
	third = ((input/10)%10);
	second = ((input/100)%10);
	first = ((input/1000)%10);
	
	if ((first <= second) && (second <= third) && (third <= fourth)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	};

	return 0;
}
