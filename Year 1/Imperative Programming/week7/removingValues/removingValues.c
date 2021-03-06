/* file    : removingValues.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Oct 24 2020 */
/* version : 1.1 */

/* Description: This program takes an array as an input, sorts the array and then prints the length
of the longest increasing sequence, if we can remove up to k values */

#include <stdio.h>
#include <stdlib.h>

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

/* this function finds the longest increasing series */
int findMax(int length, int *array, int k) {
    int allTimeMax = 0;
    int max = 0;
    int copyK = k;
    int saveI, repetitions = 0;    /* used for returning in array */
    int i = 0;

    /* checks all the numbers, I use while loop because I want to return to some previous index in the array */
    while (i < length - 1) {
        if (array[i] < array[i+1]) {
            max++;
            i++;
        } else {
            /* saves curretn i, the reason is that after I use all k, I want to return to this index to figure out whether there are better values to remove */
            /* e.g. example 2 in lab, if I don't include this, the program will remove numbers 2 and 3 and then continue, however removing 3 and 4 is better */ 
            if (repetitions == 0) {
                saveI = i;
                repetitions++;
            }
            if (copyK > 0) {
                copyK--;
            } else {
                if (max > allTimeMax) {
                    allTimeMax = max + 1;    /* + 1 because I haven't counted the last number in the subsequence */
                }
                max = 0;
                copyK = k;
                i = saveI;    /* returns to saved index */
                repetitions = 0;    /* reset repetitions, so I can save next i */
            }
            i++;
        }
    }
    if (max > allTimeMax) {
        allTimeMax = max + 1;    /* + 1 because I haven't counted the last number in the subsequence */
    }

    return allTimeMax;
}


int main(int argc, char *argv[]) {
    int length, k;
    int *array;
    int max;

    scanf("%d", &k);
    scanf("%d", &length);
    array = dynamicArray(length);

    /* fill the array */
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(length, array);    /* sort the array */

    max = findMax(length, array, k);

    printf("%d\n", max);

    free(array);

    return 0;
}