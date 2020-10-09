#include <stdio.h>
#include <stdlib.h>

/*  Write a complete program that asks the user to type in a non-negative number and then prints whether the number is a palindrome number or not */


int reverseNumber(int n) {
	int rev = 0;
	while (n > 0) {
		rev = 10*rev + n%10;
		n /= 10;
	}
	return rev;
}

int main(int argc, char *argv[]) {
	int n;
	
	do {
		printf("Type in a non-negative number: ");
		scanf("%d", &n);
	} while (n < 0);
	
	if (n == reverseNumber(n)) {
		printf("%d is a palindrome\n", n);
	} else {
		printf("%d is not a palindrome\n", n);
	}
	
	return 0;
}
