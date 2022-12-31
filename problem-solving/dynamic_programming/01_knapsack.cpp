// 0/1 knapsack problem

// input:

// output:

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

// int static matrix[102][1002];

int knapsack(vector<int> weightVector, vector<int> profitVector, int w, int n, int** matrix) {
  if (w == 0 || n == 0) return 0;

  if (matrix[n][w] != -1) return matrix[n][w];

  if (weightVector[n - 1] <= w) {
    return matrix[n][w] = max(profitVector[n - 1] + knapsack(weightVector, profitVector, w - weightVector[n - 1], n - 1, matrix),
                              knapsack(weightVector, profitVector, w, n - 1, matrix));
  } else if (weightVector[n - 1] > w) {
    return matrix[n][w] = knapsack(weightVector, profitVector, w, n - 1, matrix);
  }
}

int main() {
  // memset(matrix, -1, sizeof(matrix));

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
      matrix[i][j] = -1;

  int maxProfit = knapsack(weightVector, profitVector, w, n, matrix);

  cout << "maximum profit: " << maxProfit << endl;

  return 0;
}