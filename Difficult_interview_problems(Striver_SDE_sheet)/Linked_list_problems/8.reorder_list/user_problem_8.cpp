#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *current = head;

    while (current != NULL){
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

void reorderList(ListNode* head){
    if (!head || !head->next || !head->next->next){
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    //1. find the middle via slow and fast pointers
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //2. Split and reverse the second half
    ListNode* second = slow->next;
    slow->next = NULL;
    second = reverseList(second);

    //3. Merge the two linkedlists
    ListNode* first = head;
    while(second){
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << (temp->next ? "->" : "");
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    cout << "Enter the node values: ";
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    // Build the linked list
    for(int i = 1; i < n; i++){
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    // Reorder the list
    reorderList(head);

    // Print the reordered list
    cout << "Reordered List: ";
    printList(head);

    return 0;
}
