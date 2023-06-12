// main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <vector>
#include "environment.h"
#include "agent.h"
#include "vacuum-cleaner.h"


using std::cout;
using std::endl;


int main()
{
	/// Generate environment instance
	Environment* model = Environment::GetInstance();
	model->SetEnvironment();

	/// Show initial state of grid
	model->PrintGrid();
	cout << endl;

	/// Generate this number of vacuums
	int number_of_vacuums = 3;
	std::vector<VacuumCleaner> roombas;
	roombas.reserve(number_of_vacuums);

	/// Generate a vacuum in each row
	for (int i = 0; i < number_of_vacuums; i++)
	{
		roombas.push_back(VacuumCleaner(0, i));
	}

	/// For each roomba in the roomba list, make this steps with each
	int steps = 5;
	for (VacuumCleaner roomba : roombas)
	{
		for (int i = 0; i < steps; i++)
		{
			roomba.Step();
		}
	}

	/// Print the final state
	model->PrintGrid();
	return 0;
}
