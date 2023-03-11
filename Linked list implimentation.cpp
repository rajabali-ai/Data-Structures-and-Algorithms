
/*This code implements a linked list data structure and allows the user to add nodes to the list, sort the list by name or registration number, display the contents of the list, or exit the program.

The node struct defines the structure of each node in the linked list, which contains a name (string), registration number (int), and a pointer to the next node in the list.

The head pointer points to the first node in the list, and is initialized to NULL.

The addAtHead function creates a new node with the given name and registration number, and inserts it at the beginning of the list.

The InsertionSortByName function sorts the list by name using an insertion sort algorithm. The algorithm works by comparing each node with every other node in the list, and swapping nodes if they are out of order.

The insertionSortByReg function sorts the list by registration number in a similar way to InsertionSortByName, but compares and swaps nodes based on their registration numbers instead of their names.

The options function displays a menu of options for the user to choose from.

The display function iterates through the linked list and displays the name and registration number of each node.

The main function repeatedly displays the menu of options, reads the user's choice, and calls the appropriate function based on the choice. It exits the program when the user selects the "Exit" option.
*/


#include<iostream>
using namespace std;

struct node{
    string name;
    int reg;
    node *next; 
};

node *head=NULL;

void addAtHead(string name, int reg){

    node *newNode = new node;
    newNode->name= name;
    newNode->reg= reg;
    newNode->next=head;
    if(head==NULL){
        head=newNode;
        return;
    }
    head=newNode;
}

void InsertionSortByName(){
    if(head == NULL){
        cout<<"No list found.\n";
        return;
    }
    node* temp, *temp2;
    temp = head->next;
    temp2 = head;
    while(temp!=NULL){
        temp2 = head;
        while(temp2!=NULL){
            if(temp2->name > temp->name){
                string name;
                int reg;
                name = temp->name;              
                reg = temp->reg;
                temp->name = temp2->name;       
                temp->reg = temp2->reg;
                temp2->name = name;             
                temp2->reg = reg;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void insertionSortByReg(){
    if(head == NULL){
        cout<<"No list found.\n";
        return;
    }
    node* temp, *temp2;
    temp = head->next;
    temp2 = head;
    while(temp!=NULL){
        temp2 = head;
        while(temp2!=NULL){
            if(temp2->reg > temp->reg){
                string name;
                int reg;
                name = temp->name;
                reg = temp->reg;
                temp->name = temp2->name;       
                temp->reg = temp2->reg;
                temp2->name = name;             
                temp2->reg = reg;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}



void options(){
    cout<<"1. Emter entry in list \n 2. Sort by name \n 3. Sort by reg number \n 4. Display \n 5. Exit \n";
}

void display(){
    if(head==NULL){
        cout<<"No list found. \n";
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->name<<"\t"<<temp->reg<<"\t"<<endl;
        temp=temp->next;
    }
    
}    
    

int main(){
    string name;
    int reg;
    int choice=1;
    while(choice!=5){
        options();
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter reg: ";
            cin>>reg;
            addAtHead(name, reg);
            break;
        case 2:
            InsertionSortByName();
            break;
        case 3:
            insertionSortByReg();
            break;  
        case 4:
            display();
            break;  
        case 5:
            choice=5;        
        default:
            choice=5;
            break;
        }
    }

    return 0;
}