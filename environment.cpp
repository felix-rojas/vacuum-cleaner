#pragma once
#include "environment.h"
std::random_device rd;

Environment* Environment::instance = nullptr;

Environment::Environment()
{
}

// default contructor with random 10 by 10 environment
void Environment::SetEnvironment()
{
	cols = 10;
	rows = 10;
	dirty_cells = 0;
	grid.resize(rows, vector<int>(cols));
	randomize_dirt();
}

void Environment::SetEnvironment(int m, int n)
{
	rows = m;
	cols = n;
	dirty_cells = 0;
	grid.resize(rows, std::vector<int>(cols));
}

void Environment::SetEnvironment(int m, int n, float dirt_factor)
{
	rows = m;
	cols = n;
	dirty_cells = 0;
	grid.resize(rows, std::vector<int>(cols));
	randomize_dirt(dirt_factor);
}


// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

void Environment::randomize_dirt()
{
	for (auto& row : grid)
		for (auto& element : row)
		{
			element = rd() % 2;
			if (element == 1) dirty_cells++;
		}
}

void Environment::randomize_dirt(float dirt_index)
{
	int dirt_cell_count = 0;
	int numRows = grid.size();
	int numCols = grid[0].size();
	float desired_dirt_cells = std::round(dirt_index * numCols * numCols);

	std::set<std::pair<int, int>> filledLocations;

	while (dirt_cell_count < desired_dirt_cells)
	{
		int randomRow = getRandomInt(0, numRows - 1);
		int randomCol = getRandomInt(0, numCols - 1);

		std::pair<int, int> location = std::make_pair(randomRow, randomCol);

		// Check if the location is already filled
		if (filledLocations.find(location) == filledLocations.end()) {
			int randomValue = getRandomInt(0, 1);
			grid[randomRow][randomCol] = randomValue;
			filledLocations.insert(location);
			dirt_cell_count++;
		}
	}
	this->dirty_cells = dirt_cell_count;
}

void Environment::place_agents(vector<Agent>)
{
}


// 1 indicates dirty
int Environment::get_state(int pos_x, int pos_y)
{
	return grid[pos_y][pos_x];
}

void Environment::set_state(int pos_x, int pos_y, int state)
{
	grid[pos_y][pos_x] = state;
}


Environment* Environment::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Environment();
	}
	return instance;
}

void Environment::PrintGrid()
{
	for (const auto& row : grid) {
		for (const auto& element : row)
			std::cout << element << " ";
		std::cout << std::endl;
	}
}
