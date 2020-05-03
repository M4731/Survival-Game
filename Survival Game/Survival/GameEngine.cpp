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
		Agent *W =  new AgentWarrior(loc1, loc2, 120, 30, 0, 15);
		W->setCharacter("W");
		harta.harta[loc1][loc2] = W->getCharacter();
		harta.addAgent(W);
		
		agentsOfTypeW--;
	}
	while (agentsOfTypeA)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		Agent *A = new AgentAssassin(loc1, loc2, 120, 30, 0, 15);
		A->setCharacter("A");
		harta.harta[loc1][loc2] = A->getCharacter();
		harta.addAgent(A);

		agentsOfTypeA--;
	}
	while (agentsOfTypeH)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		Agent *H = new AgentHealer(loc1, loc2, 120, 30, 0, 15);
		H->setCharacter("H");
		harta.harta[loc1][loc2] = H->getCharacter();
		harta.addAgent(H);

		agentsOfTypeH--;
	}
	this->harta = harta;
	afisare();
}

void GameEngine::afisare()
{
	cout << this->harta << endl;
	cout << this->harta.agentsVector.size();
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
	int y = 0;
	while (y < harta.agentsVector.size())
	{
		Agent* i = harta.agentsVector[y];
		if (harta.harta[i->nextMove(harta).first][i->nextMove(harta).second] != " ")
		{
			int x = 0;
			while(x < harta.agentsVector.size()) 
			{
				Agent* j = harta.agentsVector[x];
				if (j->positionX == i->nextMove(harta).first && j->positionY == i->nextMove(harta).second && i != j)
				{
					cout << i->getCharacter() << " started fighting " << j->getCharacter() << " ." << endl;
					Agent *aux = StartFight(*i, *j);
					if (aux == i)
					{
						y--;
						if (x > y)
						{
							x--;
						}
					}
					else if (aux == j)
					{
						x--;
						if (y > x)
						{
							y--;
						}
					}
				}
				x++;
			}
		}
		cout << i->getCharacter() << " moved from [ " << i->getPositionX() << " ; " << i->getPositionY() << " ] ";
		i->moveAgent(harta);
		cout << "to [ " << i->getPositionX() << " ; " << i->getPositionY() << " ] " << endl;
		y++;
	}
}

Agent* GameEngine::StartFight(Agent& i, Agent& j)
{
	i.ability();
	j.ability();
	int w = rand() % 2;
	if (w == 1){
		cout << i.character << " died." << endl;
		harta.removeAgent(i);
		return &i;
	}
	else {
		cout << j.character << " died." << endl;
		harta.removeAgent(j);
		return &j;
	}
}
