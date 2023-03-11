/*


This code implements a singly linked list to store students' names and registration numbers. The program allows the user to insert new nodes, display the list, sort the list by registration number, sort the list by name, and exit the program.

The node struct represents each node in the linked list, with a name field to store the student's name, a reg field to store the registration number, and a next field to point to the next node in the list.

The list class represents the linked list itself, with a head pointer to the first node in the list. The insert method adds a new node to the beginning of the list with the given name and registration number. The print method displays the list in its current order. The sortReg and sortName methods sort the list by registration number and name, respectively, using a simple bubble sort algorithm. Finally, the swap method is a helper method used by the sort methods to swap the contents of two nodes.

In the main function, the user is first prompted to enter the total number of nodes they want to enter, and then prompted to enter the name and registration number for each node. After all nodes are entered, the program enters a loop where the user is prompted to select an option (insert, display, sort by reg, sort by name, or exit) until they choose to exit.

/*


#include <iostream>
using namespace std;

struct node{
    string name;
    int reg;
    node* next;

    node(): next(NULL){}
};

class list{
    node* head;

    public:
    list() : head(NULL){}
    ~list();
    void insert(string, int);
    void sortName();
    void sortReg();
    void print();
    void swap(node*&, node*&);
};
int main(){
    list l;
    int option;
    string name;
    int reg;
    bool loop = true;
    int totalNodes=0;
    cout<<"ENTER TOTAL NODES YOU WANT TO ENTER: ";
    cin>>totalNodes;
    for(int i=0; i<totalNodes; i++){
        cout<<"\nSTUDENT # "<<i+1<<endl;
        cout<<"ENTER NAME "<<endl;
        cin>>name;
        cout<<"ENTER REG "<<endl;
        cin>>reg; 
        l.insert(name, reg);
    }
    cout<<"\n1. INSERT" 
            <<"\n2. DISPLAY"
            <<"\n3. SORT BY REG"
            <<"\n4. SORT BY NAME"
            <<"\n5. EXIT\n"; 

    while(loop){
        cout<<"\nENTER YOUR OPTION: ";
        cin>>option;   
        switch(option){
            case 1:
                cout<<"ENTER NAME "<<endl;
                cin>>name;
                cout<<"ENTER REG "<<endl;
                cin>>reg; 
                l.insert(name, reg);
                break;
            case 2:
                l.print();
                break;
            case 3:
                l.sortReg();
                break;
            case 4:
                l.sortName();
                break;
            case 5:
                loop = false;
                break;
            default:
                cout<<"\nWRONG INPUT\n";
        }
    }
}

list::~list(){
    node* temp;
    temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}

void list::insert(string name, int reg){
    node* temp;
    temp = new node;
    temp->name = name;
    temp->reg = reg;
    temp->next = head;
    head = temp;
}

void list::swap(node* &temp, node* &temp2){
    string name;
    int reg;

    name = temp->name;              reg = temp->reg;
    temp->name = temp2->name;       temp->reg = temp2->reg;
    temp2->name = name;             temp2->reg = reg;
}

void list::sortReg(){
    node* temp, *temp2;
    temp = head->next;
    temp2 = head;
    while(temp!=NULL){
        //backwards compare
        temp2 = head;
        while(temp2!=NULL){
            if(temp2->reg > temp->reg){
                swap(temp, temp2);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void list::sortName(){
    node* temp, *temp2;
    temp = head->next;
    temp2 = head;
    while(temp!=NULL){
        //backwards compare
        temp2 = head;
        while(temp2!=NULL){
            if(temp2->name > temp->name){
                swap(temp, temp2);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void list::print(){
    node* temp;
    temp = head;
    while(temp!=NULL){
        cout<<"\nNAME: "<<temp->name<<"\tREG: "<<temp->reg;
        temp = temp->next;
    }
}