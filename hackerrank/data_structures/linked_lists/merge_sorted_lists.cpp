#include <bits/stdc++.h>
#include <set>
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

void printLinkedList(Node* head) {
    cout<<"printing"<<endl;
    Node* temp = head;
    while(temp != null) {
        cout<<temp->data<<endl;
        temp = temp->link;
    }
    return;
}

Node* merge_sorted_lists(Node* list1, Node* list2) {
    if (list1 == null) return list2;
    else if (list2 == null) return list1;

    Node* combined = null;
    if((list1->data) <= (list2->data)) {
        combined = list1;
        list1->link = merge_sorted_lists(list1->link, list2);
    }
    else {
        combined = list2;
        list2->link = merge_sorted_lists(list1, list2->link);
    }
    return combined;
}

int find_merge_node(Node* head1, Node* head2) {
    Node* temp = head1;
    set<Node*> s;

    while(temp != null) {
        s.insert(temp);
        temp = temp->link;
    }

    temp = head2;
    while(temp != null) {
        if(s.find(temp) != s.end()) {
            return temp->data;    
        }
        s.insert(temp);
        temp = temp->link;
    }
    return 0;
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
        // head1 = merge_sorted_lists(head1, head2);
        // printLinkedList(head1);

        // int res = find_merge_node(head1, head2);
        // cout<<res<<endl;
    }
    return 0;
}