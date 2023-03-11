/*

The code defines a class DoubleEndedQueue that represents a double-ended queue. The class has methods for checking if the queue is empty, getting the front element, enqueueing an element, dequeuing an element, and clearing the queue. The main function provides a menu of options for interacting with the queue and allows the user to choose an option to perform on the queue.
    
    */

#include <iostream>
using namespace std;

class DoubleEndedQueue {
    struct Node {
        int data;
        Node* next;
    };
    Node* front_;
    Node* rear_;
public:
    DoubleEndedQueue() {
        front_ = NULL;
        rear_ = NULL;
    }
    ~DoubleEndedQueue() {
        MakeNull();
    }
    bool IsEmpty() {
        if (front_ == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    void GetFront() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << front_->data << endl;
        }
    }
    void Enqueue(int value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = NULL;
        if (IsEmpty()) {
            front_ = new_node;
            rear_ = new_node;
        }
        else {
            rear_->next = new_node;
            rear_ = new_node;
        }
        cout << rear_->data << " added to the queue." << endl;
    }
    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            Node* temp = front_;
            front_ = front_->next;
            cout << temp->data << " is dequeued." << endl;
            delete temp;
        }
    }
    void MakeNull() {
        while (!IsEmpty()) {
            Dequeue();
        }
    }
};

void DisplayOptions() {
    cout << "0. Exit\n1. Get front element\n2. Enqueue\n3. Dequeue\n4. Make null\n";
}

int main() {
    DoubleEndedQueue queue;
    int num;
    int choice = 1;
    while (choice != 0) {
        DisplayOptions();
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            queue.GetFront();
            break;
        case 2:
            cout << "Enter value: ";
            cin >> num;
            queue.Enqueue(num);
            break;
        case 3:
            queue.Dequeue();
            break;
        case 4:
            queue.MakeNull();
            break;
        case 0:
            choice = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
