/* file    : zippingStrings.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* recursive function */
int merge(int x, int y, int i, int n, char *aM, char *aG, char *a1, char *a2, int lenght1, int lenght2) {
    if (x-1 == lenght1) {
        return 0;
    }
    
    printf("i = %d, aM = %s\n", i, aM);

    if (y-1 == lenght2) {
        return 0;
    }
    
    aM[i] = a1[x];

    if (aM[i] != aG[i]) {
        if (n > 0) {
            aM[i] = aG[i];
            n--;
            return merge(x, y, i, n, aM, aG, a1, a2, lenght1, lenght2) + merge(y, x, i, n, aM, aG, a2, a1, lenght2, lenght1);
        } else {
            return 0;
        }
    }

    i++;

    if (aM == aG) {
        return 1;
    }

    return merge(x+1, y, i, n, aM, aG, a1, a2, lenght1, lenght2) + merge(y, x, i, n, aM, aG, a2, a1, lenght2, lenght1);
}

int main(int argc, char *argv[]) {
    int n;    /* number of auxiliary letters */
    char array1[33], array2[33], arrayGoal[34];    /* arrays for strings, lenght is 33 because I need to count for '\0' */
    char arrayMerged[33];    /* for saving the merged words */
    int output;
    int lenght1, lenght2;

    scanf("%d", &n);
    scanf("%s", array1);
    scanf("%s", array2);
    scanf("%s", arrayGoal);

    printf("%d, %s, %s, %s\n",  n, array1, array2, arrayGoal);

    lenght1 = strlen(array1);
    lenght2 = strlen(array2);

    output = merge(0, 0, 0, n, arrayMerged, arrayGoal, array1, array2, lenght1, lenght2) + merge(0, 0, 0, n, arrayMerged, arrayGoal, array2, array1, lenght2, lenght1);    /* calling the recursive function */

    printf("%d\n", output);

    return 0;
}