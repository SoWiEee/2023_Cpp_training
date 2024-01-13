#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <string>
using namespace std;

class Rectangle : public Figure{
public:
	Rectangle();                                                    //預設建構式
	Rectangle(string theColor, double theWidth, double theHeight);  //建構式
	void setWidth(double newWidth);                                 //set和get function......
	double getWidth() const;
	void setHeight(double newHeight);
	double getHeight() const;
	string getClass() const;
	virtual void printinfo();                                       //題目要求的function...... 
	virtual double compArea();
	virtual double compPerimeter();
	virtual double compPrice(); 
private:
	double height;
	double width;
};

#endif