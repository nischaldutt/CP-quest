#include <bits/stdc++.h>
#include <string>
#include<stack>
#include <map>
#include <set>

#define null nullptr

using namespace std;

int main() {
  // map<int, vector<int>> m;
  // m[1].push_back(2);
  // m[1].push_back(3);
  // m[1].push_back(4);
  // m[2].push_back(6);

  // for(auto x : m) {
  //   cout<<x.second.front();
  // }

  // cout<<endl;
  
  // string str; 
  // getline(cin,str); 
  // cout << str.size() << endl; 

  // if(true) cout<<"here ";
  // else if(true) cout<<"here again ";
  // else cout<<"not true ";

  // set<int> mySet;
  // mySet.insert(1);
  // mySet.insert(2);
  // mySet.insert(3);
  // mySet.insert(4);
  // for(set<int>::const_iterator iter1 = mySet.begin(); iter1 != mySet.end(); ++iter1) {
  //   for(set<int>::const_iterator iter2 = iter1; ++iter2 != mySet.end();) {
  //     std::cout << *iter1 << " " << *iter2 << "\n"; 
  //   }
  // }

  // map<vector<int>, int> myMap;
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  cout<<arr.front();
  // myMap[arr] = 3;

  // for(auto arr: myMap) {
  //   vector<int> stack = arr.first;
  //   vector<int>::iterator itr = stack.begin();
  //   stack.erase(itr);
  //   for(auto ele: stack) {
  //     cout<<ele<<" ";
  //   }
  // }

  // stack<int> st;
  // st.push(3);
  // cout<<st.top();
  // //st.pop();
  // cout<<st.empty();
  return 0;
}