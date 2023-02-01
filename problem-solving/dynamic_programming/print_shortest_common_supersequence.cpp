// shortest common subsequence problem

// input:
// enter string x: acbcf
// enter string y: abcdaf

// output:
// shortest common super sequence: acbcdaf

// time complexity: O(n*m) i.e. proportional to sizeof the matrix

// top-down iterative solution

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

int** shortestCommonSuperSequenceMatrix(string x, string y, int n, int m) {
  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[m + 1];

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (i == 0 || j == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (x[i - 1] == y[j - 1]) {
        matrix[i][j] = 1 + matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
      }
    }
  }

  return matrix;
}

string shortestCommonSubsequence(string x, string y, int n, int m) {
  string result;
  int** matrix = shortestCommonSuperSequenceMatrix(x, y, n, m);
  int i = n, j = m;

  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) {
      result.push_back(x[i - 1]);
      i--;
      j--;
    } else {
      if (matrix[i][j - 1] > matrix[i - 1][j]) {
        result.push_back(y[j - 1]);
        j--;
      } else {
        result.push_back(x[i - 1]);
        i--;
      }
    }
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  string x, y;

  cout << "enter string x: ";
  cin >> x;

  cout << "enter string y: ";
  cin >> y;

  int n = x.length();
  int m = y.length();

  string result = shortestCommonSubsequence(x, y, n, m);

  cout << "shortest common super sequence: " << result;

  return 0;
}