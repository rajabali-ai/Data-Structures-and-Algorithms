/*

This is a C++ program that demonstrates how to sort a singly linked list of integers by rearranging the nodes so that all odd numbers come before even numbers.
    
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addNodeAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    if (head == NULL) {
        tail = newNode;
    }
    head = newNode;
}

void addNodeAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void displayNodes() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
}

void sortNodes() {
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
}

int main() {
    addNodeAtEnd(1);
    addNodeAtEnd(2);
    addNodeAtEnd(3);
    addNodeAtEnd(4);
    addNodeAtEnd(5);
    addNodeAtEnd(6);
    addNodeAtEnd(7);
    addNodeAtEnd(8);

    cout << "Nodes before sorting: ";
    displayNodes();

    sortNodes();

    cout << "Nodes after sorting: ";
    displayNodes();

    return 0;
}
