#ifndef POINT_H
#define POINT_H
#include <string>
using namespace std;

class Point{
public:
	Point();                    //�w�]�غc��
	Point(int theX, int theY);  //�غc��
	void setX(int newX);        //set�Mget function......
	int getX() const;
	void setY(int newY);
	int getY() const;
private:
	int x;
	int y;
};

#endif