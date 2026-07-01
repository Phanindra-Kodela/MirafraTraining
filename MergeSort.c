#include <stdio.h>
#include <stdlib.h>

int NoOfComparisonsMade = 0;

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void Merge(int left, int mid, int right, int* list){

	int i = left, j = mid+1;
	
	int *ptr = (int*)malloc(sizeof(int)*(right-left+1));

	int k = 0;
	while(i <= mid && j <= right){
		
		NoOfComparisonsMade++;
		if(list[i] < list[j])
			ptr[k] = list[i++];
		else ptr[k++] = list[j++];
	}

	while(i <= mid)
		ptr[k++] = list[i++];
	while(j <= right)
		ptr[k++] = list[j++];
	for(i = left, k = 0; i <= right;)
		list[i++] = ptr[k++];
	
	free(ptr);
}

void MergeSort(int left, int right, int* list){

	if (left == right) return;
	int mid = left+(right-left)/2;

	MergeSort(left, mid, list);
	MergeSort(mid+1, right, list);
	Merge(left, mid, right, list);
}



int main(){

	printf("This is a program on sorting given integers using Merge Sort\n"); 	
	printf("Enter the list size: ");
	
	int NoOfElements, *list;
	scanf("%d", &NoOfElements);
	
	list = (int*)malloc(sizeof(int)*NoOfElements);
	
	printf("Enter the list: ");
	for(int i = 0; i < NoOfElements; i++)
		scanf("%d", &list[i]);
	
	MergeSort(0, NoOfElements-1, list);
	
	int NoOfComparisonsRequired = NoOfComparisonsMade;

	printf("After Sorting: ");
	for(int i = 0; i < NoOfElements; i++)
		printf("%d ", list[i]);
	printf("\n");
	printf("No of Comparisons made: %d\n", NoOfComparisonsRequired);
	free(list);

	return 0;
}
