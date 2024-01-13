#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <string>
using namespace std;

class Rectangle : public Figure{
public:
	Rectangle();                                                    //�w�]�غc��
	Rectangle(string theColor, double theWidth, double theHeight);  //�غc��
	void setWidth(double newWidth);                                 //set�Mget function......
	double getWidth() const;
	void setHeight(double newHeight);
	double getHeight() const;
	string getClass() const;
	virtual void printinfo();                                       //�D�حn�D��function...... 
	virtual double compArea();
	virtual double compPerimeter();
	virtual double compPrice(); 
private:
	double height;
	double width;
};

#endif