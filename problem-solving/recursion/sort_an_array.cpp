// sort an array using recursion

// input:
// enter n: 4
// enter elements: 1 5 0 2

// output: 0 1 2 5

#include <bits/stdc++.h>

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

void insert(vector<int> &myVector, int temp) {
  if (!myVector.size() || myVector[myVector.size() - 1] <= temp) {
    myVector.push_back(temp);
    return;
  }

  int val = myVector[myVector.size() - 1];
  myVector.pop_back();
  insert(myVector, temp);
  myVector.push_back(val);

  return;
}

void recursiveSort(vector<int> &myVector) {
  if (myVector.size() == 1) return;

  int temp = myVector[myVector.size() - 1];
  myVector.pop_back();
  recursiveSort(myVector);
  insert(myVector, temp);

  return;
}

int main() {
  int n, element;

  cout << "enter n: ";
  cin >> n;

  vector<int> myVector;

  cout << "enter elements: ";
  fori {
    cin >> element;
    myVector.push_back(element);
  }

  recursiveSort(myVector);

  for (int x : myVector) {
    cout << x << "  ";
  }

  return 0;
}