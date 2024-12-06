######
##    Trabalho 1: Inteligência Artificial - Beatriz Rodrigues
######

import random

def solve(sudoku):
  while True:
    empty_squares = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]
    if not empty_squares:
      return sudoku

    i, j = random.choice(empty_squares)
    for num in random.sample(range(1, 10), 9):
      if is_valid(sudoku, i, j, num):
        sudoku[i][j] = num
        break

def is_valid(sudoku, i, j, num):
  # Verifica a linha
  if num in sudoku[i]:
    return False

  # Verifica a coluna
  if num in [sudoku[k][j] for k in range(9)]:
    return False

  # Verifica a submatriz 3x3
  start_i = i // 3 * 3
  start_j = j // 3 * 3
  for k in range(3):
    for l in range(3):
      if sudoku[start_i + k][start_j + l] == num:
        return False

  return True

def main():
  # Matriz do sudoku a ser resolvida
  sudoku = [[4, 5, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 2, 0, 7, 0, 6, 3, 0],
            [0, 0, 0, 0, 0, 0, 0, 2, 8],
            [0, 0, 0, 9, 5, 0, 0, 0, 0],
            [0, 8, 6, 0, 0, 0, 2, 0, 0],
            [0, 2, 0, 6, 0, 0, 7, 5, 0],
            [0, 0, 0, 0, 0, 0, 4, 7, 6],
            [0, 7, 0, 0, 4, 5, 0, 0, 0],
            [0, 0, 8, 0, 0, 9, 0, 0, 0]]

  # Chama a função solve para resolver o sudoku
  solved = solve(sudoku)

  # Imprime a matriz resolvida
  for row in solved:
    print(row)

if __name__ == '__main__':
  main()
