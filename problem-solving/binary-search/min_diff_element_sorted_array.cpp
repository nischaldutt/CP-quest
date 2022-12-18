// minimum difference element in a sorted array

// input 1
// enter array length: 7
// 1 2 3 8 10 12 15
// 12

// output:
// 12

// input 2
// enter array length: 6
// 1 2 3 8 10 15
// 12

// output:
// 10

// time complexity: O(logn)

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

int minDiffElementInSortedArray(int* arr, int size, int element) {
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element)
      return arr[mid];
    else if (arr[mid] > element)
      end = mid - 1;
    else
      start = mid + 1;
  }

  int minDiff = abs(arr[start] - element) <= abs(arr[end] - element) ? arr[start] : arr[end];

  return minDiff;
}

int main() {
  int size, element;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];

  cout << "enter element: ";
  cin >> element;

  int result = minDiffElementInSortedArray(arr, size, element);

  cout << result;

  return 0;
}