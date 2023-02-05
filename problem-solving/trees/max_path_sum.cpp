// maximum path sum: from one node to another

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

struct node {
  int data;
  struct node* left;
  struct node* right;
};

int maxPathSum(node* root, int& result) {
  if (root == null) return 0;

  int l = maxPathSum(root->left, result);
  int r = maxPathSum(root->right, result);

  int temp = max(root->data + max(l, r), root->data);
  int ans = max(temp, root->data + l + r);

  result = max(result, ans);

  return temp;
}

int main() {
  node* root;
  int result = INT_MIN;

  result = maxPathSum(root, result);

  return result;
}