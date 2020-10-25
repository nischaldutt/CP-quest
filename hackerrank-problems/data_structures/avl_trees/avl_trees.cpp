#include<bits/stdc++.h>
#include<math.h>

#define null nullptr

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  int height;
};

Node* root;

Node* createNode(int value) {
  Node* newNode = new Node();
  newNode->val = value;
  newNode->left = null;
  newNode->right = null;
  newNode->height = 0;
  return newNode;
}

int getHeight(Node* root) {
  if(!root) return -1;
  return root->height;
}

int getBalanceFactor(Node* root) {
  if(!root) return 0;
  return getHeight(root->left) - getHeight(root->right);
}

Node* rotateright(Node* x) {
  Node* y = x->left;
  Node* T = y->right;

  // right rotation
  y->right = x;
  x->left = T;

  // calculate updated height of Nodes
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node* rotateLeft(Node* x) {
  Node* y = x->right;
  Node* T = y->left;

  // left rotation
  y->left = x;
  x->right = T;

  // calculate updated height of Nodes
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node* insert(Node* root, int value) {
  if(!root) return createNode(value);

  if(root->val > value) 
    root->left = insert(root->left, value);
  else 
    root->right = insert(root->right, value);

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int balanceFactor = getBalanceFactor(root);

  // Left Left Imbalance
  if(balanceFactor > 1 && root->left->val > value) {
    return rotateright(root);
  }

  // Left right Imbalance
  if(balanceFactor > 1 && root->left->val < value) {
    root->left = rotateLeft(root->left);
    return rotateright(root);
  }

  // right Left Imbalance
  if(balanceFactor < -1 && root->right->val > value) {
    root->right = rotateright(root->right);
    return rotateLeft(root);
  }

  // right right Imbalance
  if(balanceFactor < -1 && root->right->val < value) {
    return rotateLeft(root);
  }

  return root;
}

void inOrder(Node* root) {
  if(!root) return;
  inOrder(root->left);
  cout<<root->val<<" ";
  inOrder(root->right);
  return;
}

int main() {
  Node* root = null;
  int n, value;
  cin>>n;
  while(n--) {
    cin>>value;
    root = insert(root, value);
  }
  inOrder(root);
}