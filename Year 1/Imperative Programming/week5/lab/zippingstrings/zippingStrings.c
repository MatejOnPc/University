/* file    : zippingStrings.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* recursive function */
void merge(int i, int n, char *aM, char *aG, char *a1, char *a2, int lenght1, int lenght2) {
    /* char newString[33]; */
    printf("aM = %s\n", aM);
    printf("aG = %s\n", aG);

    if (aG == aM) {
        printf("YES\n");
    }

    printf("aG[i] = %c, a1[0] = %c and a2[0] = %c\n", aG[i], a1[0], a2[0]);
    if ((aG[i] == a1[0]) && (lenght1 >= 0)) {
        aM[i] = a1[0];
        printf("aM[i] = %c\n", aM[i]);
        for (int j = 0; j < lenght1 - 1; j++) {
            a1[j] = a1[j+1];
        }
        a1[lenght1-1] = '\0';
        printf("new string = %s\n", a1);
        lenght1--;
        i++;
        printf("lenght1 = %d\n", lenght1);
        merge(i, n, aM, aG, a1, a2, lenght1, lenght2);
    }

    if ((aG[i] == a2[0]) && (lenght2 >= 0)) {
        aM[i] = a2[0];
        printf("aM[i] = %c\n", aM[i]);
        for (int j = 0; j < lenght2 - 1; j++) {
            a2[j] = a2[j+1];
        }
        a2[lenght2-1] = '\0';
        printf("new string = %s\n", a2);
        lenght2--;
        i++;
        printf("lenght2 = %d\n", lenght2);
        merge(i, n, aM, aG, a1, a2, lenght1, lenght2);
    }

    if ((aG[i] != a1[0]) && (aG[i] != a2[0])) {
        if (n > 0) {
            aM[i] = aG[i];
            n--;
            i++;
            merge(i, n, aM, aG, a1, a2, lenght1, lenght2);
        } else {
            return;
        }
    }
    /*
    printf("i = %d, aM = %s, a1 = %s, n = %d\n", i, aM, a1, n); */
}

int main(int argc, char *argv[]) {
    int n;    /* number of auxiliary letters */
    char array1[33], array2[33], arrayGoal[34];    /* arrays for strings, lenght is 33 because I need to count for '\0' */
    char arrayMerged[33];    /* for saving the merged words */
    arrayMerged[0] = '\0';
    /* int output; */
    int lenght1, lenght2;

    scanf("%d", &n);
    scanf("%s", array1);
    scanf("%s", array2);
    scanf("%s", arrayGoal);

    printf("%d, %s, %s, %s\n",  n, array1, array2, arrayGoal);

    lenght1 = strlen(array1);
    lenght2 = strlen(array2);

    merge(0, n, arrayMerged, arrayGoal, array1, array2, lenght1, lenght2);
    /* + merge(0, n, arrayMerged, arrayGoal, array2, array1, lenght2, lenght1); */   /* calling the recursive function */

    /* printf("%d\n", output); */

    return 0;
}