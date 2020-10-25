#include<bits/stdc++.h>
#include<stack>

using namespace std;

string isBalanced(string str) {
  stack<char> arr;
  for(int i=0; str[i]!='\0'; i++) {
    if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
      arr.push(str[i]);
    }
    else {
      if(!arr.empty()) {
        if(str[i] == '}') {
          if('{' == arr.top()) {
            arr.pop();
          }
          else {
            return "NO";
          }
        }
        if(str[i] == ']') {
          if('[' == arr.top()) {
            arr.pop();
          }
          else {
            return "NO";
          }
        }
        if(str[i] == ')') {
          if('(' == arr.top()) {
            arr.pop();
          }
          else {
            return "NO";
          }
        }
      }
      else return "NO";
    }
  }
  return (arr.empty()) ? "YES" : "NO";
}

int main() {
  int n;
  string str;
  cin>>n;
  while(n--) {
    cin>>str;
    cout<<isBalanced(str)<<endl;
  }
  return 0;
}