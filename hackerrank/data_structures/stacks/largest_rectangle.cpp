#include<bits/stdc++.h>
#define null nullptr

using namespace std;

int main() {
  vector<int> mySet;
  int n;
  cin>>n;
  while(n--) {
    int height;
    cin>>height;
    mySet.push_back(height);
  }
  sort(mySet.begin(), mySet.end());

  int maxArea = 0;
  int length = mySet.size();
  for(auto element: mySet) {
    int area = length * element;
    if(maxArea <= area) {
      maxArea = area;
    }
    length--;
  }
  cout<<maxArea;
  return 0;
}