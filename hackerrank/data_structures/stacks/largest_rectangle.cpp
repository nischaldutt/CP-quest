#include <bits/stdc++.h>
#include <stack>
#define null nullptr

using namespace std;

void largestAreaInHistogram(vector<int> heights, int n) {
  stack<int> myStack;
  int maxArea=0, area=0, top;
  int i=0;
  
  while(i<n) {
    if(myStack.empty() || heights[i] >= heights[myStack.top()]) {
      myStack.push(i++);
    }
    else {
      top = myStack.top();
      myStack.pop();

      area = heights[top] * (myStack.empty() ? i : (i - myStack.top() - 1));
      maxArea = (maxArea < area) ? area : maxArea;
    }
  }
  
  while(!myStack.empty()) {
    top = myStack.top();
    myStack.pop();

    area = heights[top] * (myStack.empty() ? i : (i - myStack.top() - 1));
    maxArea = (maxArea < area) ? area : maxArea;
  }
  cout<<maxArea<<endl;
  return;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int total = n;
  while (n--) {
    int height;
    cin >> height;
    arr.push_back(height);
  }
  largestAreaInHistogram(arr, total);
  return 0;
}