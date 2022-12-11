//

// input
// enter array length: 1
// 1 2 3 4 5

// output:
// 33

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < size; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

int getMinimumCostToConnectRopes(int* arr, int size) {
  int result = 0;
  priority_queue<int, vector<int>, greater<int>> myMinHeap;

  fori {
    myMinHeap.push(arr[i]);
  }

  while (myMinHeap.size() >= 2) {
    int first = myMinHeap.top();
    myMinHeap.pop();
    int second = myMinHeap.top();
    myMinHeap.pop();
    result += first + second;

    myMinHeap.push(first + second);
  }

  return result;
}

int main() {
  int size;

  cin >> size;
  int arr[size], k;

  fori cin >> arr[i];

  int minimumCost = getMinimumCostToConnectRopes(arr, size);

  cout << minimumCost;

  return 0;
}