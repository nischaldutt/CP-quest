#include <bits/stdc++.h>
#include <string>
#include <stack>
#define null nullptr

using namespace std;

int main() {
  int q, n;
  string s;
  stack<string> myStack;
  cin>>q;
  while(q--) {
    cin>>n;
    if(n == 1) {
      string str;
      cin>>str;
      myStack.push(s); 
      s += str;
    }
    else if(n == 2) {
      int k;
      cin>>k;
      myStack.push(s);
      s.erase(s.size() - k);
    }
    else if(n == 3) {
      int k;
      cin>>k;
      cout<<s[k-1]<<endl;
    }
    else {
      s = myStack.top();
      myStack.pop();
    }
  }
  return 0;
}