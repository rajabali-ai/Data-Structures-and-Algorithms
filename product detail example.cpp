#include<iostream>
using namespace std;

struct node{
    string name;
    float price;
    node *next;
}*head=NULL;

void menu(){
    cout<<"1. Add node"<<endl<<"2. Display list"<<endl<<"3. Delete node"<<endl<<"4. Exit"<<endl;

}
void input(string item_name, float price){
    node *newptr = new node;
    newptr->name= item_name;
    newptr->price= price;
    newptr->next=head;
    head=newptr;
}
void print(node *head) {
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->name<<"  "<<temp->price<<endl;
        temp=temp->next;
    }
}

void delete_node(){
    node *prev;
    node *curr=head;
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
    }
    delete curr;
    prev->next=NULL;

}
int main(){
    string product;
    float price;
    int choice=1;
    while(choice!=0){
        menu();
    cout<<"Enter choice:";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter name of product";
        cin>>product;
        cout<<endl<<"Enter product Price";
        cin>>price;
        input(product, price);
        break;
    case 2:
        print(head);
        break;
    case 3:
        delete_node();
        break;
    case 4:
        choice=0;

        break;
    default:

        break;
    }

    }
   
    return 0;
}