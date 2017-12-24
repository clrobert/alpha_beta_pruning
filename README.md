# minimax

Let an _option_ be a choice made by a player with multiple possible outcomes.

Let an _outcome_ be measured by two distinct values, _reward_ and _regret_.

Let _reward_ be the measure of benefit to the player.

Let _regret_ be the measure of cost to the player.


- Maximax: Choose the option with the maximum possible reward.

- Maximin: Choose the option where the worst possible _reward_ is the highest.

- Minimax: Choose the option where the worst possible _regret_ is the lowest.


Let the first player in this game be X and the second be O.


Simple case:
1. Given any _k-1_ game state, where _k_ is the last move in the game,
give each location (choice) on the board a reward value for the player: either 1, 0, or -1.

2. Choose the best possible reward value.

Next steps:
- Given any _k-2_ game state, choose the maximum reward.









- [ ] Need to give leaf nodes a value.
- [ ] Need to apply minimax to give the rest of the nodes a value
- [ ] Need to implement turn taking for a human player and cpu or cpu x 2 so a game can be produced.
