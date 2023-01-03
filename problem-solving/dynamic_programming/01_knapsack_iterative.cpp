// 0/1 knapsack problem

// input:
// enter n: 4
// enter weights: 1, 3, 4, 5
// enter profits: 1, 4, 5, 7
// enter weight of the knapsack: 7

// output:
// max profit: 9

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

int knapsack(vector<int> weightVector, vector<int> profitVector, int w, int n, int** matrix) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < w + 1; j++) {
      if (weightVector[i - 1] <= j) {
        matrix[i][j] = max(profitVector[i - 1] + matrix[i - 1][j - weightVector[i - 1]], matrix[i - 1][j]);
      } else if (weightVector[i - 1] > j) {
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }

  return matrix[n][w];
}

int main() {
  int weight, profit, n, w;

  cout << "enter n: ";
  cin >> n;

  vector<int> weightVector;
  vector<int> profitVector;

  cout << "enter weights: ";
  fori {
    cin >> weight;
    weightVector.push_back(weight);
  }

  cout << "enter profits: ";
  fori {
    cin >> profit;
    profitVector.push_back(profit);
  }

  cout << "enter the weight of knapsack: ";
  cin >> w;

  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[w + 1];

  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < w + 1; j++)
      if (i == 0 || j == 0)
        matrix[i][j] = 0;

  int maxProfit = knapsack(weightVector, profitVector, w, n, matrix);

  cout << "maximum profit: " << maxProfit << endl;
}