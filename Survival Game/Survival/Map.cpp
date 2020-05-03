#include "map.h"

Map::Map()
{
}

//seteaza mapa de dimensiunile date si o umple de spatii
void Map::setMap(int x, int y)
{
    int i, j;
    harta.resize(x);
    for (i = 0; i < x; i++) {
        harta[i].resize(y);
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++)
        {
            harta[i][j] = " ";
        }
    }
}

vector<vector <string> > Map::getMap() const
{
    return harta;
}

//adaugarea unui agent in vector si pe harta
void Map::addAgent( Agent* a)
{
    harta[a->getPositionX()][a->getPositionY()] = a->character;
    agentsVector.push_back(a);
}

//stergerea unui agent din vectorul de agenti punandu-l pe ultimul element din vector si folosind functia pop
//putin inspirat de pe https://github.com/fbilbie/Projects/blob/master/Surving%20game/poo_t3/World.cpp
void Map::removeAgent(Agent& a)
{
    harta[a.getPositionX()][a.getPositionY()] = " ";
    unsigned i = 0;
    while (i < agentsVector.size() && a != *agentsVector[i])
        i++;
    for (unsigned j = i; j < agentsVector.size() - 1; j++)
        agentsVector[j] = agentsVector[j + 1];
    agentsVector.pop_back();
}

//supraincarcarea operatorului << pentru afisarea hartii
ostream& operator<<(ostream& out, const Map& m)
{
    for (unsigned i = 0; i < m.getMap()[0].size() + 2; i++) {
        out << "-";
    }
    out << endl;
    for (unsigned i = 0; i < m.getMap().size(); i++) {
        out << "|";
        for (unsigned j = 0; j < m.getMap()[i].size(); j++)
        {
            out << m.getMap()[i][j];
        }
        out << "|" << endl;
    }
    for (unsigned i = 0; i < m.getMap()[0].size() + 2; i++) {
        out << "-";
    }
    return out;
}

Map::~Map()
{
    //de distrugerea hartii se ocupa distrugatorul default din <vector>
    for (unsigned i = 0; i < agentsVector.size(); i++)
    {
        if (agentsVector[i] != NULL)
            delete agentsVector[i];
    }
}

