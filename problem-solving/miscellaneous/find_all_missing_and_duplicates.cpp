// find all missing and duplicate elements from 1 to n

// input:
// enter n: 5
// enter elements: 2 3 1 5 4

// output:
// missing: 1 and duplicate: 3

// time complexity: O(n)
// space complexity: O(1)

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
  return;
}

void solve(vector<int> myVector, int n) {
  for (int i = 0; i < n; i++) {
    if (myVector[i] != myVector[myVector[i] - 1])
      swap(myVector[i], myVector[myVector[i] - 1]);
    else
      i++;
  }

  for (int i = 0; i < n; i++) {
    if (myVector[i] != i + 1)
      cout << "missing: " << i + 1 << " and duplicate: " << myVector[i] << endl;
  }

  return;
}

int main() {
  int n, element;

  cout << "enter n: ";
  cin >> n;

  vector<int> myVector;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myVector.push_back(element);
  }

  solve(myVector, n);

  return 0;
}