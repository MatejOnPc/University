#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b, steps = 1, result = 0;
	
	printf("base: ");
	scanf("%d", &a);
	printf("integer: ");
	scanf("%d", &b);
	
	while (steps*a <= b) {
		result++;
		steps = steps * a;
	}
	
	printf("%d\n", result); 
		
	return 0;
}
