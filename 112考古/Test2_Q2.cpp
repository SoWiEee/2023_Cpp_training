#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *inputFile;	/*		input - pointer to input file					*/
	FILE *outputFile;	/*		output - pointer to output file					*/
	int hit = 0;		/*		number of hits 									*/
	int out = 0;		/*		number of outs									*/
	char c;				/*		store the character reading from input file		*/
	
	/*	prepare file for input	*/
	inputFile = fopen("BATTING.IN", "r");

	/*	check input file exists or not	*/
	if (!inputFile)
	{
		printf("Input file is not exist.\n");
		system("pause");
		exit(1);
	}

	/*	prepare file for output		*/
	outputFile = fopen("BATTING.OUT", "w");
	
	/*	read the record of players
		calculate batting average and write to the output file	*/
	do {
		c = fgetc(inputFile);
		switch (c)
		{
		case 'H':
			hit++;
			fputc(c, outputFile);
			break;
		case 'O':
			out++;
			fputc(c, outputFile);
			break;
		case '\n':
			if (hit + out == 0) {
				printf("Division by zero.\n");
				system("pause");
				exit(1);
			}
			else {
				fprintf(outputFile, " %f\n", hit*1.0 / (hit + out));
				hit = 0;
				out = 0;
			}			
			break;
		case EOF:
			if (hit + out == 0) {
				printf("Division by zero.\n");
				system("pause");
				exit(1);
			}
			else {
				fprintf(outputFile, " %f", hit*1.0 / (hit + out));
				hit = 0;
				out = 0;
			}
			break;
		default:
			fputc(c, outputFile);
		}
	} while (c != EOF);

	/*	close the files		*/
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}