#include <iostream>
#include <stack>
using namespace std;

/*
Finite-State Machine에 대한 코드로
https://code.tutsplus.com/finite-state-machines-theory-and-implementation--gamedev-11867t
이 페이지의 예제를 CPP로 옮김
*/

class FSM
{
private:
	void (FSM::*activeState)();

public:
	void setState(void (FSM::*funcPtr)())
	{
		// Transition
		activeState = funcPtr;
	}

	void runAway()
	{
		cout << "Run Away" << endl;
	}

	void findLeaf()
	{
		cout << "Find Leaf" << endl;
	}

	void goHome()
	{
		cout << "Go Home" << endl;
	}

	void update()
	{
		(this->*activeState)();
	}
};

class Ant
{
private:
	int x;
	int y;
	FSM brain;

public:
	Ant()
	{
		x = 0;
		y = 0;
		brain.setState(&FSM::findLeaf);
	}

	void update()
	{
		brain.update();
	}
};

int main()
{
	Ant ant;
	ant.update();
}