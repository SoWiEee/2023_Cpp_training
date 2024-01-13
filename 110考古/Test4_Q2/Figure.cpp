#include <iostream>
#include "Figure.h"
#include <string>
using namespace std;

Figure::Figure() : color(""){}                        //預設建構式
Figure::Figure(string theColor) : color(theColor){}   //建構式

void Figure::setColor(string newColor){               //設定color
	color = newColor;
}

string Figure::getColor() const{                      //取得color值
	return color;
}

void Figure::setRate(double newRate){                 //設定rate
	rate = newRate;
}

double Figure::getRate() const{                       //取得rate值
	return rate;
}

void Figure::printinfo(){                             //輸出資訊
	cout << "color: " << getColor() << endl;
	cout << "rate: " << getRate() << endl;
}

double Figure::compArea(){                             //計算面積，預設為0
	return 0;
}

double Figure::compPerimeter(){                        //計算周長，預設為0
	return 0;
}

double Figure::compPrice(){                            //計算價錢
	return rate*compArea();
}