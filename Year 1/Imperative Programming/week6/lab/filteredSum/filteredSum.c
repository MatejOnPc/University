/* file    : filteredSum.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Oct 18 2020 */
/* version : 1.0 */

/* Description: This program takes two lines of numbers as an input, and then it
prints the sum of numbers from second line that were also in th efirst line */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recursive function, finds whether the number is in the first line */
int recBinarySearch(int left, int right, int a[], int number) {
    int mid;

    /* base case */
    if (left == right - 1) {
         /* if the number was in the first line, returns the number, else it returns 0 (because I add the return value to the sum) */
        return (a[left] == number ? number : 0);
    }

    mid = (left + right)/2;
    
    /* changes left or right based on the number, so it stays in halved array */
    if (number < a[mid]){
        right = mid;
    } else {
        left = mid;
    }

    return recBinarySearch(left, right, a, number);
} 


int main(int argc, char *argv[]) {
    int number2ndLine;    /* used for the second line */
    int sum = 0;
    int lenght;    /* lenght of the first line */
    scanf("%d:", &lenght);

    /* create an array with lenght n, fill with the numbers from first line */
    int nInArray;
    int firstLine[lenght];
    for (int i = 0; i < lenght; i++) {
        scanf("%d", &nInArray);
        firstLine[i] = nInArray;
    }

    /* repeats until number in the second line = 0, if number is also in the first line, it gets added to the sum */
    do {
        scanf("%d", &number2ndLine);
        sum += recBinarySearch(0, lenght, firstLine, number2ndLine);
    } while (number2ndLine != 0);

    printf("%d\n", sum);

    return 0;
}