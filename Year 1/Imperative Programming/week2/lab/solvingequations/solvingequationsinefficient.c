/* file    : solvingequations.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Sep 20 2020 */
/* version : 1.0 */

/* Description: This program outputs the number of possible combinations of values a, b, c that satisfy the requirement*/

/* Even though this program finds correct solution, it wasn't accepted because it's inefficient and slow */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int m, n, p, q, r;    /* input numbers */
	int a = 0, b = 0, c = 0;
	int solutions = 0;
	
	scanf("%d %d %d %d %d", &m, &n, &p, &q, &r);
	
	while (1) {
		if ((a + b + c == m) && (a*p + b*q + c*r == n)) {
			solutions += 1;
		}
		
		c++;
		
		/* next if statemensts ensure that all the possible combinations will be covered between (0, 0, 0) and (m, m, m) */
		if (c > m) {    
			b++;
			c = 0;
		}
		
		if (b > m) {
			a++;
			b = 0;
		}
		
		if (a > m) {
			break;
		}
	}
	
	printf("%d\n", solutions);
	  
	
	return 0;
}
