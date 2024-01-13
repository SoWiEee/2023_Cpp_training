#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <string>
#include "Player.h"

namespace GamePlayer
{
	class HumanPlayer : public Player {
	public:
		int getGuess();
	};
}

#endif