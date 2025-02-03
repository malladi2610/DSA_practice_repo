#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next; //store next node
            current->next = prev; //reverse pointer
            prev = current; //Move prev forward
            current = next;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout<< head->val << "->";
        head = head->next;
    }

    cout<<"NULL"<<endl;
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout<<"Original List:";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout<<"Reversed list";
    printList(reversedHead);

    return 0;

}