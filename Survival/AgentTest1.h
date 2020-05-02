
#include "Agent.h"
class AgentTest1 : public Agent
{

public:
	AgentTest1(int x, int y) :Agent( x, y, 80, 90) {
		health = 90;
	};
	void setHealth(int);
};
