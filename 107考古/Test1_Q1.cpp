#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int a[], int size, int &numberUsed);
int find_max(int a[], int size);
int find_min(int a[], int size);
const int Size = 200;

int main(){
	int Array[Size], numberUsed;
	int indexMax, indexMin;

	/*set the rand()*/
	srand((unsigned)time(NULL));
	
	/*set the array*/
	fillArray(Array, Size, numberUsed);
	
	/*find the index of max and min*/
	indexMax = find_max(Array, Size);
	indexMin = find_min(Array, Size); 

	/* show result */
	cout << "The max number in array is " << Array[indexMax] << " and the index is " << indexMax << endl;
	cout << "The min number in array is " << Array[indexMin] << " and the index is " << indexMin << endl;
	
	system("PAUSE");
	return 0;
}

/* fill array */
void fillArray(int a[], int size, int &numberUsed){
	int index = 0;

	for (index; index < Size; ++index){
		a[index] = rand() % 1101 + 11;
	}

	numberUsed = index;
		
}

int find_max(int a[], int size){
	int max = 0 ;
	int indexMax;

	for (int i = 0; i < size; ++i){
		if (a[i] > max){
			max = a[i];         //record the min
			indexMax = i;       //record the index of min
		}
	}

	return indexMax;
}


int find_min(int a[], int size){
	int min = 1112;
	int indexMin;

	for (int i = 0; i < size; ++i){
		if (a[i] < min){
			min = a[i];         //record the min
			indexMin = i;       //record the index of min
		}
	}
	return indexMin;
}
