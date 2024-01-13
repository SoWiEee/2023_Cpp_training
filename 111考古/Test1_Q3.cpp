/*
 *	First,reads and saves all numbers in the 'input.txt' file of 'Q1'
 *	by fillArray(int a[], int size, int& numberUsed) function.
 *	The program uses selection sort algorithm to sort this array.
 *	Sorts array mainly used sort(int a[], int numberUsed) function.
 *	Uses indexOfSmallest(const int a[], int startIndex, int numberOFUsed)
 *	function to find smallest numbers and swap(int& v1, int& v2) function
 *	to change position.
*/

#include <iostream>		//Uses I/O library.
#include <String>		//Uses String.
#include <fstream>		//Reading and writing files.
using namespace std;	//Defines a namespace of 'std'.

void fillArray(int a[], int size, int& numberUsed);						//Reads and saves all numbers in the file.
void sort(int a[], int numberUsed);										//Uses selection sort algorithm to sort array.
int indexOfSmallest(const int a[], int startIndex, int numberOFUsed);	//Find the index of the smallest number in the array.
void swap(int& v1, int& v2);											//Swaps the position of two integers.

int main(void) {
	const int array_size = 200;	//Sets the size of integer's array is 200.
	int count_used = 0;			//Uses to count array usage space.
	int array_num[array_size];	//Stores the number in the file.

	fillArray(array_num, array_size, count_used);	//Reads file and saves all numbers in the file.

	//Outputs before sorting 'a' array on the screen.
	cout << "----------Before sorting arrays----------\n";
	for (int i = 0; i < count_used; i++) {
		cout << array_num[i];
		if (i != (count_used - 1))
			cout << "->";
	}
	cout << "\n";

	//Outputs after sorting  'a' array on the screen.
	cout << "----------After sorting arrays----------\n";
	sort(array_num, count_used);	//Selection sort algorithm.
	for (int i = 0; i < count_used; i++) {
		cout << array_num[i];
		if (i != (count_used - 1))
			cout << "->";
	}
	cout << "\n";

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

void sort(int a[], int numberUsed) {
	/*Selection sort algorithm.*/
	int index_smallest;		//Stores the index of the smallest number.
	for (int i = 0; i < numberUsed; i++) {					//Run from 0 to the end index of 'a' array.
		index_smallest = indexOfSmallest(a, i, numberUsed);	//Find the index of the smallest number in the array.
		swap(a[i], a[index_smallest]);						//Swaps the position of currect index and the index of the smallest number.
	}
}

int indexOfSmallest(const int a[], int startIndex, int numberOFUsed) {
	/*Find the index of the smallest number.*/
	int index_smallest = startIndex;	//Assumes currect index is the smallest number.
	for (int i = (startIndex + 1); i < numberOFUsed; i++) {
		if (a[index_smallest] > a[i])	//The current smallest number comparison with the numbers of after current index.
			index_smallest = i;
	}
	return index_smallest;	//Returns the index of the smallest number.
}

void swap(int& v1, int& v2) {
	/*Swaps the position of 'v1' integer and 'v2' integer.*/
	int swap_num = v1;	//Sortes 'v1' integer.
	v1 = v2;			//Sets 'v1' integer become to 'v2' integer.
	v2 = swap_num;		//Sets 'v2' integer become to 'swap_num' integer.
}
