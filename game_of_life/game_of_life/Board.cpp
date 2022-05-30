#include "board.h"

Board::Board() : adjacent_cells_count(0), matrix(BOARD_SIZE) { srand(time(0)); }

void Board::Fill_board()
{
	char ch;

	std::cout << std::endl << "Use random fill <y/n>\n";
	std::cin >> ch;

	// LOOP FOR INSIDE 5X5 MATRIX
	int j = 8;
	if (ch == 'n')
	{
		for (auto matrix_iter = matrix.begin() + 8; matrix_iter != matrix.end() - 8; matrix_iter++, j++)
		{
			if (j % 7 == 0 || j % 7 == 6)
				matrix_iter->is_alive = 0;
			else
				std::cin >> matrix_iter->is_alive;
		}
	}
	else
	{
		for (auto matrix_iter = matrix.begin() + 8; matrix_iter != matrix.end() - 8; matrix_iter++, j++)
		{
			if (j % 7 == 0 || j % 7 == 6)
				matrix_iter->is_alive = 0;
			else
				matrix_iter->is_alive = rand() % 2;
		}
	}

	fill_matrix_edges();
}

void Board::update_board()
{
	for (auto i = matrix.begin() + 8; i != matrix.end() - 8; i++)
	{
		if (i->will_stay_alive)
			i->is_alive = 1;
		else
			i->is_alive = 0;
	}

	fill_matrix_edges();
}

void Board::fill_matrix_edges()
{
	auto sides = matrix.begin() + 7;
	auto up_and_down = matrix.begin() + 1;

	for (sides, up_and_down; sides != matrix.end() - 7; sides += 7, up_and_down++)
	{
		// LEFT AND RIGHT 
		*sides = *(sides + 5);
		*(sides + 6) = *(sides + 1);

		// UP AND DOWN
		*up_and_down = *(up_and_down + 35);
		*(up_and_down + 42) = *(up_and_down + 7);

	}

	// CORNERS
	matrix[0] = matrix[40];
	matrix[6] = matrix[36];
	matrix[42] = matrix[12];
	matrix[48] = matrix[8];
}

void Board::Show_board()
{
	int j = 8;
	for (auto i = matrix.begin() + 8; i != matrix.end() - 8; i++, j++)
	{
		if (j % 7 == 0 || j % 7 == 6)
			continue;
		std::cout << i->is_alive << ' ';
		if (j % 7 == 5)
			std::cout << std::endl;
	}


//	FOR FULL 7X7 BOARD
//	int j = 0;
//	for (auto i = matrix.begin(); i != matrix.end(); i++, j++)
//	{
//		std::cout << i->is_alive << ' ';
//		if (j % 7 == 6)
//			std::cout << std::endl;
//	}
}

void Board::Adjacent_cells_count()
{
	adjacent_cells_count = 0;
	int j = 0;

	for (auto i = matrix.begin() + 7; i != matrix.end() - 8; i++, j++)
	{
		if (j % 7 == 0 || j % 7 == 6)
			continue;
		else
		{
			adjacent_cells_count += (i - 1)->is_alive;
			adjacent_cells_count += (i + 1)->is_alive;
			for (auto k = i - 8; k != i - 5; k++)
			{
				adjacent_cells_count += k->is_alive;
				adjacent_cells_count += (k + 14)->is_alive;
			}
		}
		if ((adjacent_cells_count > 3 || adjacent_cells_count < 2) && i->is_alive)
			i->will_stay_alive = 0;
		else if (i->is_alive)
			i->will_stay_alive = 1;
		else if (adjacent_cells_count == 3 && !(i->is_alive))
			i->will_stay_alive = 1;
		else if (!(i->is_alive))
			i->will_stay_alive = 0;

		adjacent_cells_count = 0;
	}
}