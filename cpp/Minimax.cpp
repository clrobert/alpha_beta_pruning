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

/*
  pseudocode for game:

  1. initialize board to emptyness. - done
  2. initialize players to x and o, with x going first. - done
  3. have player 1 build a decision tree based on the current 
 	state of the board. the decision tree should correctly 
 	evaluate the utility of each of the possible remaining moves
 	taking into consideration the opponent's possible future moves. - in progress

	Order of work:
 	a. build decision tree - needs clearer output
 	b. evaluate utility of any given node - needs testing
 	c. choose best node based on given nodes and role - needs testing
 	d. create deep tree and alllow decisions that progress through the tree - not started
 	e. as decisions progress, eliminate previous levels - not started
 	f. integrate AB pruning -- removal of subtrees that don't need calculation - not started

  4. have player 1 create an object representing the next best move,
  	pass it to the board and have the board mark the next move. - done
  5. have player 2 do (3.) - done
  6. have player 2 do (4.) - done
  7. repeat 3-6 until a player has won or all spaces have been exhausted. - done

 Note: we shouldn't have to rebuild the tree every time. The algorithm's knowledge or ignorance
 of the game state at this point is immaterial; we aren't playing a fog-of-war game, let it be perfect.
*/
void testHarness()
{
	TicTacToe ttt;
	ttt.init();

	Player player1('x');
	Player player2('o');

	int n = 9;

	cout << "Initial game board:\n";
	ttt.printBoard();

	SimpleTree* tree  = new SimpleTree(n);
	tree->init(1);
	tree->toStringChildren();

	//SimpleTree* node;
	//node = tree;

	Player p1('x');
	SimpleTree* choice = p1.minimaxNode(tree, 1, true); // for now just a depth of 1, sure it's pretty lobotomized
	cout << "Choice: \n";
	choice->toString();
	
	ttt.markBoard(choice->getMove());
	ttt.printBoard();



	//cout << p.alphabeta(origin, depth, -∞, +∞, TRUE)

	/*
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
	*/

	cout << "Game finished.";
}

int main()
{
	testHarness();
//	playGame();
	return 0;
}
