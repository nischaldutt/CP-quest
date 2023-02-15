// longest substring with unique characters

// input:
// enter string: pwwkew

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

int lengthOfLongestSubStringWithUniqueChars(string myString) {
  int n = myString.length();
  int result = INT_MIN + 1;
  unordered_map<char, int> myMap;
  int i = 0, j = 0;

  while (j < n) {
    myMap[myString[j]]++;

    if (myMap.size() == (j - i + 1)) {
      result = max((j - i + 1), result);
      j++;
    } else if (myMap.size() < (j - i + 1)) {
      while (myMap.size() < (j - i + 1)) {
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

  cout << "enter string: ";
  cin >> myString;

  int result = lengthOfLongestSubStringWithUniqueChars(myString);
  cout << "length of longest sub-string with k unique characters: " << result;

  return 0;
}