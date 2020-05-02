#pragma once
#include "Agent.h" 

class AgentWarrior :
	public Agent
{
	double armor;
public:
	AgentWarrior(int, int, int, int, double);
	AgentWarrior();
	void setArmor(double);
	double getArmor() const;
	void setCharacter(string);
	string getCharacter();

	~AgentWarrior();
};

