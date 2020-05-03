#include "AgentAssassin.h"

//constructori ce se folosesc de constructorul default implementat in clasa abstracta
AgentAssassin::AgentAssassin(int positionX, int positionY, int health, int damage, bool inFight, int c) :Agent(positionX, positionY, health, damage, cooldown)
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

//abilitatea asasinului il face sa aiba o sansa la inceputul fiecarei batalii sa isi dubleze damage-ul
void AgentAssassin::ability()
{
    srand(time(NULL));
    if ( !this->cooldown )
    {
        if (rand() % this->chance == 1)
        {
            this->damage = 2 * this->damage;
            cout << this->character << " used their ability and gained double damage for this fight." << endl;
        }
        else cout << this->character << " used their ability but nothing happened :( " << endl;
    }
    this->cooldown = 1;
}

//functie folosita pentru a reseta abilitatea si cooldown-ul acesteia
void AgentAssassin::abilityFinish()
{
    if (this->cooldown)
    {
        if ( this->damage >= 60 )
        {
            this->damage = this->damage / 2;
        }
    }
    this->cooldown = 0;
}

AgentAssassin::~AgentAssassin()
{
    Agent::noOfAgents--;
    //distrugatorul default functioneaza bine aici
}