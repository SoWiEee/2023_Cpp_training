#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int a[], int size, int &numberUsed);
int search(int const a[], int numberUsed, int target);
const int Size = 200;

int main(){
	int Array[Size], numberUsed;
	int target, index;

	/*set the rand()*/
	srand((unsigned)time(NULL));

	/*set the array*/
	fillArray(Array, Size, numberUsed);

	/* check the input */
	do {
		cout << "Enter a number (-1 = quit): ";

		int check = 0;
		if (!(cin >> target)) {
			cin.clear();
			cin.ignore(10000, '\n');
			check = 1;
			cout << "Please enter numbers only." << endl;
		}

	/* find the target with correct input */
		if (target != -1 && check != 1) {
			index = search(Array, Size, target);
	/* show result */
			if (index == -1)
				cout << "Not found message" << endl;
			else
				cout << "Target Found. The index is " << index << endl;
		}
	} while (target != -1);

	system("PAUSE");
	return 0;
}

/* fill array */
void fillArray(int a[], int size, int &numbeUserd){
	int index = 0;

	for (index; index < Size; ++index){
		a[index] = rand() % 1101 + 11;;
	}

	numbeUserd = index;

}

/* search the array */
int search(int const a[], int numberUsed, int target){
	int index = -1;

	for (int i = 0; i < numberUsed; ++i)
		if (a[i] == target)
			index = i;

	return index;
}