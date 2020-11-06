#include <stdio.h>
#include <stdlib.h>

/* This function creates dynamically allocated array, with size given as a parameter */
int *dynamicArray(int size) {
	int *array = malloc(size*sizeof(int));
	return array;
}

/* cretes new divided arrays to sort */
int *copySubArray(int left, int right, int arr[]) {
    int length = right - left;
    int *copy = malloc(length*sizeof(int));
    for (int i=0; i < length; i++) {
        copy[i] = arr[i + left];
    }
    return copy;
}

int binarySearch(int val, int len, int arr[]) {
    int left = 0, right = len;
    while (left < right) {
        int mid = (left + right)/2;
        if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int tooManyOccurances(int sorted[], int value, int k, int len) {
    int counter = 0;
    int index = binarySearch(value, len, sorted);

    while (counter < k && sorted[index] == value) {
        counter++;
        index++;
    }
    return(counter == k);
}

void merge(int lenA, int a[], int lenB, int b[], int arr[]) {
    int idx=0, l=0, r=0;

    /* sorts arrays until one of them was fully used */
    while ((l != lenA) && (r != lenB)) {
        if (a[l] <= b[r]) {
            arr[idx] = a[l];
            l++;
        } else {
            arr[idx] = b[r];
            r++;
        }
        idx++;
    }

    /* adds the rest to the sorted array */
    while (l != lenA) {
        arr[idx] = a[l];
        idx++;
        l++;
    }
    while (r != lenB) {
        arr[idx] = b[r];
        idx++;
        r++;
    }
}

void mergeSort(int length, int arr[]) {
    /* base case */
    if (length <= 1) {
        return;
    }
    /* recursive case */
    int mid = length/2;

    /* make two subarrays and sort recursively*/
    int *left = copySubArray(0, mid, arr);
    mergeSort(mid, left);
    int *right = copySubArray(mid, length, arr);
    mergeSort(length - mid, right);

    /* merge sorted arrays */
    merge(mid, left, length - mid, right, arr);

    /* free auxiliary memory */
    free(right);
    free(left);
}

int main(int argc, char *argv[]) {
    int n, k;
    int *array, *sorted;
    char skip;
    int first = 1;

    scanf("%d %d ", &n, &k);
    array = dynamicArray(n);
    sorted = dynamicArray(n);

    for (int i = 0; i < n; i++) {
        scanf("%c%d", &skip, &array[i]);
        sorted[i] = array[i];
    }

    mergeSort(n, sorted);

    for (int i = 0; i < n; i++) {
        if (!tooManyOccurances(sorted, array[i], k, n)) {
            if (!first) {
                printf(",");
            }
            first = 0;
            printf("%d", array[i]);
        }
    }
    printf("\n");

    free(array);
    free(sorted);

    return 0;
}