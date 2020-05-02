#include "AgentAssassin.h"

AgentAssassin::AgentAssassin(int positionX, int positionY, int health, int damage, int c) :Agent(positionX, positionY, health, damage)
{
    this->chance = c;
}

void AgentAssassin::setCharacter(string name)
{
    this->character = name;
}

string AgentAssassin::getCharacter()
{
    return character;
}

void AgentAssassin::setChance(int c)
{
    this->chance = c;
}

int AgentAssassin::getChance() const
{
    return chance;
}

AgentAssassin::~AgentAssassin()
{
    Agent::noOfAgents--;
}