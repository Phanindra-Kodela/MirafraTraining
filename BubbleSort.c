#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int* ptr2){
	
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void BubbleSort(const int size, int* list){
	
	// swap adjacent elements for n rounds.
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size-1; j++){
			if(list[j]>list[j+1]){
				swap(list+j, list+j+1);
			}
		}
	}
} 

int main(){

	int NoOfElements, *list;
	printf("This is a program on sorting given integers using bubble sort\n");
	printf("Enter the number of elements in the list: ");
	scanf("%d", &NoOfElements);
	
	// allocate memory of NoOfElements integers
	list = (int*)malloc(sizeof(int)*NoOfElements);

	// read the list of size NoOfElements
	printf("\nEnter the list: ");
        for(int i = 0; i < NoOfElements; i++)
		scanf("%d", list+i);	

	BubbleSort(NoOfElements, list);

	// print sorted list
	printf("After Sorting: ");
	for(int i = 0; i < NoOfElements; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
