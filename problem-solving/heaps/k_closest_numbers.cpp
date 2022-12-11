// sort a k-sorted array

// input
// enter array length: 5
// 5 6 7 8 9
// k = 3
// x = 7

// output:
// 6 7 8

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

vector<int> getKClosestNumbers(int* arr, int size, int k, int x) {
  vector<int> result;
  priority_queue<pair<int, int>> myMaxHeap;

  fori {
    myMaxHeap.push(make_pair(abs(x - arr[i]), arr[i]));

    if (myMaxHeap.size() > k) {
      myMaxHeap.pop();
    }
  }

  while (!myMaxHeap.empty()) {
    result.push_back(myMaxHeap.top().second);
    myMaxHeap.pop();
  }

  return result;
}

int main() {
  int size;

  cin >> size;
  int arr[size], k, x;

  for (int i = 0; i < size; i++) cin >> arr[i];
  cin >> k;
  cin >> x;

  vector<int> kClosestNumbers = getKClosestNumbers(arr, size, k, x);

  for (auto number : kClosestNumbers) {
    cout << number << "  ";
  }

  return 0;
}