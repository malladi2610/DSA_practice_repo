### Understanding Reverse Pairs

A **reverse pair** is defined as a pair of indices \( (i, j) \) in the array \( \text{nums} \), such that:
1. \( 0 \leq i < j < \text{nums.length} \) (index \( i \) comes before \( j \)).
2. \( \text{nums}[i] > 2 \times \text{nums}[j] \) (the value at index \( i \) is strictly greater than twice the value at index \( j \)).

#### Key Details:
- Reverse pairs are not just based on the order of the numbers but also on the **relationship between their values**. 
- For each pair \( (i, j) \), \( \text{nums}[i] \) must satisfy the condition \( \text{nums}[i] > 2 \times \text{nums}[j] \), where \( i < j \).

---

### **Intuitive Example**

Consider \( \text{nums} = [1, 3, 2, 3, 1] \):

1. Check each valid pair \( (i, j) \) (where \( i < j \)):
   - Pair \( (0, 1) \): \( 1 > 2 \times 3 \) → False.
   - Pair \( (1, 4) \): \( 3 > 2 \times 1 \) → True (a reverse pair).
   - Pair \( (3, 4) \): \( 3 > 2 \times 1 \) → True (a reverse pair).

**Reverse pairs in this example:**
- \( (1, 4) \): \( 3 > 2 \times 1 \)
- \( (3, 4) \): \( 3 > 2 \times 1 \)

**Output:** 2 reverse pairs.

---

### **Naive Approach**

A **brute-force solution** involves checking all possible pairs \( (i, j) \):
- Iterate over all possible pairs in \( \text{nums} \).
- Check whether \( \text{nums}[i] > 2 \times \text{nums}[j] \).
- Count the valid pairs.

#### **Complexity:**
- **Time Complexity:** \( O(n^2) \), as we are comparing every pair.
- **Space Complexity:** \( O(1) \).

---

### **Optimized Approach**

To improve performance, we can use a **modified merge sort** algorithm. This reduces the time complexity to \( O(n \log n) \).

#### **Key Idea:**
1. Divide the array into two halves using **merge sort**.
2. Count reverse pairs in:
   - The left half.
   - The right half.
   - Across the two halves (this is where the optimization comes in).
3. Use the sorted order from merge sort to efficiently count reverse pairs across the two halves.

---

### **Steps in the Optimized Algorithm**

1. **Divide the Array:**
   - Recursively divide the array into left and right halves until the size becomes 1.

2. **Count Reverse Pairs Across Halves:**
   - After sorting the left and right halves, count reverse pairs where \( \text{nums}[i] > 2 \times \text{nums}[j] \), with \( i \) in the left half and \( j \) in the right half.
   - Use two pointers to efficiently count pairs.

3. **Merge the Halves:**
   - Merge the two sorted halves back together while maintaining sorted order.

4. **Combine Results:**
   - Return the total count of reverse pairs from the left, right, and across the two halves.

---

### **Algorithm (Flashcard Style)**

1. **Input:** Array \( \text{nums} \) of size \( n \).
2. **Steps:**
   - Define a recursive function `mergeSortAndCount`:
     - If the array has 1 element, return 0 (base case).
     - Divide the array into two halves.
     - Count reverse pairs in the left half, right half, and across halves.
     - Merge the two halves while maintaining sorted order.
   - During the merge step:
     - Use two pointers to count reverse pairs across the two halves efficiently.
3. **Output:** Total count of reverse pairs.

---

### **Pseudocode**

```
function reversePairs(nums):
    return mergeSortAndCount(nums, 0, nums.length - 1)

function mergeSortAndCount(nums, start, end):
    if start >= end:
        return 0

    mid = (start + end) / 2
    count = 0

    // Count reverse pairs in left and right halves
    count += mergeSortAndCount(nums, start, mid)
    count += mergeSortAndCount(nums, mid + 1, end)

    // Count reverse pairs across the two halves
    j = mid + 1
    for i from start to mid:
        while j <= end and nums[i] > 2 * nums[j]:
            j += 1
        count += (j - (mid + 1))

    // Merge the two halves
    merge(nums, start, mid, end)

    return count

function merge(nums, start, mid, end):
    temp = []
    i = start, j = mid + 1

    while i <= mid and j <= end:
        if nums[i] <= nums[j]:
            temp.append(nums[i])
            i += 1
        else:
            temp.append(nums[j])
            j += 1

    while i <= mid:
        temp.append(nums[i])
        i += 1

    while j <= end:
        temp.append(nums[j])
        j += 1

    for k from 0 to temp.length - 1:
        nums[start + k] = temp[k]
```

---

### **Complexity Analysis**

- **Time Complexity:** \( O(n \log n) \)
  - The merge sort process takes \( O(n \log n) \), and counting pairs across halves is \( O(n) \) for each level of recursion.
- **Space Complexity:** \( O(n) \)
  - Temporary array is used for merging.

---

### **C++ Code**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& nums, int start, int mid, int end) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge two sorted halves
    vector<int> temp;
    int i = start, k = mid + 1;

    while (i <= mid && k <= end) {
        if (nums[i] <= nums[k]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[k++]);
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    while (k <= end) {
        temp.push_back(nums[k++]);
    }

    for (int i = 0; i < temp.size(); i++) {
        nums[start + i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(vector<int>& nums, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int count = 0;

    count += mergeSortAndCount(nums, start, mid);
    count += mergeSortAndCount(nums, mid + 1, end);
    count += mergeAndCount(nums, start, mid, end);

    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSortAndCount(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}
```

---

### **Example Walkthrough**

#### Input:
```plaintext
nums = [1, 3, 2, 3, 1]
```

#### Execution:
1. Split the array into smaller subarrays using merge sort.
2. Count reverse pairs across subarrays at each step.
3. Merge the subarrays while maintaining sorted order.

#### Output:
```plaintext
2
```

This optimized solution efficiently counts reverse pairs in \( O(n \log n) \) time.