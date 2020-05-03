#include "AgentHealer.h"

AgentHealer::AgentHealer(int positionX, int positionY, int health, int damage, bool inFight, int h) :Agent(positionX, positionY, health, damage, cooldown)
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

void AgentHealer::ability()
{
    if ( !this->cooldown && this->health <= 50 )
    {
        cout << this->character << " was low hp and healed themselves for" << this->heal << ". " << endl;
        this->health = this->health + this->heal;
    }
    this->cooldown = 1;
}

AgentHealer::~AgentHealer()
{
    Agent::noOfAgents--;
}