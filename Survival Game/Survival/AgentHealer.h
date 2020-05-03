#pragma once
#include "Agent.h"
class AgentHealer :
	public Agent
{
	int heal;
public:
	AgentHealer(int, int, int, int, bool, int);
	void setHeal(int);
	int getHeal () const;
	void setCharacter(string);
	string getCharacter();

	void ability();

	~AgentHealer();
};

