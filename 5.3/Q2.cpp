
	//#include <stdafx>
	#include<iostream>
	#include<cstring>
	#include<string>
	#include<vector>

	using namespace std;

	class BoxOfProduce
	{
	private:
		vector<string> name;
	public:
		BoxOfProduce();
		void initialize();
		void addbundle(string bundle);
		void output();
		friend const BoxOfProduce operator +(const BoxOfProduce& b1, const BoxOfProduce& b2);
	};

	BoxOfProduce::BoxOfProduce()
	{
		initialize();
	}
	void BoxOfProduce::initialize()
	{
		name.clear();
	}
	void BoxOfProduce::addbundle(string bundle)
	{
		name.push_back(bundle);
	}
	void BoxOfProduce::output()
	{
		cout << "The box contains:";
		string s;
		for (int i = 0; i < name.size(); i++)
		{
			s = s + " <" + char('0' + 1 + i) + ">" + name[i];
		}
		cout << s << endl;
	}


	const BoxOfProduce operator +(const BoxOfProduce & b1, const BoxOfProduce & b2)
	{
		BoxOfProduce nb;
		for (int i = 0; i < b1.name.size(); i++)
		{
			nb.addbundle(b1.name[i]);
		}
		for (int i = 0; i < b2.name.size(); i++)
		{
			nb.addbundle(b2.name[i]);
		}
		return nb;
	}

	int main()
	{
		BoxOfProduce b1, b2, b3;
		b1.addbundle("Tomato");
		b1.addbundle("Potato");
		b2.addbundle("Apple");
		b2.addbundle("Pear");
		b2.addbundle("kiwi");
		b2.addbundle("Durian");
		b3 = b1 + b2;
		b1.output();
		b2.output();
		b3.output();

	}


	