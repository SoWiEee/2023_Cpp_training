#ifndef FIGURE_H
#define FIGURE_H
#include <string>
using namespace std;

namespace NUTNCSIE
{
	class Figure {
	public:
		// constructor
		Figure();
		Figure(string);

		// set and get
		string getColor();
		void setColor(string);
		double getRate();
		void setRate(double);

		// needed function
		virtual void printinfo()=0;
		virtual double compArea()=0;
		virtual double compPerimeter()=0;
		virtual double compPrice()=0;
		virtual string getClassName() = 0;	
	private:
		double rate = 1.2;
		string color;
	};
}

#endif
