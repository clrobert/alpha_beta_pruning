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

	void print();
	void printChildren();
	static SimpleTree* maxNode(SimpleTree* a, SimpleTree* b);
	static SimpleTree* minNode(SimpleTree* a, SimpleTree* b);
	void init(int height);
	void buildFakeLow();
	void buildFakeHigh();
	int getUtility();
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

	if(a->getUtility() < b->getUtility()	)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	return min;
}



