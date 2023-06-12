#pragma once

class Agent
{
public:
	Agent();
	Agent(int, bool, bool);
	~Agent();
	int GetAgentId();
	void SetAgentId(int);
	void SetAgentCollission(bool);
	void SetEnvironmentCollission(bool);
	virtual void Step();


protected:
	int id;
	bool agent_collission;
	bool environment_collission;
};