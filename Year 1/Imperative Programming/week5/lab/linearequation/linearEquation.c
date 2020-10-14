/* file    : linearEquation.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : WED Oct 14 2020 */
/* version : 1.3 */

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

/* recursive funcion */
int findSolutions(int y, int a[], int index, int multiple, int lenght) {

    /* base case */
    if ((y == 0) && (index == lenght)) {
        return 1;
    }
    /* base cases */
    if ((y < 0) || (index >= lenght) || (multiple*a[index]) > y) {
        return 0;
    }

    /* recursive call, two options, I either move to the next index in array or I add one to the multiple and stay at the same index in array */
    return findSolutions(y - multiple*a[index], a, index+1, 0, lenght) + findSolutions(y, a, index, multiple+1, lenght);
}

int main(int argc, char *argv[]) {
    int n;    /* lenght from input */
    int y;    /* desired sum */
    int solutions;
    
    scanf("%d:", &n);

    int array[n];
    fillArray(array, n);
    scanf("%d",&y);

    solutions = findSolutions(y, array, 0, 0, n);
    printf("%d\n", solutions);

    return 0;
}