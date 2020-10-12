/* file    : zippingStrings.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Oct 12 2020 */
/* version : 1.1 */

/* Description: This program receives 3 strings as an input and outputs whether it is
possible to produce the third string from the first two using n auxiliary letters */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* recursive function */
int merge(int i, int x, int y, int n, char *aG, char *a1, char *a2, int lenght) {    /* i is used as index of arrayGoal, x of array1 and y of array2 */
    
    for (int j = 0; j == 0; j++) {    /* I want to break out of the loop if I found the letter in one of the strings */
        if (i == lenght-1) {
            return 1;
        }

        if (aG[i] == a1[x]) {
            x++;
            break;
        }

        if (aG[i] == a2[y]) {
            y++;
            break;
        }

        if ((aG[i] != a1[x]) && (aG[i] != a2[y])) {
            if (n > 0) {
                n--;
                break;
            } else {
                return 0;
            }
        }
    }
    i++;
    merge(i, x, y, n, aG, a1, a2, lenght);
}

int main(int argc, char *argv[]) {
    int n;    /* number of auxiliary letters */
    char array1[33], array2[33], arrayGoal[33];    /* arrays for strings, lenght is 33 because I need to count for '\0' */
    int lenght;

    scanf("%d %s %s %s", &n, array1, array2, arrayGoal);
    lenght = strlen(arrayGoal);

    if (strlen(array1) + strlen(array2) + n == lenght) {
        merge(0, 0, 0, n, arrayGoal, array1, array2, lenght);    /* calling the recursive function */
    } else {
        printf("NO\n");
    }

    if ((merge(0, 0, 0, n, arrayGoal, array1, array2, lenght)) || (merge(0, 0, 0, n, arrayGoal, array2, array1, lenght))) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}