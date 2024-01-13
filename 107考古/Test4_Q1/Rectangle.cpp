#include <iostream>
#include "Rectangle.h"

namespace NUTNCSIE{
	// constructor 
	Rectangle::Rectangle() :width(0), height(0) {}

	Rectangle::Rectangle(string theColor, double theWidth, double theHeight) : Figure(theColor), width(theWidth), height(theHeight) {
		setRate(2.4);
	}

	double Rectangle::getWidth() { return width; }

	void Rectangle::setWidth(double theWidth) { width = theWidth; }

	double Rectangle::getHeight() { return height; }

	void Rectangle::setHeight(double theHeight) { height = theHeight; }

	void Rectangle::printinfo() {
		cout << "Class: " << getClassName() << endl << "Color: " << getColor() << endl;
	    cout << "Width: " << width << ", Height: " << height << endl;
		cout << "Area: " << compArea() << endl;
		cout << "Perimeter: " << compPerimeter() << endl;
		cout << "Price: " << compPrice() << " with Rate= " << getRate() << endl;
	}

	double Rectangle::compArea() {
		return width * height;
	}

	double Rectangle::compPerimeter() {

		return 2 * (width + height);
	}

	double Rectangle::compPrice() {
		return compArea() * getRate();
	}

	string Rectangle::getClassName() { return className; }
}

