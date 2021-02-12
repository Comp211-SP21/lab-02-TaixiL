#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char *argv[]){

	char binary[16];
	char numString[1000];
	int len = strlen(argv[1]);
	char sign = argv[1][0];
	int current = 0;
	char zero = 48;
	char one = 49;

	for (int i=1; i<len; i++)
		numString[i-1] = argv[1][i];

	for (int i=0; i<16; i++)
		binary[i] = 48;

	int count = atoi(numString);
	int num = count;

	if (count>32767 || count<-32768){
		printf("The signed 16-bit representation of %c%d is: not possible.\n", sign, count);
		return EXIT_SUCCESS;
	}
	binary[0] = (sign == 45) ? 49 : 48;

	if (sign == 45 && num != 0) {
		for (int i=0; i<16; i++)
			binary[i] = 49;
		current = 1;
		zero = 49;
		one = 48;
	}

	num = num - current;
	for (int i=15; i>0; i--) {
 		int power2 = 1;
		for (int j=i-1; j>0; j--)
			power2 = 2*power2;
		binary[16-i] = (power2<=num) ? one : zero;
		num = (binary[16-i]==one) ? (num-power2) : num;
	}

	printf("The signed 16-bit representation of %c%d is: ", sign, count);
	for (int i=0; i<16; i++)
		printf("%c", binary[i]);
	printf(".\n");
	return EXIT_SUCCESS;
}