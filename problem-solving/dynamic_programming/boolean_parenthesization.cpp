// boolean parenthesization problem

// input:
// enter string: T^F&T

// output:
// number of ways we can parenthesize the exp so that it evaluates to true: 2

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

int booleanParenthesization(string myString, int i, int j, bool isTrue) {
  int result = 0;

  if (i > j) return 0;

  if (i == j) {
    if (isTrue)
      return true;
    else
      return false;
  }

  string temp = std::to_string(i);
  temp.push_back('_');
  temp.push_back(j);
  temp.push_back('_');
  temp.push_back(isTrue);

  if (myMap.find(temp) != myMap.end()) return myMap[temp];

  for (int k = i + 1; k < j; k = k + 2) {
    int lt = booleanParenthesization(myString, i, k - 1, true);
    int rt = booleanParenthesization(myString, k + 1, j, true);
    int lf = booleanParenthesization(myString, i, k - 1, false);
    int rf = booleanParenthesization(myString, k + 1, j, false);

    if (myString[k] == '&') {
      if (isTrue) {
        result += lt * rt;
      } else {
        result += (lt * rf) + (lf * rt) + (lf * rf);
      }
    }

    if (myString[k] == '|') {
      if (isTrue) {
        result += (lt * rt) + (lt * rf) + (lf * rt);
      } else {
        result += (lf * rf);
      }
    }

    if (myString[k] == '^') {
      if (isTrue) {
        result += (lt * rt) + (lf * rf);
      } else {
        result += (lt * rf) + (lf * rt);
      }
    }
  }

  myMap[temp] = result;

  return myMap[temp];
}

int main() {
  string myString;

  cout << "enter string: ";
  cin >> myString;

  int count = booleanParenthesization(myString, 0, myString.length() - 1, true);

  cout << "number of ways we can parenthesize the exp so that it evaluates to true: " << count;

  return 0;
}