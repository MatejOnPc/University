#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
	int side;	/* lenght side of cube */
	int width, height, depth;	/* dimensions box */
	int max;	/* maximum number of cubes that fit */
	
	printf("side lenght cube: ");
	scanf("%d", &side);
	printf("width box: ");
	scanf("%d", &width);
	printf("height box: ");
	scanf("%d", &height);
	printf("depth box: ");
	scanf("%d", &depth);
	
	max = (width/side)*(height/side)*(depth/side);
	printf("At most %d cubes fit in the box.\n", max);
	return 0;
}
