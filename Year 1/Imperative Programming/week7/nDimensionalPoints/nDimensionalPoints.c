/* file    : nDimensionalPoints.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Oct 24 2020 */
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

int main(int argc, char *argv[]) {
    int n, k, i;
    int **array;
    int *point;
    int output = 0, checkPoint;    /* used for checking whether the point is in array */

    scanf("%d %d", &n, &k);    
    array = makeIntArray2D(n, k);
    /* fill the array */
    for (i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    point = dynamicArray(n);
    /* fill the point */
    for (i = 0; i < n; i++) {
        scanf("%d", &point[i]);
    }

    for (i = 0; i < k; i++) {
        if (point[0] == array[0][i]) {
            checkPoint = 1;   /* I assume that i found the point */
            for (int j = 1; j < n; j++) {
                if (array[j][i] != point[j]) {    /* If it doesn't equal, it's not the point I am searching for */
                    checkPoint = 0;
                    break;
                }
            }
            output += checkPoint;
        }
        if (point[0] < array[0][i]) {    /* because first line is ordered, once the element in array becomes larger, there's no point in checking anymore */
            break;
        }
    }

    printf("%d\n", output);

    /* free all arrays */
    destroyIntArray2D(array, n);
    free(point);

    return 0;
}