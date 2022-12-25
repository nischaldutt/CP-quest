// search in a sorted 2D matrix

// input
// enter rows: 4
// enter columns: 4

// 10 20 30 40
// 15 25 35 45
// 27 29 37 45
// 32 33 39 50

// enter element to search: 27

// output:
// (2, 0)

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < rows; i++)
#define forj for (int j = 0; j < columns; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

pair<int, int> searchInSorted2DMatrix(vector<vector<int>> matrix, int rows, int columns, int element) {
  int i = 0, j = columns - 1;
  while (i >= 0 && i < rows && j >= 0 && j < columns) {
    if (matrix[i][j] == element)
      return make_pair(i, j);
    else if (matrix[i][j] < element)
      i++;
    else if (matrix[i][j] > element)
      j--;
  }

  return make_pair(-1, -1);
}

int main() {
  int rows, columns, element;

  cin >> rows >> columns;

  vector<vector<int>> matrix(rows);

  fori {
    matrix[i] = vector<int>(columns);
    forj {
      cin >> matrix[i][j];
    }
  }

  cout << "enter element: ";
  cin >> element;

  pair<int, int> index = searchInSorted2DMatrix(matrix, rows, columns, element);

  cout << "(" << index.first << ", " << index.second << ")";

  return 0;
}