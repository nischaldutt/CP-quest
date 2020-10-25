// Find nearest greater element to the right of current element.

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define null nullptr

using namespace std;

void nearestGreaterToRight(vector<int> arr, int n) {
  vector<int> result;
  stack<int> myStack;
  for(int i = n-1; i >= 0; i--) {
    if(myStack.empty()) {
      result.push_back(-1);
    }
    else if(!myStack.empty() && myStack.top() > arr[i]) {
      result.push_back(myStack.top());
    }
    else if(!myStack.empty() && myStack.top() <= arr[i]) {
      while(!myStack.empty() && myStack.top() <= arr[i]) {
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

  reverse(result.begin(), result.end());
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
  nearestGreaterToRight(arr, arr.size());
  return 0;
}