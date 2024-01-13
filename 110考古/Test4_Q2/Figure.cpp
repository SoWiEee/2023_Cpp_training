#include <iostream>
#include "Figure.h"
#include <string>
using namespace std;

Figure::Figure() : color(""){}                        //�w�]�غc��
Figure::Figure(string theColor) : color(theColor){}   //�غc��

void Figure::setColor(string newColor){               //�]�wcolor
	color = newColor;
}

string Figure::getColor() const{                      //���ocolor��
	return color;
}

void Figure::setRate(double newRate){                 //�]�wrate
	rate = newRate;
}

double Figure::getRate() const{                       //���orate��
	return rate;
}

void Figure::printinfo(){                             //��X��T
	cout << "color: " << getColor() << endl;
	cout << "rate: " << getRate() << endl;
}

double Figure::compArea(){                             //�p�⭱�n�A�w�]��0
	return 0;
}

double Figure::compPerimeter(){                        //�p��P���A�w�]��0
	return 0;
}

double Figure::compPrice(){                            //�p�����
	return rate*compArea();
}