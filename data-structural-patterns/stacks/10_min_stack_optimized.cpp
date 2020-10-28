// Minimum element of stack (Optimized*)
// Reference: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
// Time complexity: O(1)
// We maintain a global variable which keeps track of minimum element,
// When a number smaller than the current minimum is enter then we store the 
// corrupted value by applying (2 * [element to be inserted]) - minValue
// This is way can get minimum value in O(1) time.

#include <bits/stdc++.h>
#include <stack>
#define null nullptr

using namespace std;

stack<int> myStack;
int minValue = 0;

void push(int num) {
  if(myStack.empty()) {
    myStack.push(num);
    minValue = num;
    return;
  }
  if(num < minValue) {
    myStack.push((2 * num) - minValue);
    minValue = num;
  }
  else {
    myStack.push(num);
  }
  return;
}

void pop() {
  if(myStack.empty()) return;
  if(myStack.top() < minValue) {
    minValue = (2 * minValue) - myStack.top();
    myStack.pop();
  }
  else {
    myStack.pop();
  }
  return;
}

int top() {
  if(myStack.empty()) return -1;
  if(myStack.top() < minValue) {
    return minValue;
  }
  else {
    return myStack.top();
  }
}

int getMinElement() {
  return (myStack.empty()) ? -1 : minValue;
}

int main() {
  int n, element;
  cin>>n;
  while(n--) {
    cin>>element;
    push(element);
  }
  cout<<top()<<endl;
  cout<<getMinElement()<<endl;
  pop();
  cout<<top()<<endl;
  cout<<getMinElement()<<endl;
}