// Maximum area of a rectangle in a binary matrix
// Reference: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
// Pattern similar to Maximum area under histogram problem
// We convert the 2D matrix to 1D vector and then apply maxAreaInHistogram function
// to find the maximum area for the particular vector and keep on combining the 
// vectors so as to find the the area of complete matrix.

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define null nullptr

using namespace std;

vector<int> nearestSmallerToLeft(vector<int> arr, int n) {
  vector<int> nslIndexVector;
  stack<pair<int, int>> myStack;
  for(int i = 0; i < n; i++) {
    if(myStack.empty()) {
      nslIndexVector.push_back(-1);
    }
    else if(!myStack.empty() && myStack.top().first < arr[i]) {
      nslIndexVector.push_back(myStack.top().second);
    }
    else if(!myStack.empty() && myStack.top().first >= arr[i]) {
      while(!myStack.empty() && myStack.top().first >= arr[i]) {
        myStack.pop();
      }
      if(myStack.empty()) {
        nslIndexVector.push_back(-1);
      }
      else {
        nslIndexVector.push_back(myStack.top().second);
      }
    }
    myStack.push(make_pair(arr[i], i));
  }

  return nslIndexVector;
}

vector<int> nearestSmallerToRight(vector<int> arr, int n) {
  vector<int> nsrIndexVector;
  stack<pair<int, int>> myStack;
  for(int i = n-1; i >= 0; i--) {
    if(myStack.empty()) {
      nsrIndexVector.push_back(n);
    }
    else if(!myStack.empty() && myStack.top().first < arr[i]) {
      nsrIndexVector.push_back(myStack.top().second);
    }
    else if(!myStack.empty() && myStack.top().first >= arr[i]) {
      while(!myStack.empty() && myStack.top().first >= arr[i]) {
        myStack.pop();
      }

      if(myStack.empty()) {
        nsrIndexVector.push_back(n);
      }
      else {
        nsrIndexVector.push_back(myStack.top().second);
      }
    }
    myStack.push(make_pair(arr[i], i));
  }

  reverse(nsrIndexVector.begin(), nsrIndexVector.end());
  return nsrIndexVector;
}

int maxAreaInHistogram(vector<int> heightVector, int n) {
  vector<int> nslIndexVector =  nearestSmallerToLeft(heightVector, heightVector.size());
  vector<int> nsrIndexVector =  nearestSmallerToRight(heightVector, heightVector.size());

  vector<int> widthVector;
  int vectorLength = nslIndexVector.size();
  for(int i = 0; i < vectorLength; i++) {
    widthVector.push_back(nsrIndexVector[i] - nslIndexVector[i] - 1);
  }

  vector<int> areaVector;
  for(int i = 0; i < vectorLength ; i++) {
    areaVector.push_back(heightVector[i] * widthVector[i]);
  }

  int maxArea = *max_element(areaVector.begin(), areaVector.end());
  // cout<<maxArea;
  return maxArea;
}

void maxAreaInBinaryMatrix(vector<vector<int>> matrix, int n, int m) {
  int maxArea = 0;
  vector<int> heightVector(m, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        heightVector[j] = 0;
      }
      else {
        heightVector[j] = heightVector[j] + matrix[i][j];
      }
    }
    int area = maxAreaInHistogram(heightVector, heightVector.size());
    maxArea = (maxArea < area) ? area : maxArea;
  }
  cout<<maxArea;
  return;
}

int main() {
  int n, m, element;
  cin>>n>>m;
  vector<vector<int>> matrix(n);
  for(int i = 0; i < n; i++) {
    matrix[i] = vector<int>(m);
    for(int j = 0; j < m; j++) {
      cin>>element;
      matrix[i][j] =  element;
    }
  }
  maxAreaInBinaryMatrix(matrix, matrix.size(), matrix[0].size());
  return 0;
}