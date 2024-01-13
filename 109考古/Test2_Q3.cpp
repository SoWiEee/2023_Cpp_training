#include<iostream>
using namespace std;

class HotDogStand
{
public:
	HotDogStand();								/*Initialize hotdog stand									*/
	HotDogStand(int newId, int newSold);		/*Initialize hotdog stand with Id number and sold number	*/
	void setId(int newId);						/*set hotdogstand's ID										*/
	void setSold(int newSold);					/*set number of hotdog sold									*/
	int getId() { return this->id; }			/*get hotdogstand's ID										*/
	int getSold() { return this->sold; }		/*get number of hotdog sold									*/
	static int getTotalsold();					/*get total hotdogstand sold number							*/
	void JustSold();							/*increment 1 hotdog sold									*/
private:
	int id;										/*hotdogstand's ID											*/
	int sold;									/*hotdog sold by a stand									*/
	static int totalSold;						/*total number of hotdog sold								*/
};

/*Initialize hotdog stand*/
HotDogStand::HotDogStand() : id(0), sold(0)
{
}

/*Initialize hotdog stand with Id number and sold number*/
HotDogStand::HotDogStand(int newId, int newSold) : id(newId), sold(newSold)
{
	totalSold = totalSold + newSold;
}

/*set hotdogstand's ID*/
void HotDogStand::setId(int newId)
{
	this->id = newId;
}

/*set number of hotdog sold*/
void HotDogStand::setSold(int newSold)
{
	this->sold = newSold;
}

/*get total hotdogstand sold number*/
int HotDogStand::getTotalsold()
{
	return totalSold;
}

/*increment 1 hotdog sold*/
void HotDogStand::JustSold()
{
	this->sold++;
	totalSold++;
}

int HotDogStand::totalSold = 0;

int main()
{
	/*construct 3 hotdogstand			*/
	HotDogStand hotdogstandEins(1,7), hotdogstandZwei(2,4), hotdogstandDrei(3,4);
	
	/*print information					*/
	cout << "HotDogStand 1 sold " << hotdogstandEins.getSold() << " hotdogs." << endl;
	cout << "HotDogStand 2 sold " << hotdogstandZwei.getSold() << " hotdogs." << endl;
	cout << "HotDogStand 3 sold " << hotdogstandDrei.getSold() << " hotdogs." << endl;
	cout << "Total sold " << HotDogStand::getTotalsold() << " hotdogs." << endl;

	/*hotdogstand 1 sells 2 hotdogs		*/
	hotdogstandEins.JustSold();
	hotdogstandEins.JustSold();
	/*hotdogstand 2 sells 4 hotdog		*/
	hotdogstandZwei.JustSold();
	hotdogstandZwei.JustSold();
	hotdogstandZwei.JustSold();
	hotdogstandZwei.JustSold();
	/*hotdogstand sells 3 hotdog		*/
	hotdogstandDrei.JustSold();
	hotdogstandDrei.JustSold();
	hotdogstandDrei.JustSold();
	cout << endl;
	/*print result						*/
	cout << "HotDogStand 1 sold " << hotdogstandEins.getSold() << " hotdogs." << endl;
	cout << "HotDogStand 2 sold " << hotdogstandZwei.getSold() << " hotdogs." << endl;
	cout << "HotDogStand 3 sold " << hotdogstandDrei.getSold() << " hotdogs." << endl;
	cout << "Total sold " << HotDogStand::getTotalsold() << " hotdogs." << endl;

	system("pause");
	return 0;
}