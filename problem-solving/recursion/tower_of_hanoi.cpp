// tower of hanoi

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

void towerOfHanoi(char sourceTower, char destTower, char helperTower, int n) {
  if (n == 0) return;

  towerOfHanoi(sourceTower, helperTower, destTower, n - 1);
  cout << "Move disk " << n << " from tower " << sourceTower << " to tower " << destTower << endl;
  towerOfHanoi(helperTower, destTower, sourceTower, n - 1);
}

int main() {
  int n;

  cout << "enter n: ";
  cin >> n;

  towerOfHanoi('A', 'C', 'B', n);

  return 0;
}