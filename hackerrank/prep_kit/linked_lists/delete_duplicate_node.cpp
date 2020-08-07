#include <bits/stdc++.h>
#define null nullptr

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node *head;

Node* create_node(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->link = null;
    return new_node;
}

Node* insert_node_at_tail(Node* head, int data) {
    Node* new_node = create_node(data);
    if(head == null) {
        head = new_node;
        return head;
    }

    Node* temp = head;
    while(temp->link != null) {
        temp = temp->link;
    }
    temp->link = new_node;
    return head;
}

void printLinkedList(Node* head) {
    cout<<"printing"<<endl;
    Node* temp = head;
    while(temp != null) {
        cout<<temp->data<<endl;
        temp = temp->link;
    }
    return;
}

Node* delete_duplicate_node(Node* head) {
    Node* current = head;

    while(current->link != null) {
        if(current->data != current->link->data) {
            current = current->link;
        }
        else {
            current->link = current->link->link;
            delete current->link;
        }
    }
    return head;
}

int main() {
    head = null;
    int t,n,x;

    cin>>t;
    while(t--) {
        cin>>n;
        while(n--) {
            cin>>x;
            head = insert_node_at_tail(head, x);
        }
        head = delete_duplicate_node(head);
        printLinkedList(head);
    }
    return 0;
}