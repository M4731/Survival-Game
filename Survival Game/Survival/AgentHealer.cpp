#include "AgentHealer.h"

//constructori ce se folosesc de constructorul default implementat in clasa abstracta
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

//abilitatea heal-erului il face sa isi regenereze hp de fiecare data cand scade sub 70
void AgentHealer::ability()
{
    if ( !this->cooldown && this->health <= 70 )
    {
        cout << this->character << " was low hp and healed themselves for " << this->heal << ". " << endl;
        this->health = this->health + this->heal;
        this->cooldown = 1;
    }
}

//functie folosita pentru a reseta abilitatea si cooldown-ul acesteia
void AgentHealer::abilityFinish()
{
    this->cooldown = 0;
}

AgentHealer::~AgentHealer()
{
    Agent::noOfAgents--;
    //distrugatorul default functioneaza bine aici
}