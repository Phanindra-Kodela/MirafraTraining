#include <stdio.h>

int main(){
	int a = 5; // LSB: 0101, generally a = 0000 0000 0000 0101
	printf("Before a = %d\n", a);
	a = a | (1 << 1); // set 1st bit to 1 we have total of 32 bits, from 0th bit to 31st bit
			 // 0101 | 0010 = 0111
	printf("After setting 1st bit\n");
	printf("a = %d\n", a);
	return 0;
}
