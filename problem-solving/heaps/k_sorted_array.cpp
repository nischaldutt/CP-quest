// sort a k-sorted array

// input
// enter array length: 7
// 6 5 3 2 8 10 9
// 3

// output:
// 2 3 5 6 8 9 10

// time complexity: O(nlogk)

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < size; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, pair<int, int>> ppi;

vector<int> getKthSortedArray(int* arr, int size, int k) {
  vector<int> result;
  priority_queue<int, vector<int>, greater<int>> myMinHeap;

  fori {
    myMinHeap.push(arr[i]);

    if (myMinHeap.size() > k) {
      result.push_back(myMinHeap.top());
      myMinHeap.pop();
    }
  }

  while (!myMinHeap.empty()) {
    result.push_back(myMinHeap.top());
    myMinHeap.pop();
  }

  return result;
}

int main() {
  int size;

  cin >> size;
  int arr[size], k;

  for (int i = 0; i < size; i++) cin >> arr[i];
  cin >> k;

  vector<int> sortedArray = getKthSortedArray(arr, size, k);

  for (auto x : sortedArray) {
    cout << x << "  ";
  }
  return 0;
}