### **Problem: Find the Middle Node of a Linked List**
Given the head of a **singly linked list**, return the **middle node** of the linked list.

- If there are **two middle nodes**, return the **second middle node**.

---

## **1. Approach: Fast & Slow Pointer (Tortoise and Hare Algorithm)**
### **Key Idea**
We use two pointers:
- **Slow Pointer (`slow`)** → Moves **one step** at a time.
- **Fast Pointer (`fast`)** → Moves **two steps** at a time.

By the time `fast` reaches the **end** of the list:
- `slow` will be at the **middle** of the list.

### **Steps**
1. **Initialize two pointers:**
   - `slow = head`
   - `fast = head`
2. **Traverse the list:**
   - Move `slow` **one step**.
   - Move `fast` **two steps**.
   - Stop when `fast` reaches `nullptr` (end of list).
3. **Return `slow` (middle node).**

### **Why It Works**
- If the list has **odd** length: `slow` will be at the exact middle.
- If the list has **even** length: `slow` will be at the **second middle node**, as required.

---

## **2. Algorithm**
1. **Input:** `head` of the linked list.
2. **Initialize:**  
   - `slow = head`
   - `fast = head`
3. **Traverse:**  
   - While `fast` is **not NULL** and `fast->next` is **not NULL**:
     - Move `slow` one step (`slow = slow->next`).
     - Move `fast` two steps (`fast = fast->next->next`).
4. **Return `slow` (middle node).**

---

## **3. Pseudo Code**
```markdown
function findMiddleNode(head):
    slow ← head
    fast ← head

    while fast ≠ NULL and fast.next ≠ NULL:
        slow ← slow.next
        fast ← fast.next.next

    return slow
```

---

## **4. C++ Code Implementation**
```cpp
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        return slow; // Middle node
    }
};

// Function to print the linked list from the given node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Test the function
int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    cout << "Middle node and its subsequent nodes: ";
    printList(middle); // Expected output: 3 -> 4 -> 5 -> NULL

    return 0;
}
```

---

## **5. Complexity Analysis**
- **Time Complexity:** \( O(n) \)
  - Each node is visited **once**.
- **Space Complexity:** \( O(1) \)
  - Uses only two extra pointers (`slow` and `fast`).

---

## **6. Example Walkthrough**

### **Example 1:**
#### **Input:**
```plaintext
head = [1,2,3,4,5]
```
#### **Execution:**
| Step | `slow` | `fast` | `slow` Moves To | `fast` Moves To |
|------|--------|--------|----------------|----------------|
| 1    | 1      | 1      | 2              | 3              |
| 2    | 2      | 3      | 3              | 5              |
| 3    | 3      | 5 (end) | STOP (Middle) | STOP |

#### **Output:**
```plaintext
[3 -> 4 -> 5]
```

---

### **Example 2:**
#### **Input:**
```plaintext
head = [1,2,3,4,5,6]
```
#### **Execution:**
| Step | `slow` | `fast` | `slow` Moves To | `fast` Moves To |
|------|--------|--------|----------------|----------------|
| 1    | 1      | 1      | 2              | 3              |
| 2    | 2      | 3      | 3              | 5              |
| 3    | 3      | 5      | 4              | 6 (end) |

#### **Output:**
```plaintext
[4 -> 5 -> 6]
```

---

## **7. Edge Cases Considered**
| Case | Input | Output | Notes |
|------|-------|--------|--------|
| **Empty List** | `head = []` | `[]` | Handle `nullptr` case. |
| **Single Node** | `head = [1]` | `[1]` | The middle is the only node. |
| **Even Length** | `head = [1,2,3,4,5,6]` | `[4,5,6]` | Returns second middle. |
| **Odd Length** | `head = [1,2,3,4,5]` | `[3,4,5]` | Returns the middle node. |

---

### **8. Key Takeaways**
- **Fast & Slow Pointer technique** efficiently finds the middle node.
- **Handles both even and odd-length lists correctly.**
- **Optimized to \( O(n) \) time and \( O(1) \) space.**
- **Works in a single pass**, making it ideal for large lists.

This method is widely used in **linked list problems** and is crucial for **cycle detection (Floyd's Algorithm)** as well. 🚀