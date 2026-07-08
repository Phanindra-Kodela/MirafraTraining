#include <stdio.h>
#include <malloc.h>

void swap(int *ptr1, int *ptr2){

	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int* SelectionSort(const int size, int* list){

	// allocating space for two integers
	int *ptr = (int*)malloc(sizeof(int)*2);
	int NoOfComparisonsMade = 0, NoOfSwapsMade = 0;

	for(int i = 0; i < size; i++){
		
		int LeastSoFar = i;
		
		for(int j = i+1; j < size; j++){
			
			NoOfComparisonsMade++;
			if(list[LeastSoFar] > list[j])
				LeastSoFar = j;
		}
		
		if(i != LeastSoFar) { NoOfSwapsMade++; swap(&list[i], &list[LeastSoFar]); }
	}

	ptr[0] = NoOfComparisonsMade;
	ptr[1] = NoOfSwapsMade;

	return ptr;
}

int main(){

	int NoOfElements, *list;
        printf("This is a program on sorting given integers using selection sort\n");
        printf("Enter the number of elements in the list: ");
        scanf("%d", &NoOfElements);

        // allocate memory of NoOfElements integers
        list = (int*)malloc(sizeof(int)*NoOfElements);

        // read the list of size NoOfElements
        printf("\nEnter the list: ");
        for(int i = 0; i < NoOfElements; i++)
                scanf("%d", list+i);

        int *ptr = SelectionSort(NoOfElements, list);
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

	// deallocate the used memory
	free(list);
	free(ptr);

	return 0;
}
