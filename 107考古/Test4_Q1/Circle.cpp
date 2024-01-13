#include <iostream>
#include "Circle.h"

#define PI 3.14

namespace NUTNCSIE{
	// constructor 
	Circle::Circle() :radius(0) {}

	Circle::Circle(string thecolor, double theRadius, Point theCenter) : Figure(thecolor), radius(theRadius) {
		setRate(3.2);
		setCenter(theCenter);
	}

	double Circle::getRadius() { return radius; }

	void Circle::setRadius(double theRadius) { radius = theRadius; }

	Point Circle::getCenter() { return center; }

	void Circle::setCenter(Point theCenter) { center = theCenter; }

	void Circle::printinfo() {
		cout << "Class: " << getClassName() << endl << "Color: " << getColor() << endl;
		cout << "Center: " << "(" << getCenter().getX() << "," << getCenter().getY() << ")" << endl << "Radius: " << radius << endl;
		cout << "Area: " << compArea() << endl;
		cout << "Perimeter: " << compPerimeter() << endl;
		cout << "Price: " << compPrice() << " with Rate= " << getRate() << endl;
	}

	double Circle::compArea() {
		return radius * radius * PI;
	}

	double Circle::compPerimeter() {
		return 2 * radius * PI;
	}

	double Circle::compPrice() {
		return compArea() * getRate();
	}

	string Circle::getClassName() { return className; }
}

