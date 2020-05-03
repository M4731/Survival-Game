#pragma once
#include "map.h"
#include "Agent.h"
#include "AgentWarrior.h"
#include "AgentAssassin.h"
#include "AgentHealer.h"
#include <time.h>

using namespace std;

class GameEngine
{
	Map harta;
public:
	GameEngine();
	void afisare();
	void runGame();
	void nextRound();

	Agent* StartFight(Agent&, Agent&);
};

