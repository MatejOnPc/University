/* file    : examhall.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : WED Sep 9 2020 */
/* version : 1.0 */

/* Description: This program computes how many students can do exam at the same time*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int side;	/* square space of side*side */
	int width, depth;	/* dimensions of total floor size */
	int students;	/* number of students that can take the exam */
	
	scanf("%d %d %d", &side, &width, &depth);	
	students = (width/side)*(depth/side);
	printf("%d\n", students);
	
	return 0;
}
