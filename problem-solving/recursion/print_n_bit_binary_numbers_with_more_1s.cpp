// print n-bit binary numbers having more 1's than 0's for any prefix

// input:
// enter n: 1

// output: 111 110 101

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

void printBinaryNumbers(int one, int zero, int n, string output, vector<string> &myVector) {
  if (one + zero == n) {
    myVector.push_back(output);
    return;
  }

  string output1 = output;
  output1.push_back('1');
  printBinaryNumbers(one + 1, zero, n, output1, myVector);

  if (zero < one) {
    string output2 = output;
    output2.push_back('0');
    printBinaryNumbers(one, zero + 1, n, output2, myVector);
  }

  return;
}

int main() {
  int n;

  cout << "enter n: ";
  cin >> n;

  int one = 0;
  int zero = 0;

  vector<string> myVector;

  printBinaryNumbers(one, zero, n, "", myVector);

  for (string x : myVector) cout << x << "  ";

  return 0;
}