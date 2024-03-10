#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

// return points in this turn
int humanTurn(int humanTotalScore) {
    int turnTotal = 0;
    char choice;

    do {
        int roll = rollDice();

        // roll 1 => 0 pt
        if(roll == 1){
            cout << "You roll 1 pts" << endl;
            cout << "This turn: 0 pts" << endl;
            cout << "Total score: " << humanTotalScore << " pts" << endl;
            return 0;
        }else{

        // roll 2~6 => again/hold
            turnTotal += roll;
            cout << "You roll " << roll << " pts" << endl;
            cout << "This turn: " << turnTotal << " pts" << endl;
            cout << "Total score: " << humanTotalScore + turnTotal << " pts" << endl;
            cout << "Roll again?(r/h): ";
            cin >> choice;
            if(choice == 'r'){
                turnTotal -= roll;
            }
        }
    } while(choice == 'r');

    return turnTotal;
}

// return points in this turn
int computerTurn(int computerTotalScore) {
    int turnTotal = 0;

    while(turnTotal < 20) {
        int roll = rollDice();
        // roll 1 => 0 pt
        if(roll == 1) {
            return 0;
        }else{
            turnTotal += roll;
            if(computerTotalScore + turnTotal >= 100) {
				return turnTotal;
			}
        }
        
    }
    return turnTotal;
}

int main(void) {
    srand(time(0)); // seed

    int humanTotal = 0;
    int computerTotal = 0;

    while(humanTotal < 100 && computerTotal < 100) {
        humanTotal += humanTurn(humanTotal);
        cout << "\nYour Total: " << humanTotal << endl;

        if(humanTotal >= 100) {
            cout << "You Win!" << endl;
            break;
        }

        computerTotal += computerTurn(computerTotal);
        cout << "Computer Total: " << computerTotal << endl;

        if(computerTotal >= 100) {
            cout << "Computer Win!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
