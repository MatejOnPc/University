#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
	int a, b, c;  /* sides of triangle */
	int rightAngled = 0;
	
	printf("Sides a, b and c of triangle: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if (a*a + b*b == c*c) {
		rightAngled = 1;
	}
	if (b*b + c*c == a*a) {
		rightAngled = 1;
	}
	if (c*c + a*a == b*b) {
		rightAngled = 1;
	}
	
	if (rightAngled) {
		printf("The triangle is right-angled\n");
	} else {
		printf("The triangle is not right-angled\n");
	}
	
	return 0;
}
