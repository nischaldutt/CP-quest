// diameter of a binary tree

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

int diameterOfBinaryTree(node* root, int& result) {
  if (root == null) return 0;

  int l = diameterOfBinaryTree(root->left, result);
  int r = diameterOfBinaryTree(root->right, result);

  int temp = 1 + max(l, r);
  int ans = max(temp, 1 + l + r);

  result = max(result, ans);

  return temp;
}

int main() {
  node* root;
  int result = INT_MIN;

  result = diameterOfBinaryTree(root, result);

  return result;
}