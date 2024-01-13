/*
 *	The program uses the user-defined namespace and the PFArrayD class.
 *	First,it needs the user to key in two and four doubles for the firstPFA
 *	and the secondPFA,than the two objects will use operator overloading to
 *	concatenate and return to thirdPFA object.
 *	Finaly,it will output the three objects's information,and uses function
 *	"showLastPFArrayD" to print last element of the object.
*/

#include <iostream>			//Include library.
#include "PFArrayD.h"		//Include PFArrayD class library.
using namespace NUTNCSIE;	//Set user-define namespace.
using std::cin;				//Add cin using.
using std::cout;			//Add cout using.

void showLastPFArrayD(const PFArrayD&);	//Print the last element of object.

int main(void) {
	//Set three PFArrayD objects.
	PFArrayD firstPFA(5);
	PFArrayD secondPFA(10);
	PFArrayD thirdPFA;

	double swap_num;		//Stores user's double number.

	//User key in two double number into the sencondPFA object.
	cout << "The firstPFA will add element : \n";
	for (int i = 0; i < 2; i++) {
		cout << "Please key in firstPFA's index " << i << " number : \n";
		cin >> swap_num;
		firstPFA.addElement(swap_num);
	}
	cout << "\n";

	//User key in four double number into the sencondPFA object.
	cout << "The secondPFA will add element : \n";
	for (int i = 0; i < 4; i++) {
		cout << "Please key in secondPFA's index " << i << " number : \n";
		cin >> swap_num;
		secondPFA.addElement(swap_num);
	}
	cout << "\n";

	//The firstPFA append the secondPFA,and return to the thirdPFA.
	thirdPFA = firstPFA + secondPFA;
	//Sets the capacity of thirdPFA is the double of thirdPFA's used count.
	thirdPFA.set_capacity(thirdPFA.get_used()*2);

	//Print the firstPFA's all the elements.
	cout << "firstPFA list : ";
	for (int i = 1; i <= firstPFA.get_used(); i++) {
		cout << firstPFA[i];
		if (i != firstPFA.get_used())
			cout << " => ";
	}
	cout << "\nThe capacity of firstPFA : " << firstPFA.get_capacity() << "\n";
	cout << "The used of firstPFA : " << firstPFA.get_used() << "\n\n";

	//Print the secondPFA's all the elements.
	cout << "secondPFA list : ";
	for (int i = 1; i <= secondPFA.get_used(); i++) {
		cout << secondPFA[i];
		if (i != secondPFA.get_used())
			cout << " => ";
	}
	cout << "\nThe capacity of secondPFA : " << secondPFA.get_capacity() << "\n";
	cout << "The used of secondPFA : " << secondPFA.get_used() << "\n\n";

	//Print the thirdPFA's all the elements.
	cout << "thirdPFA list : ";
	for (int i = 1; i <= thirdPFA.get_used(); i++) {
		cout << thirdPFA[i];
		if (i != thirdPFA.get_used())
			cout << " => ";
	}
	cout << "\nThe capacity of thirdPFA : " << thirdPFA.get_capacity() << "\n";
	cout << "The used of thirdPFA : " << thirdPFA.get_used() << "\n\n";

	//Print the last element of each PFArrayD object.
	cout << "The last element of firstPFA : ";
	showLastPFArrayD(firstPFA);
	cout << "\n";
	cout << "The last element of secondPFA : ";
	showLastPFArrayD(secondPFA);
	cout << "\n";
	cout << "The last element of thirdPFA : ";
	showLastPFArrayD(thirdPFA);
	cout << "\n";

	system("pause");	//Please 'pause' and return
	return 0;
}

void showLastPFArrayD(const PFArrayD& object) {
	//Prints the last number of the object.
	if (object.get_used() > 0)
		cout << object[object.get_used()];	//Print the last element of object.
	else
		cout << "The object don't have any one element.\n";
}
