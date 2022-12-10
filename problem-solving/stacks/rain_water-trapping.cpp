// rain water trapping problem

// input
// 6
// 3 0 0 2 0 4

// output:
// 10

// time complexity: O(n)

#include <bits/stdc++.h>

#include <iostream>
#include <stack>

#define null nullptr

using namespace std;

vector<int> getGreatestToRightVector(vector<int> heightVector, int size) {
  int maxElement = heightVector[size - 1];
  vector<int> myVector;

  myVector.push_back(maxElement);

  for (int i = size - 2; i >= 0; i--) {
    if (maxElement < heightVector[i]) {
      maxElement = heightVector[i];
    }
    myVector.push_back(maxElement);
  }

  reverse(myVector.begin(), myVector.end());
  return myVector;
}

vector<int> getGreatestToLeftVector(vector<int> heightVector, int size) {
  int maxElement = heightVector[0];
  vector<int> myVector;

  myVector.push_back(maxElement);

  for (int i = 1; i < size; i++) {
    if (maxElement < heightVector[i]) {
      maxElement = heightVector[i];
    }
    myVector.push_back(maxElement);
  }

  return myVector;
}

int getWaterTrapped(vector<int> heightVector, int size) {
  vector<int> lengthVector, waterHeightVector;

  vector<int> greatestToLeftVector = getGreatestToLeftVector(heightVector, size);
  vector<int> greatestToRightVector = getGreatestToRightVector(heightVector, size);

  for (int i = 0; i < size; i++) {
    waterHeightVector.push_back(min(greatestToLeftVector[i], greatestToRightVector[i]) - heightVector[i]);
  }

  int totalWaterTrapped = 0;

  for (int i = 0; i < size; i++) {
    totalWaterTrapped += waterHeightVector[i];
  }

  return totalWaterTrapped;
}

int main() {
  int n, total, element;
  vector<int> heightVector;

  cin >> n;
  total = n;

  while (n--) {
    cin >> element;
    heightVector.push_back(element);
  }

  int totalWaterTrapped = getWaterTrapped(heightVector, heightVector.size());

  cout << "Total rain water trapped: " << totalWaterTrapped;
  return 0;
}