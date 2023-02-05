// scrambled string problem

// input 1:
// enter total floors: 10
// enter total eggs: 2

// output 1:
// critical floor: 4

// bottom-up recursive memoized solution

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

int myMatrix[11][51];

int eggDropping(int e, int f) {
  if (f == 0 || f == 1) return f;

  if (e == 1) return f;

  if (myMatrix[e][f] != -1) return myMatrix[e][f];

  int result = INT_MAX - 1;

  for (int k = 1; k <= f; k++) {
    int high, low;

    if (myMatrix[e - 1][k - 1] != -1) {
      low = myMatrix[e - 1][k - 1];
    } else {
      low = eggDropping(e - 1, k - 1);
      myMatrix[e - 1][k - 1] = low;
    }

    if (myMatrix[e][f - k] != -1) {
      high = myMatrix[e][f - k];
    } else {
      high = eggDropping(e, f - k);
      myMatrix[e][f - k] = high;
    }

    int temp = 1 + max(low, high);
    result = min(result, temp);
  }

  myMatrix[e][f] = result;

  return myMatrix[e][f];
}

int main() {
  int e, f;

  cout << "enter total floors: ";
  cin >> f;

  cout << "enter total eggs: ";
  cin >> e;

  memset(myMatrix, -1, sizeof(myMatrix));

  int criticalFloor = eggDropping(e, f);
  cout << "critical floor: " << criticalFloor;

  return 0;
}