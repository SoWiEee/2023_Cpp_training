#include <iostream>
#include "Figure.h"

namespace NUTNCSIE{
	// constructor
	Figure::Figure() : color("BLACK"){
	}

	Figure::Figure(string theColor) : color(theColor){

	}

	// set and get
	string Figure::getColor(){
		return color;
	}

	void Figure::setColor(string theColor){
		color = theColor;
	}

	double Figure::getRate(){
		return rate;
	}

	void Figure::setRate(double theRate){
		rate = theRate;
	}
}