#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <utility> // For std::pair
using std::vector;

class Environment
{
public:
	vector <vector <int>> grid;
	int dirty_cells;
	int cols;
	int rows;
	int get_state(int, int);
	static Environment* GetInstance();
	static Environment* GetInstance(int, int);
	static Environment* GetInstance(int, int, float);
	void PrintGrid();
	void randomize_dirt();
	void randomize_dirt(float dirt_index);

private:
	static Environment* instance;
	Environment();
	Environment(int, int);
	Environment(int, int, float);
	~Environment();
};
