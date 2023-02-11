// delete mid element of a stack in O(1) space

// input:
// enter n: 5
// enter elements: 1 2 3 4 5

// output: 5 4 2 1

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

void deleteMidOfStack(stack<int> &myStack, int k) {
  if (k == 1) {
    myStack.pop();
    return;
  }

  int temp = myStack.top();
  myStack.pop();
  deleteMidOfStack(myStack, k - 1);
  myStack.push(temp);

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

  int mid = (myStack.size() / 2) + 1;

  deleteMidOfStack(myStack, mid);

  while (!myStack.empty()) {
    cout << myStack.top() << "  ";
    myStack.pop();
  }

  return 0;
}