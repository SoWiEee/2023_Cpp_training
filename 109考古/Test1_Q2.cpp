#include <iostream>
#include <ctime>
using namespace std;

const int arraySize = 200;	/* size of integer array */

void fillArray(int a[], int size, int& numberUsed);
void find_max(int a[], int numberUsed);
void find_min(int a[], int numberUsed);
int search(const int a[], int numberused, int target);

int main() {
	int a[arraySize];		/* an integer array								*/
	int numberUsed = 200;	/* the number of used array size				*/
	int searchInteger;		/* store the search integer						*/
	int idx;				/* store the return value of function search	*/

	/* call function fillArray to fill array a */
	fillArray(a, arraySize, numberUsed);

	/* call function find_max to find the maximum of array a */
	find_max(a, numberUsed);

	/* call function find_min to find the minimum of array a */
	find_min(a, numberUsed);

	/* prompt user to input a search integer then print out message until user input -1 */
	while (true) {
		cout << "Input a integer to search.\n";
		cout << "Input -1 if you want to stop the search.\n";
		cin >> searchInteger;

		/* if input is -1 then exit this program or call function search to search the input integer */
		if (searchInteger == -1) {
			system("pause");
			return 0;
		}
		else {
			idx = search(a, arraySize, searchInteger);

			/* if the search integer is found, print its index 
			   or print message "Not found."					*/
			if (idx != -1)
				cout << "Your search integer " << searchInteger << " is found and its index in the array is " << idx << ".\n\n";
			else
				cout << "Not found.\n\n";
		}
	}

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

/* search a integer in array a and return its index if found
   return -1 if not found										*/
int search(const int a[], int numberused, int target) {
	for (int i = 0; i < numberused; i++)
		if (a[i] == target)
			return i;

	return -1;
}