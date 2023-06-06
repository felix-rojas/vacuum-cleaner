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
	int can_move();
	void left();
	void right();
	void suck();
	void no_op();
	void check_clean();
	int pos_x, pos_y;
	int id;
	bool agent_collission = false;
	bool environment_collission = false;
};

VacuumCleaner::VacuumCleaner()
{
	pos_x, pos_y = 0;
}
VacuumCleaner::VacuumCleaner(unsigned int x, unsigned int y)
{
	pos_x = x;
	pos_y = y;

}
VacuumCleaner::~VacuumCleaner()
{
}

inline int VacuumCleaner::can_move()
{
}

inline void VacuumCleaner::left()
{
}

inline void VacuumCleaner::right()
{
}

inline void VacuumCleaner::suck()
{
}

inline void VacuumCleaner::no_op()
{
}

inline void VacuumCleaner::check_clean()
{
}


// TODO: Reference additional headers your program requires here.
