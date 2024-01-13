#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

const int number_size = 200;

int main()
{

	int number[number_size];
	ofstream outputStream;

	outputStream.open("input.txt");       //Open file.

										  //Check file exist.
	if (!outputStream) {

		cout << "file no exist!" << endl;
		exit(1);

	}

	srand(time(NULL));

	for (int i = 0; i < number_size; i++)
	{
		number[i] = rand() % 1101 + 11;    //Randomly generate 200 integers between 11 and 1111.
		outputStream << number[i] << endl; //Save integers as a text file named "input.txt".
	}

	outputStream.close();                  //Close file.

	system("PAUSE");
	return 0;
}