// a1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

int main()
{
	double celsius = 100;                           //let the celsius = 100 and decrease the value to test the answer
	double fahrenheit;                              //the fahrenheit value

	fahrenheit = 9  * celsius / 5 + 32;             //to calculate the fahrenheit value by the celsius value

	while (celsius != fahrenheit)                   //use the loop to find the same value
	{
		celsius--;
		fahrenheit = 9 * celsius / 5 + 32;
	}

	                                                //output the result 
	cout << "While Celsius = " << celsius << ", the value of Fahrenheit = " << fahrenheit << ", where two values are the same.\n";

	system("PAUSE");
	return(0);

}

