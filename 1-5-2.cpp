#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to perform insertion sort on a linked list
void insertionSort(Node** head_ref) {
    Node* sorted = nullptr;  // Initialize the sorted list as empty

    // Traverse the given linked list and insert every node to the sorted part
    Node* current = *head_ref;
    while (current != nullptr) {
        Node* nextNode = current->next;  // Store the next node

        // Insert current in the sorted linked list
        if (sorted == nullptr || sorted->data >= current->data) {
            // Insert at the beginning or if the current node should be first in sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // Locate the node before the node to be inserted
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert the current node in its correct position
            current->next = temp->next;
            temp->next = current;
        }
        
        // Move to the next node in the input list
        current = nextNode;
    }
    
    // Update head_ref to point to the sorted list
    *head_ref = sorted;
}

int main() {
    Node* head = nullptr;

    // Insert elements to the linked list
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 1);
    push(&head, 3);

    cout << "Unsorted Linked List: ";
    printList(head);

    // Perform insertion sort on the linked list
    insertionSort(&head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
