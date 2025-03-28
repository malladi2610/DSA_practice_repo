**1. Approach**

In this problem, we are not given the head of the linked list, but we have a pointer/reference to the node we need to delete. The trick to “delete” this node from the list without having access to the head is:

1. Copy the data from the next node into the current node (the one we want to delete).
2. Adjust the current node’s `next` pointer to skip the next node.
3. Effectively, the next node is removed from the linked list, and the current node now holds the value of the (old) next node.

Since each node has a unique value and we are guaranteed that the node to be deleted is not the last node, we can safely access `node->next`.

**2. Algorithm**

1. Let the node to be deleted be `node`.
2. Copy `node->next->val` into `node->val`.
3. Store a temporary pointer to `node->next` (say `temp`).
4. Point `node->next` to `node->next->next`.
5. Free `temp` (in C++ we often just let it go out of scope if we are not explicitly required to manage memory, but conceptually it is removed from the chain).

**3. Pseudocode**

```
function deleteNode(node):
    node.val = node.next.val
    temp = node.next
    node.next = node.next.next
    free temp
```

**4. Time Complexity & Space Complexity**

- **Time Complexity**: \(O(1)\). The deletion is done in constant time by copying the next node’s data and adjusting one pointer.
- **Space Complexity**: \(O(1)\). We do not allocate any additional data structure; only a temporary pointer is used.

---

## C++ Code

Below is a complete example in C++ to illustrate the concept. In a real interview or coding environment, you might only need to implement `deleteNode(Node* node)`, but here we show the full flow:

```cpp
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
```

### Explanation of the Main Steps
- **`deleteNode`**: Implements the logic to remove the given node from the list by copying the value from the next node and bypassing it.  
- **`createLinkedList`**: Creates a sample linked list from a vector.  
- **`findNode`**: Locates the first node matching a given value (used to simulate “the node to delete”).  
- **`printLinkedList`**: Prints the list to confirm the result.  

This demonstrates how to delete a node in constant time when we do not have access to the head of the linked list.