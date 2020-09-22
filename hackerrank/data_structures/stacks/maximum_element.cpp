#include<bits/stdc++.h>
#include<stack>

using namespace std;

int main() {
  int n, type, x;
  stack<int> arr;
  cin>>n;
  while(n--) {
    cin>>type;
    switch(type) {
      case 1: {
        cin>>x;
        if(arr.empty()) 
          arr.push(x);
        else 
          arr.push(max(x,arr.top()));
        break;
      }
      
      case 2: {
        if(!arr.empty()) {
          arr.pop();
        }
        break;
      }

      case 3: {
        cout<<arr.top()<<endl;
        break;
      }
    }
  }
  return 0;
}