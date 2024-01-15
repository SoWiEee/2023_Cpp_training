#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void select_sort(int list[], int n);				//select_sort
int get_min_range(int list[], int fill, int n);		//get minmun number

int main(void) {
	int num[150],									//initializing variable
		status = 0,
		length = 0,
		i=0;
	FILE* file;
	file = fopen("Numbers.txt", "r");				//open input file
	while (status != EOF) {							//read file
		status = fscanf(file, "%d", &num[length]);
		length++;
	}
	fclose(file);									//close input file
	length--;										//get int array length
	printf("Original Array:\n");					//printf original array
	for (i = 0; i < length; i++)
	{
		printf("%d\n", num[i]);
	}
	select_sort(num, length);						//call select_sort function
	file = fopen("Numbers_sorted.txt", "w");		//open output file
	printf("\nSorted Array : \n");					//print sorted array
	for (int i = 0; i < length; i++) {
		printf("%d\n", num[i]);
		fprintf(file, "%d\n", num[i]);
	}
	fclose(file);									//close output file

	system("PAUSE");
	return 0;

}

void select_sort(int list[], int n) {				//select_sort function
	int index_of_min,temp=0,fill;					//initializing variable
	for (fill = 0; fill < n; fill++) {				//sort
		index_of_min = get_min_range(list, fill, n);//call get_min_range function
		temp = list[index_of_min];
		list[index_of_min] = list[fill];
		list[fill] = temp;
	}
}


int get_min_range(int list[], int fill, int n) {	//get_min_range function
	int min_int = list[fill],index_of_min=fill;		//initializing variable
	for (int i = fill; i < n; i++)
	{
		if (min_int > list[i])						//get min_int
		{
			min_int = list[i];
			index_of_min = i;
		}
	}

	return index_of_min;							//return index_of_min
}