// maximum area in binary matrix

// input
// enter array length: 7
// 6 2 5 4 5 1 6

// output:
// 12

// time complexity: O(n)

#include <bits/stdc++.h>

#include <iostream>
#include <stack>

#define null nullptr

using namespace std;

vector<int> getNslIndexVector(vector<int> lengthVector, int size) {
  vector<int> myVector;
  stack<pair<int, int>> myStack;

  for (int i = 0; i < size; i++) {
    if (myStack.empty()) {
      myVector.push_back(-1);
    } else if (!myStack.empty() && lengthVector[i] > myStack.top().second) {
      myVector.push_back(myStack.top().first);
    } else if (!myStack.empty() && lengthVector[i] <= myStack.top().second) {
      while (!myStack.empty() && lengthVector[i] <= myStack.top().second) {
        myStack.pop();
      }

      if (myStack.empty()) {
        myVector.push_back(-1);
      } else {
        myVector.push_back(myStack.top().first);
      }
    }
    myStack.push(make_pair(i, lengthVector[i]));
  }

  return myVector;
}

vector<int> getNsrIndexVector(vector<int> lengthVector, int size) {
  vector<int> myVector;
  stack<pair<int, int>> myStack;

  for (int i = size - 1; i >= 0; i--) {
    if (myStack.empty()) {
      myVector.push_back(size);
    } else if (!myStack.empty() && lengthVector[i] > myStack.top().second) {
      myVector.push_back(myStack.top().first);
    } else if (!myStack.empty() && lengthVector[i] <= myStack.top().second) {
      while (!myStack.empty() && lengthVector[i] <= myStack.top().second) {
        myStack.pop();
      }

      if (myStack.empty()) {
        myVector.push_back(size);
      } else {
        myVector.push_back(myStack.top().first);
      }
    }
    myStack.push(make_pair(i, lengthVector[i]));
  }

  reverse(myVector.begin(), myVector.end());

  return myVector;
}

int getMaxAreaUnderHistogram(vector<int> lengthVector, int size) {
  vector<int> nslIndexVector = getNslIndexVector(lengthVector, size);
  vector<int> nsrIndexVector = getNsrIndexVector(lengthVector, size);

  vector<int> widthVector;

  for (int i = 0; i < size; i++) {
    widthVector.push_back(nsrIndexVector[i] - nslIndexVector[i] - 1);
  }

  vector<int> areaVector;

  for (int i = 0; i < size; i++) {
    areaVector.push_back(lengthVector[i] * widthVector[i]);
  }

  int maxAreaValue = *max_element(areaVector.begin(), areaVector.end());

  return maxAreaValue;
}

int getMaxAreaUnderBinaryMatrix(vector<vector<int>> matrix, int rows, int columns) {
  int maxAreaUnderBinaryMatrix = 0;
  vector<int> lengthVector(columns, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (matrix[i][j] == 0) {
        lengthVector[j] = 0;
      } else {
        lengthVector[j] = matrix[i][j] + lengthVector[j];
      }
    }
    int maxAreaUnderHistogram = getMaxAreaUnderHistogram(lengthVector, lengthVector.size());
    maxAreaUnderBinaryMatrix = maxAreaUnderBinaryMatrix < maxAreaUnderHistogram ? maxAreaUnderHistogram : maxAreaUnderBinaryMatrix;
  }

  return maxAreaUnderBinaryMatrix;
}

int main() {
  int rows, columns, element;

  cin >> rows >> columns;

  vector<vector<int>> matrix(rows);

  for (int i = 0; i < rows; i++) {
    matrix[i] = vector<int>(columns);
    for (int j = 0; j < columns; j++) {
      cin >> element;
      matrix[i][j] = element;
    }
  }

  int maxAreaUnderBinaryMatrix = getMaxAreaUnderBinaryMatrix(matrix, matrix.size(), matrix[0].size());
  cout << maxAreaUnderBinaryMatrix;

  return 0;
}
