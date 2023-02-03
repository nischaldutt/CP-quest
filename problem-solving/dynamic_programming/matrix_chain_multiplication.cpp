// matrix chain multiplication problem

// input:
// enter n: 5
// enter elements: 40 20 30 10 30

// output:
// min cost of matrix multiplication: 26000

// time complexity: O(n*n)

// bottom-up recursive memoized solution

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

int static matrix[1001][1001];

int matrixMultiplication(vector<int> myArray, int i, int j) {
  int minCost = INT_MAX - 1;

  if (i >= j) return 0;

  if (matrix[i][j] != -1) return matrix[i][j];

  for (int k = i; k < j; k++) {
    int temp = matrixMultiplication(myArray, i, k) +
               matrixMultiplication(myArray, k + 1, j) +
               (myArray[i - 1] * myArray[k] * myArray[j]);

    minCost = min(minCost, temp);
  }

  matrix[i][j] = minCost;

  return matrix[i][j];
}

int main() {
  int element, n;
  vector<int> myArray;

  cout << "enter n: ";
  cin >> n;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myArray.push_back(element);
  }

  memset(matrix, -1, sizeof(matrix));

  int result = matrixMultiplication(myArray, 1, n - 1);

  cout << "min cost of matrix multiplication: " << result;

  return 0;
}