#ifndef PFArray
#define PFArray

namespace NUTNCSIE {
	class PFArrayD {
	public:
		/* Constructor */
		PFArrayD();
		PFArrayD(const int);
		PFArrayD(const double*, const int, const int);
		PFArrayD(const PFArrayD&);		//Copy constructor.
		/* Destructor */
		~PFArrayD();

		/* Function */
		void set_capacity(const int);	//Used to set capacity on the PFArrayD class.
		void set_used(const int);		//Used to set number of used on the PFArrayD class.
		int get_capacity() const;		//Gets the capacity on the PFArrayD class.
		int get_used() const;			//Gets the number of used on the PFArrayD class.
		void addElement(const double);	//Used to add new element into the PFArrayD class's array.
		bool full() const;				//Checks if the PFArrayD class's array is full.

		/* Operator Overloading */
		friend const PFArrayD operator +(const PFArrayD&, const PFArrayD&);	//Uesd to join two PFArrayD class's array,than return new object.
		double& operator [](const int) const;								//Gets the element from PFArrayD class's array.
		PFArrayD& operator =(const PFArrayD&);								//Used to return the PFArrayD object,

	private:
		double *a;		//Stores array point.
		int capacity;	//Stores class's capacity.
		int used;		//Stores number of used on the 'a' array.
	};
}

#endif