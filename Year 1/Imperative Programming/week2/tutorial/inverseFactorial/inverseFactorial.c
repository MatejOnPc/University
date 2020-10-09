#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b = 1, result = 1;
	
	printf("type a positive integer: ");
	scanf("%d", &a);
	
	while (b*(result+1) <= a) {
		result++;
		b = b * result;
	}
	
	printf("%d\n", result); 
		
	return 0;
}
