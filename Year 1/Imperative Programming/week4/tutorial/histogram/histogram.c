#include <stdio.h>
#include <stdlib.h>

/* Assume that the array a contains only decimal digits. Count for every digit k the number of occurences of the digit k in the array a and store it in h[k]. */


void histogram(int lenght, int a[], int freq[10]) {
	int i;
	for (i = 0; i < 10; i++) {
		freq[i] = 0
	}
	for (i = 0; i < lenght; i++) {
		freq[a[i]]++;
	}
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
