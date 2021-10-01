/*💚💚💚💚💚💚*/
/*
INPUT TYPE :- 
  3 0 6 5 0 8 4 0 0
  5 2 0 0 0 0 0 0 0
  0 8 7 0 0 0 0 3 1
  0 0 3 0 1 0 0 8 0
  9 0 0 8 6 3 0 0 5
  0 5 0 0 9 0 6 0 0
  1 3 0 0 0 0 2 5 0
  0 0 0 0 0 0 0 7 4
  0 0 5 2 0 6 3 0 0
*/
#include <bits/stdc++.h>
using namespace std;

#define N 9
bool isSafeRow(int grid[N][N], int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  return true;
}
bool isSafeCol(int grid[N][N], int row, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[i][col] == num) {
      return false;
    }
  }

  return true;
}

bool isSafeBox(int grid[N][N], int row, int col, int num) {

  int rowf = row - row % 3;
  int colf = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i + rowf][j + colf] == num) {
        return false;
      }
    }
  }

  return true;
}
bool isSafe(int grid[N][N], int row, int col, int num) {
  if (isSafeBox(grid, row, col, num) && isSafeCol(grid, row, col, num) &&
      isSafeRow(grid, row, col, num)) {
    return true;
  }

  return false;
}
bool findEmptylocation(int grid[N][N], int &row, int &col) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        row = i;
        col = j;
        return true;
      }
    }
  }

  return false;
}
bool solveSudoku(int grid[N][N]) {
  int row, col;
  if (!findEmptylocation(grid, row, col)) {
    return true;
  }

  for (int i = 1; i <= 9; i++) {
    if (isSafe(grid, row, col, i)) {
      grid[row][col] = i;
      if (solveSudoku(grid)) {
        return true;
      }
      grid[row][col] = 0;
    }
  }

  return false;
}
int main() {

  int grid[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  solveSudoku(grid);
  cout << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}