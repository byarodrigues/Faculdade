######
##    Trabalho 1: Inteligência Artificial - Beatriz Rodrigues
######

import random
def get_best_square(sudoku):
  min_options = 10
  min_i = min_j = -1
  for i in range(9):
    for j in range(9):
      if sudoku[i][j] == 0:
        options = get_options(sudoku, i, j)
        if len(options) < min_options:
          min_options = len(options)
          min_i = i
          min_j = j
  return min_i, min_j

def get_options(sudoku, i, j):
  used = set(sudoku[i] + [sudoku[k][j] for k in range(9)] + [sudoku[k][l] for k in range(3) for l in range(3)])
  return [num for num in range(1, 10) if num not in used]

def solve(sudoku):
  while True:
    empty_squares = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]
    if not empty_squares:
      return sudoku

    i, j = get_best_square(sudoku)
    for num in get_options(sudoku, i, j):
      if is_valid(sudoku, i, j, num):
        sudoku[i][j] = num
        break

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
