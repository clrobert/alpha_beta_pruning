using namespace std;


class Player
{
public:
	char marker;
	Player(char c);

	int* getNextMove(char** board);
	//void minValue();
	//void maxValue(SimpleTree* tree);
	//void miniMaxDecision();
	//void calculateActualUtility(SimpleTree tree);
	int minimax(SimpleTree* node, int depth, bool maximizingPlayer);

};

Player::Player(char c)
{
	marker = c;

}
/*
int* Player::getNextMove(char** board)
{
	int* coords = new int[2];



	return coords;
}

*/


int Player::minimax(SimpleTree* node, int depth, bool maximizingPlayer)
{

    if (depth == 0 || node->height == 0)
    {
        return node->getMove().getUtility();
    }
    if (maximizingPlayer)
    {
        int bestValue = -100;
        for(int i = 0; i < node->size; i++)
        {
            int val = minimax(node->children[i], depth - 1, false);
            bestValue = max(bestValue, val);
        }
        return bestValue;
    }
    else
    {
        int bestValue = 100;
        for(int i = 0; i < node->size; i++)
        {
            int val = minimax(node->children[i], depth - 1, true);
            bestValue = min(bestValue, val);
        }
        return bestValue;
	}
	
}



//void Player::calculateActualUtility(SimpleTree tree)
//{
//
//
//}

