#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b, result = 1;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	while (b > 0) {
		result = result * a;
		b--;
	}
	
	printf("%d\n", result); 
		
	return 0;
}
