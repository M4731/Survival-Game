#pragma once
#include "map.h"
#include "Agent.h"
#include "AgentWarrior.h"
#include "AgentAssassin.h"
#include "AgentHealer.h"
#include <time.h>

class GameEngine
{
	Map harta;
public:
	GameEngine();
	void afisare();
	void runGame();
	void nextRound();
};

