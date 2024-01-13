#include <iostream>
#include "ComputerPlayer.h"
using namespace std;

namespace GamePlayer{
	int ComputerPlayer::getGuess(){
		int number;

		number = rand() % 100;

		return number;
	}
}