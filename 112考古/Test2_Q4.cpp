#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define matrixSize 8

int main() {
	int row = 0;			/*		input - the row of the input coordinate			*/
	int column = 0;			/*		input - the column of the input coordinate		*/
	bool valid = false;		/*		whether the input is valid or not				*/
	bool first = true;		/*		is the first output coordinate or not			*/

	/*	read a coordinate	*/
	do
	{
		printf("Input a coordinate (row,column) as two integers separated by a space.=>");
		scanf("%d%d", &row, &column);
		if ((row >= 0 && row < matrixSize) && (column >= 0 && column < matrixSize))
			valid = true;
		else
			printf("Input invalid!!\n");
	} while (!valid);
	
	/*	print all coordinates at vertical line excluding input itself	*/
	printf("Vertical: ");
	for (int i = 0; i < matrixSize; i++) {
		if (!first&&i != row)
			printf(",");
		if (i != row) {
			printf("(%d,%d)", i, column);
			first = false;
		}		
	}
	printf("\n");
	first = true;
	
	/*	print all coordinates at horizontal line excluding input itself		*/
	printf("Horizontal: ");
	for (int i = 0; i < matrixSize; i++) {
		if (!first&&i != column)
			printf(",");
		if (i != column) {
			printf("(%d,%d)", row, i);
			first = false;
		}
	}
	printf("\n");
	first = true;

	/*	print all coordinates at 45 degree diagonal line excluding input itself		*/
	printf("45 degree diagonal: ");
	if (row + column < matrixSize) {
		for (int i = row + column; i >= 0; i--) {
			if (!first&&i != row)
				printf(",");
			if (i != row) {
				printf("(%d,%d)", i, row + column - i);
				first = false;
			}
		}
	}
	else {
		for (int i = matrixSize - 1; i > row + column - matrixSize; i--) {
			if (!first&&i != row)
				printf(",");
			if (i != row) {
				printf("(%d,%d)", i, row + column - i);
				first = false;
			}
		}
	}
	printf("\n");
	first = true;

	/*	print all coordinates at 135 degree diagonal line excluding input itself	*/
	printf("135 degree diagonal: ");
	if (row >= column) {
		for (int i = row - column; i < matrixSize; i++) {
			if (!first&&i != row)
				printf(",");
			if (i != row) {
				printf("(%d,%d)", i, i - (row - column));
				first = false;
			}
		}
	}
	else {
		for (int i = column - row; i < matrixSize; i++) {
			if (!first&&i != column)
				printf(",");
			if (i != column) {
				printf("(%d,%d)", i - (column - row), i);
				first = false;
			}
		}
	}
	printf("\n");

	system("pause");
	return 0;
}