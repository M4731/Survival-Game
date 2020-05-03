#ifndef AGENT_H
#define AGENT_H
#include<vector>
#include<string>
#include "Map.h"

using namespace std;

class Map;
class Agent
{
protected:
    int positionX;
    int positionY;
    int health;
    int damage;

    string character;

    bool cooldown;
    //noOfAgents contorizeaza numarul de agenti, creste de fiecare data cand e construit un agent si scade de fiecare data cand este sters un agent
    //din pacare nu va fi folosit deloc in proiect, dar il las aici :D
    static int noOfAgents;

    pair <int, int> search_nearest_agent(Map&);
public:
    Agent();
    Agent(int, int, int, int, bool);
    void setPosition(int, int);
    int getPositionY() const;
    int getPositionX() const;
    void setHealth(int);
    int getHealth() const;
    void setDamage(int);
    int getDamage() const;

    void setcooldown(bool);
    bool getcooldown() const;

    bool operator== (const Agent& a);
    bool operator!= (const Agent& a);
    void moveAgent(Map&);
    pair<int, int> nextMove(Map&);
    static int getNoOfAgents();

    virtual void setCharacter(string) = 0;
    virtual string getCharacter() = 0;
    virtual void ability() = 0;
    virtual void abilityFinish() = 0;

    virtual ~Agent() = 0 ;

    friend class Map;
    friend class GameEngine;
};

#endif
