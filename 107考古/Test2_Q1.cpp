#include <iostream>
#include <cstdlib>

using namespace std;

class HotDogStand{
public:
	
	// Create at least two Constructors
	HotDogStand();
	HotDogStand(int ID);
	HotDogStand(int ID, int sold);
	
	// Accessor and Mutator
	int getID() const;
	int getsold() const;
	int gettotalSold() const;
	void setID(int ID);
	void setsold(int sold);

	// Save number of hot dog sold by one stand
	void JustSold();

private:
	int ID = 0;
	int sold = 0;
	int static totalSold;

};

int HotDogStand::totalSold = 0;


int main(){
	HotDogStand Object1(1, 2);
	HotDogStand Object2(2, 4);
	HotDogStand Object3(3, 3);
	
	cout << "Stand ID : " << Object1.getID() << endl;
	cout << "Number of hot dog sold : " << Object1.getsold() << endl;

	cout << "Stand ID : " << Object2.getID() << endl;
	cout << "Number of hot dog sold : " << Object2.getsold() << endl;

	cout << "Stand ID : " << Object3.getID() << endl;
	cout << "Number of hot dog sold : " << Object3.getsold() << endl;

	cout << endl;
	cout << "Total sold " << Object1.gettotalSold() << endl;

	system("pause");
	return 0;
}



HotDogStand::HotDogStand(){
	ID = 0;
	sold = 0;
}

HotDogStand::HotDogStand(int ID){
	setID(ID);
}

HotDogStand::HotDogStand(int ID, int sold){
	setID(ID);
	setsold(sold);
	totalSold += sold;
}

int HotDogStand::getID() const {
	return ID;
}

int HotDogStand::getsold() const {
	return sold;
}

void HotDogStand::setID(int ID){
	this->ID = ID;
}

void HotDogStand::setsold(int sold){
	this->sold = sold;
}

void HotDogStand::JustSold(){
	++sold;
	++totalSold;
}

int HotDogStand::gettotalSold() const{
	return totalSold;
}