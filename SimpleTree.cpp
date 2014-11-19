using namespace std;

class SimpleTree
{
public:
	int value;
	SimpleTree *leftChild;
	SimpleTree *rightChild;

	SimpleTree();
	void breadthFirstSearch(SimpleTree &subTree);
	void visit(SimpleTree node);
	void buildTicTacTree(char board[][3]);
	int generateRandom();
	void setValue(int rhs);
	int getValue();

};

SimpleTree::SimpleTree()
{
	value = generateRandom();
	leftChild = NULL;
	rightChild = NULL;
}

void SimpleTree::setValue(int rhs)
{
	value = rhs;
}

int SimpleTree::getValue()
{
	return value;
}

void SimpleTree::breadthFirstSearch(SimpleTree &subTree)
{
	visit(subTree);
	if(subTree.leftChild != NULL)
	{
		breadthFirstSearch(*subTree.leftChild);
	}
	if(subTree.rightChild != NULL)
	{
		breadthFirstSearch(*subTree.rightChild);	
	}
	
}

void SimpleTree::visit(SimpleTree node)
{
	std::cout << node.value;
}

void SimpleTree::buildTicTacTree(char board[][3])
{
	SimpleTree root = SimpleTree();
	root.value = generateRandom();
	root.leftChild->value = generateRandom();
	root.rightChild->value = generateRandom();
}

int SimpleTree::generateRandom()
{
	typedef std::chrono::high_resolution_clock myclock;
  	myclock::time_point beginning = myclock::now();

  	myclock::duration d = myclock::now() - beginning;
  	unsigned seed2 = d.count();

	std::default_random_engine generator;
	generator.seed (seed2);
	std::uniform_int_distribution<int> distribution(0,9);
	int dice_roll = distribution(generator); 
	
	return dice_roll;
}


/*

void SimpleTree::setLeftChild(SimpleTree& subTree)
{
	leftChild = &subTree;
	cout << leftChild;
}
*/