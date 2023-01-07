// rod cutting problem

// input:
// enter n: 8
// enter lengths: 1, 2, 3, 4, 5, 6, 7, 8
// enter profits: 1, 5, 8, 9, 10, 17, 19, 20

// output:
// max profit: 22

// time complexity: O(n*w) i.e. proportional to sizeof the matrix

// iterative solution

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < w; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

int unboundedKnapsack(vector<int> lengthVector, vector<int> profitVector, int rodLength, int n, int** matrix) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < rodLength + 1; j++) {
      if (lengthVector[i - 1] <= j) {
        matrix[i][j] = max(profitVector[i - 1] + matrix[i][j - lengthVector[i - 1]], matrix[i - 1][j]);
      } else if (lengthVector[i - 1] > j) {
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }

  return matrix[n][rodLength];
}

int main() {
  int length, profit, n, rodLength;

  cout << "enter n: ";
  cin >> n;

  vector<int> lengthVector;
  vector<int> profitVector;

  cout << "enter lengths: ";
  fori {
    cin >> length;
    lengthVector.push_back(length);
  }

  cout << "enter profits: ";
  fori {
    cin >> profit;
    profitVector.push_back(profit);
  }

  cout << "enter the length of the rod: ";
  cin >> rodLength;

  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[rodLength + 1];

  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < rodLength + 1; j++)
      if (i == 0 || j == 0)
        matrix[i][j] = 0;

  int maxProfit = unboundedKnapsack(lengthVector, profitVector, rodLength, n, matrix);

  cout << "maximum profit: " << maxProfit << endl;

  return 0;
}