#include <utility>
#include "Move.cpp"
#include <vector>

using namespace std;


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
	Move *move;

	vector<SimpleTree*> children;

	int size;

	int height;

	SimpleTree(int children);
	
	void preOrderPrint();

	int generateRandom();

	Move* getmove();

	void buildTree(Move* move);

	void buildTicTacTree();

	void print();
	void printChildren();

	void init();
};

SimpleTree::SimpleTree(int argSize)
{
	move = NULL;
	size = argSize;

	children.reserve(argSize);

	for(int i = 0; i < argSize; i++)
	{
		children[i] = NULL;
	}

}

void SimpleTree::init()
{
	for(int i = 0; i < size; i++)
	{
		children[i] = new SimpleTree(0);
		children[i]->buildTree(new Move(locations[i], 0, 'x'));
	}
}

void SimpleTree::buildTree(Move* arg)
{
	move = arg;
}

Move* SimpleTree::getmove()
{
	return move;
}

void SimpleTree::printChildren()
{
	for(int i = 0; i < size; i++)
		{
			children[i]->print();
		}	
}

void SimpleTree::print()
{
	move->toString();
}

void SimpleTree::buildTicTacTree()
{
	//child1 = new SimpleTree();
	//child1->move = new Move(loc1, 2, 'x');
//
	//child2 = new SimpleTree();
	//child2->move = new Move(loc2, 1, 'x');
//
	//child3 = new SimpleTree();
	//child3->move = new Move(loc5, 0, 'x');

}

