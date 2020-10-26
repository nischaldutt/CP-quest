// Maximum area of rectangle under histogram problem
// Reference: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// Pattern similar to combination of nearest smaller to right and nearest smaller to left problems

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

int main() {
  int n, element;
  cin>>n;
  vector<int> heightVector;
  while(n--) {
    cin>>element;
    heightVector.push_back(element);
  }
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
  cout<<maxArea;
  return 0;
}