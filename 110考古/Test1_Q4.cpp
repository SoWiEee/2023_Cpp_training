#include<iostream>
#include<cmath>
using namespace std;

double nearest_neighbor(int review_rating[], int user_rating[], int user_movie[]);
int find(double ar[], int n);

int main()
{

	int reviews[4][6] = { { 3, 1, 5, 2, 3, 5 },
						  { 4, 2 ,1 ,4 ,2 ,4 },
						  { 3, 1 ,2 ,3 ,4 ,1 },
						  { 5, 1 ,4 ,2 ,4 ,2 } };
	int reviewer[4] = { 0, 1, 2, 3 };
	int movie[6] = { 101, 102, 103, 104, 105, 106 };
	int user_rating[3], user_movie[3];
	int closely_reviewer;
	double distance[4];
	int m;

	//allow the user to enter ratings for any three movies.
	cout << "Enter three movie : " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Movie " << i+1 << " : ";
		cin >> user_movie[i];

		while (user_movie[i] < 101 || user_movie[i] > 106)
		{
			cout << "Please enter again!";
			cout << "Movie " << i + 1 << " : ";
			cin >> user_movie[i];
		}
	}

	cout << "Enter three rating : " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Movie " << user_movie[i] << " : ";
		cin >> user_rating[i];

		while (user_rating[i] < 1 || user_rating[i] > 5)
		{
			cout << "Please enter again!" << endl;
			cout << "Movie " << user_movie[i] << " : ";
			cin >> user_rating[i];
		}
	}
	
	//Find the reviewer whose ratings most closely match the ratings input by the user.
	for (int i = 0; i < 4; i++)
	{
		distance[i] = nearest_neighbor(reviews[i], user_rating, user_movie);
	}

	closely_reviewer = find(distance, 4);

	cout << "Most close reviewer : " << reviewer[closely_reviewer] << endl
		<< "Interest in the other movies by reviewer's rating : " << endl;

	//Predict the user's interest in the other movies.
	for (int i = 0; i < 6; i++)
	{
		m = i + 101;
		if (m != user_movie[0] && m != user_movie[1] && m != user_movie[2])
		{
			cout << "a rating of " << reviews[closely_reviewer][i] << " for movie " << movie[i] << endl;
		}
	}

	system("PAUSE");
	return 0;
}

//The nearest neighbor classification algorithm.
double nearest_neighbor(int review_rating[], int user_rating[], int user_movie[])
{
	double dis = 0;

	for (int i = 0; i < 3; i++)
	{
		dis += pow(review_rating[user_movie[i] - 101] - user_rating[i], 2);
	}

	dis = sqrt(dis);

	return (dis);
}

//Find most close reviewer.
int find(double ar[], int n)
{
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (ar[i] < ar[index])
		{
			index = i;
		}
	}

	return (index);
}