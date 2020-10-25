#include <bits/stdc++.h>
#define null nullptr

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node *head1, *head2;

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

bool compareLinkedLists(Node* head1, Node* head2) {
    Node *a = head1;
    Node *b = head2;

    while(a != null && b!= null && a->data == b->data) {
        a = a->link;
        b = b->link;
    }
    return a == b;
}

int main() {
    head1 = null;
    head2 = null;
    int t,n,m,x;
    cin>>t;
    while(t--) {
        cin>>n;
        while(n--) {
            cin>>x;
            head1 = insert_node_at_tail(head1, x);
        }

        cin>>m;
        while(m--) {
            cin>>x;
            head2 = insert_node_at_tail(head2, x);
        }

        bool result = compareLinkedLists(head1, head2);
        cout<<result<<endl;
    }
    return 0;
}