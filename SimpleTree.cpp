#include <utility>
#include "Move.cpp"
#include <vector>
#include <array>

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

int locationsTaken[] = {0,0,0,0,0,0,0,0,0}; // LocationsTaken. 

class SimpleTree
{
public:
	Move move;

	vector<SimpleTree*> children;
	array<int,3> selected;

	int size; // number of children

	SimpleTree(int children);
	
	void preOrderPrint();
	int generateRandom();

	Move* getNextMove(SimpleTree* root);

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
	void branchToDecision();

	Move getMove();

	bool hasTwo(array<int,3> a);
	array<int,3> getRows(int row);
	array<int,3> getColumns(int column);
	array<int,3> getDiagonals(int diagonal);

	bool canWin(); 
	bool canBlockRow();
	bool canFork(); 
	bool canBlockFork();
	bool canCenter(); 
	bool canOppositeCorner() ;
	bool canEmptyCorner() ;
	bool canEmptySide();
	Move* getWin();
	Move* getBlockRow() ;
	Move* getFork() ;
	Move* getBlockFork();
	Move* getCenter() ;
	Move* getOppositeCorner() ;
	Move* getEmptyCorner() ;
	Move* getEmptySide();
};

SimpleTree::SimpleTree(int argSize)
{
	size = argSize;
	selected[0] = 0;
	selected[1] = 1;
	selected[2] = 2;
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

// interprets the current state of the board as a tree and then runs mmab.
Move* SimpleTree::getNextMove(SimpleTree* root)
{

	return nullptr;
}

int SimpleTree::calculateUtility()
{
	int value = 0;

	if(canWin())
	{
		value = 8;
	}
	else if(canBlockRow())
	{
		value = 7;
	}
	else if(canFork())
	{
		value = 6;
	}
	else if(canBlockFork())
	{
		value = 5;
	}
	else if(canCenter())
	{
		value = 4;
	}
	else if(canOppositeCorner())
	{
		value = 3;
	}
	else if(canEmptyCorner())
	{
		value = 2;
	}
	else if(canEmptySide())
	{
		value = 1;
	}
	else
	{
		// uh, is the game done? why are you here
	}
	return value;
}

// removes the child nodes that were not selected.
void SimpleTree::branchToDecision()
{

}

// Returns true if two of three of the locations are taken
bool SimpleTree::hasTwo(array<int,3> a)
{
	return a[0] + a[1] + a[2] == 2;
}

array<int,3> SimpleTree::getRows(int row)
{
	if(row == 1)
	{
		selected[0] = locationsTaken[0];
		selected[1] = locationsTaken[1];
		selected[2] = locationsTaken[2];
	}
	else if (row == 2)
	{
		selected[0] = locationsTaken[3];
		selected[1] = locationsTaken[4];
		selected[2] = locationsTaken[5];
	}
	else if (row == 3)
	{
		selected[0] = locationsTaken[6];
		selected[1] = locationsTaken[7];
		selected[2] = locationsTaken[8];
	}
	return selected;
}

array<int,3> SimpleTree::getColumns(int column)
{

	if(column == 1)
	{
		selected[0] = locationsTaken[0];
		selected[1] = locationsTaken[3];
		selected[2] = locationsTaken[6];
	}
	else if (column == 2)
	{
		selected[0] = locationsTaken[1];
		selected[1] = locationsTaken[4];
		selected[2] = locationsTaken[7];
	}
	else if (column == 3)
	{
		selected[0] = locationsTaken[2];
		selected[1] = locationsTaken[5];
		selected[2] = locationsTaken[8];	}

	return selected;
}

array<int,3> SimpleTree::getDiagonals(int diagonal)
{

	if(diagonal == 1)
	{
		selected[0] = locationsTaken[0];
		selected[1] = locationsTaken[4];
		selected[2] = locationsTaken[8];
	}
	else if (diagonal == 2)
	{
		selected[0] = locationsTaken[2];
		selected[1] = locationsTaken[4];
		selected[2] = locationsTaken[6];
	}

	return selected;
}

bool SimpleTree::canWin() //If the player has two in a row, they can place a third to get three in a row.
{
	bool canWin = false;

	canWin = hasTwo(getRows(1)) || hasTwo(getRows(2)) || hasTwo(getRows(3))  || 
	hasTwo(getColumns(1)) || hasTwo(getColumns(2)) || hasTwo(getColumns(3)) ||
	hasTwo(getDiagonals(1)) || hasTwo(getDiagonals(2));

	return canWin;	
}

bool SimpleTree::canBlockRow() //If the opponent has two in a row, the player must play the third themselves to block the opponent.
{
	return false;	
}

bool SimpleTree::canFork() //Create an opportunity where the player has two threats to win (two non-blocked lines of 2).
{
	return false;	
}

// canblock an opponent's fork:
//The player should create two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork. For example, if "X" has a corner, "O" has the center, and "X" has the opposite corner as well, "O" must not play a corner in order to win. (Playing a corner in this scenario creates a fork for "X" to win.)
//If there is a configuration where the opponent can fork, the player should block that fork.
bool SimpleTree::canBlockFork()
{
	return false;		
}

bool SimpleTree::canCenter() //A player marks the center. (If it is the first move of the game, playing on a corner gives "O" more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
{
	return false;		
}

bool SimpleTree::canOppositeCorner() //If the opponent is in the corner, the player plays the opposite corner.
{
	return false;		
}

bool SimpleTree::canEmptyCorner() //The player plays in a corner square.
{
	return false;		
}

bool SimpleTree::canEmptySide() // The player plays in a middle square on any of the 4 sides.
{
	return false;		
}

// 
Move* SimpleTree::getWin()
{
	return nullptr;	
}

Move* SimpleTree::getBlockRow() 
{
	return nullptr;
}

Move* SimpleTree::getFork() 
{
	return nullptr;
}

Move* SimpleTree::getBlockFork()
{
	return nullptr;
}

Move* SimpleTree::getCenter() 
{
	return nullptr;
}

Move* SimpleTree::getOppositeCorner() 
{
	return nullptr;
}

Move* SimpleTree::getEmptyCorner() 
{
	return nullptr;
}

Move* SimpleTree::getEmptySide()
{
	return nullptr;
}

