#include <stdio.h>
#include <stdlib.h>

int checkColor(int a[], int n) {
	for (int i = 0; i < 18; i++) {
		if (a[i] == n) {
			return 1;
		}
	}
	return 0;
}



int main(int argc, char *argv[]) {
	int budget;
	int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	int bet = 1;
	int n;
	int print = 1;
	
	scanf("%d", &budget);
	scanf("%d", &n);
	
	while (n != -1) {		
		budget -= bet;
		
		if (checkColor(red, n)) {
			budget += 2*bet;
			bet = 1;
		} else {
			bet *= 2;
		}
		
		if (budget - bet < 0) {
			printf("BUST\n");
			print = 0;
			break;
		}
		
		scanf("%d", &n);
	}
	
	if (print) {
		printf("%d\n", budget);
	}

	return 0;
}
