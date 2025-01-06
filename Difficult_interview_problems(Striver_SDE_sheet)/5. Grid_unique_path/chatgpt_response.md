### Problem: Unique Paths on a Grid

You need to calculate the number of unique paths a robot can take from the top-left corner to the bottom-right corner of an \( m \times n \) grid, where the robot can only move **right** or **down**.

---

### **1. Approach**

This is a classic **dynamic programming (DP)** problem. The idea is to calculate the number of ways to reach each cell in the grid using the solutions to smaller subproblems.

#### **Key Observations:**
1. **Base Case:**
   - There is only one way to reach any cell in the first row or first column:
     - First row: The robot can only move right.
     - First column: The robot can only move down.

2. **Recursive Relation:**
   - To reach any cell `(i, j)`, the robot must have come either:
     - From the cell above it `(i - 1, j)`, or
     - From the cell to its left `(i, j - 1)`.
   - Thus, the number of unique paths to `(i, j)` is:
     \[
     \text{dp}[i][j] = \text{dp}[i - 1][j] + \text{dp}[i][j - 1]
     \]

3. **Optimization:**
   - Instead of using a 2D `dp` array, we can reduce space complexity by maintaining only a single row of size \( n \), as we only need the values from the previous row.

---

### **2. Algorithm (Flashcard Style)**

1. **Input:** Two integers \( m \) (number of rows) and \( n \) (number of columns).
2. **Steps:**
   - Initialize a 1D array `dp` of size \( n \), with all elements set to 1. This represents the first row of the grid (since there’s only one way to move along the first row).
   - Iterate through each row (from 1 to \( m - 1 \)):
     - For each column (from 1 to \( n - 1 \)), update `dp[j]` as:
       \[
       \text{dp}[j] = \text{dp}[j] + \text{dp}[j - 1]
       \]
       (where `dp[j]` represents the value from the row above and `dp[j - 1]` represents the value from the left).
3. **Output:** Return `dp[n - 1]`, which contains the number of unique paths to the bottom-right corner.

---

### **3. Pseudocode**

```
function uniquePaths(m, n):
    // Step 1: Initialize the DP array with all 1s
    dp ← array of size n, filled with 1

    // Step 2: Iterate through each row, starting from the second row
    for i from 1 to m - 1:
        for j from 1 to n - 1:
            dp[j] = dp[j] + dp[j - 1] // Update dp[j] with the sum of the top and left cells

    // Step 3: Return the bottom-right value
    return dp[n - 1]
```

---

### **4. Complexity Analysis**

- **Time Complexity:** \(O(m \times n)\)
  - We iterate through all the cells in the grid once.
- **Space Complexity:**
  - \(O(n)\) for the optimized 1D DP array.

---

### **5. C++ Code**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Step 1: Initialize the DP array with all 1s
    vector<int> dp(n, 1);

    // Step 2: Iterate through each row, starting from the second row
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1]; // Update dp[j]
        }
    }

    // Step 3: Return the bottom-right value
    return dp[n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows (m): ";
    cin >> m;

    cout << "Enter the number of columns (n): ";
    cin >> n;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
```

---

### **6. Example Walkthrough**

#### **Example Input:**
```plaintext
m = 3, n = 7
```

#### **Execution:**
1. **Initialization:**  
   `dp = [1, 1, 1, 1, 1, 1, 1]` (1D array for the first row).

2. **First Iteration (Row 2):**
   - Update `dp[j]` for \( j = 1 \) to \( j = 6 \):
     \[
     \text{dp} = [1, 2, 3, 4, 5, 6, 7]
     \]

3. **Second Iteration (Row 3):**
   - Update `dp[j]` for \( j = 1 \) to \( j = 6 \):
     \[
     \text{dp} = [1, 3, 6, 10, 15, 21, 28]
     \]

4. **Result:** `dp[n - 1] = 28`.

#### **Output:**
```plaintext
28
```

---

### **Key Insights:**

1. **Dynamic Programming:** The problem is efficiently solved using DP by building on smaller subproblems.
2. **Optimization:** Reducing the space complexity to \(O(n)\) by maintaining a single row of results.
3. **Constraints Handling:** The solution is efficient for the given constraints (\(m, n \leq 100\)).

This approach ensures optimal performance and clarity in implementation.