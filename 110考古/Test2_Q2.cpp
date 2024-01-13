#include <iostream>  
using namespace std;

class Rectangle {
public:
	//constructors
	Rectangle();
	Rectangle(int id, double length, double width);
	//set and get function
	void setLength(double length);
	double getLength() const;
	void setWidth(double width);
	double getWidth() const;
	int getId() const;
	//get perimeter
	double perimeter() const;
	//get area
	double area() const;
	static int getNum();
	//output rectangle data
	void output();
private:
	static int num;
	int id;
	double length;
	double width;
};

//initialize
int Rectangle::num = 0;

//default constructor
Rectangle::Rectangle() :id(0), length(1), width(1){}

//constructor
Rectangle::Rectangle(int id, double length, double width){
	this->id = id;
	this->length = length;
	this->width = width;
}

void Rectangle::setLength(double length){
	//verify the range
	while (length <0.0 || length >10.0){
		cout << "Please enter again : ";
		cin >> length;
	}
	this->length = length;
}

double Rectangle::getLength() const{
	return length;
}

void Rectangle::setWidth(double width){
	//verify the range
	while (width <0.0 || width >10.0){
		cout << "Please enter again : ";
		cin >> width;
	}
	this->width = width;
}

double Rectangle::getWidth() const{
	return width;
}

int Rectangle::getId() const{
	return id;
}

double Rectangle::perimeter() const{
	return (length+width)*2;
}

double Rectangle::area() const{
	return length*width;
}

int Rectangle::getNum(){
	num += 1;
	return num;
}

void Rectangle::output(){
	cout << endl << "Rectangle id: " << getId() << endl;
	cout << "length: " << getLength() << endl;
	cout << "width: " << getWidth() << endl;
	cout << "perimeter: " << perimeter() << endl;
	cout << "area: " << area() << endl << endl;
}

int main(){
	double length, width;
	Rectangle rectangle[3];

	//input three rectangle objecs from keyboard
	for (int i=0; i<3; i++){
		cout << "Enter the " << i+1 << " rectangle's length (0.0 ~ 10.0): ";
		cin >> length;
		rectangle[i].setLength(length);
		cout << "Enter the " << i+1 << " rectangle's width (0.0 ~ 10.0): ";
		cin >> width;
		rectangle[i].setWidth(width);
		rectangle[i] = Rectangle(rectangle[i].getNum(), rectangle[i].getLength(), rectangle[i].getWidth());
	}
	
	for (int i=0; i<3; i++){
		rectangle[i].output();
	}

	system("pause");
	return 0;
}