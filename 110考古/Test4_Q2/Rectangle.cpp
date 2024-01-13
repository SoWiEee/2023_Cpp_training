#include <iostream>
#include "Rectangle.h"
#include <string>
using namespace std;

Rectangle::Rectangle() : Figure(), width(1), height(1){}                    //預設建構式
Rectangle::Rectangle(string theColor, double theWidth, double theHeight)    //建構式
	: Figure(theColor), width(theWidth), height(theHeight){}

void Rectangle::setHeight(double newHeight){                                 //設定height
	height = newHeight;
}

double Rectangle::getHeight() const{                                         //取得height值 
	return height;
}

void Rectangle::setWidth(double newWidth){                                   //設定width
	width = newWidth;
}

double Rectangle::getWidth() const{                                          //取得width值
	return width;
}

string Rectangle::getClass() const{                                          //取得class名稱
	return "Rectangle";
}

void Rectangle::printinfo(){                                                 //輸出資訊
	cout << "class: " << getClass() << endl;
	cout << "color: " << getColor() << endl;
	cout << "width: " << getWidth() << ", height: " << getHeight() <<endl;
	cout << "area: " << compArea() << endl;
	cout << "perimeter: " << compPerimeter() << endl;
	cout << "price: " << compPrice() << ", with rate= " << getRate() << endl;
	cout << "------------------------------------------------" << endl;
}

double Rectangle::compArea(){                                                 //計算面積
	return width*height;
}

double Rectangle::compPerimeter(){                                            //計算周長
	return (width+height)*2;
}

double Rectangle::compPrice(){                                                //計算價錢
	return getRate()*compArea();
}