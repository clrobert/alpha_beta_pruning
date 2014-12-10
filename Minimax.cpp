#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include "SimpleTree.cpp"
#include "Player.cpp"
#include "TicTacToe.cpp"
#include <stack>
#include <sstream>

using namespace std;


class ReferenceType
{
	string one;
	string two;
public:
	ReferenceType(string one, string two) : one(one), two(two) {}
};
 

void testRun(char s[]);


void testOne()
{
	TicTacToe t;
	t.init();
	t.printBoard();

	char** board2;

	board2 = t.getBoard();	
}

void testTwo()
{
	SimpleTree* tree  = new SimpleTree(9);
	tree->init(1);
	//tree->printChildren();

	//SimpleTree* node;
	//node = tree;

	Player p('x');
	SimpleTree* choice = p.minimaxNode(tree, 1, true);
	//choice->print();

	//cout << p.alphabeta(origin, depth, -∞, +∞, TRUE)
}


void playGame()
{

	TicTacToe ttt;
	ttt.init();

	Player player1('x');
	Player player2('o');

	while(ttt.isDone() == false)
	{
		//Move* p1move = player1.getNextMove(ttt.getBoard());
		//ttt.markBoard(p1move);
		ttt.printBoard();

		if(ttt.isDone() != false)
		{
			//Move* p2move = player2.getNextMove(ttt.getBoard());
			//ttt.markBoard(p1move);			
			ttt.printBoard();
		}
	}

	std::cout << "Game finished.";
}


int main()
{


//	playGame();
	return 0;
}
