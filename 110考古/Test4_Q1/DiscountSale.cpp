#include <iostream>
#include "DiscountSale.h"
#include <string>
using namespace std;

DiscountSale::DiscountSale() : Sale(), discount(0){}                              //預設建構式
DiscountSale::DiscountSale(string theItem, double thePrice, double theDiscount)   //建構式
	: Sale(theItem, thePrice), discount(theDiscount){}

void DiscountSale::setDiscount(double newDiscount){                               //設定discount
	discount = newDiscount;
}

double DiscountSale::getDiscount() const{                                         //取得discount值
	return discount;
}

double DiscountSale::bill() const{                                                //取得bill(帳單)
	double f = discount / 100;
	return (1-f)*getPrice();
}

void DiscountSale::PrintInfo(){                                                   //輸出資訊
	cout << "item : " << getItem() << endl;
	cout << "price : $" << getPrice() << endl;
	cout << "discount : " << getDiscount() << "%" << endl;
	cout << "price after discount : $" << bill() << endl;
	cout << "----------------------------------" << endl;
}