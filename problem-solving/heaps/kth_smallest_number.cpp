// kth smallest number in a given array

// input
// enter array length: 6
// 7 10 4 3 20 15
// 3

// output:
// 7

// time complexity: O(n)

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>

#define null nullptr

using namespace std;

int getKthSmallest(int* arr, int size, int k) {
  priority_queue<int> myMaxHeap;

  for (int i = 0; i < size; i++) {
    myMaxHeap.push(arr[i]);

    if (myMaxHeap.size() > k) {
      myMaxHeap.pop();
    }
  }

  return myMaxHeap.top();
}

int main() {
  int size;

  cin >> size;
  int arr[size], k;

  for (int i = 0; i < size; i++) cin >> arr[i];
  cin >> k;

  int result = getKthSmallest(arr, size, k);

  cout << result;
  return 0;
}