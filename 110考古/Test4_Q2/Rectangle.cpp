#include <iostream>
#include "Rectangle.h"
#include <string>
using namespace std;

Rectangle::Rectangle() : Figure(), width(1), height(1){}                    //�w�]�غc��
Rectangle::Rectangle(string theColor, double theWidth, double theHeight)    //�غc��
	: Figure(theColor), width(theWidth), height(theHeight){}

void Rectangle::setHeight(double newHeight){                                 //�]�wheight
	height = newHeight;
}

double Rectangle::getHeight() const{                                         //���oheight�� 
	return height;
}

void Rectangle::setWidth(double newWidth){                                   //�]�wwidth
	width = newWidth;
}

double Rectangle::getWidth() const{                                          //���owidth��
	return width;
}

string Rectangle::getClass() const{                                          //���oclass�W��
	return "Rectangle";
}

void Rectangle::printinfo(){                                                 //��X��T
	cout << "class: " << getClass() << endl;
	cout << "color: " << getColor() << endl;
	cout << "width: " << getWidth() << ", height: " << getHeight() <<endl;
	cout << "area: " << compArea() << endl;
	cout << "perimeter: " << compPerimeter() << endl;
	cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
	cout << "------------------------------------------------" << endl;
}

double Rectangle::compArea(){                                                 //�p�⭱�n
	return width*height;
}

double Rectangle::compPerimeter(){                                            //�p��P��
	return (width+height)*2;
}

double Rectangle::compPrice(){                                                //�p�����
	return getRate()*compArea();
}