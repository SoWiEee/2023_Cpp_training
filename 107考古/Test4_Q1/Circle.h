#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include "Point.h"
#include <string>
using namespace std;

namespace NUTNCSIE
{
	class Circle : public Figure {
	public:
		// constructor
		Circle();
		Circle(string, double, Point);

		// set and get
		double getRadius();
		void setRadius(double);
		Point getCenter();
		void setCenter(Point);	
		string getClassName();

		// needed function
		void printinfo();
		double compArea();
		double compPerimeter();
		double compPrice();
	private:
		double radius;
		const string className = "Circle";
		Point center;
	};
}

#endif