// binary search

// input
// enter array length: 6
// 1 2 3 4 5 6

// output:
// 4

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

int binarySearch(int* arr, int size, int element) {
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element)
      return mid;
    else if (arr[mid] > element)
      end = mid - 1;
    else
      start = mid + 1;
  }

  return -1;
}

int main() {
  int size, element;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];
  cin >> element;

  int index = binarySearch(arr, size, element);

  cout << index;

  return 0;
}