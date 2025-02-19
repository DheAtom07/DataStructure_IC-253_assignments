#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int v){
        value=v;
        next=NULL;
    }
};

void insertFirstElement(Node* &Head,int v)
{
    Node* temp=new Node(v);
    Head=temp;
}
void insertAtHead(Node* &Head,int v)
{
    if (Head==NULL)
    {insertFirstElement(Head,v);}
    else
    {
        Node* temp=new Node(v);
        temp->next=Head;
        Head=temp;
    }
}
void insertAtTail(Node* &Head,int k)
{
    if (Head==NULL){
        insertFirstElement(Head,k);
    }else{
    Node* iter=Head;
    while (iter->next!=NULL){
        iter=iter->next;
    }
    Node* temp=new Node(k);
    iter->next=temp;
    }
}
void insertAtKthPosition(Node* &Head, int k, int v)
{
    Node* iter=Head;
    if (k==1){
        insertAtHead(Head,v);
    }else{
    for(int i=1;i<k-1;i++){
        iter=iter->next;
    }
    Node* temp=new Node(v);
    temp->next=iter->next;
    iter->next=temp;
    }
}

void deleteHead(Node* &Head)
{
    if (Head==NULL) {return;}
    Head=Head->next;
}
void deleteTail(Node* Head)
{
    if (Head==NULL) {return;}
    Node* iter=Head;
    while (iter->next->next!=NULL){
        iter=iter->next;
    }
    iter->next=NULL;
}
void deleteKthPosition(Node* Head,int k)
{
    if (Head==NULL){return;}
    Node* iter=Head;
    for(int i=1;i<k-1;i++){
        iter=iter->next;
    }
    if (iter->next==NULL)
    {
        deleteTail(Head);
    }else{
    iter->next=iter->next->next;
    }
}

void display(Node* Head)    //Displays element  from head to tail.
{
    Node* iter=Head;
    while (iter!=NULL){
        cout<<" -> "<<iter->value;
        iter=iter->next;
    }
    cout<<endl;
}

int main(){
    Node* Head=NULL;
    int j;
    for(int i=0;i<10;i++){
        insertAtHead(Head,i);
    }
    for(int i=0;i<10;i++){
        insertAtTail(Head,i);
    }
    insertAtKthPosition(Head,1,69);
    display(Head);
    deleteHead(Head);
    cout<<"After deleting element.";
    display(Head);
    deleteTail(Head);
    cout<<"After deleting tail.";
    display(Head);
    deleteKthPosition(Head,18);
    cout<<"After deleting kth element.";
    display(Head);
}