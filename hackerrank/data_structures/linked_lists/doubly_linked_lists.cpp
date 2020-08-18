#include <bits/stdc++.h>
#define null nullptr

using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;
};

Node *head;

Node *createNode(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->prev = null;
  temp->next = null;
  return temp;
}

Node *insert(Node *head, int data) {
  Node *new_node = createNode(data);
  if (head == null) {
    return new_node;
  }
  Node *temp = head;
  while (temp->next != null) {
    temp = temp->next;
  }
  temp->next = new_node;
  temp->next->prev = temp;
  return head;
}

Node *reverse(Node *head) {
  Node *temp = head;
  Node *link;
  while (temp->next != null) {
    link = temp->next;
    temp->next = temp->prev;
    temp->prev = link;
    temp = link;
  }
  head = temp;
  temp->next = temp->prev;
  temp->prev = null;
  return head;
}

Node *sorted_insert(Node *head, int data) {
  Node *new_node = createNode(data);
  if (head == null) return head = new_node;

  if (new_node->data <= head->data) {
    head->prev = new_node;
    new_node->next = head;
    return head = new_node;
  }

  Node *temp = head;
  while (temp->next != null) {
    if (new_node->data <= temp->next->data) {
      new_node->prev = temp;
      new_node->next = temp->next;
      temp->next = new_node;
      temp->next->next->prev = temp->next->prev;
      return head;
    }
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
  return head;
}

void printList(Node *head) {
  Node *temp = head;
  while (temp != null) {
    cout << temp->data << endl;
    temp = temp->next;
  }
  return;
}

int main() {
  head = null;
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    while (n--) {
      cin >> x;
      head = insert(head, x);
    }
    // head = reverse(head);
    // printList(head);
    cin >> x;
    head = sorted_insert(head, x);
    printList(head);
  }
  return 0;
}