/* This function creates resized histogram */
int *resizeHistogram(int oldSize, int *oldArray, int newSize) {
	int i, *newArray;
	newArray = dynamicArray(newSize);
	/* This for loop copies elements from old array to new array */
	for (i = 0; i < oldSize; i++) {
		newArray[i] = oldArray[i];
	}
	/* This loop fills new elemnts with 0 */
	for (i = oldSize-1; i < newSize; i++) {
		newArray[i] = 0;
	}
	free(oldArray);
	return newArray;
}



/* This function creates resized dynamically allocated array */
int *resizeDynamicArray(int oldSize, int *oldArray, int newSize) {
	int i, *newArray;
	newArray = dynamicArray(newSize);
	/* This for loop copies elements from old array to new array */
	for (i = 0; i < oldSize; i++) {
		newArray[i] = oldArray[i];
	}
	free(oldArray);
	return newArray;
}



int main(int argc, char *argv[]) {
	int x, a, c, m;
	int *array;
	int *histogram;    /* for representing how often each X was calculated, if some element becomes 2, there is a period */
	int size = 0;    /* size of an array */
	int position = 0;    /* passed into the function arrayContains, becomes the position of repetition */
	int period;
	int max = 0;
	
	scanf("%d %d %d %d", &x, &a, &c, &m);
	array = dynamicArray(size + 1);
	array[0] = x;
	
	histogram = dynamicArray(x + 1);    /* if x = 2, I want three elements, because I need index 2 */
	/* fills the histogram with 0 */
	for (int i = 0; i <= x; i++) {
		histogram[i] = 0;
	}
	max = x;
	histogram[x]++;
	
	/* repeats until period is found */
	while (1) {
		size += 1;
		array = resizeDynamicArray(size, array, size + 1);    /* makes the array one element longer */
		array[size] = nextNumber(x, a, c, m);    /* note that even though the lenght of new array is size + 1, index of last element is size */
		x = array[size];
		/* if x > max, I need to resize the histogram */
		if (x > max) {
			histogram = resizeHistogram(max+1, histogram, x+1);
			max = x;
		}
		histogram[x]++;
		/* if index X is equal to 2, there is a period */
		if (histogram[x] == 2) {
			/* finds the position of first occurance of X */
			for (int i = 0; i < size; i++) {
				if (array[i] == x) {
					position = i;
					break;
				}
			}
			period = size - position;
			break;
		}
	}
	printf("%d\n", period);
			
	return 0;
}
