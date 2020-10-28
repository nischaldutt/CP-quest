// Stock span problem
// Reference: https://www.geeksforgeeks.org/the-stock-span-problem/
// Pattern similar to nearest_greater_to_left problem

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define null nullptr

using namespace std;

void stockSpan(vector<int> arr, int n) {
  vector<int> indexVector;
  stack<pair<int, int>> myStack;
  for(int i = 0; i < n; i++) {
    if(myStack.empty()) {
      indexVector.push_back(-1);
    }
    else if(!myStack.empty() && myStack.top().first > arr[i]) {
      indexVector.push_back(myStack.top().second);
    }
    else if(!myStack.empty() && myStack.top().first <= arr[i]) {
      while(!myStack.empty() && myStack.top().first <= arr[i]) {
        myStack.pop();
      }
      if(myStack.empty()) {
        indexVector.push_back(-1);
      }
      else {
        indexVector.push_back(myStack.top().second);
      }
    }
    myStack.push(make_pair(arr[i], i));
  }

  indexVector[0] = 1;
  for(int i = 1; i < n; i++) {
    indexVector[i] = i - indexVector[i];
  }

  for(auto element: indexVector) {
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
  stockSpan(arr, arr.size());
  return 0;
}