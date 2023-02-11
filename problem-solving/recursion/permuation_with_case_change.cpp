// Permutation with case changes

// input:
// enter string: ab

// output: ab aB Ab AB

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

void permutationWithCaseChanges(string input, string output) {
  if (input == "") {
    cout << output << " ";
    return;
  }

  string output1 = output;
  string output2 = output;

  output1.push_back(tolower(input[0]));
  output2.push_back(toupper(input[0]));
  input.erase(input.begin() + 0);

  permutationWithCaseChanges(input, output1);
  permutationWithCaseChanges(input, output2);

  return;
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  permutationWithCaseChanges(myString, "");

  return 0;
}