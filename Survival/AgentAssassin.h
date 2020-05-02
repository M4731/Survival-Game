#pragma once
#include "Agent.h"
#include <time.h>
class AgentAssassin :
	public Agent
{
	int chance;
public:
	AgentAssassin(int, int, int, int, bool, int);
	void setChance(int);
	int getChance() const;
	void setCharacter(string);
	string getCharacter();

	void ability();

	~AgentAssassin();
};

