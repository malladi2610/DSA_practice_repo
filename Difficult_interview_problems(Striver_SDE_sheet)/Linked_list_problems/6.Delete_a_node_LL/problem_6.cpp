#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete the given node from the linked list
// node is guaranteed not to be the tail node
void deleteNode(ListNode* node) {
    // Copy the next node's value into the current node
    node->val = node->next->val;
    
    // Temporarily store the next node
    ListNode* temp = node->next;
    
    // Skip the next node
    node->next = node->next->next;
    
    // Free or delete the skipped node (optional in some environments)
    delete temp;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < (int)vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to find and return the first node with a given value
ListNode* findNode(ListNode* head, int value) {
    while (head != NULL) {
        if (head->val == value) return head;
        head = head->next;
    }
    return NULL; // if not found
}

int main() {
    // Example usage:
    // Suppose we have a linked list [4,5,1,9], and we want to delete the node with value 5.
    
    // Create the linked list
    vector<int> values = {4, 5, 1, 9};
    ListNode* head = createLinkedList(values);
    
    cout << "Original linked list: ";
    printLinkedList(head);
    
    // Find the node to be deleted
    int nodeValueToDelete;
    cout << "Enter the value of the node to delete (not the last node): ";
    cin >> nodeValueToDelete;
    
    ListNode* nodeToDelete = findNode(head, nodeValueToDelete);
    if (nodeToDelete == NULL || nodeToDelete->next == NULL) {
        cout << "Cannot delete the last node or invalid node." << endl;
    } else {
        // Delete the node
        deleteNode(nodeToDelete);
        
        // Print the updated list
        cout << "Updated linked list: ";
        printLinkedList(head);
    }

    return 0;
}
