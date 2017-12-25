# minimax
## Definition
• [as modifier] denoting a method or strategy in game theory
that minimizes the greatest risk to a participant in a game or other situation of conflict.

• [as modifier] denoting the theory that in a game with two players,
 a player's smallest possible maximum loss is equal to the same player's greatest possible minimum gain.

## My wording
Let an _option_ be a choice made by a player with multiple possible outcomes.

Let an _outcome_ be measured by two distinct values, _reward_ and _regret_.

Let _reward_ be the measure of benefit to the player.

Let _regret_ be the measure of cost to the player.

- Maximax: Choose the option with the maximum possible reward.

- Maximin: Choose the option where the worst possible _reward_ is the highest.

- Minimax: Choose the option where the worst possible _regret_ is the lowest.

## Info
### Definitions
- -inf is a move that leads to immediate defeat.
- +inf is a move that leads to immediate win.
- 0 is a move that does not move the game towards either conclusion or undetermined.
- 1 is a move that leads the player towards victory.
- -1 is a move that leads the player towards defeat.
- None is a board space that has already been utilized.

These are the numbered locations on the board:
```
{6}|{7}|{8}
-----
{3}|{4}|{5}
-----
{0}|{1}|{2}
```

### Simple case
1. Given any _k-1_ game state, where _k_ is the last move in the game,
give each location (choice) on the board a reward value for the player: either -inf, zero, +inf, or None.

Example:
For X,

```
x| |
-----
 |x|o
-----
o|x|o
```

the values would be defined in a *value matrix*:
```
{
    0: None,
    1: None,
    2: None,
    3: -inf,
    4: None,
    5: None,
    6: None,
    7: +inf,
    8: 0
}
```
The minimax decision function should return location 7.

## Requirements, first goal

- Method one: one tree.
- ~Method two: two trees. one of game states, one of game values~

- [x] Function to enumerate all possible game states.
in: empty board
out: all possible game states

- [x] Function to evaluate a single move.
- [x] Function to evaluate a single game state.
in: game state
out: dictionary of possible moves with their values, or *value matrix*

- [ ] Function to evaluate all possible game states.
in: all possible game states
method: recursively evaluate all previous value matrices from the end states.
out: attach value matrixs to each game state.

- [x] Ability for the ai to take a turn
in: reference to current game state
method: choose minimax value
out: reference to new game state

- [ ] Ability for a human to take a turn.
print: game state
in: index of move
out: game state with move

- [ ] Ability to choose minimax-ed move (minimax decision function)
in: value matrix
out: index of choice

Note: we don't need a function to find the current game state because it is updated with every move.
A move is just moving the reference of the current game state to the next game state.

- [ ] Ability for a human to play a game.
in: command args for human game
in: command args for who goes first (human, ai) -- X always goes first.
method:
print initial game state.
loop while game not over:
    notification of human turn and symbol.
    wait for human input.
    process human move.
    print new game state.

    notification of AI turn and symbol.
    process ai move.
    print new game state.

## Optimizations
- [ ] Function to prune ties and end the game earlier.

## Stretch goals
- [ ] Implementing multiple strategies.
- [ ] Function to notify when a win is not possible -- only a tie or a loss.
- [ ] Better definitions of minimax and maximin for one and two player games.

## Stretch redesign
- [ ] Ability for two AI players to play games.
loop while game not over:
    notification of AI turn and symbol.
    process ai move.
    print new game state.
