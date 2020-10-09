#include <stdio.h>
#include <stdlib.h>

/* Write a program fragment that counts the number of indices k wherea [k]is maximal */

int maximum(int lenght, int a[]) {
	int max = a[0];
	for (int i = 1; i < length; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int maxima(int lenght, int a[], int k) {
	int count = 0;
	for (i = 0; i < lenght; i++) {
		if (i == k) {
			count += 1;
		}
	}
	return count;
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
