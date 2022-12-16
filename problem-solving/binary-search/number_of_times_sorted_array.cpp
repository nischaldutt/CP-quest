// number of times a sorted array is rotated clockwise****

// input 1
// enter array length: 8
// 11 12 15 18 2 5 6 8

// output:
// 4

// input 2
// enter array length: 7
// 2 4 5 6 7 0 1

// output:
// 5

// input 3
// enter array length: 5
// 3 3 3 3 1

// output:
// 4

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

int main() {
  int size;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];

  int value = numberOfRotations(arr, size);

  cout << value;

  return 0;
}