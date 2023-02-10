// Letter Case Permutation

// input:
// enter string: a1b2

// output: a1b2 a1B2 A1b2 A1B2

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

void letterCasePermutations(string input, string output, vector<string> &myVector) {
  if (input == "") {
    cout << output << " ";
    return;
  }

  if (isalpha(input[0])) {
    string output1 = output;
    string output2 = output;

    output1.push_back(tolower(input[0]));
    output2.push_back(toupper(input[0]));
    input.erase(input.begin() + 0);

    letterCasePermutations(input, output1, myVector);
    letterCasePermutations(input, output2, myVector);
  } else {
    string output1 = output;

    output1.push_back(input[0]);
    input.erase(input.begin() + 0);
    letterCasePermutations(input, output1, myVector);
  }

  return;
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  vector<string> myVector;

  letterCasePermutations(myString, "", myVector);

  return 0;
}