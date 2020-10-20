/* file    : reachable.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 20 2020 */
/* version : 1.4 */

/* Description: This program takes an array of numbers as an input and then prints whether there's a solution following the rules given in program description */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recursive function that tries to find the solution */
void findSolution(int a[], int index, int *print) {
    int currentIndex = index;
    int steps = 0;

    /* base case */
    if (index == 0) {
        *print = 1;
        return;
    }

    /* check whther the jump is possible, if yes -> it recurse, if not -> tries to go further until out of bounds */
    while (currentIndex != 0) {
        currentIndex--;
        steps++;
        if (a[currentIndex] >= steps) {    /* whether it's possible to jump from currentIndex to index passed in the function at the beggining */
            findSolution(a, currentIndex, print);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    int lenght;
    int print = 0;    /* Value used in recursive function to indicate whether the solution was found */

    scanf("%d", &lenght);
    
    /* create an array with scanned lenght and fill it with the numbers from the input */
    int nInArray;
    int array[lenght];
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &nInArray);
        array[i] = nInArray;
    }

    findSolution(array, lenght-1, &print);

    if (print == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}