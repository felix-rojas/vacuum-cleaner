// vacuum-cleaner.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "agent.h"

class VacuumCleaner : Agent
{
public:
	VacuumCleaner();
	VacuumCleaner(unsigned int pos_x, unsigned int pos_y);
	~VacuumCleaner();

private:
	bool can_move(int,int);
	void left();
	void right();
	void suck();
	void no_op();
	void check_clean();
	int pos_x = 0; 
	int pos_y = 0;
	int stand_still = 0;
};
