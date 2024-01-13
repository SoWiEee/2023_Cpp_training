#ifndef POINT_H
#define POINT_H
#include <string>
using namespace std;

namespace NUTNCSIE
{
	class Point {
	public:
		// constructor
		Point();
		Point(int x, int y);

		// set and get
		int getX();
		void setX(int);
		int getY();
		void setY(int);
	private:
		int x;
		int y;
	};
}

#endif
