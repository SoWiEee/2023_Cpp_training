#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"
#include <string>
using namespace std;

void listFig(Figure* fig){
	fig -> printinfo();
}

int main(){
	Figure* f[5];
	f[0] = new Rectangle("RED", 10.2, 3.6);
	f[1] = new Rectangle("ORANGLE", 14, 8.1);
	f[2] = new Rectangle("BLUE", 12.8, 60.6);
	f[3] = new Circle("PINK", 10.5, Point(12,20));
	f[4] = new Circle("PURPLE", 6.4, Point(14,3));

	f[0] -> setRate(2.4);                            //設定5個圖形的rate
	f[1] -> setRate(2.4);
	f[2] -> setRate(2.4);
	f[3] -> setRate(3.2);
	f[4] -> setRate(3.2);

	for(int i=0; i<5; i++)                           //輸出資訊
		listFig(f[i]);

	system("pause");
	return 0;
}