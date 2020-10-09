#include <stdio.h>
#include <stdlib.h>

/* Write a function showTriangle with two parameters: a character ch and a positive integer n.
The function should print a triangular diagram as follows: n copies of ch on the first line,
n−1 copies of ch on the second line, etc */


void triangle(char ch, int n) {
	int i;
	while (n > 0) {
		for (i = 0; i < n; i++) {
			putchar(ch);
		}
		putchar("\n");
		n--;
	}
}

int main(int argc, char *argv[]) {
	int ch, n;
	
	printf("type a character: ");
	ch = int getchar();
	printf("type a number: ");
	scanf("%d", &n);
	
	triangle(ch, n);
	
	return 0;
}
