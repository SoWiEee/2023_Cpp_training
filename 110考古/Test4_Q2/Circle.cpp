#include <iostream>
#include "Circle.h"
#include "Point.h"
#include <string>
using namespace std;

Circle::Circle() : Figure(), radius(1), center(0,0){}                                     //�w�]�غc��
Circle::Circle(string theColor, double theRadius, Point theCenter)                        //�غc��
	: Figure(theColor), radius(theRadius), center(theCenter){}                              

void Circle::setRadius(double newRadius){                                                 //�]�wradius
	radius = newRadius;
}

double Circle::getRadius() const{                                                         //���oradius��
	return radius;
}

void Circle::setCenter(Point newCenter){                                                  //�]�wcenter
	center = newCenter;
}

Point Circle::getCenter() const{                                                          //���ocenter��
	return center;
}

string Circle::getClass() const{                                                          //���oclass�W��
	return "Circle";
}

void Circle::printinfo(){                                                                 //��X��T
	cout << "class: " << getClass() << endl;
	cout << "color: " << getColor() << endl;
	cout << "center: (" << getCenter().getX() << "," << getCenter().getY() << ")"<< endl;
	cout << "radius: " << getRadius() <<endl;
	cout << "area: " << compArea() << endl;
	cout << "perimeter: " << compPerimeter() << endl;
	cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
	cout << "------------------------------------------------" << endl;
}

double Circle::compArea(){                                                                //�p�⭱�n
	return radius*radius*3.14;
}

double Circle::compPerimeter(){                                                           //�p��P��
	return radius*2*3.14;
}

double Circle::compPrice(){                                                               //�p�����
	return getRate()*compArea();
}