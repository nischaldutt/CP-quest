// scrambled string problem

// input 1:
// enter string a: great
// enter string b: eatgr

// output 1:
// given pair of strings scrambled: true

// input 2:
// enter string a: abcde
// enter string b: caebd

// output 2:
// given pair of strings scrambled: false

// bottom-up recursive memoized solution

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

unordered_map<string, int> myMap;

bool isScrambledString(string a, string b) {
  if (a.length() != b.length()) return false;
  if (a.empty() && b.empty()) return true;

  bool isScrambled = false;
  int n = a.length();

  if (a == b) return true;
  if (n <= 1) return false;

  string key = a;
  key.push_back('_');
  key.append(b);

  if (myMap.find(key) != myMap.end()) return myMap[key];

  for (int i = 1; i < n; i++) {
    if ((isScrambledString(a.substr(0, i), b.substr(n - i, i)) && isScrambledString(a.substr(i, n - i), b.substr(0, n - i))) ||
        (isScrambledString(a.substr(0, i), b.substr(0, i)) && isScrambledString(a.substr(i, n - i), b.substr(i, n - i)))) {
      isScrambled = true;
      break;
    }
  }

  myMap[key] = isScrambled;

  return myMap[key];
}

int main() {
  string a, b;

  cout << "enter string a: ";
  cin >> a;

  cout << "enter string b: ";
  cin >> b;

  string result = isScrambledString(a, b) ? "true" : "false";

  cout << "given pair of strings scrambled: " << result;

  return 0;
}