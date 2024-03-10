#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;

// generate 2 dices
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main(void) {
    srand(time(0)); // seed
    float win = 0, lose = 0;

    for(int i = 0; i < 10000; i++) {
        int point = rollDice() + rollDice(); // random point

        if(point == 7 || point == 11){
            win++;
        }else if(point == 2 || point == 3 || point == 12){
            lose++;
        }else{
            while(true){
                int roll = rollDice() + rollDice();
                if(roll == point) {
                    win++;
                    break;
                } else if(roll == 7) {
                    lose++;
                    break;
                }
            }
        }
    }

    cout << "Winning Rate: " << (win) / (win + lose) << endl;

    return 0;
}