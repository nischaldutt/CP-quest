#include <bits/stdc++.h>
#include <stack>
#include <vector>
#define null nullptr;

using namespace std;

vector<int> getSievePrimes(int min, int max) {
  vector<int> primes;
  vector<int> list(max + 1, 0);
  list[0] = 0;
  list[1] = 0;
  
  for(int i = 2; i <= sqrt(max) ; i++) {
    for(int j = i + 1; j <= max; j++) {
      if(list[j] == 0) {
        if(j % i == 0) list[j] = 1;
      }
    }
  }

  for(int i = 2; i <= max; i++) {
    if(list[i] == 0) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  vector<int> primes = getSievePrimes(1, 10000);
  stack<int> myStack;
  int n, t, element;
  cin>>n>>t;
  while(n--) {
    cin>>element;
    myStack.push(element);
  }

  stack<int> stackB;
  for(int q = 1; q <= t; q++) {
    stack<int> stackA;
    while(!myStack.empty()) {
      if(myStack.top() % primes[q-1] == 0) {
        stackB.push(myStack.top());
        myStack.pop();
      }
      else {
        stackA.push(myStack.top());
        myStack.pop();
      }
    }
    
    while(!stackB.empty()) {
      cout<<stackB.top()<<endl;
      stackB.pop();
    }

    if(q == t) {
      while(!stackA.empty()) {
        cout<<stackA.top()<<endl;
        stackA.pop();
      }
      return 0;
    }
    
    myStack = stackA;
  }
  return 0;
}