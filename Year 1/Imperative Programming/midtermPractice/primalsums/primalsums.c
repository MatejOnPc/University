#include <stdio.h>
#include <stdlib.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* This function creates resized dynamically allocated array */
int *resizeDynamicArray(int oldSize, int *oldArray, int newSize) {
	int i, *newArray;
	newArray = dynamicArray(newSize);
	/* This for loop copies elements from old array to new array */
	for (i = 0; i < oldSize; i++) {
		newArray[i] = oldArray[i];
	}
	free(oldArray);
	return newArray;
}


int isPrime(int n) {
	if (n == 1) {
		return 0;
	}
	
	if ((n == 2) || (n == 3)) {
		return 1;
	}
	
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int a;
	int b;
	int k = 2;
	int index = 0;
	int repetitions = 0;
	int *primes;
	int size = 0;
	int n = 0;
	int sumOfPrimes = 0;
	int sum;
	
	primes = dynamicArray(size);
		
	scanf("%d", &a);
	scanf("%d", &b);
	
	while (sumOfPrimes < b) {
		if (isPrime(k)) {
			primes = resizeDynamicArray(size, primes, size + 1);
			size++;
			primes[index] = k;
			sumOfPrimes += k;
			index++;
		}
		k++;
	}
	
	while (index <= size + 1) {
		index = repetitions;
		sum = 0;
		while (sum <= b) {
			sum += primes[index];
			if (isPrime(sum)) {
				n++;
			}
			index++;
		}
		repetitions++;
	}
	
	printf("%d\n", n);
	
	return 0;
}

