// stock span problem

// input
// enter array length: 7
// 100 80 60 70 60 75 85

// output:
// 1 1 1 2 1 4 6

// time complexity: O(n)

#include <bits/stdc++.h>

#include <iostream>
#include <stack>

#define null nullptr

using namespace std;

vector<int> getNglIndexVector(vector<int> myArray, int n) {
  vector<int> myVector;
  stack<pair<int, int>> myStack;

  for (int i = 0; i < n; i++) {
    if (myStack.empty()) {
      myVector.push_back(-1);
    } else if (!myStack.empty() && myArray[i] < myStack.top().second) {
      myVector.push_back(myStack.top().first);
    } else if (!myStack.empty() && myArray[i] >= myStack.top().second) {
      while (!myStack.empty() && myArray[i] >= myStack.top().second) {
        myStack.pop();
      }

      if (myStack.empty()) {
        myVector.push_back(-1);
      } else {
        myVector.push_back(myStack.top().first);
      }
    }
    myStack.push(make_pair(i, myArray[i]));
  }

  return myVector;
}

int main() {
  int n, total, element;
  vector<int> myArray;

  cout << "enter array length: ";
  cin >> n;
  total = n;

  while (n--) {
    cout << "enter array element: ";
    cin >> element;
    myArray.push_back(element);
  }

  vector<int> result = getNglIndexVector(myArray, myArray.size());

  result[0] = 1;

  for (int i = 1; i < total; i++) {
    result[i] = i - result[i];
  }

  for (auto x : result) {
    cout << x << "  ";
  }

  return 0;
}