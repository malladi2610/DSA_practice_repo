#include<iostream>
using namespace std;

//Definition of the linkedlist
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
    public:
        ListNode* removeNthnodefromthelist(ListNode* head, int n){
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* first = dummy;
            ListNode* second = dummy;

            for(int i = 0; i<=n; ++i){
                first = first->next;
            }

            while(first != nullptr){
                first = first->next;
                second = second->next;
            }

            ListNode* nodetoDelete = second->next;
            second->next = second->next->next;
            delete nodetoDelete;

            ListNode* newHead = dummy->next;
            delete dummy;
            return newHead;
        }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    Solution sol;
    int n = 2;
    ListNode* newHead = sol.removeNthnodefromthelist(head,n);

    printList(newHead);

    //Clean up the memory until the linkedlist is empty
    while (newHead != nullptr){
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

}

