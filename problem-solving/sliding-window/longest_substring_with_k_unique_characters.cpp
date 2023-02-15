// longest substring with k unique characters

// input:
// enter string: aabacbebebe
// enter k: 3

// output:
// length of longest sub-string with k unique characters: 7

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

int lengthOfLongestSubStringWithKUniqueChars(string myString, int k) {
  int n = myString.length();
  int result = INT_MIN + 1;
  unordered_map<char, int> myMap;
  int i = 0, j = 0;

  while (j < n) {
    myMap[myString[j]]++;

    if (myMap.size() < k) {
      j++;
    }

    if (myMap.size() == k) {
      int currentWindowSize = j - i + 1;
      result = max(currentWindowSize, result);
      j++;
    }

    if (myMap.size() > k) {
      while (myMap.size() > k) {
        myMap[myString[i]]--;
        if (myMap[myString[i]] == 0) {
          myMap.erase(myString[i]);
        }
        i++;
      }
      j++;
    }
  }

  return result;
}

int main() {
  string myString;
  int k;

  cout << "enter string: ";
  cin >> myString;

  cout << "enter k: ";
  cin >> k;

  int result = lengthOfLongestSubStringWithKUniqueChars(myString, k);
  cout << "length of longest sub-string with k unique characters: " << result;

  return 0;
}