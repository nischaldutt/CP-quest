// Permutation with Spaces

// input:
// enter string: ABC

// output: ABC AB_C A_BC A_B_C

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

void permutationWithSpaces(string input, string output) {
  if (input == "") {
    cout << output << " ";
    return;
  }

  string output1 = output;
  string output2 = output;

  output1.push_back(input[0]);
  output2.push_back('_');
  output2.push_back(input[0]);
  input.erase(input.begin() + 0);

  permutationWithSpaces(input, output1);
  permutationWithSpaces(input, output2);

  return;
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  string input = "";
  string output = "";

  output.push_back(myString[0]);
  myString.erase(myString.begin() + 0);

  permutationWithSpaces(myString, output);

  return 0;
}