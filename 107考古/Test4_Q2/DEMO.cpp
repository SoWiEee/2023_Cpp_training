#include <iostream>
#include <time.h>
#include "player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
using namespace std;
using namespace GamePlayer;

bool checkForWin(int, int);
void play(Player&, Player&);

int main()
{
	int choice = 0;
	HumanPlayer hPlayer1, hPlayer2;
	ComputerPlayer cPlayer1, cPlayer2;

	srand((unsigned)time(NULL));

	do
	{
		cout << "<0> Human vs Human  <1> Human vs Computer  <2> Computer vs Computer <3> Exit\n";
		cout << "Choose one of the above: ";
		cin >> choice;

		switch (choice)
		{
		case 0: 
			play(hPlayer1, hPlayer2);
			break;
		case 1:
			play(hPlayer1, cPlayer2);
			break;
		case 2:
			play(cPlayer1, cPlayer2);
			break;
		case -1:
			break;
		default:
			cout << "Invaild choice." << endl;
			break;
		}	

		cout << endl;
	} while (choice != -1);
	
	system("pause");
	return 0;
}

bool checkForWin(int guess, int answer)
{
	if (answer == guess){
		cout << "You're right! You Win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}

void play(Player &player1, Player &player2){
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;
	while (!win){
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		cout << "Player 2's trun to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

