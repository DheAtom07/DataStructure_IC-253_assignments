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
Node* insertionSort(Node* Head)
{
    if (Head == nullptr || Head->next == nullptr) return Head;  // Handle empty or single-node list

    Node* current = Head->next;  // Start from the second node

    while (current != nullptr) {
        Node* nextNode = current->next;  // Save next node
        Node* temp = Head;

        // Find the correct position for 'current' in the sorted part of the list
        while (temp != current && temp->value <= current->value) {
            temp = temp->next;
        }

        // If 'current' is not already in the correct position
        if (temp != current) {
            // Remove 'current' from its current position
            if (current->next != nullptr) {
                current->next->previous = current->previous;
            }
            if (current->previous != nullptr) {
                current->previous->next = current->next;
            }

            // Insert 'current' before 'temp'
            if (temp == Head) {
                current->next = Head;
                current->previous = nullptr;
                Head->previous = current;
                Head = current;
            } else {
                current->previous = temp->previous;
                current->next = temp;
                temp->previous->next = current;
                temp->previous = current;
            }
        }

        // Move to the next node to be processed
        current = nextNode;
    }

    return Head;
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
    cout<<"\n Insertion sort : ";
    displayHT(insertionSort(Head));
    // displayTH(Back);
}