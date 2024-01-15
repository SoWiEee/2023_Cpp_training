//#include <stdafx>
#include <iostream>
#include<vector>
using namespace std;

int largest(vector<int> grade,int i)
{
	int largest=0;
	for (int j = 0; j < i; j++)
	{
		if (grade[j] > largest)
		{
			largest = grade[j];
		}
	}
	return(largest);
}

int main()
{
	vector<int> grade;
	vector<int> count;
	int num;
	int i = 0;

	cout << "Enter the grades (enter -1 to end the input)=>";
	cin >> num;
	while(num!=-1)
	{
		grade.push_back(num);
		i++;
		cin >> num;
	}
	for (int j = 0; j <= largest(grade, i); j++)
	{
		count.push_back(0);
	}
	for (int k = 0; k < i; k++)
	{
		int g;
		g = grade[k];
		count[g]++;
	}
	for (int j = 0; j <= largest(grade, i); j++)
	{
		cout << count[j] << " grades of " << j << "\n";
	}

	system("PAUSE");
	return(0);
}

