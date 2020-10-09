#include <stdio.h>
#include <stdlib.h>

/* Write a function that returns the number of unique real solutions of the quadratic equation a*x^2 + b*x + c = 0 */


int numSolutions(int a, int b, int c) {
	int discriminant = b*b - 4*a*c;
	return (discriminant < 0 ? 0 : 1 + (discriminant != 0)); /* if the condition is true, we return first answer after ?, if not, we return the second */
}

int main(int argc, char *argv[]) {
	int a, b, c;
	
	printf("type 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("%d\n", numSolutions(a, b, c));
	
	return 0;
}
