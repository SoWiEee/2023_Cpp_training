//#include <stdafx>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void count_letter(int letter[26], string s)
{
	for (int i = 0; i < 26; i++)
	{
		letter[i] = 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		char input = tolower(s[i]);
		if (isalpha(input))
		{
			int index;
			index = (int)input-(int)'a';
			letter[index]++;
		}
	}
}

int main()
{
	string s1, s2;
	int letter1[26], letter2[26];

	cout << "Enter two strings=>\n";
	getline(cin,s1);
	getline(cin, s2);
	count_letter(letter1, s1);
	count_letter(letter2, s2);
	for (int i = 0; i < 26; i++)
	{
		if (letter1[i] != letter2[i])
		{
			cout << "\nThey are not anagrams.\n";
			system("PAUSE");
			return(0);
		}
	}
	cout << "\nThey are anagrams.\n";

	system("PAUSE");
	return(0);
}

