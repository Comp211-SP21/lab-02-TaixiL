#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void setDefaultTo (char origin[], char tar);
int power2 (int power);

int main (int argc, char *argv[]){

	char binary[16];
	char numString[1000];
	int len = strlen(argv[1]);
	char sign = argv[1][0];
	int startVal = 0;
	char zero = 48;
	char one = 49;
	setDefaultTo(binary, zero);

	for (int i=1; i<len; i++)
		numString[i-1] = argv[1][i];

	
	int count = atoi(numString);
	int num = count;

	if (count>32767 || count<-32768){
		printf("The two's complement 16-bit representation of %c%d is: not possible.\n", sign, count);
		return EXIT_SUCCESS;
	}

	int checkNonNegative = (sign==45 && num!=0) ? 1 : 0;
	binary[0] = (checkNonNegative==1) ? 49 : 48;

	if (checkNonNegative==1) {
		setDefaultTo(binary, one);
		startVal = 1;
		zero = 49;
		one = 48;
	}

	num = num - startVal;
	for (int i=15; i>0; i--) {
		int power2Val = power2(i-1);
		binary[16-i] = (power2Val<=num) ? one : zero;
		num = (binary[16-i]==one) ? (num-power2Val) : num;
	}

	printf("The two's complement 16-bit representation of %c%d is: ", sign, count);
	for (int i=0; i<16; i++)
		printf("%c", binary[i]);
	printf(".\n");
	return EXIT_SUCCESS;
}



void setDefaultTo (char origin[], char tar) {
	if (tar==48) {
		for (int i=0; i<16; i++)
			origin[i] = 48;
	} else {
		for (int i=0; i<16; i++)
			origin[i] = 49;
	}
}

int power2 (int power) {
	int power2 = 1;
	for (int j=power; j>0; j--)
		power2 = 2*power2;
	return power2;
}