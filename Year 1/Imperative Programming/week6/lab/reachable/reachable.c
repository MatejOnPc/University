/* file    : reachable.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Oct 18 2020 */
/* version : 1.0 */

/* Description: This program takes an array of numbers as an input and then prints whether there's a solution following the rules given in program description */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recursive function that tries to find the solution */
void solution(int index, int a[], int lenght, int *print) {    /* current index, array, lenght of array and value that gets modified if there's a solution */
    /* base case, I am already out of bounds -> no solution with this particular jumps */
    if (index >= lenght) {
        return;
    }

    /* base case, I found the solution */
    if (index == lenght-1) {
        *print = 1;    /* used for printing YES or NO in main function */
        return;
    }

    /* for each possible jump, try to find the solution */
    for (int i = 1; i <= a[index]; i++) {
        solution((index+i), a, lenght, print);
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

    solution(0, array, lenght, &print);

    if (print == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}