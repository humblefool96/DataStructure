#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

void traverse(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node* insertBegin(Node *head, int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

void insertEnd(Node *head, int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

void insertAfter(Node *pos, int data) {
    if (pos == NULL) {
        cout << "previous node does not exist" << "\n";
    }
    Node *temp = new Node();
    temp->data = data;
    temp->next = pos->next;
    pos->next = temp;
}

Node* deleteNode (Node *head, int key) {
    Node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    prev->next = temp->next;
    free(temp); 
    return head;
}
//1 2 3 4 5
Node* reverse (Node *head) {
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr != NULL) {
        //store next
        next = curr->next;
        //reverse pointer
        curr->next = prev;
        //move pointers one position ahead
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    head = new Node();
    second = new Node();
    third = new Node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data  = 3;
    third->next = NULL;

    //traverse linked list
    traverse(head);
    //insert in beginning, end and at specified position
    head = insertBegin(head, 6);
    traverse(head);
    insertEnd(head, 8);
    traverse(head);
    insertAfter(head->next, 9);
    traverse(head);
    head = deleteNode(head, 6);
    traverse(head);
    head = reverse(head);
    traverse(head);

    return 0;
}