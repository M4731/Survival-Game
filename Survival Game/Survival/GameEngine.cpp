#include "GameEngine.h"

GameEngine::GameEngine()
{
	srand( time(NULL) );
	int x = 15, y = 30;
	Map harta;
	harta.setMap(x, y);
	int agentsOfType = 2;
	int agentsOfTypeH, agentsOfTypeA, agentsOfTypeW;
	agentsOfTypeH = agentsOfTypeA = agentsOfTypeW = agentsOfType;
	while (agentsOfTypeW)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		AgentWarrior W(loc1, loc2, 120, 30, 15);
		W.setCharacter("W");
		harta.harta[loc1][loc2] = W.getCharacter();
		harta.addAgent(W);
		
		agentsOfTypeW--;
	}
	while (agentsOfTypeA)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		AgentAssassin A(loc1, loc2, 120, 30, 15);
		A.setCharacter("A");
		harta.harta[loc1][loc2] = A.getCharacter();
		harta.addAgent(A);

		agentsOfTypeA--;
	}
	while (agentsOfTypeH)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		AgentHealer H(loc1, loc2, 120, 30, 15);
		H.setCharacter("H");
		harta.harta[loc1][loc2] = H.getCharacter();
		harta.addAgent(H);

		agentsOfTypeH--;
	}
	this->harta = harta;
	afisare();
}

void GameEngine::afisare()
{
	cout << this->harta << endl;
}

void GameEngine::runGame()
{
	int raspuns, round = 0;
	cout << "Round : " << round << endl;
	cout << "Do you wish to continue? 1-YES, 0-NO" << endl;
	cin >> raspuns;
	while (raspuns == 1)
	{
		nextRound();
		afisare();
		round++;
		cout << "Round : " << round << endl;
		cout << "Do you wish to continue? 1-YES, 0-NO" << endl;
		cin >> raspuns;
	}
}

void GameEngine::nextRound()
{
	for (Agent* i : harta.agentsVector)
	{
		i->moveAgent(harta);
	}
}