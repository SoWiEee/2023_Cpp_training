#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

double ConvertToMPH(int min, int sec);
double ConvertToMPH(double KPH);
const int times = 10;   // control number of tests
const int perHourToSec = 3600;

int main(){
	int min, sec;
	double KPH;

	/* set the seed of random function */
	srand((unsigned)time(NULL));

	/* control width of number */
	cout << setprecision(4);


	/* test ConvertToMPH with two integers */
	cout << "Test ConvertToMPH with two integers" << endl;
	for (int i = 0; i < times; ++i){
		min = rand() % 13;
		sec = rand() % 60;
		cout << "Min is " << min << " , Sec is " << sec << endl;
		cout << "MPH is " << ConvertToMPH(min, sec) << endl;
	}
	
	cout << endl;

	/* test ConvertToMPH with a double */
	cout << "Test ConvertToMPH with a double" << endl;
	for (int i = 0; i < times; ++i){
		KPH = (double)(rand() % 100 + 1) / (double)(rand() % 10 + 1);
		cout << "KPH is " << KPH;
		cout << " , MPH is " << ConvertToMPH(KPH) << endl;;
	}

	cout << endl;

	system("PAUSE");
	return 0;
}


/* calculate */
double ConvertToMPH(int min, int sec){
	double time = perHourToSec / ((double)min * 60 + (double)sec);

	return time;
}

/* calculate */
double ConvertToMPH(double KPH){
	double MPH = KPH / 1.61;

	return MPH;
}