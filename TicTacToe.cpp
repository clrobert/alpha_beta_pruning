class TicTacToe
{
public:
	char board[3][3];
	int turns;
	bool done;

	TicTacToe()
	{
		done = false;

	}
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
		return this->done || turns > 8;
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