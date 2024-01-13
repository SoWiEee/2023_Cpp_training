#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <string>
using namespace std;

namespace NUTNCSIE
{
	class Rectangle : public Figure {
	public:
		// constructor
		Rectangle();
		Rectangle(string, double, double);

		// set and get
		double getWidth();
		void setWidth(double);
		void setHeight(double);
		double getHeight();
		string getClassName();

		// needed function
		void printinfo();
		double compArea();
		double compPerimeter();
		double compPrice();
	private:
		double width;
		double height;
		const string className = "Rectangle";
	};
}

#endif