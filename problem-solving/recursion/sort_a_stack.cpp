// sort a stack using recursion

// input:
// enter n: 4
// enter elements: 1 5 0 2

// output: 5 2 1 0

// space-complexity: O(1)

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

void insert(stack<int> &myStack, int temp) {
  if (!myStack.size() || myStack.top() <= temp) {
    myStack.push(temp);
    return;
  }

  int val = myStack.top();
  myStack.pop();
  insert(myStack, temp);
  myStack.push(val);

  return;
}

void recursiveSort(stack<int> &myStack) {
  if (myStack.size() == 1) return;

  int temp = myStack.top();
  myStack.pop();
  recursiveSort(myStack);
  insert(myStack, temp);

  return;
}

int main() {
  int n, element;

  cout << "enter n: ";
  cin >> n;

  stack<int> myStack;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myStack.push(element);
  }

  recursiveSort(myStack);

  while (!myStack.empty()) {
    cout << myStack.top() << "  ";
    myStack.pop();
  }

  return 0;
}