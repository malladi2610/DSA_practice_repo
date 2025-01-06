### Problem: Longest Consecutive Sequence

The task is to find the length of the longest sequence of consecutive integers in an unsorted array \( \text{nums} \), where the solution must run in \( O(n) \) time.

---

### **1. Approach**

To achieve \( O(n) \) time complexity, we can use a **hash set** for efficient lookups, instead of sorting the array.

#### **Key Observations:**
1. For an element to be the **start of a sequence**, it must not have its predecessor in the array.
   - For example, \( x = 1 \) is the start of the sequence \( [1, 2, 3, 4] \) because \( 0 \) is not in the array.
2. By identifying the starting elements of sequences, we can avoid redundant checks and only process each sequence once.

---

#### **Steps to Solve:**
1. Add all elements of \( \text{nums} \) into a hash set for \( O(1) \) lookups.
2. Iterate through the array:
   - If the current number is the start of a sequence (i.e., \( x - 1 \) is not in the set), compute the length of the sequence by repeatedly checking for \( x + 1, x + 2, \dots \).
   - Track the maximum length of sequences encountered.
3. Return the maximum length.

---

### **2. Algorithm (Flashcard Style)**

1. **Input:** Array \( \text{nums} \) of size \( n \).
2. **Steps:**
   - Add all elements of \( \text{nums} \) into a hash set.
   - Initialize `maxLength = 0`.
   - For each number \( x \) in \( \text{nums} \):
     - If \( x - 1 \) is not in the hash set:
       - \( x \) is the start of a sequence.
       - Count the length of the sequence by repeatedly checking \( x, x+1, x+2, \dots \) in the hash set.
       - Update `maxLength` with the length of the sequence.
   - Return `maxLength`.
3. **Output:** Length of the longest consecutive sequence.

---

### **3. Pseudocode**

```
function longestConsecutive(nums):
    if nums.length == 0:
        return 0

    numSet ← set of all elements in nums
    maxLength ← 0

    for num in nums:
        if num - 1 not in numSet:
            currentNum ← num
            currentLength ← 1

            while currentNum + 1 in numSet:
                currentNum ← currentNum + 1
                currentLength ← currentLength + 1

            maxLength ← max(maxLength, currentLength)

    return maxLength
```

---

### **4. Complexity Analysis**

- **Time Complexity:** \( O(n) \)
  - Adding \( n \) elements to the hash set takes \( O(n) \).
  - Each sequence is processed at most once, resulting in \( O(n) \) total work.
- **Space Complexity:** \( O(n) \)
  - The hash set stores all elements of \( \text{nums} \).

---

### **5. C++ Code**

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : nums) {
        // Only start a sequence if `num - 1` is not in the set
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count the length of the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive sequence: " << longestConsecutive(nums) << endl;
    return 0;
}
```

---

### **6. Example Walkthrough**

#### Example Input:
```plaintext
nums = [100, 4, 200, 1, 3, 2]
```

#### Execution:

1. **Create Hash Set:**
   \[
   \text{numSet} = \{100, 4, 200, 1, 3, 2\}
   \]

2. **Iterate Through Elements:**
   - **For \( x = 100 \):**
     - \( 99 \notin \text{numSet} \), so \( x \) is the start of a sequence.
     - Sequence: \( [100] \), length = 1.
   - **For \( x = 4 \):**
     - \( 3 \in \text{numSet} \), so \( x \) is not the start of a sequence.
   - **For \( x = 200 \):**
     - \( 199 \notin \text{numSet} \), so \( x \) is the start of a sequence.
     - Sequence: \( [200] \), length = 1.
   - **For \( x = 1 \):**
     - \( 0 \notin \text{numSet} \), so \( x \) is the start of a sequence.
     - Sequence: \( [1, 2, 3, 4] \), length = 4.
   - **For \( x = 3 \) and \( x = 2 \):**
     - Neither is the start of a sequence because \( 2 \in \text{numSet} \) and \( 1 \in \text{numSet} \), respectively.

3. **Track Maximum Length:**
   - Longest sequence is \( [1, 2, 3, 4] \), length = 4.

#### Output:
```plaintext
4
```

---

### **7. Key Insights**

1. **Why Use a Hash Set?**
   - Efficient \( O(1) \) lookups allow us to check for consecutive elements without scanning the entire array.

2. **Why Check `num - 1`?**
   - This ensures we only process sequences starting at their smallest element, avoiding redundant checks for elements that are part of longer sequences.

3. **Efficiency:**
   - By focusing only on the starting points of sequences, we process each number in the array exactly once, achieving \( O(n) \) complexity.

This approach is efficient and handles the given constraints effectively.