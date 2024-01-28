#include <iostream>
#include <functional>
using namespace std;

enum state
{
	runAway,
	findLeaf,
	goHome
};

class FSM
{
private:
	state activeState;
	function<void()> f1;

public:
	void setState(state stateToSwitch)
	{
		activeState = stateToSwitch;
	}

};