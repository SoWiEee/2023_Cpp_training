/*
*The program will need user to key in the name.
*And program use "find_name" function to find same name.
*Than,return index of same name.
*/
#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function
#include <stdio.h>//Include library.
#include <stdlib.h>
#include <string.h>

int find_name(char word[100][20], char name[], int size);//Find same name.

int main() {

	FILE *Girls_input_file = fopen("Girls_sorted.txt", "r");//Read "Girls_sorted.txt".
	char girl_names[100][20];     //Stored girl's names from "Girls_sorted.txt".
	char name[20];                //Used to store key in from user.
	int same_index;               //Stored index from girl_names or girl_names.
	int size = 100;               //Number of names.

	if (!Girls_input_file) {
		//File open failed.
		printf("Error! File open failed.\n");
		return 1;
	}

	//Read girl's names from "Girls_sorted.txt",then stored girl's names and pointer.
	for (int i = 0; i < size; i++) {
		fgets(girl_names[i], 20, Girls_input_file);
		girl_names[i][strlen(girl_names[i]) - 1] = '\0';//Used '\0'(null) replace '\n'.
	}

	//Enter the loop and let user key in name,than find from girl_names.
	//User can key in "ZZZ" to exit the loop.
	while (1) {
		printf("Please key in one name...(\"ZZZ\" can exit.)\n");
		scanf("%s", name);  //Stored user key in.
		if (strcmp("ZZZ", name) == 0) {
			//User key in "ZZZ".
			system("pause");  //Please 'pause' and return
			return 0;
		}
		else {
			same_index = find_name(girl_names, name, (size - 1));//Find same name used binary search.
			if (same_index == -1)
				printf("\"Girls_sorted.txt\" file without \"%s\". (Use binary search.)\n", name);
			else
				printf("At index = %d,have same name,\"%s\". (Use binary search.)\n", same_index, girl_names[same_index]);
		}
	}
}

int find_name(char word[100][20], char name[], int size) {
	//Find same name used binary search.
	int left = 0;     //Set binary start number.
	int mid = 0;      //Set middle.
	int right = size; //Set binary end number.
	while (left <= right) {
		mid = (int)((left + right) / 2);//Change middle.
		if (strcmp(word[mid], name) == 0) {
			//Find same name,and return this index.
			return mid;
		}
		else if (strcmp(word[mid], name) > 0) {
			//The same name maybe exist on the left.
			right = mid - 1;
		}
		else {
			//The same name maybe exist on the right.
			left = mid + 1;
		}
	}
	return -1;
}
