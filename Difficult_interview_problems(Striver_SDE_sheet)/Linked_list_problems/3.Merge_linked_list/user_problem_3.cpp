#include<iostream>
using namespace std;

//Definition of ListNOde
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            if (!list1) return list2;
            if (!list2) return list1;
            
            //This is the new dummy linked list that is created to add the values from both the lists
            ListNode* dummy = new ListNode(-1); //Dummy node to start the new list
            ListNode* tail = dummy; //Pointer to track last node of the nmerger list

            while (list1 != nullptr && list2 != nullptr){
                if (list1->val < list2->val){
                    tail->next = list1;
                    list1 = list1->next;
                }
                else{
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }
            if(list1) tail->next = list1;
            if(list2) tail->next = list2;

            return dummy->next;
        }
};

void printList(ListNode* head){
    while(head != nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    cout<<"Merged List: ";
    printList(mergedHead);

    return 0;
}
