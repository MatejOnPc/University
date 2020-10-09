#include <stdio.h>
#include <stdlib.h>


int numberOfElements(int a[]) {
	int n = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i]) {
			n++;
		}
	}
	return n;
}


int main(int argc, char *argv[]) {
	int number;
	int lastDigit;
	int i = 0;
	int exponent;
	int numberCopy;
	int lenght = 0;
	
	scanf("%d", &number);
	numberCopy = number;
	
	while (numberCopy != 0) {
		numberCopy /= 10;
		lenght++;
	}
	
	numberCopy = number;
	int nArray[lenght];
	
	while (numberCopy != 0) {
		lastDigit = numberCopy % 10;
		nArray[lenght - 1 - i] = lastDigit;
		numberCopy /= 10;
		i++;
	}
	
	exponent = lenght - 1;
	
	printf("%d=", number);
	
	for (int j = 0; j < lenght; j++) {
		if ((nArray[j] != 0) && (j != 0)) {
			printf(" + ");
		}
		
		if (nArray[j] != 0) {
			printf("%d*10^%d", nArray[j], exponent);
		}
		
		exponent--;
	}
	printf("\n");
	
	return 0;
}

