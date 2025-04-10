#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v){
        value=v;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
};

void insertNode(Node* &Root,int k,Node* parent=nullptr){
    if(Root==nullptr){
        Root=new Node(k);
        Root->parent=parent;
    }else{
        if(Root->value<=k){
            insertNode(Root->right,k,Root);
        }else{
            insertNode(Root->left,k,Root);
        }
    }
}

void inorderPrint(Node* current){
    if(current==nullptr){
        return;
    }
    inorderPrint(current->left);
    cout<<current->value<<"->";
    inorderPrint(current->right);
    // cout<<endl;
}

void preorderPrint(Node* current){
    if(current==nullptr){
        return;
    }
    cout<<current->value<<"->";
    preorderPrint(current->left);
    preorderPrint(current->right);
    // cout<<endl;
}

void postorderPrint(Node* current){
    if(current==nullptr){
        return;
    }
    postorderPrint(current->left);
    postorderPrint(current->right);
    cout<<current->value<<"->";
    // cout<<endl;
}

int main(){
    Node* Root=nullptr;
    for(int i=0;i<10;i++){
        insertNode(Root,i);
    }
    inorderPrint(Root);
    cout<<endl;
    preorderPrint(Root);
    cout<<endl;
    postorderPrint(Root);
    cout<<endl;
}