// Minimum element of stack
// Time complexity: O(n)

#include <bits/stdc++.h>

#include <stack>
#define null nullptr

using namespace std;

stack<int> myStack, myMinStack;

void push(int element) {
  if (myStack.empty()) {
    myStack.push(element);
    myMinStack.push(element);
    return;
  }

  if (myMinStack.top() > element) {
    myMinStack.push(element);
  }
  myStack.push(element);
  return;
}

void pop() {
  if (myStack.empty()) return;

  if (myMinStack.top() == myStack.top()) {
    myMinStack.pop();
  }
  myStack.pop();
  return;
}

int getMinElement() {
  return myMinStack.empty() ? -1 : myMinStack.top();
}

int main() {
  int n, element;

  cin >> n;
  while (n--) {
    cin >> element;
    push(element);
  }
  cout << getMinElement();
  cout << endl;
  pop();
  pop();
  pop();
  pop();
  cout << getMinElement();
  return 0;
}