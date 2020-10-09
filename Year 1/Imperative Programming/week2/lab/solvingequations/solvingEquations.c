/* file    : solvingEquations.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Sep 21 2020 */
/* version : 1.3 */

/* Description: This program outputs the number of possible combinations of values a, b, c that satisfy the requirement*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int m, n, p, q, r;    /* input numbers */
	int solutions = 0, c;
	
	scanf("%d %d %d %d %d", &m, &n, &p, &q, &r);
	
	/* this nested for loops go through all posible combinations of a, b and c and if they satisfy the requirement, solutions becomes +1 */
	for (int a = 0; a <= m; a++) {
		for (int b = 0; b <= (m - a); b++) {
			c = m - a - b;
			if (a*p + b*q + c*r == n) { /* I don't need to check for a + b + c = m, because that's always true */
				solutions += 1;
			}	
		}
	}
	
	printf("%d\n", solutions);
	  
	return 0;
}
