#include <stdio.h>
#include <stdlib.h>

int numOfDigits(int n) {
	int result = 0;
	while (n != 0) {
		result++;
		n /= 10;
	}
	return result;
}

int armstrongSum(int n, int lenght) {
	int sum = 0;
	int stepSum;
	int copyN = n;
	int digit;
	
	while (copyN != 0) {
		stepSum = 1;
		digit = copyN%10;
		
		for (int i = 1; i <= lenght; i++) {
			stepSum *= digit;
		}
		
		sum += stepSum;
		copyN /= 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	int n;
	int nOfD;
	int sum;
	int output;
	int i = 1;
	int repetition = 0;
	
	scanf("%d", &n);
	
	while (1) {
		
		nOfD = numOfDigits(i);
		sum = armstrongSum(i, nOfD);
		
		if (sum == i) {
			repetition++;
			if (repetition == n) {
				output = i;
				break;
			}
		}
		
		i++;
	}
	
	printf("%d\n", output);
	
	return 0;
}
