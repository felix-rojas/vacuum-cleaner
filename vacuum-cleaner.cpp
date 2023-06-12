#pragma once
#include "vacuum-cleaner.h"
#include "environment.h"
// vacuum-cleaner.cpp : Implements vacuum-cleaner.
//

Environment* model = Environment::GetInstance();

VacuumCleaner::VacuumCleaner()
{
	SetAgentCollission(false);
	SetEnvironmentCollission(false);
	this->pos_x = 0;
	this->pos_y = 0;
}
VacuumCleaner::VacuumCleaner(unsigned int x, unsigned int y)
{
	SetAgentCollission(false);
	SetEnvironmentCollission(false);
	this->pos_x = x;
	this->pos_y = y;
}

VacuumCleaner::~VacuumCleaner()
{
}

/// check if it can move within the grid ranges
bool VacuumCleaner::can_move(int desired_pos_x, int desired_pos_y)
{
	if (desired_pos_x < model->cols && desired_pos_x >= 0)
	{
		if (desired_pos_y < model->rows && desired_pos_y >= 0)
		{
			return true;
		}
	}
}

void VacuumCleaner::left()
{
	if (can_move(pos_x - 1, pos_y))
	{
		pos_x -= 1;
	}
}

void VacuumCleaner::right()
{
	if (can_move(pos_x + 1, pos_y))
	{
		pos_x += 1;
	}
}

void VacuumCleaner::suck()
{
	model->grid[pos_x][pos_y] = 0;
}

void VacuumCleaner::no_op()
{
	stand_still += 1;
}

void VacuumCleaner::check_clean()
{
	if (model->get_state(this->pos_x, this->pos_y) == 1)
	{
		suck();
	}
}

