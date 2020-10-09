/* file    : palindromicSums.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Sep 26 2020 */
/* version : 1.0 */

/* Description: This program takes input n and outputs p and q, where p is smallest palindrome such that p >= n which can be written as the sum of two palindromic numbers
 * and q is the number of ways that p can be written as such a sum */

#include <stdio.h>
#include <stdlib.h>

/* tests whether input is palindrome, returns either True(1) or False(0)*/
int isPalindrome(int x) {
	int rev = 0;    /* reverse of input */
	int bool = 0;
	int copyX = x;    /* for comparison in the if statement, I wanted to return boolean value */
	
	while (x > 0) {
		rev = 10*rev + x%10;
		x /= 10;
	}
	
	if (copyX == rev) {
		bool = 1;
	}

	return bool;
}

/* tries to find two palindromes such that when we compute their sum, the sum = input x */
void sumOfPalindromes(int x, int *changeP, int *changeQ) {    /* takes input x and two pointers that can change the values that we print as output in the main loop */
	int y = 0;
	
	/* for loop that changes p and q from main loop if input x can be written as the sum of two palindromic numbers (i and y) */
	/* repeats until i = x/2 (11 + 22 is the same as 22 + 11), p becomes x and q is the number of ways that p can be written as such sum */
	for (int i = 1; i <= x/2; i++) {
		if (isPalindrome(i)) {
			y = x - i;
			if (isPalindrome(y)) {
				*changeP = x;
				*changeQ += 1;
			}
		}
	}	
}


int main(int argc, char *argv[]) {
	int n;    /* input number */
	int p = 0, q = 0;    /* output values */
	
	scanf("%d", &n);
	
	/* repeats until we find the smallest p */
	while (p == 0) {
		if (isPalindrome(n)) {
			sumOfPalindromes(n, &p, &q);
		}
		n++;
	}
	
	printf("%d %d\n", p, q);
	
	return 0;
}
