/* file    : crackTheCode.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.2 */

/* Description: This problem takes two strings as an input and checks whether there exists a code book for encrypting the strings */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function checks whether the letters correspond to the same letter in the second string */
int checkLetter(int i, char a[], char b[]) {
	char first, second;
	
	for (int j = 0; j < i; j++) {
		if (a[j] == a[i]) {
			first = b[j];
			second = b[i];
			break;    /* first and last occurance is enough, all the other must have passed */
		}
	}
	if (first == second) {
		return 1;
	} else {
		return 0;
	}
}
	
/* This functions returns 1 if the strings satisfy problem conditions and therefore there is such a code book */
int convertToNumbers(int lenght, char a[], char b[]) {
	int i, histogramA[26];
	
	for (i = 0; i < 26; i++) {
		histogramA[i] = 0;
	}
	
	for (i = 0; i < lenght; i++) {
		histogramA[a[i] - 'A']++;
		if (histogramA[a[i] - 'A'] > 1) {    /* With multiple occurances of the same letter, I have to check whether they correspond to the same letter each time */
			if (checkLetter(i, a, b) != 1) {    /* If they don't, return 0, if they do, it's fine and the loop continues */
				return 0;
			}
			
		}
	}
	return 1;
}


int main(int argc, char *argv[]) {
	char word1[101], word2[101];
	int lenght1, lenght2;
	
	scanf("%s", word1);
	scanf("%s", word2);
	
	lenght1 = strlen(word1);
	lenght2 = strlen(word2);
	
	/* If they are not the same lenght, print NO, if they are, check for the problem conditions */
	if (lenght1 == lenght2) { 
		if (convertToNumbers(lenght1, word1, word2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		printf("NO\n");
	}	
	
	return 0;
}
