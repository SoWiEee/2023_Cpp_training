#ifndef SALE_H
#define SALE_H
#include <string>
using namespace std;

class Sale{
public:
	Sale();                                     //預設建構式
	Sale(string theItem, double thePrice);      //建構式
	void setItem(string newItem);               //set和get function......
	string getItem() const;
	void setPrice(double newPrice);
	double getPrice() const;	
	virtual double bill() const;                //題目要求的函式......
	double savings(const Sale& other) const;
	virtual void PrintInfo();
private:
	string item;
	double price;
};

bool operator < (const Sale& first, const Sale& second);  

#endif