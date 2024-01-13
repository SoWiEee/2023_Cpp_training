#include <iostream>
#include "Point.h"
#include <string>
using namespace std;

Point::Point() : x(0), y(0){}                          //預設建構式
Point::Point(int theX, int theY) : x(theX), y(theY){}  //建構式

void Point::setX(int newX){                            //設定x
	x = newX;
}

int Point::getX() const{                               //取得x值
	return x;
}

void Point::setY(int newY){                            //設定y
	y = newY;
}
int Point::getY() const{                               //取得y值
	return y;
}