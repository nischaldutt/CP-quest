// print all subsets/power set of given string

// input:
// enter string: abc

// output:  a b c ab bc ca abc

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

void printAllSubsets(string input, string output) {
  if (input == "") {
    cout << output << " ";
    return;
  }

  string output1 = output;
  string output2 = output;
  output2.push_back(input[0]);
  input.erase(input.begin() + 0);

  printAllSubsets(input, output1);
  printAllSubsets(input, output2);

  return;
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  printAllSubsets(myString, "");

  return 0;
}