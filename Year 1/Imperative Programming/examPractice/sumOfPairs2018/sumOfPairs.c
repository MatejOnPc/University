#include <stdio.h>
#include <stdlib.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}


int main(int argc, char *argv[]) {
    int n, i;
    int scannedN;
    int hisotgram[1000], array[1000];
    int print = 1;
    int length = 0;

    scanf("%d %d", &n, &scannedN);

    for (i = 0; i <= 1000; i++) {
        hisotgram[i] = 0;
    }

    while (scannedN != 0) {
        hisotgram[scannedN]++;
        scanf("%d", &scannedN);
    }

    for (i = 0; i <= 1000; i++) {
        if (hisotgram[i] > 0) {
            array[length] = i;
            length++;
        }
    }

    for (i = 0; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            if (array[i] + array[j] == n) {
                printf("%d+%d\n", array[i], array[j]);
                print = 0;
            }
            if (array[i] + array[j] > n) {
                break;
            }
        }
    }

    if (print) {
        printf("NONE\n");
    }

    return 0;
}