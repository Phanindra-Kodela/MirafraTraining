#include <stdio.h>
#include <malloc.h>

void swap(int *ptr1, int *ptr2){
	
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int* InsertionSort(const int size, int* list){

	int *ptr = (int*)malloc(sizeof(int)*2);
	int NoOfComparisonsMade = 0, NoOfSwapsMade = 0;
	
	for(int i = 1; i < size; i++){
		
		int j = i;

		NoOfComparisonsMade++;
		
	        while(j > 0 && list[j] < list[j-1]){
			
			NoOfComparisonsMade++;
			swap(&list[j], &list[j-1]);
			NoOfSwapsMade++;
			j--;
		}
	}

	ptr[0] = NoOfComparisonsMade;
	ptr[1] = NoOfSwapsMade;
	return ptr;
}

int main(){

	int NoOfElements, *list;
	printf("This is a program on sorting given integers using insertion sort\n");
	printf("Enter the number of elements in the list: ");
	scanf("%d", &NoOfElements);
	
	// allocate memory of NoOfElements integers
	list = (int*)malloc(sizeof(int)*NoOfElements);

	// read the list of size NoOfElements
	printf("\nEnter the list: ");
        for(int i = 0; i < NoOfElements; i++)
		scanf("%d", list+i);	

	int *ptr = InsertionSort(NoOfElements, list);
	int NoOfComparisonsRequired = ptr[0];
	int NoOfSwapsRequired = ptr[1];

	// print sorted list
	printf("After Sorting: ");
	for(int i = 0; i < NoOfElements; i++){
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("No of Comparisons: %d\n", NoOfComparisonsRequired);
	printf("No of Swaps: %d\n", NoOfSwapsRequired);

	free(list);
	free(ptr);
	return 0;
}
