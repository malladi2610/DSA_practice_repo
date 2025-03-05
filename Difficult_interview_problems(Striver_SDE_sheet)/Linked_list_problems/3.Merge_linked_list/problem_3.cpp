#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode(-1); // Dummy node to start the new list
        ListNode* tail = dummy; // Pointer to track last node of merged list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Move tail forward
        }

        // Attach remaining nodes
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy->next; // Return merged list without dummy node
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Test the function
int main() {
    // Creating list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Creating list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedHead); // Expected Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL

    return 0;
}
