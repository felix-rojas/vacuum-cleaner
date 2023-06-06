// main.cpp : Defines the entry point for the application.
//
#include<iostream>
#include "environment.h"


using std::cout;
using std::endl;

int main()
{
	Environment* model = Environment::GetInstance(10,10,.2);
	model->PrintGrid();
	cout << model->dirty_cells << endl;
	return 0;
}
