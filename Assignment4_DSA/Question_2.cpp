#include <iostream>
using namespace std;

struct Node{
    int value;
    int priority;
    Node* left;
    Node* right;
    Node(int v,int p){
        value=v;
        priority=p;
        left=nullptr;
        right=nullptr;
    }   
};

void insertElement(Node* &Root,int v,int p){
    if(Root==nullptr){
        Root=new Node(v,p);
    }else{
        Node* appending=new Node(v,p);
        Node* iter1=Root;
        Node* iterp=nullptr;
        while(iter1!=nullptr){
            iterp=iter1;
            if(iter1->priority>=p){
                iter1=iter1->right;
            }else{
                iter1=iter1->left;
            }
        }
        if(iterp->priority>=p){
            iterp->right=appending;
        }else{
            iterp->left=appending;
        }
    }
}

void inorderPrint(Node* iter){
    if(iter==nullptr){
        return;
    }
    inorderPrint(iter->left);
    cout<<" -> "<<iter->value<<"("<<iter->priority<<")";
    inorderPrint(iter->right);
}

Node* deleteHighestPriorityElement(Node* Root){
    Node* temp=Root;
    Node* tempP;
    while(temp->left!=nullptr){
        tempP=temp;
        temp=temp->left;
    }
    tempP->left=temp->left;
    return temp;
}

int main(){
    Node* Root=nullptr;
    for(int i=0;i<10;i++){
        insertElement(Root,10-i,i);
    }
    insertElement(Root,100,50);
    inorderPrint(Root);
    cout<<endl;
    Node* temp=deleteHighestPriorityElement(Root);
    cout<<temp->value<<"("<<temp->priority<<")";
    cout<<endl;
}