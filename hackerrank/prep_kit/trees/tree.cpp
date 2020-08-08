#include <bits/stdc++.h>
#include <string.h>
#include <map>
#include <queue>

#define null nullptr

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
      data = value;
      left = null;
      right = null;
    }
};

class Solution {
  public: 
    Node* insert(Node* root, int data) {
      if(!root) return new Node(data);

      if(data <= root->data) 
        root->left = insert(root->left, data);
      else 
        root->right = insert(root->right, data);
      return root;
    }

    void preOrder(Node* root) {
      if(!root) return;
      Node* current = root;
      if(current) {
        std::cout<<current->data<<" ";
        preOrder(current->left);
        preOrder(current->right);
      }
      return;
    }

    int height(Node* root) {
      return (root) ? 
      (std::max(height(root->left) + 1, height(root->right) + 1)) : (-1);
    }

    void levelOrder(Node* root) {
      if(!root) return;
      std::queue<Node*> myqueue;
      myqueue.push(root);
      while(!myqueue.empty()) {
        if(root->left) myqueue.push(root->left);
        if(root->right) myqueue.push(root->right);
        std::cout<<myqueue.front()->data<<" ";
        myqueue.pop();
        root = myqueue.front();
      }
      return;
    }

    void topView(Node* root) {
      if(!root) return;
      int hd = 0;
      std::queue<std::pair<Node*, int>> myqueue;
      std::map<int, std::vector<int>> m;

      myqueue.push(std::make_pair(root, hd));
      while(!myqueue.empty()) {
        root = myqueue.front().first;
        hd = myqueue.front().second;

        m[hd].push_back(root->data);
        if(root->left) 
          myqueue.push(std::make_pair(root->left, hd-1));
        if(root->right) 
          myqueue.push(std::make_pair(root->right, hd+1));

        myqueue.pop();
      }

      for(auto x : m) {
        std::cout<<x.second.front()<<" ";
      }
    }

    bool is_leaf(Node* root) {
      return (!root->left && !root->right) ? true : false;
    }

    void decode_huff(Node* root, std::string s) {
      if(!root) return;
      std::string decoded_str;
      Node* curr = root;
      int strlen = s.size();

      for(int i=0;i<strlen;i++) {
        if(s[i] == '0') curr = curr->left;
        else curr = curr->right;
        if(is_leaf(curr)) {
          decoded_str.push_back(curr->data);
          curr = root;
        }
      }
      std::cout<<decoded_str;
    }

    Node* lca(Node* root, int v1, int v2) {
      if(v1 > v2) {
        int temp = v1;
        v1 = v2;
        v2 = temp;
      }

      if(!root) return null;
      if(root->data >= v1 && root->data <= v2) return root;
      else {
        if(root->data <= v1 && root->right) 
          root = lca(root->right, v1, v2);
        else if(root->data >= v2 && root->left) 
          root = lca(root->left, v1, v2);
        else return null;
      }
      return root;
    }

    bool isBST(Node* root) {
      static Node *prev = null;   
      if (root) { 
        if (!isBST(root->left)) return false; 
        if (prev != NULL && root->data <= prev->data) return false;
        prev = root;
        return isBST(root->right);  
      }
      return true;  
    }
};

int main() {
  Solution myTree;
  Node* root = null;
  int t, n, x;
  std::cin>>t;
  while(t--) {
    std::cin>>x;
    root = myTree.insert(root, x);
  }
  // myTree.preOrder(root);

  // std::cout<<"height == "<<myTree.height(root)<<std::endl;

  // myTree.levelOrder(root);

  // myTree.topView(root);

  bool res = myTree.isBST(root);
  (res) ? std::cout<<"yes" : std::cout<<"no";
  return 0;
}