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

// Runs the game.
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

void testHarnessA()
{
	SimpleTree* tree  = new SimpleTree(1);
	tree->init(1);
	tree->toStringChildren();

	//SimpleTree* node;
	//node = tree;

	Player p('x');
	SimpleTree* choice = p.minimaxNode(tree, 1, true);
	//choice->print();

	//cout << p.alphabeta(origin, depth, -∞, +∞, TRUE)
}

/*
  pseudocode for game:

  1. initialize board to emptyness.
  2. initialize players to x and o, with x going first.
  3. have player 1 build a decision tree based on the current 
 	state of the board. the decision tree should correctly 
 	evaluate the utility of each of the possible remaining moves
 	taking into consideration the opponent's possible future moves.

	Order of work:
 	a. build decision tree
 	b. evaluate utility of any given node
 	c. choose best node based on given nodes and role
 	d. create deep tree and alllow decisions that progress through the tree
 	e. as decisions progress, eliminate previous levels
 	f. integrate AB pruning -- removal of subtrees that don't need calculation

  4. have player 1 create an object representing the next best move,
  	pass it to the board and have the board mark the next move.
  5. have player 2 do (3.)
  6. have player 2 do (4.)
  7. repeat 3-6 until a player has won or all spaces have been exhausted.


*/
void testHarnessB()
{
	TicTacToe ttt;
	ttt.init();

	Player player1('x');
	Player player2('o');

	while(ttt.isDone() == false)
	{
		//Move* p1move = player1.getNextMove(ttt.getBoard());
		//ttt.markBoard(p1move);

		// Player 1 


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
	testHarness();
//	playGame();
	return 0;
}
