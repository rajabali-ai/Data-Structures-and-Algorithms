#include<iostream>
using namespace std;

struct stack_node{
    string name;
    int reg;
    stack_node *next;
}*top=NULL;

bool isEmpty(){
    if(top==NULL) return true;
    else return false;

}
void push(string name, int reg){
    stack_node *newptr = new stack_node;
    newptr->name= name;
    newptr->reg= reg;
    newptr->next=top;
    top=newptr;
}
void pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    stack_node *temp=top;
    top=top->next;
    delete temp;
}
void showTop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<endl<<"Top"<<endl<<"Name: "<<top->name<<endl<<"Reg: "<<top->reg<<endl;
}
void print() {
    if(isEmpty()){
        cout<<endl<<"Stack is empty"<<endl;
        return;
    }
    stack_node *temp;
    temp=top;
    while(temp!=NULL){
        cout<<temp->name<<"  "<<temp->reg<<endl;
        temp=temp->next;
    }
}



void option(){
    cout<<endl<<"1. Exit"<<endl<<"2. Push"<<endl<<"3. POP"<<endl<<"4. Show Top"<<endl<<"5. Display whole stack"<<endl;

}
int main(){
    string student;
    int reg;
    int choice=1;
    while(choice!=0){
        option();
    cout<<"Enter choice:";
    cin>>choice;
    switch (choice)
    {
    case 1:
        choice=0;
        break;    
    case 2:
        cout<<"Enter name of student";
        cin>>student;
        cout<<endl<<"Enter student reg";
        cin>>reg;
        push(student, reg);
        break;
    case 3:
        pop();
        break;
    case 4:
        showTop();
        break;
    case 5:
        print();
        break;
    default:
        break;
    }
    }
    return 0;
}