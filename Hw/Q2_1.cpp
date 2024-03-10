#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void){
    // get inputs
    float layer, basePrice, amenitie, amenitieRate, tax, taxRate;
    cout << "Floors => ";
	cin >> layer;
	cout << "Base Price => ";
	cin >> basePrice;
	cout << "The rate of amenities(%) => ";
	cin >> amenitieRate;
	cout << "The rate of taxes(%) => ";
	cin >> taxRate;

    amenitieRate /= 100;
	taxRate /= 100;

    for(int i = 0; i < layer; i++) {
        amenitie = basePrice * amenitieRate;
		tax = basePrice * (amenitieRate + 1) * taxRate;

		cout << "Floor " << i + 1 << " :" << endl;
		cout << "Base Price : $" << basePrice << endl;
		cout << "The charges on amenities : $" << amenitie << endl;
		cout << "The taxes : $" << tax << endl;
		cout << "Total cost : $" << basePrice + amenitie + tax << "\n" << endl;
		basePrice *= 1.02;
    }

    system("pause");
    return 0;
}

