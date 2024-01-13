#include <iostream>
#include "Sale.h"
#include <string>
using namespace std;

Sale::Sale() : price(0){                                  //預設建構式
	item = "";
}
Sale::Sale(string theItem, double thePrice){              //建構式
	item = theItem;
	if (thePrice >= 0)
		price = thePrice;
	else{
		cout << "Error: Cannot have a negative price!\n";
		exit(1);
	}
}

void Sale::setItem(string newItem){                        //設定item
	item = newItem;
}

string Sale::getItem() const{                              //取得item值
	return item;
}

void Sale::setPrice(double newPrice){                      //設定price
	if (newPrice >= 0)
		price = newPrice;
	else{
		cout << "Error: Cannot have a negative price!\n";
		exit(1);
	}
}

double Sale::getPrice() const{                              //取得price值
	return price;
}

double Sale::bill() const{                                  //取得bill(帳單)
	return price;
}

double Sale::savings(const Sale& other) const{              //取得saving(儲存的錢)
	return (bill() - other.bill());
}

void Sale::PrintInfo(){                                     //輸出資訊
	cout << "item : " << getItem() << endl;
	cout << "price : $" << getPrice() << endl;
	cout << "----------------------------------" << endl;
}

bool operator < (const Sale& first, const Sale& second){     //比較bill
	return (first.bill() < second.bill());
}