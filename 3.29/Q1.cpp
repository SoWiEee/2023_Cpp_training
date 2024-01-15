
#include"stdafx.h"

#include <iostream>


using namespace std;

void input(int* in_num1, int* in_num2);
void conversion(int* in_num1, int* in_num2,int *out_num1,int *out_num2,char *time);
void output(int* in_num1, int* in_num2, int* out_num1, int* out_num2, char* time);

int main()
{
	int in_num1, in_num2, out_num1, out_num2;
	char time;
	char run;

	do {
		input(&in_num1, &in_num2);
		conversion(&in_num1, &in_num2, &out_num1, &out_num2, &time);
		output(&in_num1, &in_num2, &out_num1, &out_num2, &time);
		cout << "Continue the program?(y/n)=>";
		cin >> run;
	} while (run != 'n');
  
	system("PAUSE");
	return(0);
}

void input(int* in_num1, int* in_num2)
{
	char c;
	cout << "\nPlease enter the time in 24-hour notation (hour and minute)=>";
	cin >> *in_num1 >>c>> *in_num2;
	cout << "\n";
}

void conversion(int* in_num1, int* in_num2, int* out_num1, int* out_num2, char *time)
{
	if (*in_num1 - 12 >= 1)
	{
		*out_num1 = *in_num1 - 12;
		*time = 'p';
	}
	else if (*in_num1 - 12 == 0)
	{
		*out_num1 = *in_num1;
		*time = 'p';
	}
	else if (*in_num1 - 12 < 0 && *in_num1 != 00)
	{
		*out_num1 = *in_num1;
		*time = 'A';
	}
	else if (*in_num1 == 00)
	{
		*out_num1 = 12;
		*time = 'A';
	}
	else if (*in_num1 - 12 == 0 && *in_num2 == 00)
	{
		*out_num1 = *in_num1 - 12;
		*time = 'p';
	}
	else if (*in_num1 - 12 == -12 && *in_num2 == 00)
	{
		*out_num1 = *in_num1;
		*time = 'A';
	}

	*out_num2 = *in_num2;
}

void output(int* in_num1, int* in_num2, int* out_num1, int* out_num2, char* time)
{
	switch (*time)
	{
	case 'A':
		if (*in_num1 == 00 && *in_num2 == 00)
		{
			cout << "The time 00:00 in 24-hour notation is 12:00 A.M. in 12-hour notation.\n\n";
		}
		else
		{
			cout << "The time " << *in_num1 << ":" << *in_num2 << " in 24-hour notation is " << *out_num1 << ":" << *out_num2 << " A.M. in 12-hour notation.\n\n";
		}break;
	case 'p':
		if (*in_num1 == 12 && *in_num2 == 00)
		{
			cout << "The time 12:00 in 24-hour notation is 12:00 P.M. in 12-hour notation.\n\n";
		}
		else
		{
			cout << "The time " << *in_num1 << ":" << *in_num2 << " in 24-hour notation is " << *out_num1 << ":" << *out_num2 << " P.M. in 12-hour notation.\n\n";
		}break;
	}
}