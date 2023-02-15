// length of minimum window substring

// input 1:
// enter string: totmtaptat
// enter query string: tta

// output 1:
// length minimum window substring: 3 (tat)

// input 2:
// enter string: adobecodebanc
// enter query string: abc

// output 2:
// length minimum window substring: 4 (banc)

// input 3:
// enter string: a
// enter query string: a

// output 3:
// length minimum window substring: 1 (a)

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

int minWindowSubstring(string myString, string str) {
  int n = myString.length();
  int result = INT_MAX - 1;
  unordered_map<char, int> myMap;
  int i = 0, j = 0;

  for (int i = 0; i < str.length(); i++) {
    myMap[str[i]]++;
  }

  int count = myMap.size();

  while (j < n) {
    if (myMap.find(myString[j]) != myMap.end()) {
      myMap[myString[j]]--;
      if (myMap[myString[j]] == 0) {
        count--;
      }
    }
    j++;

    if (count == 0) {
      while (count == 0) {
        if (myMap.find(myString[i]) != myMap.end()) {
          myMap[myString[i]]++;
          if (myMap[myString[i]] > 0) {
            count++;
          }
        }
        i++;
      }

      result = min(result, j - i + 1);
    }
  }

  return result;
}

int main() {
  string myString, str;

  cout << "enter string: ";
  cin >> myString;

  cout << "enter query string: ";
  cin >> str;

  int result = minWindowSubstring(myString, str);
  cout << "length minimum window substring: " << result;

  return 0;
}