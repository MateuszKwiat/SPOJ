#pragma once
#include "board.h"

class Game : protected Board
{
private:
	int amount_of_iterations;
public:
	Game();
	void game_ini();

};