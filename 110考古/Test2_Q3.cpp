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

class Cuboid {
public:
	//constructors
	Cuboid();
	Cuboid(double length, double width, double density, double height);
	// set and get function
	void setDensity(double density);
	double getDensity() const;
	void setHeight(double height);
	double getHeight() const;
	//get volume
	double volume() const;
	//get weight
	double weight() const;
	//compare volume
	bool compVol(Cuboid& c2) const;
	//output cuboid data
	void output();
private:
	double density;
	double height;
	Rectangle rect;
};

//default constructor
Cuboid::Cuboid() :rect(), density(1), height(1){}

//constructor
Cuboid::Cuboid(double length, double width, double height, double density){
	rect.setLength(length);
	rect.setWidth(width);
	this->height = height;
	this->density = density;
}

void Cuboid::setDensity(double density){
	//verify the range
	while (density <0.0 || density >2.0){
		cout << "Please enter again : ";
		cin >> density;
	}
	this->density = density;
}

double Cuboid::getDensity() const{
	return density;
}

void Cuboid::setHeight(double height){
	//verify the range
	while (height <0.0 || height >20.0){
		cout << "Please enter again : ";
		cin >> height;
	}
	this->height = height;
}

double Cuboid::getHeight() const{
	return height;
}

double Cuboid::volume() const{
	return  rect.area() * height;
}

double Cuboid::weight() const{
	return  volume() * density;
}

//compare volume
bool Cuboid::compVol(Cuboid& c2) const{
	if(volume() > c2.volume())
		return true;
	else
		return false;
}

void Cuboid::output(){
	cout << "length: " << rect.getLength() << endl;
	cout << "width: " << rect.getWidth() << endl;
	cout << "height: " << getHeight() << endl;
	cout << "volume: " << volume() << endl;
	cout << "weight: " << weight() << endl << endl;
}

//compare weight
bool compCubWeight(Cuboid& c1, Cuboid& c2){
	if(c1.weight() > c2.weight())
		return true;
	else
		return false;
}

int main(){
	Cuboid cuboid1(3.2, 9.8, 15.6, 0.8), cuboid2(5.2, 7.6, 10.2, 1.2);

	cout << "Cuboid1: " << endl;
	cuboid1.output();
	cout << "Cuboid2: " << endl;
	cuboid2.output();

	if(cuboid1.compVol(cuboid2))
		cout << "the volume of the cuboid1 is greater than the volume of the cuboid2." << endl;
	else
		cout << "the volume of the cuboid2 is greater than the volume of the cuboid1." << endl;

	if(compCubWeight(cuboid1, cuboid2))
		cout << "the weight of the cuboid1 is heavier than the weight of the cuboid2." << endl;
	else
		cout << "the weight of the cuboid2 is heavier than the weight of the cuboid1." << endl;

	system("pause");
	return 0;
}