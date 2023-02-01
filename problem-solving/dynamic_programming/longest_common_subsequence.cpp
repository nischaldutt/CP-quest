// longest common subsequence problem

// input:
// enter string x: abcdgh
// enter string y: abedfhr

// output:
// length of longest common subsequence: 4

// time complexity: O(n*m) i.e. proportional to sizeof the matrix

// bottom-up recursive memoized solution

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

int longestCommonSubsequence(string x, string y, int n, int m, int** matrix) {
  if (n == 0 || m == 0) {
    return 0;
  }

  if (matrix[n][m] != -1) {
    return matrix[n][m];
  }

  if (x[n - 1] == y[m - 1]) {
    return matrix[n][m] = 1 + longestCommonSubsequence(x, y, n - 1, m - 1, matrix);
  } else {
    return matrix[n][m] = max(longestCommonSubsequence(x, y, n - 1, m, matrix),
                              longestCommonSubsequence(x, y, n, m - 1, matrix));
  }
}

int main() {
  string x, y;

  cout << "enter string x: ";
  cin >> x;

  cout << "enter string y: ";
  cin >> y;

  int n = x.length();
  int m = y.length();

  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[m + 1];

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      matrix[i][j] = -1;
    }
  }

  int result = longestCommonSubsequence(x, y, n, m, matrix);

  cout << "length of longest common subsequence: " << result;

  return 0;
}