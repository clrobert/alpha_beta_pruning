#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include "SimpleTree.cpp"
#include "Player.cpp"
#include "TicTacToe.cpp"

void calculateActualUtility(SimpleTree tree)
{
	
	
}

int main()
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