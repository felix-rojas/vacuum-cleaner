#pragma once
class Agent
{
public:
	Agent();
	Agent(int id, bool agent_collission, bool environment_collission);
	~Agent();

protected:
	int id;
	bool agent_collission = false;
	bool environment_collission = false;
};