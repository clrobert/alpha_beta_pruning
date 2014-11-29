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
	tree->printChildren();

	//SimpleTree* node;
	//node = tree;

	Player p('x');
	cout << p.minimax(tree, 1, true);
	//cout << p.alphabeta(origin, depth, -∞, +∞, TRUE)
}


void playGame()
{

//	TicTacToe ttt;
//	ttt.init();
//
//	Player player1('x');
//	Player player2('o');
//
//	while(ttt.isDone() == false && ttt.turns < 9)
//	{
//		ttt.turns = ttt.turns + 1;
//		player1.takeMove(ttt.board);
//		ttt.printBoard(ttt.board);
//		if(ttt.isDone() != false && ttt.turns < 9)
//		{
//			ttt.turns = ttt.turns + 1;
//			player2.takeMove(ttt.board);
//			ttt.printBoard(ttt.board);
//		}
//	}
//
	std::cout << "Game finished.";
}


struct MyStruct
{
	char a,b;
};
/*
void foo(int &arg1, int arg2, int* arg3)
{
	cout << arg3;
	cout << '\n';
	arg1 += 1234;
	arg2 += 1234;
	arg3 += 1234;

	cout<< arg1;
	cout << '\n';
	cout << arg2;
		cout << '\n';
	cout << arg3;
		cout << '\n';
	cout << "done in fxn";
}

SimpleTree* Foo()
{
	SimpleTree t(1);
	return &t;
}
*/


int main()
{	
	//MyStruct f;
	//f.a = 'a';
	//f.b = 'z';
//
	//char *p = &f.a;
	//p++;
	//cout << *p;

	//unsigned char* data;
	//data = (unsigned char*)malloc(200);
	//cout << sizeof(data);
	//This is because the data pointer is expecting to hold one character.

	testTwo();

	cout << '\n';

	return 0;
}
