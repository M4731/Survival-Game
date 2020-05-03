#include "AgentWarrior.h"

//constructori ce se folosesc de constructorul default implementat in clasa abstracta
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

//abilitatea warrior-ului ii mareste hp-ul ca armura la inceputul fiecarei batalii
void AgentWarrior::ability()
{
    if (!this->cooldown)
    {
        cout << this->character << "'s passive ability makes him get" << this->armor << "% armor our of total health while he is in a fight. " << endl;
        this->health = this->health + (this->health * this->armor / 100);
    }
    this->cooldown = 1;
}

//functie folosita pentru a reseta abilitatea si cooldown-ul acesteia
void AgentWarrior::abilityFinish()
{
    if (this->cooldown)
    {
        this->health = this->health - (this->health * this->armor / 100);
    }
    this->cooldown = 0;
}

AgentWarrior::~AgentWarrior()
{
    Agent::noOfAgents--;
    //distrugatorul default functioneaza bine aici
}