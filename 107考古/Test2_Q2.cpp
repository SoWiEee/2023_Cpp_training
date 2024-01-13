#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle{

public:

	// Create at least two Constructors
	Rectangle();
	Rectangle(double lenght, double width);
	Rectangle(int id, double length, double width);

	// Accessor and Mutator
	int getid() const;
	double getlength() const;
	double getwidth() const;
	int getnumber() const;
	void setnumber(int number);
	void setlength(double length);
	void setwidth(double width);
	void setid(int ID);

	// Print the varialbe
	void printid() const;
	void printnumber() const;
	void printlength() const;
	void printwidth() const;
	void printperimeter() const;
	void printarea() const;
	void printDetail() const;

private:
	int number;
	int static id;
	double length = 0;
	double width = 0;

};

int Rectangle::id = 0;
void verifyInput(int&);
void verifyInput(double&);

int main(){
	
	int id = 0;
	double length = 0.0, 
			width = 0.0;



	// Test Rectangle 1
	//cout << "Enter Rectangle 1 id : ";
	//verifyInput(id);
	cout << "Enter Rectangle 1 length : ";
	verifyInput(length);
	cout << "Enter Rectangle 1 width : ";
	verifyInput(width);

	Rectangle Object1(length, width);
	cout << "\n------------------------------------" << endl;
	Object1.printDetail();
	cout << "\n------------------------------------" << endl;
	
	// Test Rectangle 2
	//cout << "Enter Rectangle 2 id : ";
	//verifyInput(id);
	cout << "Enter Rectangle 2 length : ";
	verifyInput(length);
	cout << "Enter Rectangle 2 width : ";
	verifyInput(width);

	Rectangle Object2(length, width);
	cout << "\n------------------------------------" << endl;
	Object2.printDetail();
	cout << "\n------------------------------------" << endl;

	// Test Rectangle 3
	cout << "Enter Rectangle 3 id : ";
	verifyInput(id);
	cout << "Enter Rectangle 3 length : ";
	verifyInput(length);
	cout << "Enter Rectangle 3 width : ";
	verifyInput(width);

	Rectangle Object3(id, length, width);
	cout << "\n------------------------------------" << endl;
	Object3.printDetail();
	cout << "\n------------------------------------" << endl;
	

	
	system("PAUSE");
	return 0;
}

void verifyInput(int &input){
	
	while (!(cin >> input)){
		cout << "Enter integer only. Input : ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

}

void verifyInput(double &input){

	while (!(cin >> input)){
		cout << "Enter double only. Input : ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

}

Rectangle::Rectangle(){
	++id;
	number = id;
	length = 0;
	width = 0;
}

Rectangle::Rectangle(double length, double width){
	++id;
	number = id;
	setwidth(width);
	setlength(length);
}

Rectangle::Rectangle(int id, double length, double width){
	setnumber(id);
	setwidth(width);
	setlength(length);
}

double Rectangle::getlength() const{
	return length;
}

double Rectangle::getwidth() const{
	return width;
}

void Rectangle::setlength(double length){
	if (length < 0.0 || length > 10.0)
		cout << "Length is out of Boundary " << endl;
	else
		this->length = length;
}

void Rectangle::setwidth(double width){
	if (width < 0.0 || width > 10.0)
		cout << "Width is out of Boundary " << endl;
	else
		this->width = width;
}

int Rectangle::getid() const{
	return id;
}

void Rectangle::setid(int ID){
	id = ID;
}

void Rectangle::printid() const {
	cout << "Rectangle's id : " << id << endl;
}

void Rectangle::printnumber() const {
	cout << "Rectangle's id : " << number << endl;
}

void Rectangle::printlength() const {
	cout << "Rectangle's length : " << length << endl;
}

void Rectangle::printwidth() const {
	cout << "Rectangle's width : " << width << endl;
}
void Rectangle::printperimeter() const {
	cout << "Rectangle's perimeter : " << (width+length)*2 << endl;
}

void Rectangle::printarea() const {
	cout << "Rectangle's area : " << width*length << endl;
}

int Rectangle::getnumber() const {
	return number;
}

void Rectangle::setnumber(int number){
	this->number = number;
}

void Rectangle::printDetail() const {
	printnumber();
	printlength();
	printwidth();
	printperimeter();
	printarea();
}