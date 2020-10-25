#include<bits/stdc++.h>
#define null nullptr

using namespace std;

void solution(vector<int> a, vector<int> b, int x) {
  int sum = 0, i = 0, j = 0, count = 0;
  int n = a.size();
  int m = b.size();

  while(sum + a[i] <= x && i < n) {
    sum += a[i];
    i++;
  }
  count = i;

  while(i >= 0 && j < m) {
    sum += b[j];
    j++;

    while(sum > x && i > 0) {
      i--;
      sum -= a[i];
    }

    if(sum <= x && i + j > count) {
      count = i + j;
    }
  }
  cout<<count<<endl;
  return;
}

int main() {
  int g;
  cin>>g;
  while(g--) {
    int n, m, x, num;
    cin>>n>>m>>x;
    vector<int> a, b;
    while(n--) {
      cin>>num;
      a.push_back(num);
    }
    while(m--) {
      cin>>num;
      b.push_back(num);
    }
    solution(a, b, x);
  }
  return 0;
}