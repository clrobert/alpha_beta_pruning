using namespace std;

class SimpleTree
{
public:
	int value;
	SimpleTree *leftChild;
	SimpleTree *rightChild;

	SimpleTree(int height);

	void printTree();
	void preOrderPrint(SimpleTree *subTree);
	void visit(SimpleTree *node);

	int generateRandom();

	int getValue();

	void buildTree(SimpleTree *tree, int height);

};

SimpleTree::SimpleTree(int height)
{
	value = generateRandom();
	buildTree(leftChild, height);
	buildTree(rightChild, height);
}

int SimpleTree::getValue()
{
	return value;
}

void SimpleTree::printTree()
{
	std::cout << "Root:";
	std::cout << value;
	std::cout << "\n";

	preOrderPrint(leftChild);
	preOrderPrint(rightChild);
}

void SimpleTree::preOrderPrint(SimpleTree *subTree)
{
	if(subTree != nullptr)
	{
		visit(subTree);

		if(subTree->leftChild != nullptr)
		{
			preOrderPrint(subTree->leftChild);
		}
		if(subTree->rightChild != nullptr)
		{
			preOrderPrint(subTree->rightChild);	
		}

	}
	
}

void SimpleTree::visit(SimpleTree *node)
{
	std::cout << "Node:";
	std::cout << node->value;
	std::cout << "\n";
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

void SimpleTree::buildTree(SimpleTree *tree, int height)
{
	if(height > 0)
	{
		height = height - 1;
		tree = new SimpleTree(height);
	}
	else
	{
		tree = nullptr;
	}
}
