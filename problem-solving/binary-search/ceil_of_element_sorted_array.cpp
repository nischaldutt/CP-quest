// ceil of an element in a sorted array

// input
// enter array length: 9
// 1 2 3 4 8 10 10 12 19
// 5

// output:
// 8

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

int ceilOfAnElement(int* arr, int size, int element) {
  int result = -1;
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element)
      return arr[mid];
    else if (arr[mid] > element) {
      result = arr[mid];
      end = mid - 1;
    } else if (arr[mid] < element)
      start = mid + 1;
  }

  return result;
}

int main() {
  int size, element;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];

  cout << "enter element: ";
  cin >> element;

  int floor = ceilOfAnElement(arr, size, element);

  cout << floor;

  return 0;
}