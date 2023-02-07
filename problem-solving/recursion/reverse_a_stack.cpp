// reverse a stack in O(1) space

// input:
// enter n: 5
// enter elements: 1 2 3 4 5

// output: 1 2 3 4 5

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

void insert(stack<int> &myStack, int element) {
  if (myStack.empty()) {
    myStack.push(element);
    return;
  }

  int temp = myStack.top();
  myStack.pop();
  insert(myStack, element);
  myStack.push(temp);

  return;
}

void reverse(stack<int> &myStack) {
  if (myStack.size() == 1) return;

  int temp = myStack.top();
  myStack.pop();
  reverse(myStack);
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

  reverse(myStack);

  while (!myStack.empty()) {
    cout << myStack.top() << "  ";
    myStack.pop();
  }

  return 0;
}