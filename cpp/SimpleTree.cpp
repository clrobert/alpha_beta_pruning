#include <utility>
#include "Move.cpp"
#include <vector>
#include <array>
#include <queue>

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



// this should be more efficient as a list, 
// i'm just too lazy to make an iterator,
// and performance isn't an issue in ttt.
//vector< pair<int,int> > locations (9);

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
	
	void preOrdertoString();
	int generateRandom();

	Move* getNextMove(SimpleTree* root);

	void buildTree(Move* move);
	int calculateCurrentUtility(char marker, int location);
	void toString();
	void toStringChildren();
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

	bool hasTwo(array<char,3> a);
	array<char,3> getRow(int row);
	array<char,3> getColumn(int column);
	array<char,3> getIfInLeftDiagonal(int diagonal);
	array<char,3> getIfInRightDiagonal(int diagonal);

	void flipCurrentMarker();
	bool isMine(char marker);
	bool isEmpty(int location);
	bool isEmpty(char checkMe);

	char isWin(int location); 
	bool isBlock(int location);
	bool isFork(int location); 
	bool isBlockFork(int location);
	bool isOppositeCorner(int location);
	bool isEmptyCorner(int location);
	bool isEmptySide(int location);
};

/*
	argSize is the number of children.
*/
SimpleTree::SimpleTree(int argSize) // int[] children
{
	size = argSize;
	selected[0] = 0;
	selected[1] = 1;
	selected[2] = 2;
	children.reserve(argSize);
	// @TODO - change to init to only the passed in chosen children so we can branch.

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

/*
	The inital call to fake data.
*/
void SimpleTree::initTicTacToe()
{
	initReversePyramid(9);
}

/*
	Attempting to create fake data.
*/
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

/*
	Interestingly designed factory method.
*/
void SimpleTree::buildTree(Move* arg)
{
	move = *arg;
}

/*
	@ensure: Creates a default low priority move to compare to in the 
	minimax function for the opposing player's decision.
*/
void SimpleTree::buildFakeLow()
{
	move.buildMove(loc0, -100, 'Y');
}

/*
	@ensure: Creates a default high priority move to compare to in the 
	minimax function for the current player's decision.
*/
void SimpleTree::buildFakeHigh()
{
	move.buildMove(loc0, 100, 'Y');
}

/*
	@ensure: Return the generated next best move.
	@ensure: Returns a default value if the utility function has not been run.
	@stub
*/
Move SimpleTree::getMove()
{
	return move;
}

/*
	@ensure: toStrings the root node and then all
	of the contained children which are initialized.
*/
void SimpleTree::toStringChildren()
{
	cout << "Root:\n";
	move.toString();

	for(int i = 0; i < size; i++)
		{
			cout << "Node: ";
			cout << i << '\n';
			children[i]->toString();			
		}	

	cout << "\n";
		
}


void SimpleTree::toString()
{
	return move.toString();
}

// Accessor
int SimpleTree::getUtility()
{
	return move.getUtility();
}

/*
	@ensure: Runs a simple max function on the integer value
	of two given nodes.
*/
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

/*
	@ensure: Runs a simple min function on the integer value
	of two given nodes.
*/
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
	@requre: interprets the current state of the board as a tree 
	@ensure: runs mmab.
 */
Move* SimpleTree::getNextMove(SimpleTree* root)
{

	return nullptr;
}

/*
	@require: This uses the current state of the board.
	@ensure: Calculates the current decision utility value of a given square and 
	player marker.
*/
int SimpleTree::calculateCurrentUtility(char cm, int location)
{
	int value = 0;
	currentMarker = cm;

	if(isWin(location))  
	{
		value = 8;
	}
	else if(isBlock(location))
	{
		value = 7;
	}
	else if(isFork(location))
	{
		value = 6;
	}
	else if(isBlockFork(location))
	{
		value = 5;
	}
	else if(location == 4) // center
	{
		value = 4;
	}
	else if(isOppositeCorner(location))
	{
		value = 3;
	}
	else if(isEmptyCorner(location))
	{
		value = 2;
	}
	else if(isEmptySide(location))
	{
		value = 1;
	}
	else
	{
		// uh, is the game done? why are you here
	}
	return value;
}

/*
 	@ensure: Removes the child nodes that were not selected
 	from the currently visited node.
 	@stub
 */
void SimpleTree::branchToDecision()
{

}

/*
	@ensure: Returns true if two of the three given locations
	are taken by the currently selected marker.
*/
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

/*
	@ensure: returns the entire row of the selected location.
*/
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

/*
	@ensure: returns the entire column of the selected location.
*/
array<char,3> SimpleTree::getColumn(int location)
{

	int column = location; 	

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

/*
	@ensure: Returns true if the given location is inside the left diagonal.
*/
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

/*
	@ensure: Returns true if the given location is inside the right diagonal.
*/
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

/*
	@ensure: returns true if the given location is a winning move.
*/
char SimpleTree::isWin(int location) 
{
	bool isWin = false;

	isWin = hasTwo(getRow(location));

	if(!isWin)
	{
		isWin = hasTwo(getColumn(location));
	}

	if(!isWin)
	{
		isWin = hasTwo(getIfInLeftDiagonal(location));
	}

	if(!isWin)
	{
		isWin = hasTwo(getIfInRightDiagonal(location));
	}

	// set selected to default state.
	return isWin;	
}

/*
	@require: Doesn't care if the current marker is uninitialized.
	@ensure: Flips the currently selected marker.
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

/*
	@ensure: Returns true if the passed location is a location
	that will block something.
*/
bool SimpleTree::isBlock(int location) 
{
	bool isBlock = false;

	flipCurrentMarker();

	isBlock = isWin(location);

	flipCurrentMarker();

	return isBlock;	
}

/*
	@ensure: Returns true if the location is the location of a possible fork.
*/
bool SimpleTree::isFork(int location)
 {
	bool forkable = false;

	if(location == 2 || ( location == 6 && isMine(0) && isMine(8) && (isEmptyCorner(2) || isEmptyCorner(6)) ) )
	{
		forkable = true;
	}
	else if (isMine(2) && isMine(6) && (isEmptyCorner(0) || isEmptyCorner(8)) )
	{
		forkable = true;
	}

	// add forks from corners to center

	return forkable;	
}

/*
	@ensure: Returns true if the location is a square that can block a fork.
*/
bool SimpleTree::isBlockFork(int location)
{
	bool isBlockFork = false;

	flipCurrentMarker();
	isBlockFork = isFork(location);
	flipCurrentMarker();

	return isBlockFork;		
}

/*
	@ensure: Returns true if ??
*/
bool SimpleTree::isOppositeCorner(int location)
{
	bool isCorner = false;

	if(location == 0 && isEmpty(gameState[8]))
	{
		isCorner = true;
	}
	else if(location == 2 && isEmpty(gameState[6]))
	{
		isCorner = true;
	}
	else if(location == 6 && isEmpty(gameState[2]))
	{
		isCorner = true;
	}
	else if(location == 8 && isEmpty(gameState[0]))
	{
		isCorner = true;
	}

	return isCorner;		
}

/*
	@ensure: Returns true if the location has the same marker as the passed marker.
*/
bool SimpleTree::isMine(char location)
{
	return currentMarker == gameState[location];
}

/*
	@ensure: Returns true if the passed location is an empty side.
*/
bool SimpleTree::isEmptySide(int location) 
{
	return isEmpty(gameState[location]) && (location == 1 || location == 3 || location == 5 || location == 7);		
}

/*
	@ensure: Returns true if the passed location is an empty corner.
*/
bool SimpleTree::isEmptyCorner(int location)
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

/*
	@ensure: Returns true if the passed marker is empty
*/
bool SimpleTree::isEmpty(char checkMe)
{
	return checkMe == ' ';
}

/*
	@ensure: Returns true if the passed location is empty
*/
bool SimpleTree::isEmpty(int location)
{
	return isEmpty(gameState[location]);
}
