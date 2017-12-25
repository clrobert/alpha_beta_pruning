def printable_value(value):
    if value == -1:
        return "O"
    if value == 0:
        return " "
    if value == 1:
        return "X"


def get_display_board(board):
    return """
        {6}|{7}|{8}
        -----
        {3}|{4}|{5}
        -----
        {0}|{1}|{2}
    """.format(*[printable_value(x) for x in board])

def print_board(board):
    print(get_display_board(board))

# alias.
def pb(board):
    print_board(board)

def has_player_won(player_value, board):
    winning_value = player_value * 3

    lines = [[0,3,6], [1,4,7], [2,5,8], [6,4,2], [0,4,8], [6,7,8], [3,4,5], [0,1,2]]

    for line in lines:
        if line_sum(line, board) == winning_value:
            return True

    return False


def line_sum(line, board):
    return sum([board[x] for x in line])


def get_other_player(player_value):
    if player_value == 1:
        return -1
    else:
        return 1


def evaluate_move(player_value, node):
    value = None
    import pdb; pdb.set_trace()

    if has_player_won(player_value, node.current_board):
        value = WIN_VALUE
    elif has_player_won(get_other_player(player_value), node.current_board):
        value = LOSE_VALUE
    elif 0 not in node.current_board: # tie
        value = 0
    else:
        value = minimax(node, True)
    return value


def evaluate_board(player_value, available_move_nodes):
    value_matrix = []
    for move in available_move_nodes:
        move.value = evaluate_move(player_value, move)
        value_matrix.append(move.value)
    return value_matrix


def get_base_board():
    return [0] * 9


class Node:
    def __init__(self, board, turn):
        self.current_board = list(board)
        self.turn = turn
        self.value = None

        # The value matrix is for evaluating
        # next moves.
        self.value_matrix = None
        self.next_nodes = None

    def printself(self):
        print("Turn %s:" % self.turn)
        print("Value: %s" % self.value)
        print(self.current_board)
        print(self.next_nodes)


def enumerate_all_choices(node, turn):
    all_choices = list()

    # Yes, iterate over the entire board. Optimize later.
    for i in range(0, 9):
        new_node = Node(node.current_board, turn)
        if new_node.current_board[i] == 0:
            new_node.current_board[i] = PLAYERS[turn%2]
            all_choices.append(new_node)

    return all_choices


def enumerate_all_games(current_node, turn):
    current_node.next_nodes = enumerate_all_choices(current_node, turn)
    if current_node.next_nodes:
        for next_node in current_node.next_nodes:
            enumerate_all_games(next_node, turn + 1)


def minimax(node, maximizing_player):
    if not node.next_nodes:
        return node.value

    if maximizing_player:
        best_value = -1
        for child_node in node.next_nodes:
            value = minimax(child_node, False)
            best_value = max(best_value, value)
        return best_value
    else:
        best_value = 1
        for child_node in node.next_nodes:
            value = minimax(child_node, True)
            best_value = min(best_value, value)
        return best_value


def evaluate_all_games(all_games):
    for game in all_games:
        pass


WIN_VALUE = 1
LOSE_VALUE = -1
PLAYERS = [1, -1]
turn = 0

root_node = Node(get_base_board(), turn - 1)
enumerate_all_games(root_node, turn)

# test beta: FAILED
print("\n-----test beta-----")
beta = root_node.next_nodes[0].next_nodes[0].next_nodes[0].next_nodes[0].next_nodes[0].next_nodes[0].next_nodes[0].next_nodes[0]
current_board = beta.current_board
print(get_display_board(current_board))
import pdb; pdb.set_trace()
print(evaluate_board(-1, beta.next_nodes))

"""
# test alpha: PASSED
print("\n-----test alpha-----")
alpha = beta.next_nodes[0]
current_board = alpha.current_board
print(get_display_board(current_board))
print(evaluate_board(1, alpha.next_nodes))
"""
