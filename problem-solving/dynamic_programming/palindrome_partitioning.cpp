// palindrome partitioning problem

// input:
// enter string: nitik

// output:
// min partitions required to make each substring a palindrome: 2

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

bool isPalindrome(string myString, int i, int j) {
  while (i != j) {
    if (myString[i] == myString[j]) {
      i++;
      j--;
    } else {
      return false;
    }
  }
  return true;
}

int palindromePartition(string myString, int i, int j) {
  int minCuts = INT_MAX - 1;

  if (i >= j) return 0;

  if (matrix[i][j] != -1) return matrix[i][j];

  if (isPalindrome(myString, i, j)) return 0;

  for (int k = i; k < j; k++) {
    int left, right;

    if (matrix[i][k] != -1) {
      left = matrix[i][k];
    } else {
      left = palindromePartition(myString, i, k);
      matrix[i][k] = left;
    }

    if (matrix[k + 1][j] != -1) {
      right = matrix[k + 1][j];
    } else {
      right = palindromePartition(myString, k + 1, j);
      matrix[k + 1][j] = right;
    }

    int temp = left + right + 1;

    minCuts = min(minCuts, temp);
  }

  matrix[i][j] = minCuts;

  return matrix[i][j];
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  memset(matrix, -1, sizeof(matrix));

  int result = palindromePartition(myString, 0, myString.length() - 1);

  cout << "min partitions required to make each substring a palindrome: " << result;

  return 0;
}