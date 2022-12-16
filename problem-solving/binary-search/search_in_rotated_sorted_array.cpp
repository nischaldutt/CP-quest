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

int numberOfRotations(int* arr, int size) {
  int start = 0, end = size - 1;

  while (start <= end) {
    // first condition
    if (arr[start] <= arr[end]) return start;

    int mid = start + ((end - start) / 2);
    int next = (mid + 1) % size;
    int prev = (mid + size - 1) % size;

    // second condition
    if (arr[mid] < arr[prev] && arr[mid] < arr[next])
      return mid;
    // third condition
    else if (arr[start] <= arr[mid])
      start = mid + 1;
    // fourth condition
    else if (arr[mid] <= arr[end])
      end = mid - 1;
  }

  return -1;
}

int binarySearch(int* arr, int size, int element, int start, int end) {
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

  cout << "enter element to find: ";
  cin >> element;

  int indexOfSmallestElement = numberOfRotations(arr, size);

  if (arr[indexOfSmallestElement] == element) return indexOfSmallestElement;

  int leftIndex = binarySearch(arr, size, element, 0, (indexOfSmallestElement + size - 1) % size);

  int rightIndex = binarySearch(arr, size, element, (indexOfSmallestElement + 1) % size, size - 1);

  int value = -1;

  if (leftIndex != -1) {
    value = leftIndex;
  } else if (rightIndex != -1) {
    value = rightIndex;
  }

  cout << value;

  return 0;
}