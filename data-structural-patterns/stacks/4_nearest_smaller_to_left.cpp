// Find nearest smaller element to the left of current element.

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define null nullptr

using namespace std;

void nearestSmallerToLeft(vector<int> arr, int n) {
  vector<int> result;
  stack<int> myStack;
  for(int i = 0; i < n; i++) {
    if(myStack.empty()) {
      result.push_back(-1);
    }
    else if(!myStack.empty() && myStack.top() < arr[i]) {
      result.push_back(myStack.top());
    }
    else if(!myStack.empty() && myStack.top() >= arr[i]) {
      while(!myStack.empty() && myStack.top() >= arr[i]) {
        myStack.pop();
      }
      if(myStack.empty()) {
        result.push_back(-1);
      }
      else {
        result.push_back(myStack.top());
      }
    }
    myStack.push(arr[i]);
  }

  for(auto element: result) {
    cout<<element<<" ";
  }
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
  nearestSmallerToLeft(arr, arr.size());
  return 0;
}