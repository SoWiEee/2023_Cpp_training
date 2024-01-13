#include <iostream>  
using namespace std;

class HotDogStand {
public:
	//constructors
	HotDogStand();
	HotDogStand(int id, int sold);
	//set and get function
	void setId(int id);
	int getId() const;
	void setSold(int sold);
	int getSold() const;
	void JustSold();
	static int getTotalSold();
private:
	int id;
	int sold;
	static int totalSold;
};

//initialize
int HotDogStand::totalSold = 0;

//default constructor
HotDogStand::HotDogStand() :id(0), sold(0){}

//constructor
HotDogStand::HotDogStand(int id, int sold){
	this->id = id;
	this->sold = sold;
	totalSold += sold;
}

void HotDogStand::setId(int id){
	this->id = id;
}

int HotDogStand::getId() const{
	return id;
}

void HotDogStand::setSold(int sold){
	this->sold = sold;
}

int HotDogStand::getSold() const{
	return sold;
} 

void HotDogStand::JustSold(){
	sold += 1;
	totalSold += 1;
}

int HotDogStand::getTotalSold(){
	return totalSold;
}

int main(){
	HotDogStand stand1(1,4), stand2(2,2), stand3(3,6);

	cout << "The hot dog stand" << stand1.getId() << " sells " << stand1.getSold() << " hotdogs." << endl;
	cout << "The hot dog stand" << stand2.getId() << " sells " << stand2.getSold() << " hotdogs." << endl;
	cout << "The hot dog stand" << stand3.getId() << " sells " << stand3.getSold() << " hotdogs." << endl;
	cout << "All hot dog stands sell " << HotDogStand::getTotalSold() << " hotdogs." << endl << endl;

	//increment the number of the hot dogs all stand has sold by one.
	stand1.JustSold();
	stand2.JustSold();
	stand3.JustSold();

	cout << "The hot dog stand" << stand1.getId() << " sells " << stand1.getSold() << " hotdogs." << endl;
	cout << "The hot dog stand" << stand2.getId() << " sells " << stand2.getSold() << " hotdogs." << endl;
	cout << "The hot dog stand" << stand3.getId() << " sells " << stand3.getSold() << " hotdogs." << endl;
	cout << "All hot dog stands sell " << HotDogStand::getTotalSold() << " hotdogs." << endl;

	system("pause");
	return 0;
}