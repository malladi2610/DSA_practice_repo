# Question

"Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109"


# Answer

### Problem: Find All Unique Quadruplets (4-Sum)

You are tasked with finding all unique quadruplets in an array that sum up to a given target.

---

### **1. Approach**
This is an extension of the **2-Sum** and **3-Sum** problems. We can solve it efficiently by using **sorting and two-pointer techniques** to reduce the complexity. Here's how you can approach the problem:

#### **Key Observations:**
1. The array can be sorted to simplify handling duplicates.
2. After sorting, fixing two numbers reduces the problem to a **2-Sum problem**, which can be solved using a two-pointer approach.
3. To ensure uniqueness:
   - Skip duplicate elements while iterating through the array.
   - Avoid duplicate quadruplets by carefully moving pointers.

#### **Steps:**
1. **Sort the Array:** Sorting ensures that duplicates are adjacent and allows for efficient two-pointer traversal.
2. **Fix Two Numbers:** Use two nested loops to fix the first two numbers.
3. **Use Two Pointers for Remaining Two Numbers:** For the remaining two numbers, use the two-pointer technique to find pairs that sum to the remaining target.
4. **Skip Duplicates:** Avoid duplicate quadruplets by skipping over repeated numbers during iteration.
5. **Collect Results:** Store the unique quadruplets in the result.

---

### **2. Algorithm (Flashcard)**
1. **Input:** An array `nums` of size \( n \) and an integer `target`.
2. **Sort the Array:** Sort `nums` in ascending order.
3. **Iterate Over the Array:**
   - Use two nested loops for indices `i` and `j` to fix the first two numbers.
   - For the remaining two numbers, use two pointers `left` and `right`.
   - Calculate the current sum: `current_sum = nums[i] + nums[j] + nums[left] + nums[right]`.
     - If `current_sum == target`, add the quadruplet to the result.
     - If `current_sum < target`, move `left` forward to increase the sum.
     - If `current_sum > target`, move `right` backward to decrease the sum.
   - Skip duplicates for all four indices.
4. **Output:** Return the result containing all unique quadruplets.

---

### **3. Pseudocode**
```
function fourSum(nums, target):
    sort(nums)
    result ← []

    for i from 0 to length(nums) - 4:
        if i > 0 and nums[i] == nums[i-1]: 
            continue  // Skip duplicate for the first number

        for j from i+1 to length(nums) - 3:
            if j > i+1 and nums[j] == nums[j-1]:
                continue  // Skip duplicate for the second number

            left ← j+1
            right ← length(nums) - 1

            while left < right:
                current_sum ← nums[i] + nums[j] + nums[left] + nums[right]

                if current_sum == target:
                    result.append([nums[i], nums[j], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left++
                    while left < right and nums[right] == nums[right-1]:
                        right--
                    left++
                    right--
                else if current_sum < target:
                    left++
                else:
                    right--

    return result
```

---

### **4. Complexity Analysis**
- **Time Complexity:**
  - Sorting: \(O(n \log n)\).
  - Two nested loops for fixing two numbers: \(O(n^2)\).
  - Two-pointer traversal for the remaining two numbers: \(O(n)\).
  - Overall: \(O(n^3)\).

- **Space Complexity:**
  - Sorting takes \(O(1)\) extra space.
  - Result storage depends on the number of quadruplets but typically \(O(k)\), where \(k\) is the number of unique quadruplets.
  - Total: \(O(k)\).

---

### **5. C++ Code**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Fix the first two numbers
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j

            int left = j + 1, right = n - 1;

            // Step 3: Two-pointer for remaining two numbers
            while (left < right) {
                long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (current_sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (current_sum < target) {
                    left++; // Increase the sum
                } else {
                    right--; // Decrease the sum
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Unique quadruplets: \n";
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
```

---

### **6. Example Walkthrough**

#### **Input:**
```plaintext
nums = [1, 0, -1, 0, -2, 2]
target = 0
```

#### **Execution:**
1. **Sorted nums:** `[-2, -1, 0, 0, 1, 2]`
2. Iterating through combinations:
   - \(i = 0, nums[i] = -2\)
     - \(j = 1, nums[j] = -1\)
       - Two-pointer: `left = 2 (nums[left] = 0)`, `right = 5 (nums[right] = 2)`
         - Quadruplets found: `[-2, -1, 1, 2]`, `[-2, 0, 0, 2]`.
   - \(i = 1, nums[i] = -1\)
     - \(j = 2, nums[j] = 0\)
       - Two-pointer: `left = 3 (nums[left] = 0)`, `right = 5 (nums[right] = 1)`
         - Quadruplet found: `[-1, 0, 0, 1]`.

#### **Output:**
```plaintext
Unique quadruplets:
[-2, -1, 1, 2]
[-2, 0, 0, 2]
[-1, 0, 0, 1]
```

---

This approach ensures that all quadruplets are unique and satisfies the \(O(n^3)\) complexity requirement.