// find maximum (or minimum) sum of a sub-array of size k

// input:
// enter n: 7
// enter elements: 2 5 1 8 2 9 1
// enter k: 3

// output:
// maximum sum of sub-array of given window size: 19

// time complexity: O(n)
// space complexity: O(1)

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

int maxSumSubarrayOfSizeK(vector<int> myVector, int n, int k) {
  int maxSum = INT_MIN + 1;
  int i = 0;
  int j = 0;
  int sum = 0;

  while (j < n) {
    sum += myVector[j];

    int currentWindowSize = j - i + 1;

    if (currentWindowSize < k) {
      j++;
    } else if (currentWindowSize == k) {
      maxSum = max(maxSum, sum);
      sum -= myVector[i];
      i++;
      j++;
    }
  }

  return maxSum;
}

int main() {
  int n, k, element;

  cout << "enter n: ";
  cin >> n;

  vector<int> myVector;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myVector.push_back(element);
  }

  cout << "enter window size: ";
  cin >> k;

  int result = maxSumSubarrayOfSizeK(myVector, n, k);

  cout << "maximum sum of sub-array of given window size: " << result;

  return 0;
}