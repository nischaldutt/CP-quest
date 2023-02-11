// print the kth symbol in grammar

// input 1:
// enter n: 4
// enter k: 3

// output 1: 1

// input 2:
// enter n: 4
// enter k: 1

// output 2: 0

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

int kthSymbolInGrammar(int n, int k) {
  if (n == 1 && k == 1) return 0;

  int mid = pow(2, n - 1) / 2;

  if (k <= mid) {
    return kthSymbolInGrammar(n - 1, k);
  } else {
    return !kthSymbolInGrammar(n - 1, k - mid);
  }
}

int main() {
  int n, k;

  cout << "enter n: ";
  cin >> n;

  cout << "enter k: ";
  cin >> k;

  int result = kthSymbolInGrammar(n, k);

  cout << "kth symbol in grammar: " << result;

  return 0;
}