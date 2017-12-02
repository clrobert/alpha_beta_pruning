class TicTacToe
{
public:
	char** board;
	int turns;
	bool done;

	TicTacToe();
	void init();
	bool isDone();
	void markBoard(Move move);
	void printBoard();
	char** getBoard();

};

TicTacToe::TicTacToe()
{
	done = false;
	turns = 0;
	board = new char*[3];
	for(int j = 0; j < 3; j++)
	{
		board[j] = new char[3];
	}
}

/*
	Initialize the board.	
*/
void TicTacToe::init()
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

/*
	Mark the board with the passed move.	
*/
void TicTacToe::markBoard(Move move)
{
	pair<int,int> loc = move.getLocation();

	board[loc.first][loc.second] = move.getMarker();

	turns++;
}

/* 
	The game is done if the done variable is true or 
	the max amount of turns have been exceeded.
*/
bool TicTacToe::isDone()
{
	return this->done || turns > 8;
}

/*
	Prints the current state of the board.
*/
void TicTacToe::printBoard()
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

/*
	Simple getter. Returns copy.
*/
char** TicTacToe::getBoard()
{
	char** returnBoard = new char*[3];

	for(int i = 0; i < 3; i++)
	{
		returnBoard[i] = new char[3];

		for(int j = 0; j < 3; j++)
		{
			returnBoard[i][j] = board[i][j];
		}
	}

	return returnBoard;
}





