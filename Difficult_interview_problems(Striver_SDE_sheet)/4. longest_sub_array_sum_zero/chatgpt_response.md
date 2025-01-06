### Problem: Largest Subarray with Sum 0

The task is to find the length of the largest subarray that has a sum equal to 0.

---

### **1. Approach**

The solution uses the **prefix sum technique** combined with a **hash map** to efficiently find subarrays with a sum of 0. 

#### **Key Insights:**
1. **Prefix Sum:** 
   - Compute a running sum (`prefix_sum`) as we iterate through the array.
   - If two indices share the same prefix sum, the elements between those indices must sum to 0.

2. **Hash Map for Prefix Sum Indices:**
   - Use an `unordered_map` to store the earliest occurrence of each prefix sum.
   - If a prefix sum is encountered again, calculate the length of the subarray using the stored index.

3. **Special Case for `prefix_sum == 0`:**
   - If the prefix sum itself becomes 0, the subarray from the start to the current index has a sum of 0.

4. **Efficient Handling of the Longest Subarray:**
   - Store the first occurrence of each prefix sum in the map to ensure we maximize the subarray length.

---

### **2. Algorithm (Flashcard Style)**

1. **Input:** An array `arr` of size \(n\).
2. **Initialize:**
   - `prefix_sum = 0` (to store the cumulative sum).
   - `max_length = 0` (to store the maximum length of subarray with sum 0).
   - `prefixIndices` as an empty hash map.
   - Store `prefixIndices[0] = -1` to handle cases where the subarray starts from index 0.
3. **Iterate Over the Array:**
   - Add `arr[i]` to `prefix_sum`.
   - If `prefix_sum == 0`:
     - Update `max_length = max(max_length, i + 1)`.
   - If `prefix_sum` exists in the hash map:
     - Calculate the subarray length as `i - prefixIndices[prefix_sum]`.
     - Update `max_length = max(max_length, length)`.
   - If `prefix_sum` is not in the hash map, store it with its index (`prefixIndices[prefix_sum] = i`).
4. **Output:** Return `max_length`.

---

### **3. Pseudocode**
```
function longestSubArrayWithSumZero(arr):
    prefix_sum ← 0
    max_length ← 0
    prefixIndices ← empty map
    prefixIndices[0] ← -1 // Handle subarrays starting from index 0

    for i from 0 to length(arr) - 1:
        prefix_sum ← prefix_sum + arr[i]

        if prefix_sum == 0:
            max_length ← max(max_length, i + 1)

        if prefix_sum exists in prefixIndices:
            startIndex ← prefixIndices[prefix_sum]
            length ← i - startIndex
            max_length ← max(max_length, length)
        else:
            prefixIndices[prefix_sum] ← i

    return max_length
```

---

### **4. Complexity Analysis**
- **Time Complexity:** \(O(n)\)
  - Single traversal of the array.
  - Hash map operations (insert and lookup) are \(O(1)\) on average.
- **Space Complexity:** \(O(n)\)
  - The hash map stores at most \(n\) entries (one for each prefix sum).

---

### **5. C++ Code**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubArrayWithSumZero(vector<int>& arr) {
    long long prefix_sum = 0; // Cumulative sum
    int max_length = 0; // Maximum length of subarray with sum 0
    unordered_map<long long, int> prefixIndices; // Map to store prefix sums
    prefixIndices[0] = -1; // Handle subarrays starting from index 0

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];

        // If prefix_sum == 0, the subarray from 0 to i has sum 0
        if (prefix_sum == 0) {
            max_length = max(max_length, i + 1);
        }

        // If prefix_sum is already in the map, calculate the subarray length
        if (prefixIndices.find(prefix_sum) != prefixIndices.end()) {
            int startIndex = prefixIndices[prefix_sum];
            int length = i - startIndex;
            max_length = max(max_length, length);
        } else {
            // Store the prefix_sum and its index
            prefixIndices[prefix_sum] = i;
        }
    }

    return max_length;
}

int main() {
    int n, ele;
    vector<int> arr;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> ele;
        arr.push_back(ele);
    }

    int result = longestSubArrayWithSumZero(arr);
    cout << "The maximum length of the subarray with sum 0 is: " << result << endl;

    return 0;
}
```

---

### **6. Example Walkthrough**

#### **Input:** 
```plaintext
arr = [15, -2, 2, -8, 1, 7, 10, 23]
```

#### **Execution:**
1. **Initialization:** 
   - `prefix_sum = 0`, `max_length = 0`.
   - `prefixIndices = {0: -1}`.
2. **Iterating:**
   - \(i = 0\), `prefix_sum = 15`:
     - Add `prefix_sum` to map: `{0: -1, 15: 0}`.
   - \(i = 1\), `prefix_sum = 13`:
     - Add `prefix_sum` to map: `{0: -1, 15: 0, 13: 1}`.
   - \(i = 2\), `prefix_sum = 15`:
     - Found `prefix_sum` in map at index 0.
     - Subarray length: \(2 - 0 = 2\), update `max_length = 2`.
   - \(i = 3\), `prefix_sum = 7`:
     - Add `prefix_sum` to map: `{0: -1, 15: 0, 13: 1, 7: 3}`.
   - \(i = 4\), `prefix_sum = 8`:
     - Add `prefix_sum` to map: `{0: -1, 15: 0, 13: 1, 7: 3, 8: 4}`.
   - \(i = 5\), `prefix_sum = 15`:
     - Found `prefix_sum` in map at index 0.
     - Subarray length: \(5 - 0 = 5\), update `max_length = 5`.
   - \(i = 6\), `prefix_sum = 25`:
     - Add `prefix_sum` to map: `{... , 25: 6}`.
   - \(i = 7\), `prefix_sum = 48`:
     - Add `prefix_sum` to map: `{... , 48: 7}`.
3. **Result:** `max_length = 5`.

#### **Output:**
```plaintext
5
```

This solution efficiently computes the largest subarray with a sum of 0 using \(O(n)\) time and \(O(n)\) space.