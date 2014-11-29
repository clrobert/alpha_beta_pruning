#include <utility>
#include "Move.cpp"
#include <vector>

using namespace std;


const pair<int,int> loc0 (-1,-1);

const pair<int,int> loc1 (0,0);
const pair<int,int> loc2 (0,1);
const pair<int,int> loc3 (0,2);
const pair<int,int> loc4 (1,0);
const pair<int,int> loc5 (1,1);
const pair<int,int> loc6 (1,2);
const pair<int,int> loc7 (2,0);
const pair<int,int> loc8 (2,1);
const pair<int,int> loc9 (2,2);

const pair<int,int> locations[] = {loc1, loc2, loc3, loc4, loc5, loc6, loc7, loc8, loc9};


class SimpleTree
{
public:
	Move move;

	vector<SimpleTree*> children;

	int size; // number of children

	SimpleTree(int children);
	
	void preOrderPrint();

	int generateRandom();

	Move getMove();

	void buildTree(Move* move);
	int calculateUtility();
	void print();
	void printChildren();
	static SimpleTree* maxNode(SimpleTree* a, SimpleTree* b);
	static SimpleTree* minNode(SimpleTree* a, SimpleTree* b);
	void init(int height);
	void buildFakeLow();
	void buildFakeHigh();
	int getUtility();
	void initTicTacToe();
	void initReversePyramid(int height);
};

SimpleTree::SimpleTree(int argSize)
{
	size = argSize;

	children.reserve(argSize);

	for(int i = 0; i < argSize; i++)
	{
		children[i] = new SimpleTree(0);
	}
}



void SimpleTree::init(int height)
{

	if(height > 0)
	{
		for(int i = 0; i < size; i++)
		{
			children[i] = new SimpleTree(9); // make nine new leaf nodes that have no children
			children[i]->buildTree(new Move(locations[i], i * 5, 'x')); // set them all up to reference the loc list
			children[i]->init(height - 1);
		}

	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			children[i] = new SimpleTree(0); // make nine new leaf nodes that have no children
			children[i]->buildTree(new Move(locations[i], i * -5, 'o')); // set them all up to reference the loc list
		}
	}	
}

int SimpleTree::calculateUtility()
{
	return 0;
}

void SimpleTree::initTicTacToe()
{
	initReversePyramid(9);
}

void SimpleTree::initReversePyramid(int height)
{
	if(height > 0)
	{
		for(int i = 0; i < size; i++)
		{
			children[i] = new SimpleTree(height - 1); // make n - 1 new leaf nodes that have no children
			children[i]->buildTree(new Move(locations[i], i * 5, 'x')); 
			children[i]->init(height - 1);
		}

	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			children[i] = new SimpleTree(0); // make nine new leaf nodes that have no children
			children[i]->buildTree(new Move(locations[i], i * -5, 'o')); // set them all up to reference the loc list
		}
	}	
}


void SimpleTree::buildTree(Move* arg)
{
	move = *arg;
}

void SimpleTree::buildFakeLow()
{
	move.buildMove(loc0, -100, 'Y');
}

void SimpleTree::buildFakeHigh()
{
	move.buildMove(loc0, 100, 'Y');
}


Move SimpleTree::getMove()
{
	return move;
}

void SimpleTree::printChildren()
{
	for(int i = 0; i < size; i++)
		{
			cout << "Root:\n";
			children[i]->print();
			cout << "Child: ";
			cout << i << '\n';
			children[i]->printChildren();			
		}	
}

void SimpleTree::print()
{
	move.toString();
}

int SimpleTree::getUtility()
{
	return move.getUtility();
}

SimpleTree* SimpleTree::maxNode(SimpleTree* a, SimpleTree* b)
{
	SimpleTree* max;

	if(a->getUtility() > b->getUtility())
	{
		max = a;
	}
	else
	{
		max = b;
	}
	return max;
}

SimpleTree* SimpleTree::minNode(SimpleTree* a, SimpleTree* b)
{
	SimpleTree* min;

	if(a->getUtility() < b->getUtility())
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
}
/*
// interprets the current state of the board as a tree and then runs mmab.
Move* SimpleTree::getNextMove(SimpleTree* root)
{




	return nullptr;
}

int SimpleTree::calculateUtility(int[] locationsTaken)
{
	int value = 0;

	if(canWin(locationsTaken))
	{
		value = 8;
	}
	else if(canBlockRow(locationsTaken))
	{
		value = 7;
	}
	else if(canFork(locationsTaken))
	{
		value = 6;
	}
	else if(canBlockFork(locationsTaken))
	{
		value = 5;
	}
	else if(canCenter(locationsTaken))
	{
		value = 4;
	}
	else if(canOppositeCorner(locationsTaken))
	{
		value = 3;
	}
	else if(canEmptyCorner(locationsTaken))
	{
		value = 2;
	}
	else if(canEmptySide(locationsTaken))
	{
		value = 1;
	}
	else
	{
		// uh, is the game done? why are you here
	}
}




// removes the child nodes that were not selected.
void SimpleTree::branchToDecision()
{

}

bool canWin() //If the player has two in a row, they can place a third to get three in a row.
{
	return false;	
}

bool canBlockRow() //If the opponent has two in a row, the player must play the third themselves to block the opponent.
{
	return false;	
}

bool canFork() //Create an opportunity where the player has two threats to win (two non-blocked lines of 2).
{
	return false;	
}

// canblock an opponent's fork:
//The player should create two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork. For example, if "X" has a corner, "O" has the center, and "X" has the opposite corner as well, "O" must not play a corner in order to win. (Playing a corner in this scenario creates a fork for "X" to win.)
//If there is a configuration where the opponent can fork, the player should block that fork.
bool canBlockFork()
{
	return false;		
}

bool canCenter() //A player marks the center. (If it is the first move of the game, playing on a corner gives "O" more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
{
	return false;		
}

bool canOppositeCorner() //If the opponent is in the corner, the player plays the opposite corner.
{
	return false;		
}

bool canEmptyCorner() //The player plays in a corner square.
{
	return false;		
}

bool canEmptySide() // The player plays in a middle square on any of the 4 sides.
{
	return false;		
}

// 
Move* getWin()
{
	return nullptr;	
}

Move* canBlockRow() 
{
	return nullptr;
}

Move* getFork() 
{
	return nullptr;
}

Move* canBlockFork()
{
	return nullptr;
}

Move* getCenter() 
{
	return nullptr;
}

Move* getOppositeCorner() 
{
	return nullptr;
}

Move* getEmptyCorner() 
{
	return nullptr;
}

Move* getEmptySide()
{
	return nullptr;
}

*/