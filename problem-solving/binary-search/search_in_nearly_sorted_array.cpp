// find index of an element in a rotated sorted array

// input
// enter array length: 8
// 11 12 15 18 2 5 6 8

// output:
// 2

// time complexity: O(logn) + O(logn) + O(logn) = O(logn)

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

int nearlySortedBinarySearch(int* arr, int size, int element) {
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element)
      return mid;
    else if (mid > start && arr[mid - 1] == element)
      return mid - 1;
    else if (mid < end && arr[mid + 1] == element)
      return mid + 1;
    else if (arr[mid] > element)
      end = mid - 2;
    else
      start = mid + 2;
  }

  return -1;
}

int main() {
  int size, element;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];

  cout << "enter element to find: ";
  cin >> element;

  int index = nearlySortedBinarySearch(arr, size, element);

  cout << index;

  return 0;
}