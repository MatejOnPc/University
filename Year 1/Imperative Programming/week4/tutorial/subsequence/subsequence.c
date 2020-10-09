#include <stdio.h>
#include <stdlib.h>

/* Write a program fragment that computes the length of the longest increasing (sub)sequence in the array a. */

int longestIncSequence(int lenght, int a[]) {
	int max = 0;
	int seqLenght = 1;
	for (int i = 0; i < length-1; i++) {
		if (a[i] < a[i+1]) {
			seqLenght++;
			if (seqLenght > max) {
				max = seqLenght;
			}
		} else {
			seqLenght = 1;
	}
	return max;
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
