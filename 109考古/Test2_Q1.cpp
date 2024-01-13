#include<iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle();												/*initialize a rectangle with length 1 and width 1		*/
	Rectangle(int newId, double newLength, double newWidth);	/*initialize a rectangle with its ID, length and width	*/
	void setId(int newId);										/*set rectangle ID										*/
	void setLength(double newLength);							/*set rectangle length and check range					*/
	void setWidth(double newWidth);								/*set rectangle width and check range					*/
	static int getNum();										/*get number of generated rectangles					*/
	int getId() { return this->id; }							/*get rectangle ID										*/
	double getLength() { return this->length; }					/*get rectangle	lenght									*/
	double getWidth() { return this->width; }					/*get rectangle width									*/
	double getPerimeter();										/*get perimeter of rectangle							*/
	double getArea();											/*get area of rectangle									*/
	void rectInfo();											/*print rectangle informaiton							*/

private:
	static int num;												/*number of generated rectangles						*/
	int id;														/*rectangle Id tracked by num							*/
	double length;												/*rectangle lenght										*/
	double width;												/*rectangle width										*/
};

/*initialize a rectangle with length 1 and width 1				*/
Rectangle::Rectangle():length(1), width(1)
{
}

/*initialize a rectangle with its ID, length and width			*/
Rectangle::Rectangle(int newId, double newLength, double newWidth) : id(newId)
{
	this->setLength(newLength);
	this->setWidth(newWidth);
}

/*get number of generated rectangles							*/
int Rectangle::getNum()
{
	num++;
	return num;
}

/*set rectangle ID												*/
void Rectangle::setId(int newId)
{
	this->id = newId;
}

/*set rectangle length and check range							*/
void Rectangle::setLength(double newLength)
{
	bool notInRange = true;
	double checkLength = newLength;
	while (notInRange)
	{
		if (checkLength < 0.0 || checkLength > 10.0)
		{
			cout << "length should be form 0 to 10." << endl;
			cout << " Length: ";
			cin >> checkLength;
		}
		else
		{
			notInRange = false;
			this->length = checkLength;
		}
	}
}

/*set rectangle width and check range							*/
void Rectangle::setWidth(double newWidth)
{
	bool notInRange = true;
	double checkWidth = newWidth;
	while (notInRange)
	{
		if (checkWidth < 0.0 || checkWidth > 10.0)
		{
			cout << "width should be form 0 to 10." << endl;
			cout << " Width: ";
			cin >> checkWidth;
		}
		else
		{
			notInRange = false;
			this->width = checkWidth;
		}
	}
}

/*get perimeter of rectangle									*/
double Rectangle::getPerimeter()
{
	return (this->getLength() + this->getWidth()) * 2;
}

/*get area of rectangle											*/
double Rectangle::getArea()
{
	return this->getLength() * this->getWidth();
}

/*print rectangle informaiton									*/
void Rectangle::rectInfo()
{
	cout << "ID: " << this->getId() << endl;
	cout << "Length: " << this->getLength() << endl;
	cout << "Width: " << this->getWidth() << endl;
	cout << "Perimeter: " << this->getPerimeter() << endl;
	cout << "Area: " << this->getArea() << endl << endl;
}

int Rectangle::num = 0;

int main(void)
{
	int id;
	double length;
	double width;
	bool lengthNotInRange = true;
	bool widthNotInRange = true;

	/*use default constructor and set new length and width*/
	Rectangle rectangleEins;
	cout << "Input rectangle 1 length and width" << endl;
	rectangleEins.setId(Rectangle::getNum());
	cout << " Length: ";
	cin >> length;
	rectangleEins.setLength(length);
	cout << " Wdth: ";
	cin >> width;
	rectangleEins.setWidth(width);

	/*construct a new rectangle and set new length and width*/
	id = Rectangle::getNum();
	Rectangle rectangleZwei(id, 1, 1);
	cout << "Input rectangle 2 length and width" << endl;
	cout << " Length: ";
	cin >> length;
	rectangleZwei.setLength(length);
	cout << " Wdth: ";
	cin >> width;
	rectangleZwei.setWidth(width);

	/*construct a new rectangle*/
	id = Rectangle::getNum();
	cout << "Input rectangle 3 length and width" << endl;
	cout << " Length: ";
	cin >> length;
	while (lengthNotInRange)
	{	
		/*check length range*/
		if (length < 0.0 || length > 10.0)
		{
			cout << "length should be form 0 to 10." << endl;
			cout << " Length: ";
			cin >> length;
		}
		else
		{
			lengthNotInRange = false;
		}
	}
	cout << " Wdth: ";
	cin >> width;
	while (widthNotInRange)
	{
		/*check width range*/
		if (width < 0.0 || width > 10.0)
		{
			cout << "width should be form 0 to 10." << endl;
			cout << " Length: ";
			cin >> width;
		}
		else
		{
			widthNotInRange = false;
		}
	}
	Rectangle rectangleDrei(id, length, width);
	
	cout << endl;
	/*print information*/
	rectangleEins.rectInfo();
	rectangleZwei.rectInfo();
	rectangleDrei.rectInfo();

	system("pause");
	return 0;
}