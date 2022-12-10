// Minimum element of stack
// Time complexity: O(1)

#include <bits/stdc++.h>

#include <stack>
#define null nullptr

using namespace std;

stack<int> myStack;
int minValue = 0;

void push(int element) {
  if (myStack.empty()) {
    myStack.push(element);
    minValue = element;
    return;
  }

  if (element > minValue) {
    myStack.push(element);
  } else {
    myStack.push((2 * element) - minValue);
    minValue = element;
  }

  return;
}

void pop() {
  if (myStack.empty()) return;
  if (myStack.top() < minValue) {
    minValue = (2 * minValue) - myStack.top();
  }

  myStack.pop();
  return;
}

int top() {
  if (myStack.empty()) return -1;
  if (myStack.top() < minValue) {
    return minValue;
  } else {
    return myStack.top();
  }
}

int getMinElement() {
  return (myStack.empty()) ? -1 : minValue;
}

int main() {
  int n, element;
  cin >> n;
  while (n--) {
    cin >> element;
    push(element);
  }

  cout << top() << endl;
  cout << getMinElement() << endl;
  pop();
  cout << top() << endl;
  cout << getMinElement() << endl;
  return 0;
}