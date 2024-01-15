/*
*First,read text file into programa and use string array to stored text.
*Than use "Selection_Sorting" fnuction to sort string array in alphabetical order.
*Final write a file to save result.
*/
#define _CRT_SECURE_NO_WARNINGS									
#include <stdio.h>												
#include <stdlib.h>
#include <string.h>

void Selection_Sorting(char *list[], int n);						//Sort string array in alphabetical order.
int alpha_first(char *list[], int min_sub, int max_sub);
int main() {

	FILE *Girls_input_file = fopen("Girls.txt", "r");				//Read "Girls.txt".
	FILE *Girls_output_file = fopen("Girls_sorted.txt", "w");		//Write "Girls_sorted.txt".
	char girl_names[100][20];										//Stored girl's names from "Girls.txt".
	char *girl_names_pointer[100];									//Stored 'girl_names' pointer.
	int size = 100;													//Number of names.

	if (!Girls_input_file) {										//File open failed.
		printf("Error! File open failed.\n");
		return 1;
	}

	printf("Original string array\n");									//Read girl's names from "Girls.txt",then stored girl's names and pointer.
	for (int i = 0; i < size; i++) {
		fgets(girl_names[i], 20, Girls_input_file);
		girl_names_pointer[i] = girl_names[i];
		printf("%s", girl_names_pointer[i]);
	}

	Selection_Sorting(girl_names_pointer, size);					//Sort string array in alphabetical order.

	printf("\nSorted string array\n");									//Write to sorted string array,and display.
	for (int i = 0; i < size; i++) {
		fputs(girl_names_pointer[i], Girls_output_file);
		printf("%s", girl_names_pointer[i]);
	}

	fclose(Girls_input_file);										//Close file.
	fclose(Girls_output_file);

	system("pause");												//Please 'pause' and return
	return 0;
}

void Selection_Sorting(char *list[], int n) {						//Sort string array in alphabetical order.
	int fill, index_of_min;
	char *temp;
	for (fill = 0; fill < n - 1; fill++)
	{
		index_of_min = alpha_first(list, fill, n);
		if (index_of_min != fill)
		{
			temp = list[index_of_min];
			list[index_of_min] = list[fill];
			list[fill] = temp;
		}
	}
}
int alpha_first(char *list[], int min_sub, int max_sub)				//find the index of the string that comes first alphabeticaally in elemints min_sub...max_sub of list
{
	int first, i;
	first = min_sub;
	for (i = min_sub + 1; i < max_sub; i++)
	{
		if (strcmp(list[i], list[first]) < 0)
		{
			first = i;
		}
	}
	return (first);
}