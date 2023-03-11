#include<iostream>
using namespace std;

struct node{
    string name;
    float reg;
    node *next;
    node *prev;
};
node *head=NULL;
node *tail=NULL;

void menu(){
    cout<<"0. Exit Program"<<endl<<"1. Add a student at start of list"<<endl;
    cout<<"2. Add a student at the end of list"<<endl<<"3. Add a student between the nodes"<<endl;
    cout<<"4. Show all students"<<endl<<"5. Find a student"<<endl<<"6. Remove a student"<<endl;
    cout<<"7. Remove all students"<<endl;
}
bool isEmpty(){
    if(head==NULL) return true;
    else return false;
}

void addAtStart(string name, int reg){
    node *newNode = new node;
    newNode->name= name;
    newNode->reg= reg;
    newNode->prev=NULL;
    newNode->next=head;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    head->prev=newNode;
    head=newNode;
}
void addAtEnd(string name, int reg){
    node *newNode = new node;
    newNode->name= name;
    newNode->reg= reg;
    newNode->next=NULL;
    newNode->prev=tail;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
void addAtSpecificPos(string name, int reg, int pos){
    node *newNode;
    newNode->name=name;
    newNode->reg=reg;
    node *temp;
    temp=head;
    for(int i=1; i<pos; i++ ){
        if(temp->next != NULL) {
             temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev=temp->prev;
    delete temp;
    }

}
void show() {
    if(isEmpty()){
        cout<<"No student found."<<endl;
    }else{
    node *temp= new node;
    temp=head;
    while(temp!=NULL){
        cout<<temp->name<<"  "<<temp->reg<<endl;
        temp=temp->next;
    }
    }
}

void find(string name){
    bool found=false;
    node *temp=head;
    while(temp!=NULL){
        if(name==temp->name){
            cout<<"Student is found in the list."<<endl;
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(!found){
        cout<<"Student not found."<<endl;
    }
    delete temp;
}

void remove(string name){
    bool found=false;
    node *temp=head;
    while(temp!=NULL){
        if(name==temp->name){
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(!found){
        cout<<"Student not found."<<endl;
    }
    if(temp==head){
        head=temp->next;
    }
    if(temp==tail){
        tail=temp->prev;
    }else{
    temp->prev=temp->next;
    }
    cout<<temp->name<<" removed."<<endl;
    delete temp;
}

void removeAll(){
    head=NULL;
    tail=NULL;
}
int main(){
    string name;
    int reg;
    int pos;
    int choice=1;
    while(choice!=0){
        menu();
    cout<<"Enter choice:";
    cin>>choice;
    switch (choice)
    {
    case 0:
        choice=0;

        break;    
    case 1:
        cout<<"Enter name of student: ";
        cin>>name;
        cout<<endl<<"Enter Student reg no: ";
        cin>>reg;
        addAtStart(name, reg);
        break;
    case 2:
        cout<<"Enter name of student: ";
        cin>>name;
        cout<<endl<<"Enter Student reg no: ";
        cin>>reg;
        addAtEnd(name, reg);
        break;
    case 3:
        cout<<"Enter name of student: ";
        cin>>name;
        cout<<endl<<"Enter Student reg no: ";
        cin>>reg;
        cout<<endl<<"Enter position at which you want to add: ";
        cin>>pos;
        addAtSpecificPos(name, reg,pos);
        break;   
    case 4:
        show();
        break;
    case 5:
        cout<<"Enter student name you want to find: ";
        cin>>name;
        find(name);
        break;
    case 6:
        cout<<"Enter student name you want to remove: ";
        cin>>name;
        remove(name);
        break;    
    case 7:
        removeAll();
    default:
        break;
    }
    }
    return 0;
}