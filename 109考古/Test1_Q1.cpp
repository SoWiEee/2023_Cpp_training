#include <iostream>
#include <ctime>
using namespace std;

const int arraySize = 200;	/* size of integer array */

void fillArray(int a[], int size, int& numberUsed);
void find_max(int a[], int numberUsed);
void find_min(int a[], int numberUsed);

int main() {
	int a[arraySize];		/* an integer array					*/
	int numberUsed = 200;	/* the number of used array size	*/

	/* call function fillArray to fill array a */
	fillArray(a, arraySize, numberUsed);

	/* call function find_max to find the maximum of array a */
	find_max(a, numberUsed);

	/* call function find_min to find the minimum of array a */
	find_min(a, numberUsed);

	system("pause");
	return 0;
}

/* fill array a with random integer between 11 and 1111 */
void fillArray(int a[], int size, int& numberUsed) {
	srand(time(NULL));
	for (int i = 0; i < numberUsed; i++)
		a[i] = rand() % 1101 + 11;
}

/* find the maximum of array a and print it with its index in the array */
void find_max(int a[], int numberUsed) {
	int max = 10;	/* store the maximum of array a	*/
	int idx = 0;	/* store the index of maximum	*/

	for (int i = 0; i < numberUsed; i++)
		if (max < a[i]) {
			max = a[i];
			idx = i;
		}
	cout << "Maximum of the array is " << max << " and its index in the array is " << idx << ".\n";
}

/* find the minimum of array a and print it with its index in the array */
void find_min(int a[], int numberUsed) {
	int min = 1112;	/* store the minimum of array a	*/
	int idx = 0;	/* store the index of maximum	*/

	for (int i = 0; i < numberUsed; i++)
		if (min > a[i]) {
			min = a[i];
			idx = i;
		}
	cout << "Minimum of the array is " << min << " and its index in the array is " << idx << ".\n";
}