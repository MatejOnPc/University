#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
	int amount, remainder;
	
	printf("Price in cents: ");
	scanf("%d", &amount);
	
	remainder = amount % 5;
	amount = amount - remainder;
	if (remainder >= 3) {
		amount += 5;
	}
	
	printf("Rounded number of cents you have to pay is %d.\n", amount);
	
	return 0;
}
