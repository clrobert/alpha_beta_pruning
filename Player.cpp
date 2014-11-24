
class Player
{
public:
	char marker;
	Player(char c);

	int* getNextMove(char** board);
	void minValue();
	void maxValue(SimpleTree* tree);
	void miniMaxDecision();
	//void calculateActualUtility(SimpleTree tree);

};

Player::Player(char c)
{
	marker = c;

}

int* Player::getNextMove(char** board)
{
	int* coords = new int[2];



	return coords;
}

void Player::maxValue(SimpleTree* tree)
{

}

void Player::minValue()
{

}

void Player::miniMaxDecision()
{

}

//void Player::calculateActualUtility(SimpleTree tree)
//{
//
//
//}

