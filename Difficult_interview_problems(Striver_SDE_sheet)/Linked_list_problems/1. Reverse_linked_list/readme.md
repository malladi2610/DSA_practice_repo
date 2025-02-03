

### **Problem: Reverse a Singly Linked List**
#### **Given** the head of a singly linked list, reverse the list and return the reversed list.

---



## **1. Approach**
To reverse a linked list, we need to change the `next` pointers of the nodes so that they point in the opposite direction.

### **Key Idea:**
- We traverse the list while maintaining three pointers:
  1. `prev` (previous node) → initially `nullptr`
  2. `current` (current node) → initially pointing to `head`
  3. `next` (next node) → temporarily stores the next node before reversing the `next` pointer.

### **Steps:**
1. **Initialize pointers:**
   - `prev = nullptr` (this will become the new head).
   - `current = head`.
   - `next = nullptr` (to temporarily store `current->next`).
   
2. **Iterate through the list until `current` becomes `nullptr`:**
   - Store `current->next` in `next` (so that we don’t lose the rest of the list).
   - Reverse the `next` pointer of `current` to point to `prev`.
   - Move `prev` forward to `current`.
   - Move `current` forward to `next`.

3. **Return `prev` as the new head of the reversed list.**

---



## **2. Algorithm**


1. **Input:** A pointer to the head of the singly linked list.
2. **Initialize three pointers:**
   - `prev = nullptr`
   - `current = head`
   - `next = nullptr`
3. **Traverse the list:**
   - While `current` is not `nullptr`:
     - Store `current->next` in `next`.
     - Reverse the `next` pointer of `current` to point to `prev`.
     - Move `prev` to `current`.
     - Move `current` to `next`.
4. **Return `prev` (new head of the reversed list).**

---

## **3. Pseudo Code**
```markdown
function reverseList(head):
    prev ← NULL
    current ← head

    while current ≠ NULL:
        next ← current.next   // Store next node
        current.next ← prev   // Reverse pointer
        prev ← current        // Move prev forward
        current ← next        // Move current forward

    return prev  // New head of the reversed list
```

---

## **4. C++ Code Implementation**
```cpp
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
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
            next = current->next; // Store next node
            current->next = prev; // Reverse pointer
            prev = current;       // Move prev forward
            current = next;       // Move current forward
        }
        
        return prev; // New head of the reversed list
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
```

---

## **5. Complexity Analysis**
- **Time Complexity:** \( O(n) \)
  - Each node is visited exactly once, so the time complexity is linear.
  
- **Space Complexity:** \( O(1) \)
  - No extra space is used except for a few pointer variables.

---

## **6. Example Walkthrough**
### **Example 1:**
#### **Input:**
```
head = [1 -> 2 -> 3 -> 4 -> 5 -> NULL]
```
#### **Execution:**
| Iteration | `current` | `next` (stored) | `current->next` (reversed) | `prev` (moved) | `current` (moved) |
|-----------|----------|----------------|----------------|------------|------------|
| 1         | 1        | 2              | NULL           | 1          | 2          |
| 2         | 2        | 3              | 1              | 2          | 3          |
| 3         | 3        | 4              | 2              | 3          | 4          |
| 4         | 4        | 5              | 3              | 4          | 5          |
| 5         | 5        | NULL           | 4              | 5          | NULL       |

#### **Output:**
```
[5 -> 4 -> 3 -> 2 -> 1 -> NULL]
```

---

### **Example 2:**
#### **Input:**
```
head = [1 -> 2 -> NULL]
```
#### **Output:**
```
[2 -> 1 -> NULL]
```

---

### **Example 3:**
#### **Input:**
```
head = []
```
#### **Output:**
```
[]
```

---

### **Key Takeaways**
- **Iterative approach** is space-efficient (`O(1)`) and preferred for large lists.
- **Uses three pointers (`prev`, `current`, `next`)** to reverse the links efficiently.
- **Each node is visited once**, making it **optimal at O(n) time complexity**.

