#include "AgentWarrior.h"

AgentWarrior::AgentWarrior(int positionX, int positionY, int health, int damage,double a):Agent( positionX, positionY, health, damage)
{
    this->armor = a;
}

void AgentWarrior::setCharacter(string name)
{
    this->character = name;
}

string AgentWarrior::getCharacter()
{
    return character;
}

void AgentWarrior::setArmor(double a)
{
    this->armor = a;
}

double AgentWarrior::getArmor() const
{
    return armor;
}

AgentWarrior::~AgentWarrior()
{
    Agent::noOfAgents--;
}