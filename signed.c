#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int power2 (int power);

int main (int argc, char *argv[]){

	char binary[16];
	char numString[1000];
	int len = strlen(argv[1]);
	char sign = argv[1][0];

	for (int i=1; i<len; i++)
		numString[i-1] = argv[1][i];

	int count = atoi(numString);
	int num = count;

	if (count>32767 || count<-32767){
		printf("The signed 16-bit representation of %c%d is: not possible.\n", sign, num);
		return EXIT_SUCCESS;
	}

	binary[0] = (sign == 45) ? 49 : 48;

	for (int i=15; i>0; i--) {
		int power2Val = power2(i-1);
		binary[16-i] = (power2Val<=count) ? 49 : 48;
		count = (binary[16-i]==49) ? (count-power2Val) : count;
	}

	printf("The signed 16-bit representation of %c%d is: ", sign, num);
	for (int i=0; i<16; i++)
		printf("%c", binary[i]);
	printf(".\n");
	return EXIT_SUCCESS;
}



int power2 (int power) {
	int power2 = 1;
	for (int j=power; j>0; j--)
		power2 = 2*power2;
	return power2;
}