/* file    : numberPyramids.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Oct 19 2020 */
/* version : 1.0 */

/* Description: This programs reads an array from input and outputs whether its possible to create a pyramid based on the rules given in problem description */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* cretes new divided arrays to sort */
int *copySubArray(int left, int right, int arr[]) {
    int length = right - left;
    int *copy = malloc(length*sizeof(int));
    for (int i=0; i < length; i++) {
        copy[i] = arr[i + left];
    }
    return copy;
}

void merge(int lenA, int a[], int lenB, int b[], int arr[]) {
    int idx=0, l=0, r=0;

    /* sorts arrays until one of them was fully used */
    while ((l != lenA) && (r != lenB)) {
        if (a[l] <= b[r]) {
            arr[idx] = a[l];
            l++;
        } else {
            arr[idx] = b[r];
            r++;
        }
        idx++;
    }

    /* adds the rest to the sorted array */
    while (l != lenA) {
        arr[idx] = a[l];
        idx++;
        l++;
    }
    while (r != lenB) {
        arr[idx] = b[r];
        idx++;
        r++;
    }
}


void mergeSort(int length, int arr[]) {
    /* base case */
    if (length <= 1) {
        return;
    }
    /* recursive case */
    int mid = length/2;

    /* make two subarrays and sort recursively*/
    int *left = copySubArray(0, mid, arr);
    mergeSort(mid, left);
    int *right = copySubArray(mid, length, arr);
    mergeSort(length - mid, right);

    /* merge sorted arrays */
    merge(mid, left, length - mid, right, arr);

    /* free auxiliary memory */
    free(right);
    free(left);
}

/* prints whether there is a solution or not */
void solution(int lenght, int a[], int index, int sumSoFar) {
    int sum;

    /* base case, I went through all numbers in array */
    if (index == lenght) {
        printf("YES\n");
        return;
    }

    if (a[index] == 0) {    /* I want to skip 0s at the begging of sorted array */
        solution(lenght, a, index+1, sumSoFar);
    } else {
        sum = a[index];
        if (sumSoFar < sum) {    /* based on the problem rules */
            sumSoFar += a[index];
            solution(lenght, a, index+1, sumSoFar);
        } else {    /* If the rule was broken, I want to print NO and return */
            printf("NO\n");
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    int max = 0, i;
    int *histogram;
    int lenght;
    scanf("%d:", &lenght);


    /* create an array with scanned lenght, fill with the numbers from input*/
    int nInArray;
    int array[lenght];
    for (i = 0; i < lenght; i++) {
        scanf("%d", &nInArray);
        array[i] = nInArray;
    }

    /* this fucntion finds maximum value in array */
    for (i = 0; i < lenght; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    histogram = dynamicArray(max + 1);    /* I want to have index with value max */
    for (i = 0; i < max+1; i++) {
        histogram[i] = 0;
    }

    /* fill histogram with 0s */
    for (i = 0; i < lenght; i++) {
        histogram[array[i]]++;
    }

    mergeSort(max+1, histogram);    /* sort histogram */

    solution(max+1, histogram, 0, 0);

    free(histogram);

    return 0;
}