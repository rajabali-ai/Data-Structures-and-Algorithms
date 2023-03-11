#include<iostream>
using namespace std;

class stack{
    struct node
    {
        int data;
        node *next;
    }*top;
    
    public:
    stack(){
        top=NULL;       
    }
    bool isEmpty(){
        if(top == NULL) return true;
        else return false;
    }
    void push(int value){
            node *newNode= new node;
            newNode->data=value;
            newNode->next=top;
            top=newNode;
            cout<<top->data<<" Pushed."<<endl;
        }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
            return;
        }else{
            node *temp;
            temp=top;
            top=top->next;
            cout<<temp->data<<" poped."<<endl;
            delete temp;
        }
    }
};

void options(){
    cout<<"0. Exit \n 1. push \n 2. pop \n ";
}

int main(){
    stack Dstack;
    int num;
    int choice=1;
    while(choice!=0){
        options();
    cout<<"Enter choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter number: ";
        cin>>num;
        Dstack.push(num);
        break;
    case 2:
        Dstack.pop();
        break;
    case 0:
        choice=0;
        break;
    default:
        break;
    }
    }
    return 0;
}