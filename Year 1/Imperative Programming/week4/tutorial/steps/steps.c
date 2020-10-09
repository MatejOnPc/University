#include <stdio.h>
#include <stdlib.h>

/* Write a program fragment that counts the number of indices k for which a[k] < a[k+1] */

int numberOfSteps(int lenght, int a[]) {
	int count = 0;
	for (int i = 0; i < length-1; i++) {
		count += (a[i] < a[i+1]);
	}
	return count;
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
