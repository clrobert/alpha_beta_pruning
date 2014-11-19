#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include "SimpleTree.cpp"
#include "Player.cpp"
#include "TicTacToe.cpp"

using namespace std;


class ReferenceType
{
	string one;
	string two;
public:

	ReferenceType(string one, string two) : one(one), two(two) {}
};

void testRun(char s[]);

void calculateActualUtility(SimpleTree tree)
{


}


int main()
{	
	TicTacToe t;
	t.init();

	SimpleTree s;
	s.buildTicTacTree(t.getBoard());

	//playGame();

	return 0;
}

void playGame()
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
}