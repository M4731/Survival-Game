#include "GameEngine.h"

//se genereaza harta cea pe care o vom folosi pentru joc si se construieste vectorul de agenti
//se afiseaza harta prima data pentru inceperea jocului
GameEngine::GameEngine()
{
	srand( time(NULL) );
	int x, y, agentsOfType;
	cout << "What dimentions do you want the map to have ?";
	cin >> x >> y;
	harta.setMap(x, y);
	cout << "How many agents of a type do you want ?";
	cin >> agentsOfType;
	int agentsOfTypeH, agentsOfTypeA, agentsOfTypeW;
	agentsOfTypeH = agentsOfTypeA = agentsOfTypeW = agentsOfType;
	while (agentsOfTypeW)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		Agent *W =  new AgentWarrior(loc1, loc2, 150, 30, 0, 15);
		W->setCharacter("W");
		harta.harta[loc1][loc2] = W->getCharacter();
		harta.addAgent(W);
		
		agentsOfTypeW--;
	}
	while (agentsOfTypeA)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		Agent *A = new AgentAssassin(loc1, loc2, 100, 40, 0, 2);
		A->setCharacter("A");
		harta.harta[loc1][loc2] = A->getCharacter();
		harta.addAgent(A);

		agentsOfTypeA--;
	}
	while (agentsOfTypeH)
	{
		unsigned loc1 = rand() % x, loc2 = rand() % y;
		Agent *H = new AgentHealer(loc1, loc2, 120, 30, 0, 25);
		H->setCharacter("H");
		harta.harta[loc1][loc2] = H->getCharacter();
		harta.addAgent(H);

		agentsOfTypeH--;
	}
	afisare();
}

//afiseaza harta
void GameEngine::afisare()
{
	cout << this->harta << endl;
}

//metoda care se ocupa de rulatul jocului cat primeste 1 de la tastatura si cat timp avem mai mult de un agent
//daca avem un singur agent acesta este declarat castigator si jocul se incheie automat
void GameEngine::runGame()
{
	int raspuns, round = 0;
	cout << "Round : " << round << endl;
	cout << "Do you wish to continue? 1-YES, 0-NO" << endl;
	cin >> raspuns;
	int ok = harta.agentsVector.size();
	while (raspuns == 1)
	{
		if (ok > 1)
		{
			do
			{
				nextRound();
				afisare();
				round++;
				cout << "Round : " << round << endl;
				cout << "Do you wish to continue? 1-YES, 0-NO" << endl;
				cin >> raspuns;
				ok = harta.agentsVector.size();
			} while (ok > 1);
		}
	}
	
}

//metoda care ruleaza jocul
//ne plimbam prin vectorul de agenti, daca un agent vrea sa se duca undeva unde nu este spatiu(loc ocupat)
//cautam agentul care se afla pe acea pozitie in a doua parcurgere a vectorului de agenti
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
			//daca vectorul de agenti are lungimea 1 atunci avem un castigator, dar daca acesta are <= 0 hp nu avem niciun castigator pentru ca ambii agenti sunt morti
			if (harta.agentsVector.size() == 1)
			{
				cout << "Game is over!" << endl;
				if (harta.agentsVector[0]->getHealth() > 0)
				{
					cout << endl << harta.agentsVector[0]->character << " won!" << endl;
					break;
				}
				else
				{
					cout << "Nobody won. All agents died." << endl;
					break;
				}
			}
		}
		//se afiseaza movementul fiecarui agent
		cout << i->getCharacter() << " moved from [ " << i->getPositionX() << " ; " << i->getPositionY() << " ] ";
		i->moveAgent(harta);
		cout << "to [ " << i->getPositionX() << " ; " << i->getPositionY() << " ] " << endl;
		y++;
	}
}

//metoda care se ocupa de lupte
//lupta se termina cand macar un agent a ajuns la <0 hp
//exista posibilitatea sa moara ambii agenti, caz in care amandoi sunt stersi din vector
Agent* GameEngine::StartFight(Agent& i, Agent& j)
{
	while (i.getHealth() > 0 && j.getHealth() > 0)
	{
		i.ability();
		j.ability();
		j.setHealth( j.getHealth() - i.getDamage() );
		cout << i.getCharacter() << " struck " << j.getCharacter() << " for " << i.getDamage() << " health. ";
		cout << j.getCharacter() << " is down to " << j.getHealth() << " health." <<endl;
		i.setHealth(i.getHealth() - j.getDamage());
		cout << j.getCharacter() << " struck " << i.getCharacter() << " for " << j.getDamage() << " health. ";
		cout << i.getCharacter() << " is down to " << i.getHealth() << " health." <<endl;
	}
	i.abilityFinish();
	j.abilityFinish();

	if (i.getHealth() <= 0){
		cout << i.character << " died." << endl;
		harta.removeAgent(i);
		return &i;
	}
	if (j.getHealth() <= 0){
		cout << j.character << " died." << endl;
		harta.removeAgent(j);
		return &j;
	}
}
