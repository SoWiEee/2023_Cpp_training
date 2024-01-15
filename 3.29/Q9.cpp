// b1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<iomanip>                

using namespace std;

int main()
{
	double n, guess1, r,guess2;                                   //enter the number which is n, and the guess number 1 and 2

	cout << "Enter a number to calculate the square root =>";     //prompt the user to enter the number
	cin >> n;

	guess1 = n / 2;                                               //calculate the guess1
	r = n / guess1;
	guess2 = (guess1 + r) / 2;                                    //calculate the guess2

	while ((guess1 - guess2) > (guess1 * 0.01))                   //give condition the run the loop
	{
		guess1 = guess2;
		r = n / guess1;
		guess2 = (guess1 + r) / 2;
	}

	cout << "The square root of the number is " << fixed << setprecision(2) << guess2 <<"\n";  //output the result

	system("PAUSE");
	return(0);
}