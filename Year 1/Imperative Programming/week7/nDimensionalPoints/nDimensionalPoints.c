/* file    : .c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 20 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>

/* make a 2D dynamic array */
int **makeIntArray2D(int height, int width) {
    int row, **arr;
    arr = malloc(height*sizeof(int *));
    for (row=0; row < height; row++) {
        arr[row] = malloc(width*sizeof(int));
    }
    return arr;
}

/* free a 2D dynamic array */
void destroyIntArray2D(int **arr, int height) {
    int row;
    for (row=0; row < height; row++) {
        free(arr[row]);
    }
    free(arr);
}

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* recursive function, finds whether the number is in the first line */
int recBinarySearch(int n, int k, int left, int right, int a[n][k], int number, int *index) {
    int mid;

    /* base case */
    if (left == right - 1) {
         /* if the number was in the first line, returns the number, else it returns 0 (because I add the return value to the sum) */
        if (a[0][left] == number) {
            *index = left;
            return 1;
        } else {
            return 0;
        }
    }

    mid = (left + right)/2;
    
    /* changes left or right based on the number, so it stays in halved array */
    if (number < a[0][mid]){
        right = mid;
    } else {
        left = mid;
    }

    return recBinarySearch(n, k, left, right, a, number, index);
} 

int main(int argc, char *argv[]) {
    int n, k, i;
    int **array;
    int *point;
    int index;
    int value;

    scanf("%d %d", &n, &k);    
    array = makeIntArray2D(n, k);

    for (i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }

    point = dynamicArray(n);

    for (i = 0; i < n; i++) {
        scanf("%d", &point[i]);
    }

    value = point[0];

    if (recBinarySearch(n, k, 0, k, array, value, &index)) {
        printf("index = %d\n", index);
        while (array[0][index] == value) {
            index--;
        }
        index++;
        printf("index = %d". index);
    }

    return 0;
}