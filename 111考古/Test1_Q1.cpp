/*
 *	Randomly generates 166 integers between 7 and 1008.
 *	Than,outputs them to a text file,'input.txt'.
*/

#include <iostream>		//Uses I/O library.
#include <String>		//Uses String.
#include <fstream>		//Reading and writing files.
#include <time.h>		//Uses now time to set random seed.
using namespace std;	//Defines a namespace of 'std'.

int main(void) {
	const int Random_num = 166;						//Number of randomly generate.
	const int Random_start = 7;						//The number is the start number of random numbers range.
	const int Random_end = 1008;					//The number is the end number of random numbers range.
	const int range = Random_end - Random_start + 1;//Random range.
	const string filename = "input.txt";			//Sets file name.

	//Sets random seed.
	srand((unsigned)time(NULL));

	//Sets open file.
	fstream file;
	file.open(filename, ios::out);

	//Checking the file open successfully or failed.
	if (file.fail())
		cout << "Failed to open file!!\n";
	else {
		for (int i = 0; i < Random_num; i++) {		//Generates 166 random numbers.
			file << (rand() % range) + Random_start;//Writes random number to the file.
			if (i != (Random_num - 1))				//Determine last one.
				file << "\n";
		}
		file.close();								//Saves and closes the file
		cout << "Completed to write file!!\n";		//Prints to the screen.
	}

	system("PAUSE");	//Please 'pause' and return
	return(0);			//Return of the program.
}
