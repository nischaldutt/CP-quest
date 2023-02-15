// first negative number in every window of size k

// input 1:
// enter n: 8
// enter elements: 12 -1 -7 8 -15 30 16 28
// enter k: 3

// output 1:
// first negative number in every window of size k: -1 -1 -7 -15 -15 0

// input 2:
// enter n: 4
// enter elements: -1 -2 -7 -1
// enter k: 3

// output 2:
// first negative number in every window of size k: -1 -2

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

vector<int> maxSumSubarrayOfSizeK(vector<int> myVector, int n, int k) {
  list<int> myList;
  vector<int> result;
  int i = 0;
  int j = 0;

  while (j < n) {
    if (myVector[j] < 0) {
      myList.push_back(myVector[j]);
    }

    int currentWindowSize = j - i + 1;

    if (currentWindowSize < k) {
      j++;
    } else if (currentWindowSize == k) {
      if (myList.empty()) {
        result.push_back(0);
      } else {
        result.push_back(myList.front());

        if (myVector[i] == myList.front()) {
          myList.pop_front();
        }
      }
      i++;
      j++;
    }
  }

  return result;
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

  vector<int> result = maxSumSubarrayOfSizeK(myVector, n, k);

  cout << "first negative number in every window of size k: ";
  for (int x : result) cout << x << "  ";

  return 0;
}