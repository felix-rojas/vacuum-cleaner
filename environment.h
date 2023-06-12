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
private:
	static Environment* instance;
	Environment();
	~Environment();

public:
	vector <vector <int>> grid;
	vector <Agent> AgentList;
	int dirty_cells = 0;
	int cols = 0;
	int rows = 0;
	int get_state(int, int);
	void set_state(int pos_x, int pos_y, int state);
	static Environment* GetInstance();
	void PrintGrid();
	void SetEnvironment();
	void SetEnvironment(int m, int n);
	void SetEnvironment(int m, int n, float dirt_factor);
	void randomize_dirt();
	void randomize_dirt(float dirt_index);
	void place_agents(vector <Agent>);
	// delete copy contructor
	Environment(const Environment& obj)= delete;
};
