// kth smallest number in a given array

// input
// enter array length: 6
// 7 10 4 3 20 15
// 3

// output:
// 7

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

int getKthLargest(int* arr, int size, int k) {
  priority_queue<int, vector<int>, greater<int>> myMinHeap;

  fori {
    myMinHeap.push(arr[i]);

    if (myMinHeap.size() > k) {
      myMinHeap.pop();
    }
  }

  return myMinHeap.top();
}

int main() {
  int size;

  cin >> size;
  int arr[size], k;

  for (int i = 0; i < size; i++) cin >> arr[i];
  cin >> k;

  int result = getKthLargest(arr, size, k);

  cout << result;
  return 0;
}