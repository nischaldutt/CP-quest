// peak element in an unsorted array

// input 1
// enter array length: 7
// 10 20 15 2 23 90 67

// output:
// 20

// input 2
// enter array length: 4
// 5 10 20 15

// output:
// 20

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

int peakElement(int* arr, int size) {
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (mid > 0 && mid < size - 1) {
      if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        return arr[mid];
      else if (arr[mid - 1] > arr[mid])
        end = mid - 1;
      else if (arr[mid + 1] > arr[mid])
        start = mid + 1;

    } else if (mid == 0) {
      if (arr[0] > arr[1])
        return arr[0];
      else
        return arr[1];
    } else if (mid == size - 1) {
      if (arr[size - 1] > arr[size - 2])
        return arr[size - 1];
      else
        return arr[size - 2];
    }
  }

  return -1;
}

int main() {
  int size;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];

  int peak = peakElement(arr, size);

  cout << peak;

  return 0;
}