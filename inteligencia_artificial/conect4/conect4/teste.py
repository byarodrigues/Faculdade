board = [[' ' for _ in range(7)] for _ in range(6)]
player = 'X'
game_over = False

class conectfour:

    def print_board():
        for row in board:
            print('|'.join(row))

    def drop_piece(column):
        global game_over
        for i in range(5, -1, -1):
            if board[i][column] == ' ':
                board[i][column] = player
                break
        if self.check_win(i, column):
            game_over = True
        elif self.check_full():
            game_over = True

    def check_win(row, column):
    # check for horizontal win
        count = 0
        for i in range(column, 7):
            if board[row][i] == player:
                count += 1
            else:
                break
        for i in range(column - 1, -1, -1):
            if board[row][i] == player:
                count += 1
            else:
                break
            if count >= 4:
                return True

    # check for vertical win
        count = 0
        for i in range(row, 6):
            if board[i][column] == player:
                count += 1
            else:
                break
        if count >= 4:
            return True

    # check for diagonal win
        count = 0
        for i, j in zip(range(row, 6), range(column, 7)):
            if board[i][j] == player:
                count += 1
            else:
                break
        for i, j in zip(range(row - 1, -1, -1), range(column - 1, -1, -1)):
            if board[i][j] == player:
                count += 1
            else:
                break
        if count >= 4:
            return True

        count = 0
        for i, j in zip(range(row, 6), range(column, -1, -1)):
            if board[i][j] == player:
                count += 1
            else:
                break
        for i, j in zip(range(row - 1, -1, -1), range(column + 1, 7)):
            if board[i][j] == player:
                count += 1
            else:
                break
        if count >= 4:
            return True

        return False

    def check_full():
        for row in board:
            if ' ' in row:
                return False
        return True

class jogador_automatico:
    def __init__(self):
        pass

    def choose_move(self, board):
        # choose a random column
        import random
        return random.randint(0, 6)

class heuristica:
    def __init__(self, player):
        self.player = player

    def choose_move(self, board):
        best_score = -float('inf')
        best_column = None
        for column in range(7):
            score = self.score_move(board, column)
        if score > best_score:
            best_score = score
            best_column = column
        return best_column

    def score_move(self, board, column):
        score = 0
        for row in range(6):
            if board[row][column] == ' ':
            board[row][column] = self.player
            score += self.score_position(board, row, column)
            board[row][column] = ' '
        return score

    def score_position(self, board, row, column):
        score = 0
        # horizontal
        count = 0
        for i in range(column, 7):
            if board[row][i] == self.player:
            count += 1
        else:
            break
        for i in range(column - 1, -1, -1):
            if board[row][i] == self.player:
            count += 1
        else:
            break
        score += count - 1

    # vertical
        count = 0
        for i in range(row, 6):
            if board[i][column] == self.player:
            count += 1
        else:
            break
        score += count - 1

    # diagonal
        count = 0
        for i, j in zip(range(row, 6), range(column, 7)):
            if board[i][j] == self.player:
            count += 1
        else:
            break
        for i, j in zip(range(row - 1, -1, -1), range(column - 1, -1, -1)):
            if board[i][j] == self.player:
            count += 1
        else:
            break
        score += count - 1

        count = 0
        for i, j in zip(range(row, 6), range(column, -1, -1)):
            if board[i][j] == self.player:
                count += 1
            else:
                break
        for i, j in zip(range(row - 1, -1, -1), range(column + 1, 7)):
            if board[i][j] == self.player:
                count += 1
            else:
       


def main():
    while not game_over:
        print_board()
        column = int(input(f"{player}, choose a column (0-6): "))
        drop_piece(column)
        if player == 'X':
            player = 'O'
        else:
            player = 'X'

    print_board()
    if check_full():
        print("It's a tie!")
    else:
        print(f"{player} wins!")

    ai = AIPlayer()
    while not game_over:
        if player == 'X':
        # player's turn
           column = int(input(f"{player}, choose a column (0-6): "))
        else:
        # AI's turn
           column = ai.choose_move(board)
        drop_piece(column)
        if player == 'X':
            player = 'O'
        else:
            player = 'X'
