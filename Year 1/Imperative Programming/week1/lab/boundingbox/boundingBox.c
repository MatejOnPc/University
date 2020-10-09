/* file    : boundingBox.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Sep 13 2020 */
/* version : 1.0 */

/* Description: This program finds smallest axes-aligned rectangle that surrounds the triangle given in input*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b, c, d, e, f; /* x and y coordinates of triangle */
	int minX, minY, maxX, maxY; /* x and y coordinates of the rectangle */
	
	scanf ("%d" "%d" "%d" "%d" "%d" "%d", &a, &b, &c, &d, &e, &f);
	
	minX = a;
	minY = b;
	maxX = a;
	maxY = b;
	
	if (c < minX) {
		minX = c;
		}
	if (e < minX) {
		minX = e;
		}
	if (c > maxX) {
		maxX = c;
		}
	if (e > maxX) {
		maxX = e;
		}
	
	if (d < minY) {
		minY = d;
		}
	if (f < minY) {
		minY = f;
		}
	if (d > maxY) {
		maxY = d;
		}
	if (f > maxY) {
		maxY = f;
		}
	
	printf("[(%d,%d),(%d,%d)]\n", minX, minY, maxX, maxY);
	
	return 0;
}
