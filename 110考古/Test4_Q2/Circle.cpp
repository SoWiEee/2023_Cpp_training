#include <iostream>
#include "Circle.h"
#include "Point.h"
#include <string>
using namespace std;

Circle::Circle() : Figure(), radius(1), center(0,0){}                                     //預設建構式
Circle::Circle(string theColor, double theRadius, Point theCenter)                        //建構式
	: Figure(theColor), radius(theRadius), center(theCenter){}                              

void Circle::setRadius(double newRadius){                                                 //設定radius
	radius = newRadius;
}

double Circle::getRadius() const{                                                         //取得radius值
	return radius;
}

void Circle::setCenter(Point newCenter){                                                  //設定center
	center = newCenter;
}

Point Circle::getCenter() const{                                                          //取得center值
	return center;
}

string Circle::getClass() const{                                                          //取得class名稱
	return "Circle";
}

void Circle::printinfo(){                                                                 //輸出資訊
	cout << "class: " << getClass() << endl;
	cout << "color: " << getColor() << endl;
	cout << "center: (" << getCenter().getX() << "," << getCenter().getY() << ")"<< endl;
	cout << "radius: " << getRadius() <<endl;
	cout << "area: " << compArea() << endl;
	cout << "perimeter: " << compPerimeter() << endl;
	cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
	cout << "------------------------------------------------" << endl;
}

double Circle::compArea(){                                                                //計算面積
	return radius*radius*3.14;
}

double Circle::compPerimeter(){                                                           //計算周長
	return radius*2*3.14;
}

double Circle::compPrice(){                                                               //計算價錢
	return getRate()*compArea();
}