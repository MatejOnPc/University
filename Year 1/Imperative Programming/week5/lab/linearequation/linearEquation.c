/* file    : linearEquation.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fillArray(int a[], int lenght) {
    int x;
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
}

int findSolutions(int y, int *a, int *mul, int lenght, int index) {
    int sum = 0;
    int steps = 0;

    for (int i = 0; i < lenght; i++) {
        sum += a[i] * mul[i];
    }

    if (sum > y) {
        mul[index] = 0;
        steps--;
        mul[index-steps]++;
    }

    if (sum == y) {
        mul[index] = 0;
        index++;
        findSolutions();
        return 1;
    }

    mul[index]++;
    findSolutions();

}

int main(int argc, char *argv[]) {
    int solutions = 0;
    int n;
    int array[n];
    int multiples[n];
    int y;
    
    scanf("%d:", &n);
    fillArray(array, n);
    scanf("%d",&y);

    for (int i = 0; i < n; i++) {
        multiples[i] = 0;
    }



    solutions = findSolutions(y, 0, 0);    


    return 0;
}