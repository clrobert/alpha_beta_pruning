POSITIVE_INFINITY = 100
NEGATIVE_INFINITY = -100


def printable_value(value):
    if value == -1:
        return "O"
    if value == 0:
        return " "
    if value == 1:
        return "X"


def get_game_board():
    return [0] * 9


def get_display_board(board):
    return """
        {6}|{7}|{8}
        -----
        {3}|{4}|{5}
        -----
        {0}|{1}|{2}
    """.format(*[printable_value(x) for x in board])


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


def evaluate_move(player_value, board, location):
    new_board = list(board)
    new_board[location] = player_value

    if has_player_won(player_value, board):
        return POSITIVE_INFINITY
    elif has_player_won(get_other_player(player_value), board):
        return NEGATIVE_INFINITY
    else:
        return 0


def evaluate_board(player_value, board):
    all_move_values = []

    for i in range(0, 9):
        all_move_values.append(evaluate_move(player_value, board, i))

    return all_move_values


board = get_game_board()
display_board = get_display_board(board)

print(display_board)
print(evaluate_board(1, board))
