#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node* previous;
    Node(int v){
        value=v;
        next=NULL;
        previous=NULL;
    }
};

void insertFirstElement(Node* &Head,Node* &Back,int v)
{
    Node* element=new Node(v);
    Head=element;
    Back=element;
}
void insertAtHead(Node* &Head,Node* &Back,int v)
{
    if (Head==NULL && Back==NULL){
        insertFirstElement(Head,Back,v);
    }else if(Head==Back){
        Node* temp=new Node(v);
        temp->next=Head;
        Head->previous=temp;
        Head->next=temp;
        temp->previous=Head;
        Head=temp;
    }else{
        Node* temp=new Node(v);
        temp->previous=Back;
        Head->previous=temp;
        temp->next=Head;
        Back->next=temp;
        Head=temp;
    }
}
void insertAtTail(Node* &Head,Node* &Back,int v)
{
    if (Head==NULL && Back==NULL){
        insertFirstElement(Head,Back,v);
    }else if(Head==Back){
        Node* temp=new Node(v);
        temp->next=Head;
        Head->previous=temp;
        Head->next=temp;
        temp->previous=Head;
        Head=temp;
    }else{
        Node* temp=new Node(v);
        temp->next=Head;
        temp->previous=Back;
        Back->next=temp;
        Head->previous=temp;
        Back=temp;
    }
}
void insertAtKthPosition(Node* &Head,Node* &Back, int k, int v)
{
    int lenLL=1;
    if(k!=0 || k!=1){
    Node* temp1=Head;
    while (temp1->next!=Head){
        lenLL++;
        temp1=temp1->next;
    }
    k=k%lenLL;}
    Node* iter=Head;
    if (Head==NULL && k==1){
        insertFirstElement(Head,Back,v);
    }
    else if (Head==Back && k==2){
        Node* temp=new Node(v);
        temp->next=Head;
        Head->previous=temp;
        Head->next=temp;
        temp->previous=Head;
        Head=temp;
    }else if (k==1){
        insertAtHead(Head,Back,v);
    }else{
        for(int i=1;i<k-1;i++){
            iter=iter->next;
        }
        if (iter->next==Head){
            insertAtTail(Head,Back,v);
        }
        else{
            Node* element=new Node(v);
            element->next=iter->next;
            element->previous=iter;
            iter->next->previous=element;
            iter->next=element;
        }
    }
}

void deleteHead(Node* &Head,Node* Back)
{
    Head->next->previous=Back;
    Head->previous->next=Head->next;
    Head=Head->next;
} 
void deleteTail(Node* Head,Node* &Back)
{
    Back->previous->next=Head;
    Back->next->previous=Back->previous;
    Back=Back->previous;
}
void deleteKthPosition(Node* &Head,Node* Back,int k)
{
    int lenLL=1;
    if(k!=0 || k!=1){
    Node* temp1=Head;
    while (temp1->next!=Head){
        lenLL++;
        temp1=temp1->next;
    }
    k=k%lenLL;}
    if (k==1){
        deleteHead(Head,Back);
    }else{
        Node* iter=Head;
        for(int i=1;i<k-1;i++){
            iter=iter->next;
        }
        iter->next=iter->next->next;
        iter->next->next->previous=iter;
    }
}

void display(Node* Head,int k)
{
    Node* temp=Head;
    for(int i=1;i<=k;i++){
        cout<<" -> "<<temp->value;
        temp=temp->next;
    }
    cout<<endl;
}
void displayKthTillk_1(Node* Head,Node* Back,int k)
{
    int listElementCounter=1;
    Node* iter=Head;
    int counter=1;
    while (iter->next!=Head)
    {
        iter=iter->next;
        listElementCounter++;
        counter++;
        if (counter>=k){
            cout<<" -> "<<iter->value;
        }

    }
    iter=Head;
    counter=0;           //Watch again before exam.
    while (counter<k-1){
        cout<<" -> "<<iter->value;
        counter++;
        iter=iter->next;
    }
    cout<<endl;
}
int main(){
    Node* Head=NULL;
    Node* Back=NULL;
    int j;
    for(int i=0;i<10;i++){
        insertAtHead(Head,Back,i);
    }
    // for(int i=0;i<10;i++){
        // insertAtTail(Head,Back,i+20);
    // }
    display(Head,20);
    displayKthTillk_1(Head,Back,4);
    insertAtKthPosition(Head,Back,21,69);
    display(Head,30);
    deleteHead(Head,Back);
    deleteTail(Head,Back);
    deleteKthPosition(Head,Back,23);
    display(Head,60);
}