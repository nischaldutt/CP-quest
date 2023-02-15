// count all occurances of anagrams of given query string

// input:
// enter string: aabaabaa
// enter query string: aaba

// output:
// total anagram count: 4

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

int anagramCount(string myString, string str) {
  unordered_map<char, int> myMap;
  int n = myString.size();

  for (int i = 0; i < str.length(); i++)
    myMap[str[i]]++;

  int count = myMap.size();
  int windowSize = str.size();
  int result = 0;

  int i = 0, j = 0;

  while (j < n) {
    if (myMap.find(myString[j]) != myMap.end()) {
      myMap[myString[j]]--;

      if (myMap[myString[j]] == 0) {
        count--;
      }
    }

    int currentWindowSize = j - i + 1;

    if (currentWindowSize < windowSize) {
      j++;
    } else if (currentWindowSize == windowSize) {
      if (count == 0) {
        result++;
      }

      if (myMap.find(myString[i]) != myMap.end()) {
        myMap[myString[i]]++;

        if (myMap[myString[i]] == 1) {
          count++;
        }
      }

      i++;
      j++;
    }
  }

  return result;
}

int main() {
  string myString, str;

  cout << "enter the string: ";
  cin >> myString;

  cout << "enter query string: ";
  cin >> str;

  int result = anagramCount(myString, str);
  cout << "total anagram count: " << result;

  return 0;
}