#include <stdio.h>
#include <stdlib.h>

/* Write a program that prompts the user to type in the coordin-ates of two crossings and then prints the distance
between thesetwo locations in terms of the number of blocks between them */


int absval(int x) {
	return (x >= 0 ? x : -x);
}

int manhattanDistance(int x0, int y0, int x1, int y1) {
	return absval(x1 - x0) + absval(y1 - y0);
}


int main(int argc, char *argv[]) {
	int x0, y0, x1, y1;
	printf("First coordinates: ");
	scanf("%d %d", &x0, &y0);
	printf("Second coordinates: ");
	scanf("%d %d", &x1, &y1);
	
	printf("Manhattan distance between (%d, %d) and (%d, %d) is ", x0, y0, x1, y1);
	printf("%d blocks\n", manhattanDistance(x0, y0, x1, y1));
		
	return 0;
}
