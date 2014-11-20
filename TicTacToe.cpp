class TicTacToe
{
public:
	char** board;
	int turns;
	bool done;

	TicTacToe();
	void init();
	bool isDone();
	void markBoard(char marker, int* location);
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

void TicTacToe::markBoard(char marker, int* location)
{
	board[location[0]][location[1]] = marker;
}

bool TicTacToe::isDone()
{
	return this->done || turns > 8;
}

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
