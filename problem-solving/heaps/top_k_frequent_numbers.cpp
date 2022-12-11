// sort a k-sorted array

// input
// enter array length: 7
// 1 1 1 3 2 2 4
// k = 2

// output:
// 2 1

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

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

vector<int> getTopKFrequentNumber(int* arr, int size, int k) {
  vector<int> result;
  unordered_map<int, int> myMap;

  fori {
    myMap[arr[i]]++;
  }

  priority_queue<pi, vector<pi>, greater<pi>> myMinHeap;

  for (auto itr = myMap.begin(); itr != myMap.end(); itr++) {
    myMinHeap.push(make_pair(itr->second, itr->first));

    if (myMinHeap.size() > k) {
      myMinHeap.pop();
    }
  }

  while (!myMinHeap.empty()) {
    result.push_back(myMinHeap.top().second);
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

  vector<int> topKFrequentNumbers = getTopKFrequentNumber(arr, size, k);

  for (auto number : topKFrequentNumbers) {
    cout << number << "  ";
  }

  return 0;
}