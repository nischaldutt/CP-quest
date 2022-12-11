// sort a k-sorted array

// input
// enter array length: 7
// 1 1 1 3 2 2 4

// output:
// 1 1 1 2 2 4 3

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

vector<int> getSortedArray(int* arr, int size) {
  vector<int> result;
  unordered_map<int, int> myMap;

  fori {
    myMap[arr[i]]++;
  }

  priority_queue<pi, vector<pi>, greater<pi>> myMinHeap;

  for (auto itr = myMap.begin(); itr != myMap.end(); itr++) {
    myMinHeap.push(make_pair(itr->second, itr->first));
  }

  while (!myMinHeap.empty()) {
    int frequency = myMinHeap.top().first;

    while (frequency--) {
      result.push_back(myMinHeap.top().second);
    }

    myMinHeap.pop();
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  int size;

  cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++) cin >> arr[i];

  vector<int> sortedArray = getSortedArray(arr, size);

  for (auto number : sortedArray) {
    cout << number << "  ";
  }

  return 0;
}