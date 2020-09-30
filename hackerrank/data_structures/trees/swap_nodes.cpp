#include <bits/stdc++.h>
#include <vector>
#include <queue>

#define null nullptr

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* root;

Node* createNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = null;
  newNode->right = null;
  return newNode;
}

Node* makeBinaryTree(vector<vector<int>> indexes) {
  Node* root = createNode(1);
  queue<Node*> myQueue;
  Node* curr = root;
  myQueue.push(curr);

  int inLength = indexes.size();
  for(int itr=0;itr<inLength;itr++) {
    int a = indexes[itr][0];
    int b = indexes[itr][1];

    curr = myQueue.front();
    if(a != -1) {
      Node* newNode = createNode(a);
      myQueue.push(newNode);
      curr->left = newNode;
    }
    if(b != -1) {
      Node* newNode = createNode(b);
      myQueue.push(newNode);
      curr->right = newNode;
    }
    myQueue.pop();
  }
  return root;
}

vector<int> inOrder(Node* root, vector<int> &result) {
  Node* curr = root;
  if(!curr) return result;
  if(curr->left) inOrder(curr->left, result);
  result.push_back(curr->data);
  // cout<<curr->data<<" ";
  if(curr->right) inOrder(curr->right, result);
  return result;
}

void swapOperation(Node* parent) {
  Node* temp = parent->left;
  parent->left = parent->right;
  parent->right = temp;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
  Node* root = makeBinaryTree(indexes);
  Node* parent = root;
  int length = queries.size(), k;
  vector<vector<int>> result(length);
  
  for(int itr=0;itr<length;itr++) {
    k = queries[itr];

    queue<Node*> myQueue;
    int level = 0;
    int nodeCount = 0; // count of total nodes in a particular level of a tree

    parent = root;
    myQueue.push(parent);
    parent = myQueue.front();

    while(!myQueue.empty()) {
      level++;
      nodeCount = myQueue.size();
      while(nodeCount--) {
        if(level % k == 0) swapOperation(parent);
        if(parent->left) myQueue.push(parent->left);
        if(parent->right) myQueue.push(parent->right);
        myQueue.pop();
        parent = myQueue.front();
      }
    }
    vector<int> arr;
    result[itr] = inOrder(root, arr);
  }
  return result;
}

int main() {
  root = null;
  int n, a, b, t, k;
  cin>>n;
  vector<vector<int>> indexes(n);

  for(int itr=0;itr<n;itr++) {
    cin>>a>>b;
    indexes[itr].push_back(a);
    indexes[itr].push_back(b);
  }

  cin>>t;
  vector<int> queries;
  while(t--) {
    cin>>k;
    queries.push_back(k);
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for(auto arr : result) {
    auto arrLength = arr.size();
    for(auto element : arr) {
      cout<<element<<" ";
    }
    cout<<endl;
  }
  return 0;
}