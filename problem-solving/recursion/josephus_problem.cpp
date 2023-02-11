// josephus problem

// input:
// enter n: 5
// enter k: 2
// enter elements: 1 2 3 4 5

// output: 3

#include <bits/stdc++.h>

#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

void josephusProblem(vector<int> myVector, int k, int startIndex, int &ans) {
  if (myVector.size() == 1) {
    ans = myVector[0];
    return;
  }

  int indexToKill = (startIndex + k) % myVector.size();
  myVector.erase(myVector.begin() + indexToKill);
  josephusProblem(myVector, k, indexToKill, ans);

  return;
}

int main() {
  int n, k, element;

  cout << "enter n: ";
  cin >> n;

  cout << "enter k: ";
  cin >> k;

  int startIndex = 0;
  int ans = -1;

  vector<int> myVector;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myVector.push_back(element);
  }

  josephusProblem(myVector, k - 1, startIndex, ans);

  cout << "result: " << ans;

  return 0;
}