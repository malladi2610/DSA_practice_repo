### **Problem: Merge Two Sorted Linked Lists**
You are given the heads of two sorted linked lists, **list1** and **list2**. Merge them into a single **sorted** linked list by **splicing** together the nodes of the first two lists.

---

## **1. Approach**
Since both lists are **already sorted**, we can merge them efficiently using a **two-pointer technique**. We iterate through both lists, comparing their nodes, and attach the smaller node to the result list.

### **Key Idea**
1. Use two pointers, `p1` (for `list1`) and `p2` (for `list2`).
2. Compare the values of `p1` and `p2`, and attach the smaller node to the merged list.
3. Move the pointer forward in the list that contained the smaller value.
4. If one list is fully traversed, attach the remaining nodes from the other list.
5. Return the head of the new merged list.

---

## **2. Algorithm**
1. **Handle edge cases**:
   - If `list1` is empty, return `list2`.
   - If `list2` is empty, return `list1`.

2. **Initialize:**
   - A **dummy node** to simplify list handling.
   - A **tail pointer** (`tail`) that tracks the last node in the merged list.

3. **Merge lists using two-pointer approach:**
   - Traverse `list1` and `list2` simultaneously.
   - Append the node with the smaller value to `tail`.
   - Move the pointer in the list that contributed the node.

4. **Attach the remaining nodes** (if any) to `tail`.

5. **Return the merged list starting from `dummy->next`**.

---

## **3. Pseudo Code**
```
function mergeTwoLists(list1, list2):
    if list1 is NULL: return list2
    if list2 is NULL: return list1

    dummy ← new ListNode(-1)
    tail ← dummy

    while list1 ≠ NULL and list2 ≠ NULL:
        if list1.val < list2.val:
            tail.next ← list1
            list1 ← list1.next
        else:
            tail.next ← list2
            list2 ← list2.next
        tail ← tail.next

    // Attach remaining nodes
    if list1 ≠ NULL:
        tail.next ← list1
    else:
        tail.next ← list2

    return dummy.next
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
```

---

## **5. Complexity Analysis**
- **Time Complexity:** \( O(n + m) \)
  - We iterate through `list1` and `list2` **once**, making comparisons and attaching nodes.
- **Space Complexity:** \( O(1) \)
  - We **reuse** the existing nodes and only create a dummy node.

---

## **6. Example Walkthrough**

### **Example 1**
#### **Input:**
```plaintext
list1 = [1, 2, 4]
list2 = [1, 3, 4]
```
#### **Execution:**
| Step | `list1` Head | `list2` Head | `Merged List`  |
|------|-------------|-------------|---------------|
| 1    | **1** → 2 → 4 | **1** → 3 → 4 | 1 → |
| 2    | 2 → 4 | **1** → 3 → 4 | 1 → 1 → |
| 3    | **2** → 4 | 3 → 4 | 1 → 1 → 2 → |
| 4    | 4 | **3** → 4 | 1 → 1 → 2 → 3 → |
| 5    | **4** | 4 | 1 → 1 → 2 → 3 → 4 → |
| 6    | NULL | **4** | 1 → 1 → 2 → 3 → 4 → 4 → NULL |

#### **Output:**
```plaintext
[1, 1, 2, 3, 4, 4]
```

---

## **7. Edge Cases Considered**
| Case | `list1` | `list2` | Expected Output |
|------|--------|--------|----------------|
| **Both empty** | `[]` | `[]` | `[]` |
| **One list empty** | `[]` | `[0]` | `[0]` |
| **One list is larger** | `[1, 2, 3]` | `[10]` | `[1, 2, 3, 10]` |
| **All values same** | `[2, 2, 2]` | `[2, 2]` | `[2, 2, 2, 2, 2]` |

---

## **8. Key Takeaways**
✅ **Dummy Node simplifies handling the head of the list**.  
✅ **Merging is done in-place** without creating new nodes.  
✅ **Optimized for \( O(n + m) \) complexity**, making it efficient for larger lists.  
✅ **Handles all edge cases correctly.**

This **merge technique** is widely used in **merge sort for linked lists**. 🚀