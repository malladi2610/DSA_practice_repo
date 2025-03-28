#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

/*This is the final logic to detect the linkedlist*/
bool hasCycle(ListNode *head){

    //THis is the base condition
    if (head == NULL || head->next == NULL){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    //As this problem is solved by the two pointers concept of slow and fast
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        //THis is the condition to detect the cycle
        if(slow == fast){
            return true;
        }
    }
    return false;
}


//Helper function to create a linked list from a vector

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < (int)values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}


// Utility to connect the tail to a given position (pos) to create a cycle
// If pos == -1, no cycle is created
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    
    ListNode* tail = head;
    ListNode* cycleNode = NULL;
    int currentIndex = 0;
    
    while (tail->next != NULL) {
        if (currentIndex == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        currentIndex++;
    }
    
    // Link tail's next to cycleNode if cycleNode is found
    if (cycleNode != NULL) {
        tail->next = cycleNode;
    }
}

int main() {
    // Example usage:
    // head = [3,2,0,-4], pos = 1 => output: true
    
    // Input reading
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "No nodes in the list. Exiting..." << endl;
        return 0;
    }
    
    vector<int> values(n);
    cout << "Enter the values of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    int pos;
    cout << "Enter the position (0-indexed) where the tail should link to (-1 if no cycle): ";
    cin >> pos;
    
    // Create the linked list
    ListNode* head = createLinkedList(values);
    
    // Create cycle if pos != -1
    createCycle(head, pos);
    
    // Check for cycle
    bool result = hasCycle(head);
    
    if (result) {
        cout << "true (The linked list has a cycle)" << endl;
    } else {
        cout << "false (The linked list does not have a cycle)" << endl;
    }
    
    return 0;
}