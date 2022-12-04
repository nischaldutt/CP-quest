// maximum area under histogram

// input
// enter array length: 7
// 6 2 5 4 5 1 6

// output:
//

// time complexity: O(n)

#include <bits/stdc++.h>

#include <iostream>
#include <stack>

#define null nullptr

using namespace std;

vector<int> getNslIndexVector(vector<int> myArray, int n) {
  vector<int> myVector;
  stack<pair<int, int>> myStack;

  for (int i = 0; i < n; i++) {
    if (myStack.empty()) {
      myVector.push_back(-1);
    } else if (!myStack.empty() && myArray[i] > myStack.top().second) {
      myVector.push_back(myStack.top().first);
    } else if (!myStack.empty() && myArray[i] <= myStack.top().second) {
      while (!myStack.empty() && myArray[i] <= myStack.top().second) {
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

vector<int> getNsrIndexVector(vector<int> myArray, int n) {
  vector<int> myVector;
  stack<pair<int, int>> myStack;

  for (int i = n - 1; i >= 0; i--) {
    if (myStack.empty()) {
      myVector.push_back(n);
    } else if (!myStack.empty() && myArray[i] > myStack.top().second) {
      myVector.push_back(myStack.top().first);
    } else if (!myStack.empty() && myArray[i] <= myStack.top().second) {
      while (!myStack.empty() && myArray[i] <= myStack.top().second) {
        myStack.pop();
      }

      if (myStack.empty()) {
        myVector.push_back(n);
      } else {
        myVector.push_back(myStack.top().first);
      }
    }
    myStack.push(make_pair(i, myArray[i]));
  }

  reverse(myVector.begin(), myVector.end());

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

  vector<int> nslIndexVector = getNslIndexVector(myArray, myArray.size());
  vector<int> nsrIndexVector = getNsrIndexVector(myArray, myArray.size());

  vector<int> widthVector;
  for (int i = 0; i < total; i++) {
    widthVector.push_back(nsrIndexVector[i] - nslIndexVector[i] - 1);
  }

  vector<int> areaVector;
  for (int i = 0; i < total; i++) {
    areaVector.push_back(myArray[i] * widthVector[i]);
  }

  int maxArea = *max_element(areaVector.begin(), areaVector.end());

  cout << "max area under histogram: " << maxArea;

  return 0;
}