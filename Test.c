/*
 ============================================================================
 Name        : NucleotideCounter.c
 Author      : Me
 Version     :
 Copyright   : Your copyright notice
 Description : Nucleotide Counter program in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.

	int aCount = 0; // variable that will hold the count for a
	int cCount = 0; // variable that will hold the count for c
	int gCount = 0; // variable that will hold the count for g
	int tCount = 0; // variable that will hold the count for t

	char inputFile[100]; // char array initialization
	char outputFile[100]; // char array initialization

	printf("Enter input filename: \n"); // prompt
	scanf("%s", inputFile);

	printf("Enter output filename: \n"); // prompt
	scanf("%s", outputFile);

	FILE *input;
	input = fopen(inputFile, "r"); // read into a file

	FILE *output;
	output = fopen(outputFile, "w"); // write into a file

	if (input == NULL) {
		return 0;
	}

	char buffer[BUFSIZ]; // buffer containing BUFSIZ bytes

	char nextChar;
	while (fscanf(input, "%c", &nextChar) != EOF) { // switch statement that determine which nucleotide count to increment
		switch (nextChar) {
		case 'A':
			++aCount;
			break;
		case 'C':
			++cCount;
			break;
		case 'G':
			++gCount;
			break;
		case 'T':
			++tCount;
			break;
		case '\n':
			fprintf(output, "%d %d %d %d\n", aCount, cCount, gCount, tCount);
			aCount = cCount = gCount = tCount = 0;
			break;
		default:
			break;
		}
	}

	fprintf(output, "%d %d %d %d\n", aCount, cCount, gCount, tCount);
	fflush(output); // flushes the output buffer of a stream

	fclose(input); // close the input file
	fclose(output); // close the output file
	printf("Complete\n"); // print complete to end the input user
}

