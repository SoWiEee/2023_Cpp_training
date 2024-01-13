#include <iostream>
#include <cstdlib>
using namespace std;


// Declare Rectangle body
class Rectangle{

public:

	// Create at least two Constructors
	Rectangle();
	Rectangle(double length, double width);
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
	double length;
	double width;

};

// Declare Cuboid body
class Cuboid{
public:

	// Create at least two Constructors
	Cuboid();
	Cuboid(double length, double width, double height, double density);
	Cuboid(int id, double length, double width, double height, double density);
	
	// Accessor and Mutator
	int getid() const;
	double getlength() const;
	double getwidth() const;
	double getheight() const;
	double getdensity() const;
	double getvolume() const;
	double getweight() const;
	void setlength(double length);
	void setwidth(double width);
	void setheight(double height);
	void setdensity(double density);
	void setid(int ID);

	// Print the varialbe
	void printid() const;
	void printnumber() const;
	void printlength() const;
	void printwidth() const;
	void printperimeter() const;
	void printarea() const;
	void printheight() const;
	void printdensity() const;
	void printvolume() const;
	void printweight() const;
	void printDetail() const;

	// Compare volume 
	bool compVol(Cuboid& Object1) const;


private:
	double density;
	double height;
	Rectangle rect;

};

int Rectangle::id = 0;
const bool compCubWeight(Cuboid& Object1, Cuboid&Object2);

int main(){
	Cuboid Cuboid1(3.2, 9.8, 15.6, 0.8),
		   Cuboid2(5.2, 7.6, 10.2, 1.2);
	
	// Show Cuboid1 data
	Cuboid1.printDetail();
	Cuboid2.printDetail();



	cout << "Compare the volume of the calling Cuboid object is greater than the " << endl;
	cout << "volume of the Cuboid object passed as reference into the function " << endl;
	cout << "or not. 1 (true)  0 (false). Pass Cuboid2 to Cuboid1. " << endl;
	cout << "Type : " << Cuboid1.compVol(Cuboid2) << endl;

	cout << endl;

	cout << "Compare Cuboid1 is heavier than Cuboid2 or not. 1 (true)  0 (false). " << endl;
	cout << "Type : " << compCubWeight(Cuboid1, Cuboid2) << endl;

	

	system("PAUSE");
	return 0;
}



// Setup class Rectangle
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



// Setup class Cuboid
Cuboid::Cuboid(){
	rect = Rectangle(0, 0);
	density = 0;
	height = 0;
}

Cuboid::Cuboid(double length, double width, double height, double density){
	rect = Rectangle(length, width);
	setheight(height);
	setdensity(density);
}

Cuboid::Cuboid(int id, double length, double width, double height, double density){
	rect = Rectangle(id, length, width);
	setheight(height);
	setdensity(density);
}

int Cuboid::getid() const{
	return rect.getid();
}

double Cuboid::getlength() const{
	return rect.getlength();
}

double Cuboid::getwidth() const{
	return rect.getwidth();
}

double Cuboid::getheight() const{
	return height;
}

double Cuboid::getdensity() const{
	return density;
}

double Cuboid::getvolume() const{
	return rect.getwidth()*rect.getlength()*height;
}

double Cuboid::getweight() const{
	return rect.getwidth()*rect.getlength()*height*density;
}

void Cuboid::setlength(double length){
	rect.setlength(length);
}

void Cuboid::setwidth(double width){
	rect.setwidth(width);
}
void Cuboid::setheight(double height){
	if (height < 0.0 || height > 20.0)
		cout << "Cuboid "  << rect.getnumber() << " Height is out of Boundary " << endl;
	else
		this->height = height;
}

void Cuboid::setdensity(double density){
	if (density < 0.0 || density > 2.0)
		cout << "Cuboid " << rect.getnumber() << " Density is out of Boundary " << endl;
	else
		this->density = density;
}

void Cuboid::setid(int ID){
	rect.setid(ID);
}

void Cuboid::printid() const{
	cout << "Cuboid's id : " << rect.getid() << endl;
}

void Cuboid::printnumber() const{
	cout << "Cuboid's number : " << rect.getnumber() << endl;
}

void Cuboid::printlength() const{
	cout << "Cuboid's length : " << rect.getlength() << endl;
}

void Cuboid::printwidth() const{
	cout << "Cuboid's width : " << rect.getwidth() << endl;
}

void Cuboid::printperimeter() const{
	cout << "Cuboid's perimeter : " << (rect.getwidth() + rect.getlength() + height) * 4 << endl;
}

void Cuboid::printarea() const{
	cout << "Cuboid's area : " << (rect.getwidth()*rect.getlength() + rect.getlength()*height + height*rect.getwidth()) * 2 << endl;
}

void Cuboid::printheight() const{
	cout << "Cuboid's height : " << height << endl;
}

void Cuboid::printdensity() const{
	cout << "Cuboid's density : " << density << endl;
}

void Cuboid::printvolume() const{
	cout << "Cuboid's volume : " << rect.getwidth()*rect.getlength()*height << endl;
}

void Cuboid::printweight() const{
	cout << "Cuboid's weight : " << rect.getwidth()*rect.getlength()*height*density << endl;
}

bool Cuboid::compVol(Cuboid& Object1) const{
	
	if (Object1.getvolume() < this->getvolume())
		return true;
	else
		return false;
}

const bool compCubWeight(Cuboid& Object1, Cuboid&Object2){

	if (Object1.getweight() > Object2.getweight())
		return true;
	else
		return false;

}

void Cuboid::printDetail() const{
	printnumber();
	printlength();
	printwidth();
	printheight();
	printdensity();
	printperimeter();
	printarea();
	printvolume();
	printweight();
	cout << "---------------------------------------" << endl;
}
