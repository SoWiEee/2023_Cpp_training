#ifndef FIGURE_H
#define FIGURE_H
#include <string>
using namespace std;

class Figure{
public:
	Figure();                         //�w�]�غc��
	Figure(string theColor);          //�غc��
	void setColor(string newColor);   //set�Mget function......
	string getColor() const;
	void setRate(double newRate);
	double getRate() const;
	virtual void printinfo();         //�D�حn�D��function......
	virtual double compArea();
	virtual double compPerimeter();
	virtual double compPrice();
private:
	string color;
	double rate;
};

#endif