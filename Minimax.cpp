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
public:
	string one;
	string two;
	ReferenceType(string one, string two) : one(one), two(two) {}
};

void testRun(ReferenceType s);

void calculateActualUtility(SimpleTree tree)
{


}

int main()
{

	//playGame();

	ReferenceType r("six", "five");

	testRun(r);

	return 0;
}

void testRun(ReferenceType s)
{
	cout << s.one;
	cout << s.two;

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