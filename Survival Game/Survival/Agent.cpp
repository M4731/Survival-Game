#include "Agent.h"

int Agent::noOfAgents = 0;

Agent::Agent()
{
    this->positionX = 0;
    this->positionY = 0;
    this->health = 0;
    this->damage = 0;
    this->cooldown = 0;
    Agent::noOfAgents++;
}

Agent::Agent(int x, int y, int health, int damage, bool inFight)
{
    this->positionX = x;
    this->positionY = y;
    this->health = health;
    this->damage = damage;
    this->cooldown = 0;
    Agent::noOfAgents++;
}

void Agent::setPosition(int x, int y)
{
    this->positionX = x;
    this->positionY = y;
}

int Agent::getPositionY() const
{
    return positionY;
}

int Agent::getPositionX() const
{
    return positionX;
}

int Agent::getHealth() const
{
    return health;
}

void Agent::setHealth( int h )
{
    health = h;
}

void Agent::setDamage(int damage)
{
    this->damage = damage;
}

int Agent::getDamage() const
{
    return damage;
}

int Agent::getNoOfAgents()
{
    return noOfAgents;
}

void Agent::setcooldown(bool ok)
{
    this->cooldown = ok;
}

bool Agent::getcooldown() const
{
    return this->cooldown;
}

bool Agent::operator==(const Agent& a)
{
    if (this->positionX == a.getPositionX() && this->positionY == a.getPositionY() && this->health == a.getHealth() && this->damage == a.getDamage()) {
        return true;
    }
    else {
        return false;
    }
}

bool Agent::operator!=(const Agent& a)
{
    if (this->positionX != a.getPositionX() || this->positionY != a.getPositionY() || this->health != a.getHealth() || this->damage != a.getDamage()) {
        return true;
    }
    else {
        return false;
    }
}

pair<int, int> Agent::search_nearest_agent(Map& harta)
{
    int distmin = INT16_MAX;
    Agent* aux = NULL;
   // vector<Agent*> a = harta.agentsVector; mod ( i - i ) + mod( j - j )
    for (Agent* i : harta.agentsVector) {
        int x = abs(positionX - i->positionX);
        int y = abs(positionY - i->positionY);
        //  unsigned dist = min(x,y) + abs(x-y)
        int ajutor;
        if (x < y) 
            ajutor =  x;
        else 
            ajutor =  y;
        if ( (ajutor + abs(x - y) < distmin) && i->positionX != positionX || i->positionY != positionY) {
            distmin = ajutor + abs(x - y);
            aux = i;
        }
    }
    if (aux)
    {
        return { aux->positionX, aux->positionY };
    }
    else
    {
        return { 0 , 0 };
    }
}

void Agent::moveAgent(Map& harta)
{
    int y = 0, x = 0;
    harta.harta[positionX][positionY] = " ";
    pair<int, int> p = search_nearest_agent(harta);
    if (positionY - p.second != 0)
    {
        y = ( p.second - positionY ) / abs(positionY - p.second);
    }
    if (positionX - p.first != 0)
    {
        x = ( p.first - positionX ) / abs(positionX - p.first);
    }
    if ( positionY + y < harta.harta[0].size() && positionY + y >= 0 )
        if (positionX + x < harta.harta.size() && positionX + x >= 0)
            setPosition(positionX + x, positionY + y);
    harta.harta[positionX][positionY] = character;
}

pair<int, int> Agent::nextMove(Map& harta)
{
    int y = 0, x = 0;
    pair<int, int> p = search_nearest_agent(harta);
    if (positionY - p.second != 0)
    {
        y = (p.second - positionY) / abs(positionY - p.second);
    }
    if (positionX - p.first != 0)
    {
        x = (p.first - positionX) / abs(positionX - p.first);
    }
    if (positionY + y < harta.harta[0].size() && positionY + y >= 0)
        if (positionX + x < harta.harta.size() && positionX + x >= 0)
            return { positionX + x, positionY + y };
}

Agent::~Agent()
{
}
