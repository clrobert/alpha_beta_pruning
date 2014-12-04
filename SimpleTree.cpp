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

char gameState[9]; // gameState. 

class SimpleTree
{
public:
	Move move;

	vector<SimpleTree*> children;
	array<char,3> selected;

	char currentMarker;

	int size; // number of children

	SimpleTree(int children);
	
	void preOrderPrint();
	int generateRandom();

	Move* getNextMove(SimpleTree* root);

	void buildTree(Move* move);
	int calculateUtility(char marker);
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

	char hasTwo(array<char,3> a);
	array<char,3> getRows(int row);
	array<char,3> getColumns(int column);
	array<char,3> getDiagonals(int diagonal);

	char canWin(); 
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

/*
	Calculates the current decision utility value of a given square and 
	player marker.
	This uses the current state of the board.
*/
int SimpleTree::calculateCurrentUtility(char cm, int location)
{
	int value = 0;
	currentMarker = cm;

	if(canWin())  // can win
	{
		value = 8;
	}
	else if(canBlock()) // can block
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

// Returns the marker if two of three of the locations are taken
bool SimpleTree::hasTwo(array<char,3> a)
{
	int count = 0;

	if(a[0] == currentMarker)
	{
		count++;
	}

	if(a[1] == currentMarker)
	{
		count++;
	}

	if(a[2] == currentMarker)
	{
		count++;
	}

	return count == 2;
}

array<char,3> SimpleTree::getRow(int location)
{
	if(location < 3)
	{
		selected[0] = gameState[0];
		selected[1] = gameState[1];
		selected[2] = gameState[2];
	}
	else if (location >= 3 && location < 6)
	{
		selected[0] = gameState[3];
		selected[1] = gameState[4];
		selected[2] = gameState[5];
	}
	else if (location >= 6)
	{
		selected[0] = gameState[6];
		selected[1] = gameState[7];
		selected[2] = gameState[8];
	}
	return selected;
}

array<char,3> SimpleTree::getColumn(int location)
{

	int column = location 	
	if(column % 3 == 0)
	{
		selected[0] = gameState[0];
		selected[1] = gameState[3];
		selected[2] = gameState[6];
	}
	else if (column % 3 == 1)
	{
		selected[0] = gameState[1];
		selected[1] = gameState[4];
		selected[2] = gameState[7];
	}
	else if (column % 3 == 2)
	{
		selected[0] = gameState[2];
		selected[1] = gameState[5];
		selected[2] = gameState[8];
	}

	return selected;
}

array<char,3> SimpleTree::getIfInLeftDiagonal(int location)
{

	if(location % 4 == 0)
	{
		selected[0] = gameState[0];
		selected[1] = gameState[4];
		selected[2] = gameState[8];
	}

	return selected;
}

array<char,3> SimpleTree::getIfInRightDiagonal(int location)
{
	if (location == 2 || location == 4 || location == 6)
	{
		selected[0] = gameState[2];
		selected[1] = gameState[4];
		selected[2] = gameState[6];
	}

	return selected;
}

//void SimpleTree::setGameState(char gamestate[]); // 

// If the player has two in a row, they can place a third to get three in a row.
// Returns the possible winner if there is a winner.
char SimpleTree::canWin(int location) 
{
	bool canWin = false;

	canWin = hasTwo(getRow(location));

	if(!canWin)
	{
		canWin = hasTwo(getColumn(location));
	}

	if(!canWin)
	{
		canWin = hasTwo(getIfInLeftDiagonal(location));
	}

	if(!canWin)
	{
		canWin = hasTwo(getIfInRightDiagonal(location));
	}

	// set selected to default state.

	return canWin;	
}

/*
Doesn't care if the current marker is uninitialized.
*/
void SimpleTree::flipCurrentMarker()
{
	if(currentMarker == 'X')
	{
		currentMarker = 'O';
	}
	else
	{
		currentMarker = 'X';
	}
}

bool SimpleTree::canBlock(int location) 
{
	bool canBlock = false;

	flipCurrentMarker();

	canBlock = canWin(location);

	flipCurrentMarker();

	return canBlock;	
}


bool SimpleTree::canFork() //Create an opportunity where the player has two threats to win (two non-blocked lines of 2).
{
	bool forkable = false;

	if(isMine(0) && isMine(8) && (isEmptyCorner(2) || isEmptyCorner(6)) )
	{
		forkable = true;
	}
	else if (isMine(2) && isMine(6) && (isEmptyCorner(0) || isEmptyCorner(8)) )
	{
		forkable = true;
	}

	return forkable;	
}

// canblock an opponent's fork:
//The player should create two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork. For example, if "X" has a corner, "O" has the center, and "X" has the opposite corner as well, "O" must not play a corner in order to win. (Playing a corner in this scenario creates a fork for "X" to win.)
//If there is a configuration where the opponent can fork, the player should block that fork.
bool SimpleTree::canBlockFork()
{
	bool canBlockFork = false;

	flipCurrentMarker();
	canBlockFork = canFork();
	flipCurrentMarker();

	return canBlockFork;		
}

/*
A player marks the center. (If it is the first move of the game, 
playing on a corner gives "O" more opportunities to make a mistake 
and may therefore be the better choice; however, it makes no difference between perfect players.)
*/
bool SimpleTree::canCenter() 
{
	return isEmpty(gameState[4]);		
}

 //If the opponent is in the corner, the player plays the opposite corner.
bool SimpleTree::canOppositeCorner(location)
{
	bool canCorner = false;

	if(location == 0 && isEmpty(gameState[8]))
	{
		canCorner = true;
	}
	else if(location == 2 && isEmpty(gameState[6]))
	{
		canCorner = true;
	}
	else if(location == 6 && isEmpty(gameState[2]))
	{
		canCorner = true;
	}
	else if(location == 8 && isEmpty(gameState[0]))
	{
		canCorner = true;
	}

	return canCorner;		
}

// Silly naming for if the marker at the location matches the given marker
bool SimpleTree::isMine(char location)
{
	return currentMarker == gameState[location];
}

bool SimpleTree::canEmptyCorner() //The player plays in a corner square.
{
	return isEmpty(gameState[0]) || isEmpty(gameState[2]) || isEmpty(gameState[6]) || isEmpty(gameState[8]);			
}

bool SimpleTree::canEmptySide() // The player can play in a middle square on any of the 4 sides.
{
	return isEmpty(gameState[1]) || isEmpty(gameState[3]) || isEmpty(gameState[5]) || isEmpty(gameState[7]);		
}

bool SimpleTree::isEmptyCorner(location)
{
	bool isCornerable;

	if(location == 0)
	{
		isCornerable = isEmpty(0) && isEmpty(1) && isEmpty(3);
	}
	if(location == 2)
	{
		isCornerable = isEmpty(1) && isEmpty(2) && isEmpty(5);
	}
	else if (location == 6)
	{
		isCornerable = isEmpty(3) && isEmpty(6) && isEmpty(7);
	}
	else if (location == 8)
	{
		isCornerable = isEmpty(5) && isEmpty(7) && isEmpty(8);
	}

	return isCornerable;
}

bool SimpleTree::isEmpty(char checkMe)
{
	return checkMe == ' ';
}

bool SimpleTree::isEmpty(int location)
{
	return gameState[location] == ' ';
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

