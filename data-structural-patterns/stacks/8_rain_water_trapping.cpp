// Rain water trapping problem
// Reference: https://www.geeksforgeeks.org/trapping-rain-water/
// Time complexity: O(n), where n is the size of heightVector

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define null nullptr

using namespace std;

vector<int> getGreatestToRightVector(vector<int> heightVector, int n) {
  vector<int> greatestToRightVector;
  int maxElement = heightVector[n-1];
  greatestToRightVector.push_back(maxElement);
  for(int i = n-2; i >= 0; i--) {
    if(maxElement < heightVector[i]) {
      maxElement = heightVector[i];
    }
    greatestToRightVector.push_back(maxElement);
  }

  reverse(greatestToRightVector.begin(), greatestToRightVector.end());
  return greatestToRightVector;
}

vector<int> getGreatestToLeftVector(vector<int> heightVector, int n) {
  vector<int> greatestToLeftVector;
  int maxElement = heightVector[0];
  greatestToLeftVector.push_back(maxElement);
  for(int i = 1; i < n; i++) {
    if(maxElement < heightVector[i]) {
      maxElement = heightVector[i];
    }
    greatestToLeftVector.push_back(maxElement);
  }

  return greatestToLeftVector;
}

void rainWaterTrapping(vector<int> heightVector, int n) {
  vector<int> greatestToRightVector = getGreatestToRightVector(heightVector, n);
  vector<int> greatestToLeftVector = getGreatestToLeftVector(heightVector, n);

  vector<int> waterHeightVector;
  for(int i = 0; i < n; i++) { 
    waterHeightVector.push_back(min(greatestToLeftVector[i], greatestToRightVector[i]) - heightVector[i]);
  }

  int totalWaterTrapped = 0;
  for(auto waterHeightTrappedInBlock: waterHeightVector) {
    totalWaterTrapped += waterHeightTrappedInBlock;
  }
  cout<<totalWaterTrapped;
  return;
}

int main() {
  int n, element;
  cin>>n;
  vector<int> arr;
  while(n--) {
    cin>>element;
    arr.push_back(element);
  }
  rainWaterTrapping(arr, arr.size());
  return 0;
}