#include <iostream>
#include "Point.h"
#include <string>
using namespace std;

Point::Point() : x(0), y(0){}                          //�w�]�غc��
Point::Point(int theX, int theY) : x(theX), y(theY){}  //�غc��

void Point::setX(int newX){                            //�]�wx
	x = newX;
}

int Point::getX() const{                               //���ox��
	return x;
}

void Point::setY(int newY){                            //�]�wy
	y = newY;
}
int Point::getY() const{                               //���oy��
	return y;
}