#include <utility>
#include "Move.cpp"

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


class SimpleTree
{
public:
	Move *move;

	SimpleTree* child1;
	SimpleTree* child2;
	SimpleTree* child3;
	SimpleTree* child4;
	SimpleTree* child5;
	SimpleTree* child6;
	SimpleTree* child7;
	SimpleTree* child8;
	SimpleTree* child9;

	int height;

	SimpleTree();
	SimpleTree(Move move, int height);
	
	void preOrderPrint();

	int generateRandom();

	Move* getmove();

	void buildTree(int height);

	void buildTicTacTree();

	void printLevel();

	void printIfExists();
};

SimpleTree::SimpleTree()
{
}


SimpleTree::SimpleTree(Move inVal, int height)
{
	move = &inVal;
	height = height;
}

Move* SimpleTree::getmove()
{
	return move;
}

void SimpleTree::printLevel()
{
	//	std :: cout << "Node:";
	//	std :: cout << move.utility;
	//	std :: cout << "\n";
//
	child1->printIfExists();
	child2->printIfExists();
	child3->printIfExists();
	child4->printIfExists();
	child5->printIfExists();
	child6->printIfExists();
	child7->printIfExists();
	child8->printIfExists();
	child9->printIfExists();

	//	if(leftChild != nullptr)
	//	{
	//		leftChild->preOrderPrint();
	//	}
	//	if(rightChild != nullptr)
	//	{
	//		rightChild->preOrderPrint();	
	//	}
}

void SimpleTree::printIfExists()
{
	move->toString();
}

void SimpleTree::buildTicTacTree()
{
	child1 = new SimpleTree();
	child1->move = new Move(loc1, 2, 'x');

	child2 = new SimpleTree();
	child2->move = new Move(loc2, 1, 'x');

	child3 = new SimpleTree();
	child3->move = new Move(loc5, 0, 'x');


	// utility = 0; marker = ''; } ;
	//{ Move {};



}

