/*
 *	The program will use point array to be a dynamic 2D array,it defines a size 6 point array.
 *	Than assigns each point array's size and gives number.
 *	When it prints irregular 2D array on the screen,finds maximum and minimum elements.
 *	Finaly,counts number of all elements and computes average in the 2D array.
 *	Prints information on the screen.
*/

#include <iostream>		//Uses I/O library.
using namespace std;	//Defines a namespace of 'std'.

int main(void) {
	const int column = 6;					//The number of column.
	const int length[] = { 5,2,4,1,6,3 };	//Each column's size.
	int **array = new int*[column];			//Sets dynamic 2D array.
	int Count_Elements = 0, Total_num = 0;	//Used to count the number and sum of all elements.
	double Average = 0.0;					//Stores the average of all elements.
	int Max_col = 0, Max_row = 0, Min_col = 0, Min_row = 0;	//Stores index number.

	//Assigns each point array's object size.
	for (int i = 0; i < column; i++) {
		array[i] = new int[length[i]];
		Count_Elements += length[i];
	}

	//Sets 1-th column.
	array[0][0] = 83;
	array[0][1] = 12;
	array[0][2] = 64;
	array[0][3] = 23;
	array[0][4] = 5;
	//Sets 2-th column.
	array[1][0] = 62;
	array[1][1] = 37;
	//Sets 3-th column.
	array[2][0] = 59;
	array[2][1] = 45;
	array[2][2] = 78;
	array[2][3] = 90;
	//Sets 4-th column.
	array[3][0] = 83;
	//Sets 5-th column.
	array[4][0] = 66;
	array[4][1] = 30;
	array[4][2] = 45;
	array[4][3] = 80;
	array[4][4] = 2;
	array[4][5] = 96;
	//Sets 6-th column.
	array[5][0] = 33;
	array[5][1] = 69;
	array[5][2] = 75;

	//Prints 2D array on the screen.
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < length[i]; j++) {
			cout << array[i][j] << " ";
			Total_num += array[i][j];
			if (array[i][j] > array[Max_col][Max_row]) {
				Max_col = i;
				Max_row = j;
			}
			if (array[i][j] < array[Min_col][Min_row]) {
				Min_col = i;
				Min_row = j;
			}
		}
		cout << "\n";
	}

	//Computes average of all elements.
	Average = (double) Total_num / Count_Elements;

	//Prints the number of elements in the 2D array.
	cout << "The number of elements : " << Count_Elements << "\n";

	//Prints the average of all elements.
	cout << "The average of elements : " << Average << "\n";

	//Prints the maximum's and the minimum's index and number in the 2D array.
	cout << "The maximum element : " << array[Max_col][Max_row] << "\n";
	cout << "The maximum's index: (" << Max_col << ", " << Max_row << ")\n";
	cout << "The minimum element : " << array[Min_col][Min_row] << "\n";
	cout << "The minimum's index: (" << Min_col << ", " << Min_row << ")\n";

	//Deallocates array's memory.
	for (int i = 0; i < column; i++)
		delete[] array[i];
	delete[] array;

	system("PAUSE");	//Please 'pause' and return
	return 0;			//Return of the program.
}