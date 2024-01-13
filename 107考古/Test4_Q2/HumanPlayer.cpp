#include <iostream>
#include "HumanPlayer.h"
using namespace std;

namespace GamePlayer{
	int HumanPlayer::getGuess(){
		int number;

		cin >> number;

		return number;
	}
}