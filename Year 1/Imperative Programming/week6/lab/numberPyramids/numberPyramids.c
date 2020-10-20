/* file    : numberPyramids.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 20 2020 */
/* version : 1.4 */

/* Description: This programs reads an array from input and outputs whether its possible to create a pyramid based on the rules given in problem description */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* this function finds whether there is a majority in the array */
int hasMajority(int length, int a[]) {
    int candidate, counter, surplus = 0;
    int i;
    int *newArray;    /* if there is a majority, I'll create new array without the element and pass it to the function again (so I'll check for all levels) */
    int index = 0;

    /* this loop finds candidate for a majority */
    for (i=0; i < length; i++) {
        if (surplus == 0) { /* there's a new candidate */
            candidate = a[i];
            surplus = 1;
        } else { /* we have a candidate already */
            if (a[i] == candidate) { /* another vote */
            surplus++;
            } else { /* cancel out votes */
                surplus--;
            }
        }
    }

    /* if there is a majority, then we know the candidate */
    counter = 0;
    for (i=0; i < length; i++) {
        if (a[i] == candidate) {
            counter++;
        }
    }

    /* if candidate has a majority, I create new array without the candidate and pass it to the function again */
    if (2*counter > length) {    /* has a majority */
        length = length - counter;    /* lenght of the new array */
        newArray = dynamicArray(length);
        /* fills the new array with all the elemnts that are not the candidate */
        for (i = 0; i < length + counter; i++) {
            if (a[i] != candidate) {
                newArray[index] = a[i];
                index++;
            }
        }
        /* if lenght isn't zero, I call the function again with the new array. If it is, I return 1 and therefore print YES */
        if (length != 0) {
            return hasMajority(length, newArray);
        } else {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int *array;
    int nInArray;
    int lenght;
    scanf("%d:", &lenght);

    /* create an array with scanned lenght, fill with the numbers from input*/
    array = dynamicArray(lenght);
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &nInArray);
        array[i] = nInArray;
    }

    if (hasMajority(lenght, array)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(array);    /* free dynamically allocated array */

    return 0;
}