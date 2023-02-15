// maximum of all sub-arrays of size k

// input:
// enter n: 8
// enter elements: 1 3 -1 -3 5 3 6 7
// enter k: 3

// output:
// maximums of all sub-arrays of size k: 3 3 5 5 6 7

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

vector<int> maxOfSubarraysOfSizeK(vector<int> myVector, int n, int k) {
  vector<int> result;
  list<int> myList;

  int i = 0, j = 0;

  while (j < n) {
    while (myList.size() > 0 && myList.back() < myVector[j]) {
      myList.pop_back();
    }

    myList.push_back(myVector[j]);

    int currentWindowSize = j - i + 1;

    if (currentWindowSize < k) {
      j++;
    }

    if (currentWindowSize == k) {
      result.push_back(myList.front());

      if (myList.front() == myVector[i]) {
        myList.pop_front();
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

  vector<int> result = maxOfSubarraysOfSizeK(myVector, n, k);

  cout << "maximums of all sub-arrays of size k: ";
  for (int x : result) cout << x << "  ";

  return 0;
}
