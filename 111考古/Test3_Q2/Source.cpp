/*
 *	The program Reads input file "Q1.cpp",modifies it's content.
 *	First adds "<PRE>" and "</PRE>" at the front and the end of the content.
 *	Than replaces "<" and ">" to "&lt;" and "&gt;".
 *	Finaly,output a filename "Q2.html".
*/

#include <iostream>		//Uses I/O library.
#include <String>		//Uses String.
#include <fstream>		//Reading and writing files.
using namespace std;	//Defines a namespace of 'std'.

int main(void) {
	const string input_file = "Q1.cpp";		//Sets input file name.
	const string output_file = "Q2.html";	//Seds output file name.
	string Q1_code, line_tmp;				//Used to store string.
	int num = 0, position = -1;				//Used to store index and position of '<' or '>'.

	
	fstream file;							//Sets open file.
	cout << "Open file \"" << input_file << "\"...\n";
	file.open(input_file, ios::in);			//Open input file "Q1.cpp".

	//Checking the file open successfully or failed.
	if (file.fail()) {
		cout << "Failed to open \"" << input_file << "\" file!!\n";
		system("PAUSE");
		exit(0);
	}
	cout << "Successful to open!!\n";

	cout << "Read " << input_file << " file...\n";
	Q1_code += "<PRE>\n";							//Adds string "<PRE>" at the front of the Q1_code.
	//Reads input file's code.
	while (getline(file, line_tmp)) {
		num = 0;									//Initialize index value.
		while (line_tmp.find_last_of('<') != line_tmp.npos) {
			//Checks if string "line_tmp" have string '<',"npos" is mean maximum index.
			position = line_tmp.find('<', num);		//Find '<' position at string "line_tmp".
			line_tmp.replace(position, 1, "&lt;");	//Replace '<' to "&lt;".
			num++;									//Count index.
		}
		num = 0;									//Initialize index value.
		while (line_tmp.find_last_of('>') != line_tmp.npos) {
			//Checks if string "line_tmp" have string '>',"npos" is mean maximum index.
			position = line_tmp.find('>', num);		//Find '>' position at string "line_tmp".
			line_tmp.replace(position, 1, "&gt;");	//Replace '>' to "&gt;".
			num++;									//Count index.
		}
		Q1_code += line_tmp + '\n';
	}
	Q1_code += "</PRE>\n";							//Adds string "</PRE>" at the end of the Q1_code.
	cout << "Completed to read file!!\n";
	file.close();									//Closes input file "Q1.cpp".
	cout << "Close the file!!\n";

	cout << "Open file \"" << output_file << "\"...\n";
	file.open(output_file, ios::out);				//Open output file "Q2.html".

	//Checking the file open successfully or failed.
	if (file.fail()) {
		cout << "Failed to open \"" << output_file <<"\" file!!\n";
		system("PAUSE");
		exit(0);
	}
	cout << "Successful to open!!\n";

	cout << "Write " << output_file << " file...\n";
	file << Q1_code;	//Writes Q1_code into the output file.
	cout << "Completed to write file!!\n";
	cout << "Close the file!!\n";
	file.close();		//Closes output file "Q2.html".

	system("PAUSE");	//Please 'pause' and return
	return 0;			//Return of the program.
}
