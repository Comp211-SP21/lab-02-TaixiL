#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char *argv[]){

	int index=31;
	char binary[32];
	int len = strlen(argv[1]);

	for (int i=0; i<len; i++)
		binary[i] = (argv[1][i]==48) ? argv[1][i]+1 : argv[1][i]-1;

	if (binary[31]==48)
		binary[31]=49;
	else {
		while (index>=0 && binary[index]==49) {
			binary[index]=48;
			index--;
		}
		if (index>=0 && binary[index]==48)
			binary[index]=49;
	}

	printf("The negation of the 32-bit two's complement integer %s is: ", argv[1]);
	for (int i=0; i<32; i++)
		printf("%c", binary[i]);
	printf(".\n");
	return EXIT_SUCCESS;
}