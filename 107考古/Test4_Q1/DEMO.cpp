#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Point.h"
#include "Circle.h"
using namespace std;
using namespace NUTNCSIE;

void listFig(Figure*);

int main(){
	 Figure* f[5];

	 f[0] = new Rectangle("RED", 10.2, 3.6);
	 f[1] = new Rectangle("ORANGLE", 14, 8.1);
	 f[2] = new Rectangle("BLUE", 12.8, 60.6);
	 f[3] = new Circle("PINK", 10.5, Point(12, 20));
	 f[4] = new Circle("PURPLE", 6.4, Point(14, 3));

	for (int i = 0; i < 5; i++) {
		listFig(f[i]);
	 }

	system("PAUSE");
	return 0;
}

void listFig(Figure* fig) {
	
	fig->printinfo();
	
	cout << "---------------------------------------------- "<< endl;
}