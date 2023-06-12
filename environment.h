#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <utility> // For std::pair
#include "vacuum-cleaner.h"
#include "agent.h"

using std::vector;

class Environment
{
public:
	vector <vector <int>> grid;
	vector <Agent> AgentList;
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
	void place_agents(vector <Agent>);

private:
	static Environment* instance;
	Environment();
	Environment(int, int);
	Environment(int, int, float);
	~Environment();
};
