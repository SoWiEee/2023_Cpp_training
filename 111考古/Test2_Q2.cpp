#include<iostream>
using namespace std;

class Rectangle {
public:
	// default constructor
	// set length and width to 0.1
	Rectangle();
	// set length and width of this rectangle
	Rectangle(const double lengthValue, const double widthValue);

	// get functions
	double getLength() const { return length; };
	double getWidth() const { return width; };

	// set functions
	void setLength(const double lengthValue);
	void setWidth(const double widthValue);

	// print the rectangle's informations
	void printRectangle() const;
private:
	double length;
	double width;
};

class Cuboid {
public:
	// default constructor
	// set length, width, height, and density to 0.1
	Cuboid();
	// check value is valid and set attribute to them
	Cuboid(double lengthValue, double widthValue, double heightValue, double densityValue);

	// get functions
	double getLength() const { return rect.getLength(); }
	double getWidth() const { return rect.getWidth(); }
	double getHeight() const { return height; }
	double getDensity() const { return density; }
	static int getNum() { return num; }
	int getId() const { return id; }

	// set functions
	void setLength(const double lengthValue);
	void setWidth(const double widthValue);
	void setHeight(const double heightValue);
	void setDensity(const double densityValue);
	void setRect(const Rectangle& rectValue);

	// compare volume
	bool compVol(Cuboid&) const;

	// print the information of the cuboid
	void printCuboid() const;
private:
	int id;
	static int num;
	double density;
	double height;
	Rectangle rect;

};

// output whether the first Cuboid object is heavier than second one
bool compCubWeight(const Cuboid&, const Cuboid&);

// set the static variable
int Cuboid::num = 0;

int main(void) {
	Cuboid cuboid1(3.2, 9.8, 15.6, 0.8);
	Cuboid cuboid2(5.2, 7.6, 10.2, 1.2);

	// if success to construct two object
	// then print two cuboid's information and compare two cuboid
	if (Cuboid::getNum() == 2) {
		cuboid1.printCuboid();
		cuboid2.printCuboid();

		if (cuboid1.compVol(cuboid2)) {
			cout << "\nthe volume of the cuboid " << cuboid1.getId() << " is greater than the volume of the cuboid " << cuboid2.getId() << endl;
		}
		else {
			cout << "\nthe volume of the cuboid " << cuboid2.getId() << " is greater than the volume of the cuboid " << cuboid1.getId() << endl;
		}

		if (compCubWeight(cuboid1, cuboid2)) {
			cout << "the cuboid " << cuboid1.getId() << " is heavier than the cuboid " << cuboid2.getId() << endl;
		}
		else {
			cout << "the cuboid " << cuboid2.getId() << " is heavier than the cuboid " << cuboid1.getId() << endl;
		}
	}
	else {
		cout << "\nsome data of cuboid is error" << endl;
	}
	


	system("PAUSE");
	return 0;
}

// default constructor
Rectangle::Rectangle() {
	length = 0.1;
	width = 0.1;
}

Rectangle::Rectangle(const double lengthValue, const double widthValue) {
	bool error = false;
	if (lengthValue <= 0 || lengthValue >= 10) {
		error = true;
		cout << "The length of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}

	if (widthValue <= 0 || widthValue >= 10) {
		error = true;
		cout << "The width of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}

	// construct object only all information correct
	if (!error) {
		length = lengthValue;
		width = widthValue;
	}
	else {
		cout << "Please re-enter length and width of the rectangle" << endl;
		return;
	}
}

void Rectangle::setLength(const double lengthValue) {
	if (lengthValue > 0 && lengthValue < 10) {
		length = lengthValue;
	}
	else {
		cout << "The length of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}
}
void Rectangle::setWidth(const double widthValue) {
	if (widthValue > 0 && widthValue < 10) {
		width = widthValue;
	}
	else {
		cout << "The width of rectangle must be larger than 0.0 and less than 10.0." << endl;
	}
}

void Rectangle::printRectangle() const {
	double perimeter = 2 * (length + width);
	double area = length * width;

	//print information
	cout << "-------------------------------------------------------" << endl;
	cout << "Rectangle length: " << length << endl;
	cout << "Rectangle width: " << width << endl;
	cout << "Rectangle perimeter: " << perimeter << endl;
	cout << "Rectangle area: " << area << endl;
}

Cuboid::Cuboid() {
	rect.setLength(0.1);
	rect.setWidth(0.1);
	height = 0.1;
	density = 0.1;
}
Cuboid::Cuboid(double lengthValue, double widthValue, double heightValue, double densityValue) {
	bool error = false;
	if (lengthValue <= 0 || lengthValue >= 10) {
		error = true;
		cout << "The length of cuboid must be larger than 0.0 and less than 10.0." << endl;
	}
	if (widthValue <= 0 || widthValue >= 10) {
		error = true;
		cout << "The width of cuboid must be larger than 0.0 and less than 10.0." << endl;
	}
	if (heightValue < 0 || heightValue > 20) {
		error = true;
		cout << "The height of cuboid must be larger than 0.0 and less than 20.0." << endl;
	}
	if (densityValue < 0 || densityValue > 2) {
		error = true;
		cout << "The density of cuboid must be larger than 0.0 and less than 2.0." << endl;
	}

	// construct object only all information correct
	if (!error) {
		rect.setLength(lengthValue);
		rect.setWidth(widthValue);
		height = heightValue;
		density = densityValue;
		id = num++;
	}
	else {
		cout << "Please re-enter the Cuboid's data." << endl;
	}
}

void Cuboid::setLength(const double lengthValue) {
	rect.setLength(lengthValue);
}
void Cuboid::setWidth(const double widthValue) {
	rect.setWidth(widthValue);
}
void Cuboid::setHeight(const double heightValue) {
	if (heightValue >= 0 && heightValue <= 10) {
		height = heightValue;
	}
	else {
		cout << "The height of cuboid must be not less than 0.0 or larger than 20.0." << endl;
	}
}
void Cuboid::setDensity(const double densityValue) {
	if (densityValue >= 0 && densityValue <= 2) {
		density = densityValue;
	}
	else {
		cout << "The density of cuboid must be not less than 0.0 or larger than 2.0." << endl;
	}
}
void Cuboid::setRect(const Rectangle& rectValue) {
	rect.setLength(rectValue.getLength());
	rect.setWidth(rectValue.getWidth());
}

bool Cuboid::compVol(Cuboid& cuboid) const {
	double v1 = rect.getLength() * rect.getWidth() * height;
	double v2 = cuboid.getLength() * cuboid.getWidth() * cuboid.getHeight();

	return (v1 > v2);
}
void Cuboid::printCuboid() const {
	double volume = rect.getLength() * rect.getWidth() * height;
	double weight = volume * density;
	cout << "------------------------------------------------------" << endl;
	cout << "Cuboid id :" << id << endl;
	cout << "Cuboid length: " << rect.getLength() << endl;
	cout << "Cuboid width: " << rect.getWidth() << endl;
	cout << "Cuboid height: " << height << endl;
	cout << "Cuboid density: " << density << endl;
	cout << "Cuboid volume: " << volume << endl;
	cout << "Cuboid weight: " << weight << endl;

}

bool compCubWeight(const Cuboid& c1, const Cuboid& c2) {
	double w1 = c1.getLength() * c1.getWidth() * c1.getHeight() * c1.getDensity();
	double w2 = c2.getLength() * c2.getWidth() * c2.getHeight() * c2.getDensity();

	return (w1 > w2);
}