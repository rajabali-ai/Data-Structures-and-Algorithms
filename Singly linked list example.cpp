#include<iostream>

using namespace std;

class linkedlist{
int data;
linkedlist *next;
static linkedlist *head;

public:

void addatmiddle(int w){
int length;

linkedlist *ptr=head;

linkedlist *middle=new linkedlist;
middle->data=w;
while(ptr!=NULL){
ptr=ptr->next;
length++;	
}

ptr=head;
length=length/2;
length--;


while(length!=0){

	ptr=ptr->next;
	length--;
	}
linkedlist *temp;
temp=ptr->next;

middle->next=temp;
ptr->next=middle;


}
static bool search(int x){
    linkedlist *temp=head;
    while( temp!=NULL){
        if(temp->data==x){
           cout<<"\nITEM FOUND ";
		    return true;
            
        }
        temp=temp->next;
    }
    
    cout<<"\n not found ";
    return false;
}

static void deletelinked(int x){
linkedlist *ptrprev,*ptr=head;
while( ptr!=NULL){
    ptrprev=ptr;
    ptr=ptr->next;
	if(ptr->data==x){
		break;
	}
    }
if(ptr==NULL){
  
  
 return;
}if(ptr==head){
head=ptr->next;
}else{
  ptrprev->next=ptr->next;
    
}
delete ptr;
cout<<"\nITEM FOUND AND SUCESSFULLY DELETED \n\n";

}



 void addathead(int x){

    linkedlist *newptr = new linkedlist;
    newptr->data=x;
    newptr->next=head;
    head= newptr;
}
 void addattail(int x){

linkedlist *newptr= new linkedlist ;
linkedlist *temp=head;
newptr->data=x;
newptr->next=NULL;
if(head==NULL){
    newptr=head;
    return;

}
else
while(temp->next!=NULL){
    temp=temp->next;

}
temp->next=newptr;
}

void display(){
    linkedlist *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

};
linkedlist* linkedlist::head=NULL; 

int main(){

    linkedlist n;
  
int x;
   do{
        cout<<"\nWHICH OPERARION YOU WANT TO PERFORM \n1 ADD AT HEAD \n2 ADD AT TAIL \n3 ADD NODE AT MIDDLE \n4 DISPLAY \n5 SEARCH\n6 DELETE SPECIFIC NODE \n ";
      cin>>x;
      if(x==1){
      	int y;
      	cout<<"\nENTER VALUE WHICH YOU WANT TO ADD AT HEAD\n";
      		cin >>y;
          n.addathead(y);
      }  
      else if(x==2){
      	int y;
      	cout<<"\nENTER VALUE WHICH YOU WANT TO ADD AT TAIL\n";
		  cin >>y;
          n.addattail(y);
      }  
      else if(x==3){
      	int y;
      	cout<<"\nENTER VALUE WHICH YOU WANT TO ADD AT MIDDLE\n";
		  cin>>y;
         n.addatmiddle(y);
       
    }  else if(x==4){
    	cout<<"\nDISPLAYING ..............\n";
    	
          n.display();

      }else if(x==5){
          int z;
          cout<<"ENTER ELEMENT YOU WANT TO SEARCH";
          cin>>z;
      	n.search(z);

			}

      else if(x==6){
      	int y;
      	cout<<"\nENTER VALUE WHICH YOU WANT TO DELETE\n";
		cin>>y;
      	n.deletelinked(y);
	  }
      else{
         break;
		 
      }
      
    } while(1);
    return 0;
}
