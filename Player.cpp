using namespace std;

/*
  A tictactoe player.
*/ 
class Player
{
public:
	char marker;
	Player(char c);
	SimpleTree* nextMove;

	//Move* getNextMove(char** board);
	int minimax(SimpleTree* node, int depth, bool maximizingPlayer);
	SimpleTree* minimaxNode(SimpleTree* node, int depth, bool maximizingPlayer);
};

/*
  Initializes a player with a marker.
*/
Player::Player(char c)
{
	marker = c;
}

/*
  
*/
int Player::minimax(SimpleTree* node, int depth, bool maximizingPlayer)
{

    if (depth == 0 || node->size == 0)
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

SimpleTree* Player::minimaxNode(SimpleTree* node, int depth, bool maximizingPlayer)
{

    if (depth == 0 || node->size == 0)
    {
        return node;
    }
    if (maximizingPlayer)
    {
        SimpleTree* bestNode = new SimpleTree(0);
        bestNode->buildFakeLow();
        for(int i = 0; i < node->size; i++)
        {
            SimpleTree* val = minimaxNode(node->children[i], depth - 1, false);
            bestNode = SimpleTree::maxNode(bestNode, val);
        }
        return bestNode;
    }
    else
    {
        SimpleTree* bestNode = new SimpleTree(0);
        bestNode->buildFakeHigh();
        for(int i = 0; i < node->size; i++)
        {
            SimpleTree* val = minimaxNode(node->children[i], depth - 1, true);
            bestNode = SimpleTree::minNode(bestNode, val);
        }
        return bestNode;
	}
	
}


/*
 function alphabeta(node, depth, α, β, maximizingPlayer)
      if depth = 0 or node is a terminal node
          return the heuristic value of node
      if maximizingPlayer
          for each child of node
              α := max(α, alphabeta(child, depth - 1, α, β, FALSE))
              if β ≤ α
                  break (* β cut-off *)
          return α
      else
          for each child of node
              β := min(β, alphabeta(child, depth - 1, α, β, TRUE))
              if β ≤ α
                  break (* α cut-off *)
          return β
(* Initial call *)
*/
