#pragma once
#include "agent.h"

Agent::Agent()
{
	id = 1;
	agent_collission = false;
	environment_collission = false;
}

Agent::Agent(int agent_id, bool does_agent_collide, bool does_environment_collide) 
{
	id = agent_id;
	agent_collission = does_agent_collide;
	environment_collission = does_environment_collide;
}

Agent::~Agent()
{
}

int Agent::GetAgentId()
{
	return id;
}

void Agent::SetAgentId(int new_id)
{
	this->id = new_id;
}

void Agent::SetAgentCollission(bool does_collide)
{
	this->agent_collission = does_collide;
}

void Agent::SetEnvironmentCollission(bool does_collide)
{
	this->environment_collission = does_collide;
}
