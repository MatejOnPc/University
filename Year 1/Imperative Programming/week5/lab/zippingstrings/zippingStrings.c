/* file    : zippingStrings.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Oct 12 2020 */
/* version : 1.3 */

/* Description: This program receives 3 strings as an input and outputs whether it is
possible to produce the third string from the first two using n auxiliary letters */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* recursive function */
int merge(int i, int x, int y, int n, char *aG, char *a1, char *a2, int lenght, int lenght1, int lenght2) {    /* i is used as index of arrayGoal, x of array1 and y of array2 */
    
    for (int j = 0; j == 0; j++) {    /* I want to break out of the loop if I found the letter in one of the strings */
        if (i == lenght) {    /* base case */
            if (lenght1 == x && lenght2 == y) {    /* checks whether I used all the letters from strings 1 and 2 */
                return 1;
            } else {
                return 0;
            }
        }

        if (aG[i] == a1[x]) {    /* I used letter from array1, so x++ */
            x++;
            break;
        }

        if (aG[i] == a2[y]) {    /* I used letter from array2, so y++ */
            y++;
            break;
        }

        /* If I can't use next letter from string 1 or 2, use auxiliary letter */
        if ((aG[i] != a1[x]) && (aG[i] != a2[y])) {
            if (n > 0) {    /* Checks whether I can still use n */
                n--;
                break;
            } else {
                return 0;
            }
        }
    }
    i++;
    merge(i, x, y, n, aG, a1, a2, lenght, lenght1, lenght2);    /* recursive call */
}

int main(int argc, char *argv[]) {
    int n;    /* number of auxiliary letters */
    char array1[33], array2[33], arrayGoal[33];    /* arrays for strings, lenght is 33 because I need to count for '\0' */
    int lenght;
    int lenght1, lenght2;

    scanf("%d %s %s %s", &n, array1, array2, arrayGoal);
    lenght = strlen(arrayGoal);
    lenght1 = strlen(array1);
    lenght2 = strlen(array2);

    /* checks whether it's possible to fotm the last word based on the number of letters in each string and n */
    if ((lenght1 + lenght2 + n >= lenght) && (lenght1 + lenght2 <= lenght)) {
        /* If at least one is true, return 1. I swap the arrays 1 and 2, so I can go over all the possibilities */
        if ((merge(0, 0, 0, n, arrayGoal, array1, array2, lenght, lenght1, lenght2)) || (merge(0, 0, 0, n, arrayGoal, array2, array1, lenght, lenght2, lenght1))) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }
    
    return 0;
}