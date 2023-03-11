/* 
    CS221 Assignment 01
    2020154 Hamza Mehmood
    2020408 Rajab Ali
    
    
   This code is implementing a linked list data structure in C++ using a class named linkedList. It contains a nested node structure to represent the nodes of the linked list. The linkedList class has member functions to add a new node at the tail of the linked list (addAtTail), display the linked list (display), and arrange the nodes such that all odd numbered nodes are placed before even numbered nodes (arrangeOddEven).

The main function creates an object of linkedList class and adds new nodes to the list based on user input. Then it displays the nodes before and after the arrangement.



*/    
#include<iostream>
using namespace std;

class linkedList{
    struct node{
        int data;
        node *next;
        node(){next=NULL;}
    };
    node *head;
    node *tail;
    public:
    linkedList(){
        head=NULL; 
        tail=NULL;
    }
    void addAtTail(int value){
        node *ptrNew = new node, *ptrTemp=head;
	    ptrNew->data = value;
	    ptrNew -> next = NULL;
        if (head == NULL)
        {
            head = ptrNew;
            return;
        }
        while (ptrTemp->next!=NULL)
            ptrTemp=ptrTemp->next;
        ptrTemp->next= ptrNew;	

    }
    void dispaly(){
        if(head==NULL){
            cout<<"No nodes found.";
        }
        node *temp=head;
        while( temp!= NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        delete temp;
    }

    
    void arrangeOddEven(){
        if(head==NULL || head->next==NULL ){
            cout<<"Add at least two nodes to sort!";
            return;
        }
        if(head->next->next==NULL){
            node *temp=head->next;
            head->next=NULL;
            temp->next=head;
            head=temp;
            return;
        }
        node *even = head->next;
        node *odd=head;
        node *oddHead=odd;
        head=even;
        while(even!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd = even->next;
            even->next=odd->next;
            if(even->next!=NULL){
                even=odd->next;
            }
            
        }
        odd->next=NULL;
        even->next=oddHead;
    }    
};


int main(){
    linkedList list;
    int value,choice=1;
    while(choice==1){
        cout<<"Enter value: ";
        cin>>value;
        list.addAtTail(value);
        cout<<"Press 1 to enter more value: ";
        cin>>choice;
    }
    cout<<"Nodes before arrangement: ";
    list.dispaly();
    cout<<"Nodes after arrangement: ";
    list.arrangeOddEven();
    list.dispaly();
    

    return 0;
}