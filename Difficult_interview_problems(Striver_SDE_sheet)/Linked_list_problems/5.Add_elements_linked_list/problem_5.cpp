#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented as linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Dummy head to build the resulting list
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;

    // Traverse both lists
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;
        int newDigit = sum % 10;
        carry = sum / 10;

        current->next = new ListNode(newDigit);
        current = current->next;

        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }

    // The result list is dummy->next
    return dummy->next;
}

// Helper function to create a linked list from vector
ListNode* createLinkedList(const vector<int>& nums) {
    if(nums.empty()) return NULL;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for(int i = 1; i < (int)nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input handling
    int n1, n2;
    cout << "Enter number of digits in first linked list: ";
    cin >> n1;

    vector<int> v1(n1);
    cout << "Enter digits for first linked list in reverse order: ";
    for(int i = 0; i < n1; i++) {
        cin >> v1[i];
    }

    cout << "Enter number of digits in second linked list: ";
    cin >> n2;

    vector<int> v2(n2);
    cout << "Enter digits for second linked list in reverse order: ";
    for(int i = 0; i < n2; i++) {
        cin >> v2[i];
    }

    // Create linked lists
    ListNode* l1 = createLinkedList(v1);
    ListNode* l2 = createLinkedList(v2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Resultant Linked List (in reverse order): ";
    printLinkedList(result);

    return 0;
}
