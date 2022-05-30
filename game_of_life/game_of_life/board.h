#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Board
{
public:
	enum {BOARD_SIZE = 49};
private:
	int adjacent_cells_count;
	class Cell
	{
	public:
		bool is_alive;
		bool will_stay_alive;
		Cell() : is_alive(0), will_stay_alive(0) {}
	};
	void fill_matrix_edges();
protected:
	std::vector<Cell> matrix;
	void Adjacent_cells_count();
	void update_board();
public:
	Board();
	void Fill_board();
	void Show_board();
	Cell& operator[](int n) { return matrix[n]; }
};