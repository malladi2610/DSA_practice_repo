### Problem: Maximum Subarray Sum (Kadane's Algorithm)

You are tasked with finding the contiguous subarray (containing at least one number) that has the largest sum and returning its sum. Kadane's algorithm is the most efficient solution for this problem.

---

### **1. Approach**
The problem asks for the subarray with the maximum sum. **Kadane’s Algorithm** provides an \(O(n)\) solution by maintaining a running sum and a global maximum sum while iterating through the array.

#### **Key Idea of Kadane's Algorithm**
1. Maintain two variables:
   - `currentSum`: Keeps track of the sum of the current subarray.
   - `maxSum`: Tracks the maximum sum found so far.

2. At each step, decide:
   - Whether to include the current element in the ongoing subarray.
   - Or start a new subarray with the current element.

3. Update the `maxSum` if `currentSum` exceeds the previously stored `maxSum`.

#### **Steps to Solve:**
1. Initialize:
   - `currentSum` to `nums[0]`.
   - `maxSum` to `nums[0]`.
2. Iterate through the array from index 1:
   - Update `currentSum`:
     - `currentSum = max(nums[i], currentSum + nums[i])`.
   - Update `maxSum`:
     - `maxSum = max(maxSum, currentSum)`.
3. Return `maxSum` as the largest sum.

---

### **2. Algorithm (Flashcard Style)**
1. **Input:** An array `nums` of size \(n\).
2. **Initialize:** 
   - `currentSum = nums[0]`
   - `maxSum = nums[0]`
3. **Iterate Over the Array:**
   - For each element starting from the second:
     - Update `currentSum = max(nums[i], currentSum + nums[i])`.
     - Update `maxSum = max(maxSum, currentSum)`.
4. **Output:** Return `maxSum`.

---

### **3. Pseudocode**
```
function maxSubArray(nums):
    currentSum ← nums[0]
    maxSum ← nums[0]

    for i from 1 to length(nums) - 1:
        currentSum ← max(nums[i], currentSum + nums[i])
        maxSum ← max(maxSum, currentSum)

    return maxSum
```

---

### **4. Complexity Analysis**
- **Time Complexity:** \(O(n)\)
  - Single pass through the array.
- **Space Complexity:** \(O(1)\)
  - No additional data structures are used.

---

### **5. C++ Code**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}
```

---

### **6. How to Extend Kadane’s Algorithm to Return the Subarray**
To return the actual subarray with the maximum sum, track the start and end indices of the subarray:

1. Maintain a `tempStart` variable to track the start of the current subarray.
2. When starting a new subarray (`currentSum = nums[i]`), update `tempStart = i`.
3. When updating `maxSum`, set:
   - `start = tempStart`
   - `end = i` (current index).

**Modified C++ Code to Track Subarray:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums, int& start, int& end) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    int tempStart = 0;

    start = 0;
    end = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart = i; // Start a new subarray
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart; // Update the start index
            end = i;           // Update the end index
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int start = 0, end = 0;
    int result = maxSubArray(nums, start, end);

    cout << "The maximum subarray sum is: " << result << endl;
    cout << "The subarray is: [";
    for (int i = start; i <= end; i++) {
        cout << nums[i];
        if (i < end) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
```

---

### **7. Example Walkthrough**
#### Input:
```plaintext
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

#### Execution:
- Initialize: `currentSum = -2, maxSum = -2, start = 0, end = 0`.
- Step-by-step:
  - i=1: `nums[1] = 1`
    - `currentSum = max(1, -2 + 1) = 1`
    - `maxSum = max(-2, 1) = 1`
    - Update start and end indices: `start = 1, end = 1`.
  - i=2: `nums[2] = -3`
    - `currentSum = max(-3, 1 - 3) = -2`
    - `maxSum remains 1`.
  - i=3: `nums[3] = 4`
    - `currentSum = max(4, -2 + 4) = 4`
    - `maxSum = max(1, 4) = 4`
    - Update start and end indices: `start = 3, end = 3`.
  - i=4: `nums[4] = -1`
    - `currentSum = max(-1, 4 - 1) = 3`
    - `maxSum remains 4`.
  - i=5: `nums[5] = 2`
    - `currentSum = max(2, 3 + 2) = 5`
    - `maxSum = max(4, 5) = 5`
    - Update start and end indices: `start = 3, end = 5`.
  - i=6: `nums[6] = 1`
    - `currentSum = max(1, 5 + 1) = 6`
    - `maxSum = max(5, 6) = 6`
    - Update end index: `end = 6`.

#### Output:
```plaintext
The maximum subarray sum is: 6
The subarray is: [4, -1, 2, 1]
```

---

This implementation is efficient and tracks both the maximum sum and the subarray that produces it.