#include <stdio.h>
#include <stdlib.h>

int isEven(int digit) {
	if (digit % 2 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	int n;
	int sumOdd = 0;
	int sumEven = 0;
	int lastDigit;
	
	scanf("%d", &n);
	
	while (n != 0) {
		lastDigit = n%10;
		if (isEven(lastDigit)) {
			sumEven += lastDigit;
		} else {
			sumOdd += lastDigit;
		}
		n /= 10;
	}
	
	if (sumOdd == sumEven) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
