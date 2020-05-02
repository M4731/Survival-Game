#include "AgentHealer.h"

AgentHealer::AgentHealer(int positionX, int positionY, int health, int damage, int h) :Agent(positionX, positionY, health, damage)
{
    this->heal = h;

}

void AgentHealer::setCharacter(string name)
{
    this->character = name;
}

string AgentHealer::getCharacter()
{
    return character;
}

void AgentHealer::setHeal(int h)
{
    this->heal = h;
}

int AgentHealer::getHeal() const
{
    return heal;
}

AgentHealer::~AgentHealer()
{
    Agent::noOfAgents--;
}