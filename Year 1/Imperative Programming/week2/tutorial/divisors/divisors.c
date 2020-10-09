#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int number;
	
	printf("type a positive integer: ");
	scanf("%d", &number);
	
	for (int divisor = 1; divisor <= number/2; divisor++) {
		if (number % divisor == 0) {
			printf("%d ", divisor);
		}
	}
	
	printf("%d\n", number); /*each number divides itself*/
	
	return 0;
}
