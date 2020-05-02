#pragma once
#include "Agent.h"
class AgentHealer :
	public Agent
{
	int heal, mana;
public:
	AgentHealer(int, int, int, int, int);
	void setHeal(int);
	int getHeal () const;
	void setCharacter(string);
	string getCharacter();

	~AgentHealer();
};

