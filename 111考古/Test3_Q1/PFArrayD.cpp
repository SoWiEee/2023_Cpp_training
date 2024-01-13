#include <iostream>
#include "PFArrayD.h"
using std::cin;
using std::cout;

namespace NUTNCSIE {
	//PFArratD's constructor.
	PFArrayD::PFArrayD() : a(nullptr), capacity(0), used(0) {/*Empty*/ }

	//PFArratD's destructor.
	PFArrayD::~PFArrayD() {
		delete[] a;
	}

	//PFArratD's constructor.
	PFArrayD::PFArrayD(const int capacity_value) : a(new double[capacity_value]), capacity(capacity_value), used(0) {/*Empty*/ }

	//PFArratD's constructor.
	PFArrayD::PFArrayD(const double *a_value, const int capacity_value, const int used_value) : a(new double[capacity_value]), capacity(capacity_value), used(used_value) {
		//Checks if capacity_value and used_value is a invalid value.
		if (capacity_value < 0 || used_value < 0 || capacity_value < used_value) {
			cout << "Error! The capacity_value is a invalid value!\n";
			system("pause");
			exit(0);
		}
		else {
			//Puts "a_value" array's number to "a" array.
			for (int i = 0; i < used_value; i++) {
				a[i] = a_value[i];
			}
			delete[] a_value;	//Releases "a_value" memory.
		}
	}

	//Copy constructor.
	PFArrayD::PFArrayD(const PFArrayD& object) : capacity(object.get_capacity()), used(object.get_used()) {
		a = new double[capacity];
		for (int i = 0; i < used; i++)
			a[i] = object.a[i];
	}

	//Sets new capacity of PFArratD class.
	void PFArrayD::set_capacity(const int capacity_value) {
		//Checks if capacity_value is a invalid value.
		if (capacity_value < used || capacity_value < 0) {
			cout << "Error! The capacity_value is a invalid value!\n";
			system("pause");
			exit(0);
		}
		else {
			//Sets a new double class "a_contain",it's capacity extend or reduce to "capacity_value".
			double *a_contain = new double[capacity_value];
			for (int i = 0; i < used; i++)
				a_contain[i] = a[i];
			capacity = capacity_value;
			delete[] a;
			a = a_contain;
		}
	}

	//Sets new number of used on the PFArratD class.
	void PFArrayD::set_used(const int used_value) {
		if (capacity < used_value || used_value < 0) {
			cout << "Error! The used_value is a invalid value!\n";
			system("pause");
			exit(0);
		}
		else
			used = used_value;
	}

	//Get capacity of the PFArrayD class.
	int PFArrayD::get_capacity() const {
		return capacity;
	}

	//Get number of used on the PFArratD class.
	int PFArrayD::get_used() const {
		return used;
	}

	//Adds new element on the PFArray class.
	void PFArrayD::addElement(const double element) {
		if (!full()) {
			a[used] = element;
			used += 1;
		}
		else
			cout << "Error! The array is full.\n";
	}

	//Checks if the PFArrayD class's capacity is full.
	bool PFArrayD::full() const {
		return capacity == used;
	}

	//Sets operator '+' overloading.
	const PFArrayD operator +(const PFArrayD& object1, const PFArrayD& object2) {
		//Sets new capacity and new double object,initial setting new used is 0.
		int new_capacity = object1.capacity + object2.capacity;
		double *a_contain = new double[new_capacity];
		int new_used = 0;

		//Stores object1's all elements and counts number of the used.
		for (int i = 0; i < object1.used; i++) {
			a_contain[new_used] = object1.a[i];
			new_used++;
		}

		//Stores object2's all elements and counts number of the used.
		for (int i = 0; i < object2.used; i++) {
			a_contain[new_used]= object2.a[i];
			new_used++;
		}
		return PFArrayD(a_contain, new_capacity, new_used);
	}

	//Sets operator '[]' overloading.
	double& PFArrayD::operator [](const int index) const {
		//Check if index is a invalid value.
		if (index < 1 || index > capacity) {
			cout << "Error! The index is a invalid value!\n";
			system("pause");
			exit(0);
		}
		else if (index > used) {
			cout << "Error! The index is not used!\n";
			system("pause");
			exit(0);
		}
		else
			return a[index-1];
	}

	//Sets operator '=' overloading.
	PFArrayD& PFArrayD::operator =(const PFArrayD& object) {
		//Sets PFArratD new object to be returned,and define a array container.
		capacity = object.capacity;
		used = object.used;
		delete[] a;
		a = new double[capacity];

		//Store all element.
		for (int i = 0; i < used; i++)
			a[i] = object.a[i];

		return *this;
	}
}
