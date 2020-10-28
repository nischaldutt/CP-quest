// Minimum element of stack
// Reference: https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
// Time complexity: O(n)

#include <bits/stdc++.h>
#include <stack>
#define null nullptr

using namespace std;

stack<int> stackA, stackB;

void push(int num) {
  if(stackA.empty()) {
    stackA.push(num);
    stackB.push(num);
    return;
  }
  if(num > stackB.top()) {
    stackA.push(num);
  }
  else {
    stackA.push(num);
    stackB.push(num);
  }
  return;
}

void pop() {
  if(stackA.empty()) return;
  if(stackA.top() == stackB.top()) {
    stackA.pop();
    stackB.pop();
  }
  else {
    stackA.pop();
  }
  return;
}

int getMinElement() {
  return stackB.empty() ? -1 : stackB.top();
}

int main() {
  int n, element;
  cin>>n;
  while(n--) {
    cin>>element;
    push(element);
  }
  cout<<getMinElement();
  cout<<endl;
  pop(); pop(); pop(); pop();
  cout<<getMinElement();
  return 0;
}