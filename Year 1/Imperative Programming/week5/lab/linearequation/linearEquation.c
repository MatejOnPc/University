/* file    : linearEquation.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.2 */

/* Description: This program finds number of possible solutions for a given linear equation */

#include <stdio.h>
#include <stdlib.h>

/* fills array from input */
void fillArray(int a[], int lenght) {
    int x;
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
}

/* fills array multiples */
void fillMultiples(int a[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        a[i] = 0;
    }
}

/* fills maximum values for each integer, used for going through all the possible solutions */
void fillMaxMultiples(int max[], int a[], int lenght, int y) {
    for (int i = 0; i < lenght; i++) {
        max[i] = y / a[i];
    }
}

/* recursive funcion */
int findSolutions(int y, int a[], int mul[], int max[], int lenght, int solutions) {
    int sum = 0;
    int i;

    /* base case */
    if (mul[1] > max[1]) {
        return solutions;
    }

    /* calculates sum */
    for (i = 1; i < lenght; i++) {
        sum += a[i] * mul[i];
    }

    /* makes sure I move through all possibilities */
    for (i = 1; i < lenght; i++) {
        if (mul[i] > max[i]) {
            mul[i-1]++;
            mul[i] = 0;
            return findSolutions(y, a, mul, max, lenght, solutions);
        }
    }

    /* to make the program more efficient, I don't go through all the possibilities, but check the condition for the multiple with the first indes */
    if ((y - sum >= 0) && ((y-sum) % a[0] == 0)) {
        solutions++;
    }

    mul[lenght-1]++;

    findSolutions(y, a, mul, max, lenght, solutions);    /* recursive call */
}

int main(int argc, char *argv[]) {
    int n;    /* lenght from input */
    int y;    /* desired sum */
    int solutions;
    
    scanf("%d:", &n);

    int array[n];
    int multiples[n];
    int maxMultiples[n];

    fillArray(array, n);
    scanf("%d",&y);
    fillMultiples(multiples, n);
    fillMaxMultiples(maxMultiples, array, n, y);

    solutions = findSolutions(y, array, multiples, maxMultiples, n, 0);

    printf("%d\n", solutions);

    return 0;
}