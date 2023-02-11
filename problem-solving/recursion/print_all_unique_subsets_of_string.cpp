// print all unique subsets of given string

// input:
// enter string: aab

// output:  a b aa ab aab

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

void printAllSubsets(string input, string output, set<string> &mySet) {
  if (input == "") {
    mySet.insert(output);
    return;
  }

  string output1 = output;
  string output2 = output;
  output2.push_back(input[0]);
  input.erase(input.begin() + 0);

  printAllSubsets(input, output1, mySet);
  printAllSubsets(input, output2, mySet);

  return;
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  set<string> mySet;

  printAllSubsets(myString, "", mySet);

  for (string x : mySet) cout << x << " ";

  return 0;
}