// sort a k-sorted array

// input
// enter array length: 7
// 1 1 1 3 2 2 4
// k = 2

// output:
// 2 1

// time complexity: O(nlogk)

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < totalPoints; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

vector<pi> getClosestPointToOrigin(vector<vector<int>> matrix, int totalPoints, int k) {
  vector<pi> result;
  priority_queue<ppi> myMaxHeap;

  fori {
    int distanceFromOrigin = sqrt(matrix[i][0] * matrix[i][0] + matrix[i][1] * matrix[i][1]);
    myMaxHeap.push(make_pair(distanceFromOrigin, make_pair(matrix[i][0], matrix[i][1])));

    if (myMaxHeap.size() > k) {
      myMaxHeap.pop();
    }
  }

  while (!myMaxHeap.empty()) {
    result.push_back(myMaxHeap.top().second);
    myMaxHeap.pop();
  }

  return result;
}

int main() {
  int element, totalPoints, k;

  cin >> totalPoints;
  vector<vector<int>> matrix(totalPoints);

  for (int i = 0; i < totalPoints; i++) {
    matrix[i] = vector<int>(2);
    for (int j = 0; j < 2; j++) {
      cin >> element;
      matrix[i][j] = element;
    }
  }
  cin >> k;

  vector<pi> kClosestPoints = getClosestPointToOrigin(matrix, totalPoints, k);

  for (auto point : kClosestPoints) {
    cout << "(" << point.first << ", " << point.second << ")  ";
  }

  return 0;
}