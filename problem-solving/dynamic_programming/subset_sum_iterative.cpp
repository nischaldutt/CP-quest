// subset sum problem

// input:
// enter n: 5
// enter elements: 2, 3, 7, 8, 10
// enter the sum: 11

// output:
// subset sum: true

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

bool subsetSum(vector<int> myArray, int sum, int n, int** matrix) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (myArray[i - 1] <= j) {
        matrix[i][j] = matrix[i - 1][j - myArray[i - 1]] || matrix[i - 1][j];
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

  cout << "enter elements: ";
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
      if (i == 0)
        matrix[i][j] = false;
      if (j == 0)
        matrix[i][j] = true;
    }
  }

  string result = subsetSum(myArray, sum, n, matrix) ? "true" : "false";

  cout << "subset sum: " << result << endl;

  return 0;
}