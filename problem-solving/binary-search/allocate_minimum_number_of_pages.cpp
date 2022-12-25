// allocate minimum number of pages

// input
// enter array length: 4
// 10 20 30 40
// enter k: 2

// output:
// 60

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

bool isValid(vector<int> pagesVector, int size, int k, int max) {
  int students = 1;
  int sum = 0;

  fori {
    sum += pagesVector[i];

    if (sum > max) {
      sum = pagesVector[i];
      students++;
    }

    if (students > k) {
      return false;
    }
  }

  return true;
}

int allocateMinNumberOfPages(vector<int> pagesVector, int size, int k) {
  int start = *max_element(pagesVector.begin(), pagesVector.end());
  int end = 0;
  fori end += pagesVector[i];

  int result = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (isValid(pagesVector, size, k, mid)) {
      result = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return result;
}

int main() {
  int size, k, x;

  cin >> size;

  vector<int> pagesVector;

  fori {
    cin >> x;
    pagesVector.push_back(x);
  }

  cout << "enter k: ";
  cin >> k;

  int result = allocateMinNumberOfPages(pagesVector, size, k);

  cout << result;

  return 0;
}