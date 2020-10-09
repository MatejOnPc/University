/* file    : arrayReduction.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Oct 3 2020 */
/* version : 1.0 */

/* Description: Array of positive integers is given as an input. If there exists an element which equals to the sum of all other 
 * elements in the array, then we remove it and keep repeating this process until no such element exists
 * The output is the number of elements in the maximally reduced array */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function returns maximum value in the given array */
int findMaxValue(int lenght, int a[]) {
	int maxValue = a[0];
	
	/* if a[i] > current maximum, maxValue is replaced with a[i] */
	for (int i = 1; i < lenght; i++) {
		if (a[i] > maxValue) {
			maxValue = a[i];
		}
	}
	return maxValue;
}

/* This function returns sum of all elements in the array, without the maximum value */
int sumOfArray (int lenght, int max, int a[]) {
	int sum = 0;
	
	/* add each number in array */
	for (int i = 0; i < lenght; i++) {
		sum += a[i];
	}
	sum -= max;    /*because I added all the numbers, I need to subtract maximum */
	return sum;
}

/* This function returns number of elements in maximally reduced array following the rules in the problem description */
void reducedArray(int lenght, int a[]) {
	int maxValue;
	int sum;
	int numOfElements = lenght;    /* I don't want to modify the value of lenght, because it's used in other fnctions */
	
	/* This do while loop reduces the array one number each time, if it's possible. If not, it prints number of elements in reduced array */
	do {
		maxValue = findMaxValue(lenght, a);    /* maximum value in current array */
		sum = sumOfArray(lenght, maxValue, a);    /* sum of all elements except the maximum value */
		
		/* If there exists an element which equals to the sum of all other elements in the array...*/
		if (maxValue == sum) {
			numOfElements--;
			/* element with maximum value gets replaced for 0. Note that lenght doesn't change, but numOfElements gets reduced */
			for (int i = 0; i < lenght; i++) {
				if (a[i] == maxValue) {
					a[i] = 0;
					break;
				}
			}
		} else {    /* ....if there is no such element, the number of elements in the current array gets printed and do while loop terminates */
			printf("%d\n", numOfElements);
		}
	} while (maxValue == sum);
}


int main(int argc, char *argv[]) {
	int numOfIntegers;
	char semicolon;
	int currentNumber;
	
	scanf("%d", &numOfIntegers);
	scanf("%c", &semicolon);
	
	int numbers[numOfIntegers];
	
	/* Assigning values from input to the array */
	for (int i = 0; i < numOfIntegers; i++) {
		scanf("%d", &currentNumber);
		numbers[i] = currentNumber;
	}
	
	reducedArray(numOfIntegers, numbers);
	
	return 0;
}
