// longest common subsequence problem

// input:
// enter string x: abcdgh
// enter string y: abedfhr

// output:
// length of longest common subsequence: 4

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

int longestCommonSubsequence(string x, string y, int n, int m, int** matrix) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (x[i - 1] == y[j - 1]) {
        matrix[i][j] = 1 + matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
      }
    }
  }

  return matrix[n][m];
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
      if (i == 0 || j == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  int lengthOfLCS = longestCommonSubsequence(x, y, n, m, matrix);

  int deletions = n - lengthOfLCS;
  int insertions = m - lengthOfLCS;

  int result = deletions + insertions;

  cout << "length of longest common subsequence: " << result;

  return 0;
}