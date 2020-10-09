#include <stdio.h>
#include <stdlib.h>

/* The expression (a || b || c) evaluates to a non-zero value (true) if at least one of the expressions 
a, b or c is non-zero. Write a function with three parameters of type int that returns a non-zero value (true)
if and only if at least two of its parameters are non-zero. */


int majorityVote(int a, int b, int c) {
	return ((a && b) || (b && c) || (c && a));
}


int main(int argc, char *argv[]) {
	int a, b, c;
	
	printf("type three numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if (majorityVote(a, b, c)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}
