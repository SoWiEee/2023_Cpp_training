#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include "Point.h"
#include <string>
using namespace std;

class Circle : public Figure{
public:
	Circle();                                                    //�w�]�غc��
	Circle(string theColor, double theRadius, Point theCenter);  //�غc��
	void setRadius(double newRadius);                            //set�Mget function......
	double getRadius() const;
	void setCenter(Point newCenter);
	Point getCenter() const;
	string getClass() const;
	virtual void printinfo();                                    //�D�حn�D��function......
	virtual double compArea();
	virtual double compPerimeter();
	virtual double compPrice(); 
private:
	double radius;
	Point center;
};

#endif