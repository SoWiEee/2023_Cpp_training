//selection sort
#include <iostream>
using namespace std;

int findmin(const int arr[], int start,int numberused = 10)
{
	int smallest;
	smallest = start;
	for (int i = start; i < numberused; i++)
		if (arr[i] < arr[smallest])
			smallest = i;
	return smallest;
}

void switchvalue (int &v1, int &v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
	return;
}

void sort(int arr[], int numberused = 10)
{
	int min;
	for (int i = 0; i < numberused-1; i++)
	{
		min = findmin(arr, i );
		switchvalue(arr[i], arr[min]);
	}
}
int main()
{
	int arr[10] = { 9,4,5,6,3,1,7,2,0,8 };
	sort(arr);
	for (int x : arr)
	{
		cout << x << " ";
	}
	
	system("PAUSE");
	return 0;
}
