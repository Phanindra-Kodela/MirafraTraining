#include <stdio.h>

void binary(int x){

	int bit, start = 0;
	for(int i = sizeof(int)*8-1; i >= 0; i--){
		bit =  x>>i & 1;
		if(bit) start = 1;
		if(start)
			printf("%d", bit);
	}
	printf("\n");
}

int main(){

	int x;
	scanf("%d", &x);
	printf("Decimal: %d\n", x);
       	printf("Binary: ");
	binary(x);	
	return 0;
}
