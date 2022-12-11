// find the frequency of an element in a given sorted array

// input
// enter array length: 7
// 2 4 10 10 10 18 20
// 10

// output:
// 3

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

int getFirstOccurence(int* arr, int size, int element) {
  int result = -1;
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element) {
      result = mid;
      end = mid - 1;
    } else if (arr[mid] > element)
      end = mid - 1;
    else
      start = mid + 1;
  }

  return result;
}

int getLastOccurence(int* arr, int size, int element) {
  int result = -1;
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = start + ((end - start) / 2);

    if (arr[mid] == element) {
      result = mid;
      start = mid + 1;
    } else if (arr[mid] > element)
      end = mid - 1;
    else
      start = mid + 1;
  }

  return result;
}

int main() {
  int size, element;

  cin >> size;

  int arr[size];

  fori cin >> arr[i];
  cin >> element;

  int first = getFirstOccurence(arr, size, element);
  int last = getLastOccurence(arr, size, element);

  int frequency = last - first + 1;

  cout << "frequency: " << frequency;

  return 0;
}