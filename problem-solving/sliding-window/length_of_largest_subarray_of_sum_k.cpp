// length of largest sub-array of sum = k

// input:
// enter n: 7
// enter elements: 4 1 1 1 2 3 5
// enter k: 5

// output:
// length of largest sub-array of sum k: 4

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

int lengthOfLargestSubArrayOfSumK(vector<int> myVector, int n, int k) {
  int result = INT_MIN + 1;
  int sum = 0;
  int i = 0, j = 0;

  while (j < n) {
    sum += myVector[j];

    if (sum < k) {
      j++;
    }

    if (sum == k) {
      int currentWindowSize = j - i + 1;
      result = max(currentWindowSize, result);
      j++;
    }

    if (sum > k) {
      while (sum > k) {
        sum -= myVector[i];
        i++;
      }
      j++;
    }
  }

  return result;
}

int main() {
  int n, element, k;

  cout << "enter n: ";
  cin >> n;

  vector<int> myVector;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myVector.push_back(element);
  }

  cout << "enter k: ";
  cin >> k;

  int result = lengthOfLargestSubArrayOfSumK(myVector, n, k);
  cout << "length of largest sub-array of sum k: " << result;

  return 0;
}