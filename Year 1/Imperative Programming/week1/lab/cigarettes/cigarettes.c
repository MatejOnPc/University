/* file    : hello.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : SUN Sep 13 2020 */
/* version : 1.0 */

/* Description: This program finds how many cigarettes can a man make based on the number of found cigarette butts */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int butts, cigarettes;
	
	scanf("%d", &butts);
	cigarettes = (butts - 1) / 3;
	printf("%d\n", cigarettes);
	
	return 0;
}
