Here's a step-by-step approach to understanding and solving the "Product of Array Except Self" problem:

---

### 1. Approach to Solve the Problem:
  
#### How to think about it:
- **No division operation allowed:** You can't simply multiply all numbers and divide by each element.
- **Linear complexity (O(n)):** You need to solve it in a single pass or multiple linear passes.
- **Prefix and Suffix Products:**
  - Calculate the product of all elements to the left of each index.
  - Calculate the product of all elements to the right of each index.
- Multiply these two products to get the final result at each position.

#### Building Blocks (C++ Concepts):
- **Arrays/Vectors:** To store prefix and suffix products.
- **Loops:** Iterate through the array to compute prefix and suffix.
- **Multiplication and accumulation:** Basic arithmetic operations.

**Technique Used:**  
- **Prefix-Suffix product (Two-Pass method)**

---

### 2. Algorithm (Flashcard):

**Step-by-step solution:**
- Initialize two arrays (`leftProduct`, `rightProduct`) each of length equal to input array size.
- Calculate `leftProduct` array by traversing from left to right:
  - `leftProduct[i] = nums[i-1] * leftProduct[i-1]`
- Calculate `rightProduct` array by traversing from right to left:
  - `rightProduct[i] = nums[i+1] * rightProduct[i+1]`
- Finally, multiply corresponding elements from `leftProduct` and `rightProduct` arrays to form the result array.

---

### 3. Pseudocode:
```
function productExceptSelf(nums):
    n = size of nums
    leftProduct = array of size n initialized to 1
    rightProduct = array of size n initialized to 1
    answer = array of size n

    for i from 1 to n-1:
        leftProduct[i] = nums[i-1] * leftProduct[i-1]

    for i from n-2 down to 0:
        rightProduct[i] = nums[i+1] * rightProduct[i+1]

    for i from 0 to n-1:
        answer[i] = leftProduct[i] * rightProduct[i]

    return answer
```

---

### 4. Complexity Analysis:

- **Time Complexity:** O(n)  
  *(Linear complexity as we traverse the array a constant number of times.)*

- **Space Complexity:** O(n)  
  *(Two additional arrays used for storing prefix and suffix products.)*

_Note: The space complexity can be reduced to O(1) if the output array is not counted, but typically O(n) is acceptable here._

---

### 5. Detailed C++ Code:

Here's the C++ implementation following your coding structure:

```cpp
/* Library Functions */
#include <iostream>
#include <vector>
using namespace std;

/* Problem Specific Function */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftProduct(n, 1);
    vector<int> rightProduct(n, 1);
    vector<int> answer(n);

    // Compute prefix products
    for (int i = 1; i < n; i++) {
        leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
    }

    // Compute suffix products
    for (int i = n - 2; i >= 0; i--) {
        rightProduct[i] = nums[i + 1] * rightProduct[i + 1];
    }

    // Combine prefix and suffix products
    for (int i = 0; i < n; i++) {
        answer[i] = leftProduct[i] * rightProduct[i];
    }

    return answer;
}

/* Main Function */
int main() {
    vector<int> nums;
    int n, ele;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> ele;
        nums.push_back(ele);
    }

    vector<int> result = productExceptSelf(nums);

    cout << "Output: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
```

---

### Example Run:
```
Enter the number of elements: 4
Enter the elements of the array: 1 2 3 4
Output: 24 12 8 6
```

This implementation strictly adheres to your requirements and can easily be adapted for competitive coding.