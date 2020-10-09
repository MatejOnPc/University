/* file    : cyclicRandomGenerators.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.4 */

/* Description:  This program reads from the input parameters x, a, c and m and outputs the period of the pseudo random generator */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* This function calculates the next number in the pseudo random generator */
int nextNumber(int x, int a, int c, int m) {
	int result;
	result = (a*x+c) % m;
	return result;
}

int main(int argc, char *argv[]) {
	int x, a, c, m;
	int *array;
	int *histogram;    /* for representing how often each X was calculated, if some element becomes 2, there is a period */
	int position;
	int period;
	
	scanf("%d %d %d %d", &x, &a, &c, &m);
	
	array = dynamicArray(m+1);
	/* size is m, because X = (something) % m, so it can get only values from 0 to m-1, I put m+1 just to make sure if it goes through all the possible numbers before finding the period */
	array[0] = x;
	histogram = dynamicArray(m);    /* same reason as the array */
	/* fills the histogram with 0 */
	for (int i = 0; i < m; i++) {
		histogram[i] = 0;
	}
	histogram[x]++;

	/* repeats until period is found */
	for (int i = 1; i < m + 1; i++) {
		x = nextNumber(x, a, c, m);
		array[i] = x;
		histogram[x]++;
		/* if index X is equal to 2, there is a period */
		if (histogram[x] == 2) {
			/* finds the position of the first occurance of X */
			for (int j = 0; j < m; j++) {
				if (array[j] == x) {
					position = j;
					break;
				}
			}
			period = i - position;    /* calculates the period based on the second and first occurance */
			break;
		}
	}
	printf("%d\n", period);
			
	return 0;
}
