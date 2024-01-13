/*
 *	This program is designed to make users log in better and safer.
 *	We set its password is "12345",and user can change password by
 *	changing 'PIN' unsigned integer.
 *	First,it will randomly select 10 values ​​from 0, 1 or 2 for 0~9.
 *	Than,output to the screen.And user have to key in password by
 *	corresponding random numbers.
*/

#include <iostream>		//Uses I/O library.
#include <time.h>		//Uses now time to set random seed.
#include <math.h>		//Uses 'pow' function.
using namespace std;	//Defines a namespace of 'std'.

int main(void) {
	const int Pin_size = 5;							//The password is a five-digit PIN number.
	const int Pin_range = 10;						//A range of the one digit from 0 to 9.
	const int Random_Type = 3;						//The type of the random number is 3.
	const int Random_NUM[Random_Type] = { 1,2,3 };	//The random numbers set 1, 2, or 3.
	const int PIN = 12345;							//The PIN is actual password.
	unsigned int Random_PIN = 0;					//Stores random numbers ​​corresponding to 0~9.
	int Input_PIN = 0;								//Stores input PIN numbers by the user.
	int NUM = 0;									//Stores the random numbers corresponding to the actual password.
	int Single_PIN;									//Uses to store one-digit random PIN number.

	//Sets random seed.
	srand((unsigned)time(NULL));

	//Randomly generate 1, 2, or 3 corresponding to 0~9.
	//Output PIN(0~9) and random numbers to the screen.
	cout << "PIN : ";
	for (int i = 0; i < Pin_range; i++) {
		cout << i;
		Random_PIN += Random_NUM[rand() % Random_Type] * pow(10, i);
	}
	cout << "\nNUM : ";
	cout << Random_PIN << "\n";

	//Require user to enter password.(Actual PIN=12345)
	cout << "-----Test process-----\n";
	cout << "Please key in PIN numbers...(Actual PIN=12345)\n";
	cout << "User PIN : ";
	cin >> Input_PIN;

	//Get random NUM from PIN numbers and random numbers.
	for (int i = 0; i < Pin_size; i++) {
		Single_PIN = int(PIN / pow(10, i)) % 10;					//Get single PIN number.
		Single_PIN = int(Random_PIN / pow(10, 9 - Single_PIN)) % 10;//Get single random PIN number.
		NUM += Single_PIN * pow(10, i);								//Becomes to new random PIN 'NUM'.
	}

	//Output actual PIN and corresponding random numbers to the screen.
	cout << "Actual PIN : ";
	cout << PIN;
	cout << "\nRandom NUM : ";
	cout << NUM << "\n";

	//Respond correctly or failed.
	if (Input_PIN == NUM)
		cout << "Correct!!\n";
	else
		cout << "Incorrect!!\n";

	system("PAUSE");	//Please 'pause' and return
	return(0);			//Return of the program.
}
