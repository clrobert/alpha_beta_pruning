#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>


class SimpleBinaryTree
{
	public:
	class Node
	{
	public:
		int item;
		Node *leftChild;
		Node *rightChild;
	};
	Node root;

	void breadthFirstSearch(Node subTree);
	void visit(Node node);
	void buildSimpleTree(char board[][3]);
	
};


void SimpleBinaryTree::breadthFirstSearch(SimpleBinaryTree::Node subTree)
{
	visit(subTree);
	breadthFirstSearch(*subTree.leftChild);
	breadthFirstSearch(*subTree.rightChild);	
}

void SimpleBinaryTree::visit(Node node)
{
	std::cout << node.item;
}

void SimpleBinaryTree::buildSimpleTree(char board[][3])
{
	//Node root();
	//root.item = board[0][0];
	//root.leftChild = board[0][1];
	//root.rightChild = board[0][2];


}

//void calculateUtility(SimpleBinaryTree::Node node)
//{
//
//
//}

class Player
{
public:
	void takeMove(char board[][3]);
	void minValue();
	void maxValue();
	void miniMaxDecision();
	char marker;
	char *crayon;

	Player(char c);
};

Player::Player(char c)
{
	marker = c;
}

void Player::takeMove(char board[][3])
{

}

void Player::maxValue()
{

}

void Player::minValue()
{

}

void Player::miniMaxDecision()
{

}

class TicTacToe
{
public:
	char board[3][3];
	int turns;

	void init()
	{
		turns = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				board[i][j] = '_';
			}
		}

	}

	bool isDone()
	{
		bool isDone = false;



		return isDone;
	}

	void printBoard(char board[][3])
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				std::cout << board[i][j];
				if(j != 2)
				{
					std::cout << '|';
				}
			}
			std::cout << '\n';
			
		}

		std::cout << '\n';
		std::cout << '\n';
	}

};

int runIt()
{

	TicTacToe ttt;
	ttt.init();

	Player player1('x');
	Player player2('o');

	while(ttt.isDone() == false && ttt.turns < 9)
	{
		ttt.turns = ttt.turns + 1;
		player1.takeMove(ttt.board);
		ttt.printBoard(ttt.board);
		if(ttt.isDone() != false && ttt.turns < 9)
		{
			ttt.turns = ttt.turns + 1;
			player2.takeMove(ttt.board);
			ttt.printBoard(ttt.board);
		}
	}

	std::cout << "Game finished.";

	return 0;
}

int main()
{
	Player p('x');

	//std::cout << p->marker;

	std::cout << p.marker;

	std::cout << p->crayon;


	return 0;
}

