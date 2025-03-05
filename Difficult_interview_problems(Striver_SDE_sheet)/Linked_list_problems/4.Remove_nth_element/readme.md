To remove the nth node from the end of a singly linked list, we can utilize the two-pointer technique. This approach allows us to efficiently locate and remove the desired node in a single traversal of the list.

**Algorithm:**

1. **Initialize Two Pointers:** Start by creating two pointers, `first` and `second`, both pointing to the head of the list.

2. **Advance the First Pointer:** Move the `first` pointer `n` steps ahead in the list. This creates a gap of `n` nodes between the `first` and `second` pointers.

3. **Move Both Pointers Until End:** Simultaneously move both `first` and `second` pointers one step at a time until the `first` pointer reaches the end of the list. At this point, the `second` pointer will be positioned just before the node that needs to be removed.

4. **Remove the Target Node:** Adjust the `next` reference of the `second` pointer to skip the target node, effectively removing it from the list.

**Edge Cases:**

- **Removing the Head Node:** If the node to be removed is the head of the list (i.e., `n` equals the length of the list), we need to update the head to the next node.

- **Single Node List:** If the list contains only one node and `n` is 1, the result should be an empty list.

**Pseudo Code:**

```
function removeNthFromEnd(head, n):
    dummy = new ListNode(0)
    dummy.next = head
    first = dummy
    second = dummy

    // Move first n+1 steps ahead
    for i from 0 to n:
        first = first.next

    // Move both pointers until first reaches the end
    while first is not null:
        first = first.next
        second = second.next

    // Remove the nth node
    second.next = second.next.next

    return dummy.next
```

**Time Complexity:** O(L), where L is the length of the linked list, since we traverse the list once.

**Space Complexity:** O(1), as we use a constant amount of extra space.

**C++ Implementation:**

```cpp
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        // Get the new head
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Create the list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int n = 2;
    ListNode* newHead = sol.removeNthFromEnd(head, n);

    // Print the updated list
    printList(newHead);

    // Clean up memory
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
```

**Explanation:**

1. **Dummy Node:** A dummy node is used to handle edge cases gracefully, such as removing the head node. It simplifies the logic by ensuring that the `second` pointer always points to the node before the one we want to remove.

2. **Advancing the First Pointer:** By moving the `first` pointer `n+1` steps ahead, we maintain a gap of `n` nodes between the `first` and `second` pointers. This setup allows the `second` pointer to reach the node just before the target node when the `first` pointer reaches the end.

3. **Simultaneous Traversal:** Both pointers are moved together until the `first` pointer reaches the end. At this point, the `second` pointer is positioned just before the node to be removed.

4. **Node Removal:** The `next` reference of the `second` pointer is updated to skip the target node, effectively removing it from the list.

5. **Memory Management:** The node to be deleted is explicitly deleted to free up memory, and the dummy node is also deleted before returning the new head of the list.

This approach ensures that the nth node from the end is removed efficiently with a single traversal of the list. 