/* file    : zippingStrings.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* This function calculates square root of n, used for lenght of an array */
int squareRoot(int n) {
    int num = 0;
    for (int i = 1; i*i<=n; i++) {
        num++;
    }
    return num;
}

/* recursive function */
int merge(int x, int y, char *arr, int i, char *a1, char *a2, int lenght1, int lenght2) {
    arr[i] = a1[x];

    return;
}

int main(int argc, char *argv[]) {
    int n;    /* number of auxiliary letters */
    char *array1[33], *array2[33], *arrayGoal[34];    /* arrays for strings, lenght is 33 because I need to count for '\0' */
    char *arrayMerged[33];    /* for saving the merged words */
    int square;
    int output;
    int lenght1, lenght2;

    scanf("%d", &n);
    scanf("%s", array1);
    scanf("%s", array2);
    scanf("%s", arrayGoal);

    lenght1 = strlen(array1);
    lenght2 = strlen(array2);

    output = merge(0, 0, arrayMerged, 0, lenght1, lenght2);    /* calling the recursive function */

    printf("%d\n", output);

    return 0;
}