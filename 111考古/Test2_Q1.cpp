#include<iostream>
using namespace std;

class Rectangle{
public:
	// default constructor
	// set length and width to 0
	Rectangle();  
	// set length and width of this rectangle
	Rectangle(const double lengthValue, const double widthValue);

	// get functions
	int getId() const { return id; };
	double getLength() const { return length; };
	double getWidth() const { return width; };
	static int getNum() { return num; };

	// set functions
	void setLength(const double lengthValue);
	void setWidth(const double widthValue);

	// print the rectangle's informations
	void printRectangle() const;
private:
	static int num;
	int id;
	double length;
	double width;
};

int Rectangle::num = 0;

int main(void) {
	double length, width;
	Rectangle rectangles[3];

	while (Rectangle::getNum() < 3) {
		cout << "\nPlease input the length and width of the Rectangle " << Rectangle::getNum() << endl;
		cout << "Length ( larger than 0.0 and less than 10.0 ) => ";
		cin >> length;
		cout << "Width ( larger than 0.0 and less than 10.0 ) => ";
		cin >> width;

		Rectangle rectangle(length, width);
		rectangles[Rectangle::getNum() - 1] = rectangle;
	}

	for (int i = 0; i < 3; i++) {
		rectangles[i].printRectangle();
	}

	system("PAUSE");
	return 0;
}

Rectangle::Rectangle() {
	length = 0.1;
	width = 0.1;
}
Rectangle::Rectangle(const double lengthValue, const double widthValue) {
	bool error = false;
	if (lengthValue <= 0 || lengthValue >= 10) {
		error = true;
		cout << "The length of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}

	if (widthValue <= 0 || widthValue >= 10) {
		error = true;
		cout << "The width of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}
	if (!error) {
		length = lengthValue;
		width = widthValue;
		id = num++;
	}
	else {
		cout << "Please re-enter length and width of the rectangle" << endl;
		return;
	}
}

void Rectangle::setLength(const double lengthValue) {
	if (lengthValue > 0 && lengthValue < 10) {
		length = lengthValue;
	}
	else {
		cout << "The length of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}
}
void Rectangle::setWidth(const double widthValue) {
	if (widthValue > 0 && widthValue < 10) {
		width = widthValue;
	}
	else {
		cout << "The width of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}
}

void Rectangle::printRectangle() const {
	double perimeter = 2 * (length + width);
	double area = length * width;

	//print information
	cout << "-------------------------------------------------------" << endl;
	cout << "Rectangle id: " << id << endl;
	cout << "Rectangle length: " << length << endl;
	cout << "Rectangle width: " << width << endl;
	cout << "Rectangle perimeter: " << perimeter << endl;
	cout << "Rectangle area: " << area << endl;
}