// equal sum partition problem

// input:
// enter n: 4
// enter weights: 1, 5, 11, 5

// output:
// equal sum partition: true

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
        matrix[i][j] = myArray[i - 1] + matrix[i - 1][j - myArray[i - 1]] || matrix[i - 1][j];
      } else if (myArray[i - 1] > j) {
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }

  return matrix[n][sum];
}

bool equalSumPartition(vector<int> myArray, int n, int myArraySum) {
  int requiredSum = myArraySum / 2;
  int** matrix;
  matrix = new int*[n + 1];

  for (int i = 0; i < n + 1; i++)
    matrix[i] = new int[requiredSum + 1];

  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < requiredSum + 1; j++)
      if (i == 0)
        matrix[i][j] = false;
      else if (j == 0)
        matrix[i][j] = true;

  return subsetSum(myArray, requiredSum, n, matrix);
}

int main() {
  int element, n;

  cout << "enter n: ";
  cin >> n;

  vector<int> myArray;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myArray.push_back(element);
  }

  int myArraySum = 0;
  string result = "false";

  fori myArraySum += myArray[i];

  if (myArraySum % 2 == 0) {
    result = equalSumPartition(myArray, n, myArraySum) ? "true" : "false";
  }
  cout << "equal sum partition: " << result << endl;

  return 0;
}