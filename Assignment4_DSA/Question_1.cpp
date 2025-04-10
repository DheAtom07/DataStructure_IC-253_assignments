#include <iostream>
using namespace std;

int numberOfComparisonsForInsertion=0;
int numberOfComparisonsForSearch=0;
int numberOfComparisonsForDeleting=0;
// Both search and insertion can be done by two methods : recursive and loop.
struct Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v){                    
        value=v;
        left= nullptr;
        right= nullptr;
        parent= nullptr;
    }
};

void insertNewElement(Node* &Root, int k, Node* parent=nullptr){
    if(!Root){
        Root=new Node(k);
        Root->parent=parent;
        numberOfComparisonsForInsertion++;
    }else if(Root->value<=k){
        insertNewElement(Root->right,k,Root);
        numberOfComparisonsForInsertion+=2;
    }else if(Root->value>k){
        insertNewElement(Root->left,k,Root);
        numberOfComparisonsForInsertion+=3;
    }
}

Node* searchInBST(Node* Root,int k){
    Node* temp=Root;
    while (temp!=nullptr && temp->value!=k){
        numberOfComparisonsForSearch+=2;
        if(temp->value<=k){
            temp=temp->right;
            numberOfComparisonsForSearch++;
        }else if(temp->value>k){
            temp=temp->left;
            numberOfComparisonsForSearch+=2;
        }
    }
    numberOfComparisonsForSearch+=2;
    if(temp==nullptr){
        return new Node(-1);
    }
    numberOfComparisonsForSearch++;
    return temp;
}

Node* maximumValueNode(Node* Root){
    if(Root==nullptr){
        numberOfComparisonsForDeleting++;
        return Root;
    }
    while(Root->right!=nullptr){
        numberOfComparisonsForDeleting++;
        Root=Root->right;
    }
    numberOfComparisonsForDeleting++;
    return Root;
}

void deleteNode(Node* &Root,int k){
    Node* temp=searchInBST(Root,k);
    if(temp==nullptr || temp->value==-1){
        cout<<"Value containing Node doesn't exist in Tree.";
        numberOfComparisonsForDeleting+=2;
        return;
    }
    if(temp==Root){
        numberOfComparisonsForDeleting++;
        if(Root->right==nullptr && Root->left==nullptr){
            delete Root;
            numberOfComparisonsForDeleting++;
            Root = nullptr;
        }else if(Root->right==nullptr){
            numberOfComparisonsForDeleting+=2;
            Root=Root->left;
        }else if(Root->left==nullptr){
            numberOfComparisonsForDeleting+=3;
            Root=Root->right;
        }else{
            numberOfComparisonsForDeleting+=3;
            Node* pred = maximumValueNode(Root->left);
            Root->value = pred->value;
            deleteNode(Root->left, pred->value);
        }
        return;
    }
    if(temp->left==nullptr && temp->right==nullptr){
        numberOfComparisonsForDeleting+=2;
        if(temp->parent->right==temp){
            numberOfComparisonsForDeleting++;
            temp->parent->right=nullptr;
            delete temp;
        }else{
            numberOfComparisonsForDeleting++;
            temp->parent->left=nullptr;
            delete temp;
        }
    }else if(temp->left==nullptr){
        numberOfComparisonsForDeleting++;
        temp->right->parent=temp->parent;
        temp->parent->right=temp->right;
        delete temp;
        return;
    }else  if(temp->right==nullptr){
        numberOfComparisonsForDeleting++;
        temp->left->parent=temp->parent;
        temp->parent->left=temp->left;
        delete temp;
        return;
    }else{
        numberOfComparisonsForDeleting++;
        Node* temp2=maximumValueNode(temp->left);
        temp->right->parent=temp2;
        temp2->right=temp->right;
        temp->left->parent=temp->parent;
        temp->parent=temp->left;
        delete temp;
    }
}

void inorderPrint(Node* Root) {
    if (Root == nullptr) return;

    inorderPrint(Root->left);
    cout << Root->value << " -> ";
    inorderPrint(Root->right);
}

int main(){
    Node *Root=nullptr;
    for(int i=0;i<5;i++){
        insertNewElement(Root,2*i);
        insertNewElement(Root,2*(-i)-2);
    }   
    inorderPrint(Root);
    cout<<endl<<"Number of comparisons for insertion : "<<numberOfComparisonsForInsertion<<endl;
    cout<<"The answer of Search is : "<<searchInBST(Root,0)->value<<endl;
    cout<<"The number of comparisons for search is : "<<numberOfComparisonsForSearch<<endl;
    deleteNode(Root,6);
    inorderPrint(Root);
    cout<<endl;
    cout<<"Number of comparisons for deleting : "<<numberOfComparisonsForDeleting<<endl;
}