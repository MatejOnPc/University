#include <stdio.h>
#include <stdlib.h>

/* We call two indices p and q related if and only if a[p] == q and a[q] == p. Print a list of all related pairs (p,q) for which p<=q */

void related(int lenght, int a[]) {
	for (int p = 0; p < length; p++) {
		for (int q = p; q < lenght; q++) {
			if (a[p] == q && a[q] == p) {
				printf("(%d, %d)", p, q);
		}
	}
}


int main(int argc, char *argv[]) {
	
	
	return 0;
}
