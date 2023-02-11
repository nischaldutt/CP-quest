// generate balanced parenthesis

// input:
// enter n: 2

// output: ()() (())

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

void generateAllBalancedParenthesis(int open, int close, string output, vector<string> &myVector) {
  if (open == 0 && close == 0) {
    myVector.push_back(output);
    return;
  }

  if (open != 0) {
    string output1 = output;
    output1.push_back('(');
    generateAllBalancedParenthesis(open - 1, close, output1, myVector);
  }

  if (close > open) {
    string output2 = output;
    output2.push_back(')');
    generateAllBalancedParenthesis(open, close - 1, output2, myVector);
  }

  return;
}

int main() {
  int n;

  cout << "enter n: ";
  cin >> n;

  int open = n;
  int close = n;
  string output = "";

  vector<string> myVector;

  generateAllBalancedParenthesis(open, close, output, myVector);

  for (string x : myVector) cout << x << "  ";

  return 0;
}