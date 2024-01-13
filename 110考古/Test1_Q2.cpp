#include<iostream>
#include<fstream>
using namespace std;

const int number_size = 300;

void fillArray(int a[], int size, int& numberUsed);
int find_max(const int a[], int numberUsed);
int find_min(const int a[], int numberUsed);

int main()
{

	int number[number_size];
	int numberUsed;
	int max_index, min_index;

	fillArray(number, number_size, numberUsed);
	max_index = find_max(number, numberUsed);
	min_index = find_min(number, numberUsed);

	//Output the maximum, minimum, and their indices.
	cout << "Maximum >> index " << max_index << " : " << number[max_index] << endl;
	cout << "Minimum >> index " << min_index << " : " << number[min_index] << endl;

	system("PAUSE");
	return 0;
}

//Implement the partial array.
void fillArray(int a[], int size, int& numberUsed)
{
	int num = 200;
	numberUsed = num;

	ifstream inputStream;

	inputStream.open("input.txt");       //Open file.

										 //Check file exist.
	if (!inputStream) {

		cout << "file no exist!" << endl;
		exit(1);

	}

	for (int i = 0; i < size; i++)
	{
		if (i < numberUsed)
		{
			inputStream >> a[i];
		}
		else
		{
			a[i] = 0;
		}
	}
	inputStream.close();                  //Close file.

}

//Find maximum number.
int find_max(const int a[], int numberUsed)
{
	int max_index = 0;

	for (int i = 1; i < numberUsed; i++)
	{
		if (a[i] > a[max_index])
		{
			max_index = i;
		}
	}

	return (max_index);
}

//Find minimum number.
int find_min(const int a[], int numberUsed)
{
	int min_index = 0;

	for (int i = 1; i < numberUsed; i++)
	{
		if (a[i] < a[min_index])
		{
			min_index = i;
		}
	}

	return (min_index);
}