/* file    : quadraticSums.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Oct 11 2020 */
/* version : 1.0 */

/* Description:  This programm receives input n and outputs in how many different ways n can be expressed as a sum of squares */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* This function calculates square root of n, used for lenght of an array */
int squareRoot(int n) {
    int num = 0;
    for (int i = 1; i*i<=n; i++) {
        num++;
    }
    return num;
}

/* recursive function */
int sumOfSquares(int n, int sum, int x, int *s) {    /* n = input, sum = for storing sum, x = at first it is last index of array, *s = array */
    /* if x is less 0, check whether sum == n, if yes, then we add 1 to number of solutions */
    if (x < 0) {
        return (n == sum);
    }
    /* if sum is larger than what we want, there's no point in continuing with the recursive */
    if (sum > n) {
        return 0;
    }
    /* if sum == input, I want to add 1 to the number of solutions and stop the recursive */
    if (sum == n) {
        return 1;
    }
    /* there are two options, either the sum contains the number in array or it doesn't. Note that x becomes one less, so we move through all the numbers in array */
    return sumOfSquares(n, sum+s[x], x-1, s) + sumOfSquares(n, sum, x-1, s);
}

int main(int argc, char *argv[]) {
    int n;    /* input */
    int *array;    /* array of squares */
    int square;
    int output;

    scanf("%d", &n);
    square = squareRoot(n);

    array = dynamicArray(square);    /* I want the lenght to be some value x, 
    where x is equal to square root of input, because if I squared larger number, the sum would be more than n */

    /* Fill the array with squares */
    for (int i = 1; i <= square; i++) {
        array[i-1] = i*i;
    }
    
    output = sumOfSquares(n, 0, square-1, array);    /* calling the recursive function */

    printf("%d\n", output);

    return 0;
}