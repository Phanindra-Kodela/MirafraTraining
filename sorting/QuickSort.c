#include <stdio.h>
#include <stdlib.h>

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

int NoOfComparisonsMade = 0;

void QuickSort(int left, int right, int* list){
	
	//Base Condition
	if(left >= right) return;

	// chose pivot first
	int pivot = list[left];

	// sort the array according to the pivot
	
	// find the nearest position which is greater than pivot.
	int i = left+1;
	while(i <= right && list[i] <= pivot) { NoOfComparisonsMade++; i++; }
	
	// there is no element greater than pivot so keep the pivot at the end
	if(i > right) {
		swap(&list[left], &list[right]);
		QuickSort(left, right-1, list);
		return;
	}

	// find the nearest position which is smaller than pivot.
	int j;
	for(j = left+1; j <= right; j++) { NoOfComparisonsMade++; if(list[j] < pivot) break; }

	// there is no element smaller than pivot so keep the pivot at the beginning
	if(j > right){
		QuickSort(left+1, right, list);
		return;
	}

	// move to the position where you need to move smaller elements before i
	j = i+1;
	while(j <= right){
		if(list[j] < pivot){
			swap(&list[j], &list[i]);
			i++;
		}
		j++;
	}

	// place the pivot before i position and quick sort onto left & right side of pivot
	
	swap(&list[i-1], &list[left]);
	QuickSort(left, i-2, list);
	QuickSort(i, right, list);
}

int main(){

	printf("This is a program on sorting given integers using Quick Sort\n");
	
	// read input size
	printf("Enter number of integers: ");
	int size, *list;
	scanf("%d", &size);

	//allocate the memory for the input size
	list = (int*)malloc(sizeof(int)*size);

	// read input
	printf("Enter the list: ");
	for(int i = 0; i < size; i++) scanf("%d", &list[i]);

	// call QuickSort function
	QuickSort(0, size-1, list);

	//print sorted list and no of comparisons made
	printf("Sorted list: ");
	for(int i = 0; i < size; i++) printf("%d ", list[i]);
	printf("\nNo of comparisons made: %d\n", NoOfComparisonsMade);

	// deallocate the used memory
	free(list);

	return 0;
}
