#include<iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle();												/*initialize a rectangle with length 1 and width 1		*/
	Rectangle(int newId, double newLength, double newWidth);	/*initialize a rectangle with its ID, length and width	*/
	void setId(int newId);										/*set rectangle ID										*/
	void setLength(double newLength);							/*set rectangle length and check range					*/
	void setWidth(double newWidth);								/*set rectangle width and check range					*/
	int getId() { return this->id; }							/*get rectangle ID										*/
	double getLength() { return this->length; }					/*get rectangle	lenght									*/
	double getWidth() { return this->width; }					/*get rectangle width									*/
	double getPerimeter();										/*get perimeter of rectangle							*/
	double getArea();											/*get area of rectangle									*/
	void rectInfo();											/*print rectangle informaiton							*/

private:
	int id;														/*rectangle Id tracked by num							*/
	double length;												/*rectangle lenght										*/
	double width;												/*rectangle width										*/
};

/*initialize a rectangle with length 1 and width 1				*/
Rectangle::Rectangle() :length(1), width(1)
{
}

/*initialize a rectangle with its ID, length and width			*/
Rectangle::Rectangle(int newId, double newLength, double newWidth) : id(newId)
{
	this->setLength(newLength);
	this->setWidth(newWidth);
}

/*set rectangle ID												*/
void Rectangle::setId(int newId)
{
	this->id = newId;
}

/*set rectangle length and check range							*/
void Rectangle::setLength(double newLength)
{
	bool notInRange = true;
	double checkLength = newLength;
	while (notInRange)
	{
		if (checkLength < 0.0 || checkLength > 10.0)
		{
			cout << "length should be form 0 to 10." << endl;
			cout << " Length: ";
			cin >> checkLength;
		}
		else
		{
			notInRange = false;
			this->length = checkLength;
		}
	}
}

/*set rectangle width and check range							*/
void Rectangle::setWidth(double newWidth)
{
	bool notInRange = true;
	double checkWidth = newWidth;
	while (notInRange)
	{
		if (checkWidth < 0.0 || checkWidth > 10.0)
		{
			cout << "width should be form 0 to 10." << endl;
			cout << " Width: ";
			cin >> checkWidth;
		}
		else
		{
			notInRange = false;
			this->width = checkWidth;
		}
	}
}

/*get perimeter of rectangle									*/
double Rectangle::getPerimeter()
{
	return (this->getLength() + this->getWidth()) * 2;
}

/*get area of rectangle											*/
double Rectangle::getArea()
{
	return this->getLength() * this->getWidth();
}

/*print rectangle informaiton									*/
void Rectangle::rectInfo()
{
	cout << "ID: " << this->getId() << endl;
	cout << "Length: " << this->getLength() << endl;
	cout << "Width: " << this->getWidth() << endl;
	cout << "Perimeter: " << this->getPerimeter() << endl;
	cout << "Area: " << this->getArea() << endl << endl;
}

class Cuboid
{
public:
	Cuboid();																			/*initialize cuboid with length 1, width 1, height 1 and density 1	*/
	Cuboid(double newLength, double newWidth, double newHeight, double newDensity);		/*initialize cuboid with length, width, height and density			*/
	void setDensity(double newDensity);													/*set cuboid density and check range								*/
	void setHeight(double newHeight);													/*set cuboid height	and check range									*/
	double getDensity() { return this->density; }										/*get cuboid density												*/
	double getHeight() { return this->height; }											/*get cuboid height													*/
	double getVolume();																	/*get cuboid volume													*/
	double getWeight();																	/*get cuboid weight													*/
	bool compVol(Cuboid& newCuboid);													/*compare cuboid volume												*/
	void cuboidInfo();																	/*print cuboid information											*/

private:
	double density;																		/*cuboid density													*/
	double height;																		/*cuboid height														*/
	Rectangle rect;																		/*rectangle object													*/
};

/*initialize cuboid with length 1, width 1, height 1 and density 1		*/
Cuboid::Cuboid() : rect(), density(1), height(1)
{
}

/*initialize cuboid with length, width, height and density				*/
Cuboid::Cuboid(double newLength, double newWidth, double newHeight, double newDensity)
{
	this->rect.setLength(newLength);
	this->rect.setWidth(newWidth);
	this->setHeight(newHeight);
	this->setDensity(newDensity);
}

/*set cuboid density and check range									*/
void Cuboid::setDensity(double newDensity)
{
	bool notInRange = true;
	double checkDensity = newDensity;
	while (notInRange)
	{
		if (checkDensity < 0.0 || checkDensity > 2.0)
		{
			cout << "density should be from 0.0 to 2.0." << endl;
			cout << "Density: ";
			cin >> checkDensity;
		}
		else
		{
			notInRange = false;
			this->density = checkDensity;
		}
	}
}

/*set cuboid height and check range										*/
void Cuboid::setHeight(double newHeight)
{
	bool notInRange = true;
	double checkHeight = newHeight;
	while (notInRange)
	{
		if (checkHeight < 0.0 || checkHeight > 20.0)
		{
			cout << "heught should be from 0.0 to 20.0" << endl;
			cout << "height: ";
			cin >> checkHeight;
		}
		else
		{
			notInRange = false;
			this->height = checkHeight;
		}
	}
}

/*get cuboid volume														*/
double Cuboid::getVolume()
{
	return this->rect.getLength() * this->rect.getWidth() * this->getHeight();
}

/*get cuboid weight														*/
double Cuboid::getWeight()
{
	return this->getVolume() * this->getDensity();
}

/*compare cuboid volume													*/
bool Cuboid::compVol(Cuboid& newCuboid)
{
	if (this->getVolume() > newCuboid.getVolume())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*compare cuboid weight													*/
bool compCubWeight(Cuboid& cuboidA, Cuboid& cuboidB)
{
	if (cuboidA.getWeight() > cuboidB.getWeight())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*print cuboid information												*/
void Cuboid::cuboidInfo()
{
	cout << "Length: " << this->rect.getLength() << endl;
	cout << "Width: " << this->rect.getWidth() << endl;
	cout << "Height: " << this->getHeight() << endl;
	cout << "Volume: " << this->getVolume() << endl;
	cout << "Weight: " << this->getWeight() << endl;
}

int main()
{
	/*construct 2 cuboid*/
	Cuboid Cuboid1(3.2, 9.8, 15.6, 0.8), Cuboid2(5.2, 7.6, 10.2, 1.2);
	cout << "Cuboid 1:" << endl;
	Cuboid1.cuboidInfo();
	cout << endl << "Cuboid 2 :" << endl;
	Cuboid2.cuboidInfo();
	cout << endl;

	/*compare volume of 2 cuboid*/
	if (Cuboid1.compVol(Cuboid2))
	{
		cout << "Cuboid 1 is bigger than Cuboid 2." << endl;
	}
	else
	{
		cout << "Cuboid 2 is bigger than Cuboid 2." << endl;
	}

	/*compare weught of 2 cuboid*/
	if (compCubWeight(Cuboid1, Cuboid2))
	{
		cout << "Cuboid 1 is heavier than cuboid 2." << endl;
	}
	else
	{
		cout << "Cuboid 2 is heavier than Cuboid 1." << endl;
	}

	system("pause");
	return 0;
}