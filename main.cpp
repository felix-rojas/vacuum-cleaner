// main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "environment.h"
#include "agent.h"
#include "vacuum-cleaner.h"


using std::cout;
using std::endl;


int main()
{
	Environment* model = Environment::GetInstance();
	model->SetEnvironment();
	model->PrintGrid();
	cout << endl;
	VacuumCleaner roomba;
	for (size_t i = 0; i < 7; i++)
	{
		roomba.GetPosition(); roomba.Step();
	}
	roomba.GetPosition();

	cout << roomba.clean_count << endl;

	cout << roomba.IsStopped() << endl;
	model->PrintGrid();
	return 0;
}
