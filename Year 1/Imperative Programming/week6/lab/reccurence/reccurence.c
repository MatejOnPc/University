/* file    : reccurence.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Oct 18 2020 */
/* version : 1.0 */

/* Description: This program reads the input n and outputs Cn, where Cn is defined by the reccurence in problem description */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* recursive function, returns the value of Cn */
int reccurence(int n, int rM[]) {
    /* base cases */
    if (n <= 1) {
        return n*2;
    }

    /* recursive case */
    if (rM[n] == 0) {
        /* reccurence(n) has not been computed before */
        rM[n] = 4 * reccurence(n-1, rM) - reccurence(n-2, rM);
    }

    return rM[n];
}


int main(int argc, char *argv[]) {
    int n;
    int output;
    int reccurenceMembers[47];

    /* fill the array with 0s */
    for (int i = 0; i < 47; i++) {
        reccurenceMembers[i] = 0;
    }

    scanf("%d", &n);

    output = reccurence(n, reccurenceMembers);

    printf("%d\n", output);

    return 0;
}