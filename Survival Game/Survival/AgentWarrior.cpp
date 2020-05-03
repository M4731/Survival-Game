#include "AgentWarrior.h"

AgentWarrior::AgentWarrior(int positionX, int positionY, int health, int damage, bool inFight,double a):Agent( positionX, positionY, health, damage, cooldown)
{
    this->armor = a;
}

AgentWarrior::AgentWarrior():Agent(0,0,0,0,0)
{
    this->armor = 0;
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

void AgentWarrior::ability()
{
    if (!this->cooldown)
    {
        cout << this->character << "'s passive ability makes him take" << this->armor << "% less damage from all sources. " << endl;
        this->health = this->health + (this->health * this->armor / 100);
    }
    this->cooldown = 1;
}

AgentWarrior::~AgentWarrior()
{
    Agent::noOfAgents--;
}