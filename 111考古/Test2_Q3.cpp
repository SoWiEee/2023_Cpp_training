#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Money {
public:
	// default constructor
	// set dollars and cents to 0
	Money();

	// compute dollarspart and centspart
	// set dollars and cents to them
	Money(double money);

	// set dollars and cents to parameters
	Money(int dollarsValue, int centsValue);

	//get functions
	int getDollars() const { return dollars; }
	int getcents() const { return cents; }

	//set functions
	void setDollars(const int dollarsValue);
	void setCents(const int centsValue);

	//Returns percentFigure percent of Money.
	//example: If percentFigure is 10, a Money object is returned that
	//represents 0.1 of the amount of moeny of the calling object
	//If purse is a Money objet representing $100.20, purse.percent(10)
	//is a Money object representing $10.02
	const Money percent(const int percentFigure) const;

	//overload operators
	friend const Money operator +(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount);
	friend const bool operator ==(const Money& amount1, const Money& amount2);
	friend const bool operator >(const Money& amount1, const Money& amount2);
	friend const bool operator <(const Money& amount1, const Money& amount2);
	friend const ostream& operator <<(ostream& outs, const Money& amount);
	friend const istream& operator >>(istream& ins, Money& amount);

	// compute dollarspart and centspart
	int dollarspart(const double amount) const;
	int centspart(const double amount) const;

private:
	int dollars;
	int cents;
};

int main(void) {
	fstream fin("money.txt");
	Money M1, M2, M3, M4, M5, M6;

	fin >> M1;
	fin >> M2;
	cout << "\nM1 = " << M1;
	cout << "\nM2 = " << M2;

	M3 = M1 + M2;
	cout << "\n-------------------------------";
	cout << "\nA. M3 = M1 + M2";
	cout << "\nM3:" << M3;

	M4 = M1 - M2;
	cout << "\n-------------------------------";
	cout << "\nB. M4 = M1 - M2";
	cout << "\nM4: " << M4;

	cout << "\n-------------------------------";
	cout << "\nC. Read -2.71 from keyboard as Money object M5.";
	cout << "\nPlease input -2.71 >> ";
	cin >> M5;
	while (!(M5 == Money(double(-2.71)))) {
		cout << "M5 != $-2.71" << endl;
		cin >> M5;
	}
	cout << "\nM5 = " << M5;

	cout << "\n-------------------------------";
	cout << "\nD. Test the equality of M5 and M4.";
	cout << "\nM5: " << M5;
	cout << ", M4: " << M4;
	if (M5 == M4) {
		cout << "\nM5 is equal to M4";
	}
	else {
		cout << "\nM5 is not equal to M4";
	}

	M5 = -M5;
	cout << "\n-------------------------------";
	cout << "\nE. M5 = -M5";
	cout << "\nM5: " << M5;

	M6 = M5.percent(10);
	cout << "\n-------------------------------";
	cout << "\nF. M6 = M5.percent(10)";
	cout << "\nM6: " << M6;

	cout << "\n-------------------------------";
	cout << "\nG. M6 > M5";
	cout << "\nM6 = " << M6;
	cout << ", M5 = " << M5;
	if (M6 > M5) {
		cout << "\nM6 is greater than M5";
	}
	else {
		cout << "\nM6 is not greater than M5";
	}

	cout << "\n-------------------------------";
	cout << "\nH. M6 < M5";
	cout << "\nM6 = " << M6;
	cout << ", M5 = " << M5;
	if (M6 < M5) {
		cout << "\nM6 is less than M5";
	}
	else {
		cout << "\nM6 is not less than M5";
	}
	cout << endl;


	system("PAUSE");
	return 0;
}

Money::Money() {
	dollars = 0;
	cents = 0;
}
Money::Money(double money) {
	dollars = dollarspart(money);
	cents = centspart(money);
}
Money::Money(int dollarsValue, int centsValue) : dollars(dollarsValue), cents(centsValue) {}

void Money::setDollars(const int dollarsValue) {
	dollars = dollarsValue;
}
void Money::setCents(const int centsValue) {
	cents = centsValue;
}

const Money operator +(const Money& amount1, const Money& amount2) {
	int new_dollars = amount1.dollars + amount2.dollars;
	int new_cents = amount1.cents + amount2.cents;

	new_dollars += new_cents / 100;
	new_cents %= 100;

	return Money(new_dollars, new_cents);
}
const Money operator -(const Money& amount1, const Money& amount2) {
	double doubleAmount1 = static_cast<double>(amount1.dollars) + static_cast<double>(amount1.cents) / 100;
	double doubleAmount2 = static_cast<double>(amount2.dollars) + static_cast<double>(amount2.cents) / 100;

	return Money(doubleAmount1 - doubleAmount2);
}
const Money operator -(const Money& amount) {
	double doubleAmount = static_cast<double>(amount.dollars) + static_cast<double>(amount.cents) / 100;
	
	return Money(-doubleAmount);
}
const bool operator ==(const Money& amount1, const Money& amount2) {
	double doubleAmount1 = static_cast<double>(amount1.dollars) + static_cast<double>(amount1.cents) / 100;
	double doubleAmount2 = static_cast<double>(amount2.dollars) + static_cast<double>(amount2.cents) / 100;

	return doubleAmount1 == doubleAmount2;
}
const bool operator >(const Money& amount1, const Money& amount2) {
	double doubleAmount1 = static_cast<double>(amount1.dollars) + static_cast<double>(amount1.cents) / 100;
	double doubleAmount2 = static_cast<double>(amount2.dollars) + static_cast<double>(amount2.cents) / 100;

	return doubleAmount1 > doubleAmount2;
}
const bool operator <(const Money& amount1, const Money& amount2) {
	double doubleAmount1 = static_cast<double>(amount1.dollars) + static_cast<double>(amount1.cents) / 100;
	double doubleAmount2 = static_cast<double>(amount2.dollars) + static_cast<double>(amount2.cents) / 100;

	return doubleAmount1 < doubleAmount2;
}
const ostream& operator <<(ostream& outs, const Money& amount) {
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);

	if (amount.dollars < 0 || amount.cents < 0) {
		outs << "$-";
	}
	else {
		outs << "$";
	}
	outs << absDollars;
	if (absCents < 10) {
		outs << ".0";
	}
	else {
		outs << ".";
	}
	outs << absCents;
	return outs;
}
const istream& operator >>(istream& ins, Money& amount) {
	double doubleAmount;
	ins >> doubleAmount;

	amount = Money(doubleAmount);
	return ins;
}

const Money Money::percent(const int percentFigure) const {
	double doubleAmount = static_cast<double>(dollars) + static_cast<double>(cents) / 100;

	return Money(doubleAmount * percentFigure / 100);
}

int Money::dollarspart(const double amount) const {
	return static_cast<int>(amount);
}

int Money::centspart(const double amount) const {
	return (amount * 100 - static_cast<int>(amount) * 100);
}