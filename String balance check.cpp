/*
This is a C++ program that checks whether a string containing brackets, parentheses, and curly braces is balanced or not.

The program defines a queue class using a linked list implementation with a node structure that stores a character and a pointer to the next node. The queue class has member functions for push, pop, showPop, and print.

The isBalanced function takes a string input and uses a queue to check if the brackets in the string are balanced. It iterates through the string, pushing opening brackets onto the queue. Then it iterates through the string again from the end, popping brackets from the queue and checking if they match the corresponding closing brackets in the string. If a mismatch is found or the queue is empty before all brackets are matched, the function returns false. If all brackets are matched and the queue is empty at the end, the function returns true.

The main function repeatedly prompts the user to enter a string and calls the isBalanced function to check if the string is balanced or not. The program exits when the user enters "0".
*/

#include <iostream>
using namespace std;

class queue{
    struct node{
    char data;
    node* next;
    node():next(NULL), data('\0'){}
    };
    node* front;
    node* rear;
    public:
    queue():front(NULL),rear(NULL){}
    ~queue(){
    node* temp;
    temp = front;
    while(front!=NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
    }
    void push(char data){
    node* temp;
    temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(rear == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    }
    void pop(){
    node* temp;
    temp = front;
    if(front==NULL){
        cout<<"\nQUEUE IS EMPTY\n";
    }
    else{
        front = temp->next;
        delete temp;
    }
    }
    char showPop(){
    node* temp;
    temp = front;
    if(front == NULL)
        return '\0';
    return temp->data;
    }
    void print(){
    node* temp;
    temp = front;
    cout<<"\n[EXIT] ";
    while(temp!=NULL){
        cout<<" <-- "<<temp->data;
        temp = temp->next;
    }
    cout<<'\n';
    }
};

bool isBalanced(string data){
    queue q;
    int len;
    char ch;
    len = data.length();
    for(int i=0; i<len; i++){
        if (data[i] == '(' || data[i] == '['
            || data[i] == '{'){

            q.push(data[i]);
            continue;
        }

    }

    for(int i=len-1; i>=0; i--){
        if(data[i] == ')' || data[i] == ']'
            || data[i] == '}'){

            ch = q.showPop();
            

            if(ch == '\0')
                return false;
            if(data[i] == ')'){
                if(ch != '(')
                    return false;
            }
            else if(data[i] == ']'){
                if(ch != '[')
                    return false;
            }
            else{
                if(ch != '{')
                    return false;
            }
            q.pop();
        }
    }
    ch = q.showPop();
    if(ch != '\0')
        return false;
    return true;
}

int main(){   
    string data;
    int len;
    bool flag;
    while(true){
        cout<<"\n\nENTER STRING (EXIT=0): ";
        cin>>data;
        flag = isBalanced(data);
        if(flag){
            cout<<"BALANCED";
        }
        else{
            cout<<"NOT BALANCED";
        }
        if(data == "0"){
            break;
        }
    }
}
