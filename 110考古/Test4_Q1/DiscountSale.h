#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "Sale.h"
#include <string>
using namespace std;

class DiscountSale : public Sale{
public:
	DiscountSale();                                                      //預設建構式
	DiscountSale(string theItem, double thePrice, double theDiscount);   //建構式
	void setDiscount(double newDiscount);                                //set function								
	double getDiscount() const;                                          //get function
	virtual double bill() const;                                         //題目要求的函式......
	virtual void PrintInfo();
private:
	double discount;
};

#endif