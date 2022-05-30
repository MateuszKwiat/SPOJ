#include "game_logic.h"

Game::Game()
{
	std::cout << "How many iterations:\n";
	std::cin >> amount_of_iterations;
	Board::Fill_board();
	std::cout << std::endl;
}


void Game::game_ini()
{
	// MAIN GAME LOOP
	for (int i = 0; i < amount_of_iterations; i++)
	{
		std::cout << std::endl << i << " iterations:\n";
		Board::Show_board();
		Board::Adjacent_cells_count();
		Board::update_board();
	}
}