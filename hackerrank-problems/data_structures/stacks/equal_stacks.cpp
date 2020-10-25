#include<bits/stdc++.h>
#include<math.h>
#include<map>

using namespace std;

int getHeight(vector<int> arr) {
  int height = 0;
  for(auto element: arr) {
    height += element;
  }
  return height;
}

int equalStacks(vector<int> stack1, vector<int> stack2, vector<int> stack3) {
  int n1 = stack1.size();
  int n2 = stack2.size();
  int n3 = stack3.size();

  int h1 = getHeight(stack1);
  int h2 = getHeight(stack2);
  int h3 = getHeight(stack3);

  int top1 = 0, top2 = 0, top3 = 0;

  while(1) {
    // if any tree is empty return zero
    if(h1 == top1 || h2 == top2 || h3 == top3) 
      return 0;
    // if all 3 heights are same return height
    if(h1 == h2 && h2 == h3) 
      return h1;
    // if stack1 has max height, remove top and update new height
    if(h1 >= h2 && h1 >= h3) 
      h1 -= stack1[top1++];
    // if stack2 has max height, remove top and update new height
    else if(h2 >= h1 && h2 >= h3) 
      h2 -= stack2[top2++];
    // if stack3 has max height, remove top and update new height
    else if(h3 >= h2 && h3 >= h1) 
      h3 -= stack3[top3++];
  }
  return 0;
}

int main() {
  int n1, n2, n3, val;
  cin>>n1>>n2>>n3;
  vector<int> stack1, stack2, stack3;
  while(n1--) {
    cin>>val;
    stack1.push_back(val); 
  }

  while(n2--) {
    cin>>val;
    stack2.push_back(val); 
  }

  while(n3--) {
    cin>>val;
    stack3.push_back(val); 
  }
  
  int maxHeight = equalStacks(stack1, stack2, stack3);

  cout<<maxHeight;
}