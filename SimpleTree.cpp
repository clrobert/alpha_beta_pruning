class SimpleTree
{
public:
	int item;
	SimpleTree *leftChild;
	SimpleTree *rightChild;

	void breadthFirstSearch(SimpleTree &subTree);
	void visit(SimpleTree node);
	void buildRandomTree(char board[][3]);
	int generateRandom();

};

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
	std::cout << node.item;
}

void SimpleTree::buildRandomTree(char board[][3])
{
	SimpleTree root = SimpleTree();
	root.item = generateRandom();
	root.leftChild->item = generateRandom();
	root.rightChild->item = generateRandom();

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