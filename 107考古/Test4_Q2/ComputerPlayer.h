#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include <string>
#include "Player.h"

namespace GamePlayer
{
	class ComputerPlayer : public Player {
	public:
		int getGuess();
	};
}

#endif