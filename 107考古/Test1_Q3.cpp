#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort(int a[], int numberUsed);
int indexOfSmallest(const int a[], int startIndex, int numberUsed);
void swap(int &v1, int &v2);
const int Size = 50;
const int numberUsed = 20;

int main(){
	int Array[Size];

	/* set rand() */
	srand((unsigned)time(NULL));

	/* partial fill array */
	for (int i = 0; i < Size; ++i){
		if (i >= numberUsed){
			Array[i] = 0;
		}
		else
			Array[i] = rand() % 101 - 50;
	}

	/* show the array */
	cout << "Before :" << endl;
	for (int i = 0; i < numberUsed; ++i)
		cout << Array[i] << " ";

	/* sorting array */
	sort(Array, numberUsed);

	/* show the result */
	cout << endl << endl << "After :" << endl;
	for (int i = 0; i < numberUsed; ++i)
		cout << Array[i] << " ";

	cout << endl;

	system("PAUSE");
	return 0;
}

/* sort */
void sort(int a[], int numberUsed){
	int index;	/* return index */

	for (int i = 0; i < numberUsed - 1; ++i){
		index = indexOfSmallest(a, i, numberUsed);
		swap(a[index], a[i]);
	}
}

/* find the smallest */
int indexOfSmallest(const int a[], int startindex, int numberUsed){
	int index;	/* return index */

	for (int i = startindex + 1; i < numberUsed; ++i){
		if (a[startindex] > a[i]){
			index = i;
			startindex = i;
		}
		else{
			index = startindex;
		}
	}

	return index;
}


/* swap the number */
void swap(int& v1, int& v2){
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}