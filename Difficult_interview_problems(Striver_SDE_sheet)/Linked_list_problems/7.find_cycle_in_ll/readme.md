**1. Approach**

To determine if a linked list has a cycle, the most common efficient technique is the **Floyd’s Tortoise and Hare** algorithm (also known as the slow and fast pointers technique). Here’s how it works:

- Use two pointers, **slow** and **fast**.  
- **slow** moves one step at a time (`slow = slow->next`).  
- **fast** moves two steps at a time (`fast = fast->next->next`).  
- If there is a cycle, eventually **slow** and **fast** will meet (point to the same node).  
- If **fast** or `fast->next` becomes `NULL` at any point, it means the list does not have a cycle (because we’ve reached the end).

**2. Algorithm**

1. If `head` is `NULL` or `head->next` is `NULL`, return `false` (no cycle).  
2. Initialize two pointers: `slow = head` and `fast = head`.  
3. While `fast` and `fast->next` are not `NULL`:  
   - Move `slow` one step ahead: `slow = slow->next`.  
   - Move `fast` two steps ahead: `fast = fast->next->next`.  
   - If `slow == fast` at any point, return `true` (there is a cycle).  
4. If the loop terminates, return `false` (no cycle found).

**3. Pseudocode**

```
function hasCycle(head):
    if head == NULL or head.next == NULL:
        return false

    slow = head
    fast = head

    while fast != NULL and fast.next != NULL:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return true

    return false
```

**4. Time Complexity & Space Complexity**

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the list. In the worst case, the fast pointer traverses each node at most once or twice.  
- **Space Complexity**: \(O(1)\), as we only use two pointers (constant extra space).

---

## C++ Code

Below is a full example in C++ illustrating the creation of a linked list with a possible cycle, detecting the cycle using Floyd’s Tortoise and Hare algorithm, and printing the result.

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

// Function to detect if there is a cycle in the linked list
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move slow by 1
        fast = fast->next->next;     // move fast by 2
        
        if (slow == fast) {
            return true;             // cycle detected
        }
    }
    
    return false; // no cycle
}

// Helper function to create a linked list from a vector
// Returns the head of the list
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
```

### Explanation of the Main Steps

1. **`createLinkedList`**: Builds a singly-linked list from the input values.  
2. **`createCycle`**: Connects the tail of the linked list to the node at position `pos`, creating a cycle if `pos != -1`.  
3. **`hasCycle`**: Uses Floyd’s Tortoise and Hare algorithm to detect a cycle.  
   - If `slow` and `fast` meet, there is a cycle.  
   - If `fast` or `fast->next` becomes `NULL`, no cycle exists.  
4. **In `main`**:  
   - We read the number of nodes, create the linked list, optionally create a cycle, and then test for a cycle using `hasCycle`.  

This satisfies the requirement to determine if a linked list has a cycle in it.