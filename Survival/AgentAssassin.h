#pragma once
#include "Agent.h"
class AgentAssassin :
	public Agent
{
	int chance;
public:
	AgentAssassin(int, int, int, int, int);
	void setChance(int);
	int getChance() const;
	void setCharacter(string);
	string getCharacter();

	~AgentAssassin();
};

