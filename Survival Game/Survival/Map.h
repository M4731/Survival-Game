#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<vector>
#include<string>
#include "Agent.h"
using namespace std;

class Agent;
class Map
{
    vector< vector<string> > harta;
    vector<Agent*> agentsVector;

public:
    Map();
    void setMap(int, int);
    vector< vector <string> > getMap() const;
    void addAgent(Agent&);
    void removeAgent(Agent&);
    friend ostream& operator<<(ostream&, const Map&);
    friend class GameEngine;
    friend class Agent;
};

#endif
