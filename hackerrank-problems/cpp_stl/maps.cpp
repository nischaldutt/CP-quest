#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int q, t, y, sum = 0;
  string x;
  map<string, int> m;
  map<string, int>::iterator key;
  cin >> q;
  while (q--) {
    cin >> t >> x;
    switch (t) {
    case 1:
      cin >> y;
      key = m.find(x);
      if (key != m.end()) {
        sum = y + m[x];
        cout << "#### sum = " << sum << endl;
        m[x] = sum;
      }
      else {
        cout << "new element" << endl;
        m.insert(make_pair(x, y));
      }
      cout << "#### Case 1 ####" << endl;
      for (key = m.begin(); key != m.end(); key++) {
        cout << "\t" << key->first << "\t" << key->second;
      }

      break;

    case 2:
      sum = 0;
      m[x] = sum;
      cout << "#### Case 2 ####" << endl;
      for (key = m.begin(); key != m.end(); key++) {
        cout << "\t" << key->first << "\t" << key->second;
      }
      break;

    case 3:
      cout << m[x] << endl;
      cout << "#### Case 3 ####" << endl;
      for (key = m.begin(); key != m.end(); key++) {
        cout << "\t" << key->first << "\t" << key->second;
      }
      break;
    }
  }
  return 0;
}
