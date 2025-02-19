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
    Node* temp=new Node(v);
    Head=temp;
    Back=temp;
}
void insertAtHead(Node* &Head,Node* &Back,int j)
{
    if (Head==NULL){
        insertFirstElement(Head,Back,j);
    }else{
    Node* temp=new Node(j);
    temp->next=Head;
    Head->previous=temp;
    Head=temp;
    }
}
void insertAtTail(Node* &Head,Node* &Back, int j)
{
    if (Back==NULL){
        insertFirstElement(Head,Back,j);
    }else{
        Node* temp=new Node(j);
        temp->previous=Back;
        Back->next=temp;
        Back=temp;
    }
}
void insertAtKthPosition(Node* &Head,Node* &Back,int k,int j)
{
    if (Head==NULL & k==1){
        insertFirstElement(Head,Back,j);
    }else if (k==1){
        insertAtHead(Head,Back,j);
    }else{
        Node* iter=Head;
        for (int i=1;i<k-1;i++){
            iter=iter->next;
        }
        Node* temp=new Node(j);
        temp->next=iter->next;
        temp->previous=iter;
        iter->next->previous=temp;
        iter->next=temp;
    }
}
void deleteHead(Node* &Head)
{
    if (Head==NULL){return;}
    Head=Head->next;
    Head->previous=NULL;
}
void deleteTail(Node* &Back)
{
    if (Back==NULL){return;}
    Back=Back->previous;
    Back->next=NULL;
}
void deleteKthPosition(Node* &Head,int k)
{
    if (Head==NULL){return;}
    if (k==1) {deleteHead(Head);} else {
        Node* iter=Head;
        for(int i=1;i<k-1;i++){
            iter=iter->next;
        }
        iter->next=iter->next->next;
        iter->next->previous=iter;
    }
}
void displayHT(Node* Head)
{
    Node* temp=Head;
    while (temp!=NULL){
        cout<<" -> "<<temp->value;
        temp=temp->next;
    }
    cout<<endl;
}
/* Proof of being doubly linked list that it can be printed in both direction.  
void displayTH(Node* Back){ 
    Node* temp=Back;
    while (temp!=NULL){
        cout<<" -> "<<temp->value;
        temp=temp->previous;
    }
    cout<<endl;
}   */
int main(){
    Node* Head=NULL;
    Node* Back=NULL;
    int j;
    for(int i=0;i<10;i++){
        insertAtHead(Head,Back,i);
    }
    for(int i=0;i<10;i++){
        insertAtTail(Head,Back,i);
    }
    displayHT(Head);
    insertAtKthPosition(Head,Back,2,69);
    displayHT(Head);
    deleteHead(Head);
    deleteTail(Back);
    displayHT(Head);
    deleteKthPosition(Head,4);
    deleteKthPosition(Head,1);
    displayHT(Head);
    // displayTH(Back);
}