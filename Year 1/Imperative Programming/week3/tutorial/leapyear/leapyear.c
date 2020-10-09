#include <stdio.h>
#include <stdlib.h>

/* A year is aleap yearif it is divisible by 4, but not by 100. Exceptions are years that are divisibleby 400
 (these are leap years). Write a function isLeapYear that determines whether a year is a leap year or not */


int isLeapYear(int year) {
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int main(int argc, char *argv[]) {
	int a;
	
	scanf("%d", &a);
	if (isLeapYear(a)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}
