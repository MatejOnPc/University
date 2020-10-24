/* file    : submatrix.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SAT Oct 24 2020 */
/* version : 1.0 */

/* Description: This program takes two 2D arrays as an input and then prints how many times the second array occurs in the first array */

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

/* this function checks whether array2 occurs in array1 */
int checkArray(int m, int n, int a, int b, int **array1, int **array2) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (array1[m + i][n + j] != array2[i][j]) {
                return 0;
            } 
        }
    }
    return 1;
}


int main(int argc, char *argv[]) {
    int m, n, a, b, i;
    int **array1;
    int **array2;
    int output = 0;

    /* create and fill the first array */
    scanf("%d %d", &m, &n);    
    array1 = makeIntArray2D(m, n);
    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &array1[i][j]);
        }
    }

    /* create and fill the second array */
    scanf("%d %d", &a, &b);    
    array2 = makeIntArray2D(a, b);
    for (i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &array2[i][j]);
        }
    }

    /* this nested loops finds all the occurances */
    for (i = 0; i <= m-a; i++) {    /* m-a so I won't go out of bounds */
        for (int j = 0; j <= n-b; j++) {    /* n-b so I won't go out of bounds */
            if (array1[i][j] == array2[0][0]) {
                output += checkArray(i, j, a, b, array1, array2);
            } 
        }
    }

    printf("%d\n", output);

    /* free all arrays */
    destroyIntArray2D(array1, m);
    destroyIntArray2D(array2, a);

    return 0;
}