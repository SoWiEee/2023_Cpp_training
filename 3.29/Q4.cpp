
#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;

void input_length(double* feet, double* inch);
double conversion(double* feet, double* inch);
void output_length(double* feet, double* inch);

int main()
{
	double feet, inch;
	char stop = 'z';

	input_length(&feet, &inch);
	output_length(&feet, &inch);

	cout << "continue?(y/n) => ";
	cin >> stop;

	while (true)
	{
		if (stop == 'y')
		{
			input_length(&feet, &inch);
			output_length(&feet, &inch);
			cout << "continue?(y/n) => ";
			cin >> stop;
		}
		else if (stop == 'n')
		{
			system("PAUSE");
			return 0;
		}
	}

	system("PAUSE");
	return 0;
}

void input_length(double* feet, double* inch) {
	cout << "Enter the feet => ";
	cin >> *feet;
	cout << "Enter the inch => ";
	cin >> *inch;
}

double conversion(double* feet, double* inch) {
	*feet = *feet + *inch / 12;

	return (*feet) * 0.3048;
}

void output_length(double* feet, double* inch) {
	cout << "It's ";
	printf("%.2f", conversion(feet, inch));
	cout << " meters\n";
}