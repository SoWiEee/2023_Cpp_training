#ifndef POINT_H
#define POINT_H
#include <string>
using namespace std;

class Point{
public:
	Point();                    //預設建構式
	Point(int theX, int theY);  //建構式
	void setX(int newX);        //set和get function......
	int getX() const;
	void setY(int newY);
	int getY() const;
private:
	int x;
	int y;
};

#endif