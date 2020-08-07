#include <bits/stdc++.h>
#include <unordered_set>
#define null nullptr

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* head;

Node* create_node(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->link = null;
    return new_node;
}

Node* insert_node(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->link = head;
    head = new_node;
    return head;
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

Node* insertNodeAtPosition(Node* head, int data, int pos) {
    Node* new_node = create_node(data);
    Node* temp = head;

    if(pos == 0) {
        return insert_node(head, data);
    }

    for(int i=0;i<=(pos-2);i++) {
        temp = temp->link;
    }
    new_node->link = temp->link;
    temp->link = new_node;
    return head;
}

Node* deleteNode(Node* head, int pos) {
    Node* temp = head;

    if(pos == 0) {
        return head = temp->link;
    }

    for(int i=0;i<=(pos-2);i++) {
        temp = temp->link;
    }
    Node* node = temp->link;
    temp->link = temp->link->link;
    free(node);
    return head;
}

Node* reverseListIterative(Node* head) {
    Node *current, *previous, *next;
    previous = null;
    current = head;

    while(current != null) {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}

Node* reverseListRecursive(Node* head) {
    Node* a = head;
    if(a->link == null) {
        head = a;
        return head;
    }
    head = reverseListRecursive(a->link);
    Node* b = a->link;
    b->link = a;
    a->link = null;
    return head;
}

bool has_cycle(Node* head) {
    unordered_set<Node*> unset;
    Node* temp = head;
    while(temp != null) {
        if(unset.find(temp->link) != unset.end()) {
            return true;
        }
        else {
            unset.insert(temp->link);
            temp = temp->link;
        }
    }
    return false;
}

bool floyd_pointers(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;

        if(fast == slow) return true;
    }
    return false;
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

void reversePrint(Node* head) {
    Node* temp = head;
    if(temp == null) {
        return;
    }
    reversePrint(temp->link);
    cout<<temp->data<<endl;
    return;
}

int main() {
    head = null;
    int n,x,pos;
    cin>>n;
    while(n--) {
        cin>>x;
        // head = insert_node(x);
        head = insert_node_at_tail(head, x);
    }
    printLinkedList(head);

    // cin>>x>>pos;
    // head = insertNodeAtPosition(head, x, pos);

    // cin>>pos;
    // head = deleteNode(head, pos);
    // printLinkedList(head);
    
    // cout<<"printing in reverse ==> "<<endl;
    // reversePrint(head);

    // cout<<"list reversed iteratively ==> "<<endl;
    // head = reverseListIterative(head);
    // printLinkedList(head);

    cout<<"list reversed recursively ==> "<<endl;
    head = reverseListRecursive(head);
    printLinkedList(head);
    
    return 0;
}