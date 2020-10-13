/* file    : linearEquation.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillArray(int a[], int lenght) {
    int x;
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
}

void fillMaxMultiples(int max[], int a[], int lenght, int y) {
    for (int i = 0; i < lenght; i++) {
        max[i] = y / a[i];
    }
}

int findSolutions(int y, int a[], int mul[], int max[], int lenght, int solutions) {
    int sum = 0;
    int i;

    for (int i = 0; i < lenght; i++) {
        printf("%d ", mul[i]);
    }
    printf("\n");

    if (mul[0] > max[0]) {
        return solutions;
    }

    for (i = 0; i < lenght; i++) {
        if (mul[i] > max[i]) {
            mul[i-1]++;
            mul[i] = 0;
            return findSolutions(y, a, mul, max, lenght, solutions);
        }
    }


    for (i = 0; i < lenght; i++) {
        sum += a[i] * mul[i];
    }

    if (sum == y) {
        solutions++;
    }

    mul[lenght-1]++;

    findSolutions(y, a, mul, max, lenght, solutions);
}

int main(int argc, char *argv[]) {
    int n;
    int y;
    int solutions;
    
    scanf("%d:", &n);

    int array[n];
    int multiples[n];
    int maxMultiples[n];

    fillArray(array, n);
    scanf("%d",&y);

    for (int i = 0; i < n; i++) {
        multiples[i] = 0;
    }

    fillMaxMultiples(maxMultiples, array, n, y);
/*
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", maxMultiples[i]);
    }
    printf("\n"); */

    solutions = findSolutions(y, array, multiples, maxMultiples, n, 0);

    printf("%d\n", solutions);

    return 0;
}