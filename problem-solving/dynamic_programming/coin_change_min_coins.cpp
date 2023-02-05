// coin change problem: minimum number of coins required to make the given sum

// input:
// enter n: 3
// enter coin values: 1, 2, 3
// enter the sum: 5

// output:
// minimum number of coins required to make the given sum: 5

// time complexity: O(n*sum) i.e. proportional to sizeof the matrix

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

int coinChangeMinCoins(vector<int> myArray, int sum, int n, int** matrix) {
  for (int i = 2; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (myArray[i - 1] <= j) {
        matrix[i][j] = min(1 + matrix[i][j - myArray[i - 1]], matrix[i - 1][j]);
      } else if (myArray[i - 1] > j) {
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }

  return matrix[n][sum];
}

int main() {
  int element, n, sum;

  cout << "enter n: ";
  cin >> n;

  vector<int> myArray;

  cout << "enter coin values: ";
  fori {
    cin >> element;
    myArray.push_back(element);
  }

  cout << "enter the sum: ";
  cin >> sum;

  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[sum + 1];

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (i == 1) {
        if (j % myArray[0] == 0) {
          matrix[i][j] = j / myArray[0];
        } else {
          matrix[i][j] = INT_MAX - 1;
        }
      }

      if (j == 0) matrix[i][j] = 0;

      if (i == 0) matrix[i][j] = INT_MAX - 1;
    }
  }

  int result = coinChangeMinCoins(myArray, sum, n, matrix);

  cout << "minimum number of coins required to make the given sum: " << result << endl;

  return 0;
}