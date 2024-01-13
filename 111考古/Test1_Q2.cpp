/*
 *	First,reads and saves all numbers in the 'input.txt' file of 'Q1'
 *	by fillArray(int a[], int size, int& numberUsed) function.
 *	Than,finds the indices of maximum and minimum numbers by find_max()
 *	and find_min() functions.And outputs their indices and numbers to
 *	the screen.
*/

#include <iostream>		//Uses I/O library.
#include <String>		//Uses String.
#include <fstream>		//Reading and writing files.
using namespace std;	//Defines a namespace of 'std'.

void fillArray(int a[], int size, int& numberUsed);	//Reads and saves all numbers in the file.
int find_max(int a[], int numberUsed);				//Find maximum number's index from the array.
int find_min(int a[], int numberUsed);				//Find minimum number's index from the array.

int main(void) {
	const int array_size = 200;	//Sets the size of integer's array is 200.
	int count_used = 0;			//Uses to count array usage space.
	int array_num[array_size];	//Stores the number in the file.
	int max_index, min_index;	//Stores the index of the maximum and minimum number in the array.

	fillArray(array_num, array_size, count_used);	//Reads file and saves all numbers in the file.
	max_index = find_max(array_num, count_used);	//Find maximum number's index from the 'array_num' array.
	min_index = find_min(array_num, count_used);	//Find minimum number's index from the 'array_num' array.

	//Outputs max and min numbers to the screen.
	cout << "Max_number = " << array_num[max_index] << ", Max_index = " << max_index << "\n";
	cout << "Min_number = " << array_num[min_index] << ", Min_index = " << min_index << "\n";

	system("PAUSE");	//Please 'pause' and return
	return(0);			//Return of the program.
}

void fillArray(int a[], int size, int& numberUsed) {
	/*Reads and stores all numbers in the 'input.txt' file.*/
	const string filename = "input.txt";	//Set file name 'input.txt'.

	//Sets open file.
	fstream file;
	file.open(filename, ios::in);

	//Checking the file open successfully or failed.
	if (file.fail()) {
		cout << "Failed to open file!!\n";
		system("PAUSE");
		exit(0);	//Fail to open file.
	}
	else {
		cout << "Read input.txt file...\n";
		do {
			file >> a[numberUsed];					//Reads numbers and stores it in the 'a' array.
			numberUsed++;							//Counts 'a' array's usage space.
		} while (!file.eof() && numberUsed < size);	//Checks file eof.
		cout << "Completed to read file!!\n";
		file.close();								//Saves and closes the file
	}
}

int find_max(int a[], int numberUsed) {
	/*Finds maximum number's index.*/
	int max = 0;			//Set maximum number to the '0' index of the 'a' array.
	for (int i = 1; i < numberUsed; i++) {
		if (a[i] > a[max])	//Finds and comparisons all numbers in the 'a' array.
			max = i;
	}
	return max;				//Return maximum number's index.
}

int find_min(int a[], int numberUsed) {
	/*Finds minimum number's index.*/
	int min = 0;			//Set minimum number to the '0' index of the 'a' array.
	for (int i = 1; i < numberUsed; i++) {
		if (a[i] < a[min])	//Finds and comparisons all numbers in the 'a' array
			min = i;
	}
	return min;				//Return minimum number's index.
}
