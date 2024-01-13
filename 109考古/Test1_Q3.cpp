#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int numberOfReviewer = 4; /* the number of reviewers	*/
const int numberOfMovie = 6;	/* the number of movies		*/

int main() {
	int review[numberOfReviewer][numberOfMovie] = { { 3,1,5,2,1,5 },
													{ 4,2,1,4,2,4 },
													{ 3,1,2,4,4,1 },
													{ 5,1,4,2,4,2 } };	/* a table of reviews including 4 reviewers and 6 movies	*/
	int rating[2][3];													/* store the user rating									*/
	bool inputError;													/* a flag of input error									*/
	double minDistance = 7.0;											/* store the minimum distance between user and reviewer		*/
	double distance = 0.0;												/* store the distance between user and reviewer				*/
	int closestReviewer = 0;											/* store the closest reviewer								*/

	/* prompt user to input ratings for three movies */
	do {
		inputError = false;
		cout << "Input ratings for three movies, movies are numberes 100-105 and ratings range from 1 to 5(ex:102 5 104 2 105 5).\n";
		cin >> rating[0][0] >> rating[1][0] >> rating[0][1] >> rating[1][1] >> rating[0][2] >> rating[1][2];
		if (rating[0][0] == rating[0][1] || rating[0][0] == rating[0][2] || rating[0][1] == rating[0][2]) {
			inputError = true;
			cout << "Duplicate rating, please input again.\n\n";
		}
		else
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 3; j++)
					if (i == 0) {
						if (!(rating[i][j] >= 100 && rating[i][j] <= 105)) {
							inputError = true;
							cout << "Input error, please input again.\n\n";
							break;
						}
					}
					else
						if (!(rating[i][j] >= 1 && rating[i][j] <= 5)) {
							inputError = true;
							cout << "Input error, please input again.\n\n";
							break;
						}
	} while (inputError);

	/* determine whose ratings most closely match user's rating using Cartesian distance */
	for (int i = 0; i < numberOfReviewer; i++) {
		distance = sqrt(pow(abs(rating[1][0] - review[i][rating[0][0] - 100]), 2) + pow(abs(rating[1][1] - review[i][rating[0][1] - 100]), 2) + pow(abs(rating[1][2] - review[i][rating[0][2] - 100]), 2));
		if (distance < minDistance) {
			minDistance = distance;
			closestReviewer = i;
		}
	}

	/* print the closest reviewer */
	cout << "Reviewer "<< closestReviewer<<"'s ratings most closely match your ratings.\n";

	/* print the prediction in the other movies */
	for (int i = 0; i < numberOfMovie; i++)
		if (!(rating[0][0] - 100 == i || rating[0][1] - 100 == i || rating[0][2] - 100 == i))
			cout << "I guess you want to rate " << review[closestReviewer][i] << " for movie " << i + 100 << ".\n";

	system("pause");
	return 0;
}