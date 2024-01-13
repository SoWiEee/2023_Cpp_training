#include <iostream>
#include "Point.h"

namespace NUTNCSIE{
	// constructor
	Point::Point() : x(0), y(0){
	}

	Point::Point(int theX, int theY) : x(theX), y(theY){

	}

	// set and get
	int Point::getX(){
		return x;
	}

	void Point::setX(int theX){
		x = theX;
	}

	int Point::getY(){
		return y;
	}

	void Point::setY(int theY){
		y = theY;
	}
}