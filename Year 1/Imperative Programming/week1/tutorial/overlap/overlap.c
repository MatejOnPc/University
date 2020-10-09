#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
	int x1, y1, r1;  /* center + radius first circle */
	int x2, y2, r2;  /* center + radius second circle */
	int dx, dy, r;   /* delta x, delta y, sum radius */
	
	printf("Center and radius 1st circle: ");
	scanf("%d %d %d", &x1, &y1, &r1);
	printf("Center and radius 2nd circle: ");
	scanf("%d %d %d", &x2, &y2, &r2);
	
	dx = x2 - x1;
	dy = y2 - y1;
	r = r1 + r2;
	
	if (dx*dx + dy*dy <= r*r) {
		printf("Overlap\n");
	} else {
		printf("No overlap\n");
	}
	
	return 0;
}
