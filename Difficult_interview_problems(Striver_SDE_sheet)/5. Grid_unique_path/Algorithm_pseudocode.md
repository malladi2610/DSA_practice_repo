# Algorithm

### Algorithm: Count Unique Paths in a Grid

#### Input:
- Two integers `m` (number of rows) and `n` (number of columns).

#### Steps:
1. Initialize a 1D array `dp` of size `n`, with all elements set to `1`.  
   - This represents the first row of the grid (since there’s only one way to move along the first row).

2. Iterate through each row (from 1 to `m - 1`):
   - For each column (from 1 to `n - 1`), update `dp[j]` as:
     ```
     dp[j] = dp[j] + dp[j - 1]
     ```
     - Here, `dp[j]` represents the value from the row above, and `dp[j - 1]` represents the value from the left.

#### Output:
- Return `dp[n - 1]`, which contains the number of unique paths to the bottom-right corner.


# Pseudocode
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

# A detailed explanantion on the optimisation (Having a 1 D array than 2D array)
### **Understanding the Optimization: Reducing from 2D DP Array to 1D DP Array**

Let’s break it down step by step:

---

### **1. Why Use a 2D DP Array Initially?**
When solving the problem using **dynamic programming**, the idea is to compute the number of unique paths for every cell in the \( m \times n \) grid. This is done using the formula:
\[
\text{dp}[i][j] = \text{dp}[i-1][j] + \text{dp}[i][j-1]
\]
This means:
- To calculate the number of paths to reach cell `(i, j)`, we add:
  - The number of paths from the cell above `(i-1, j)` (moving down).
  - The number of paths from the cell to the left `(i, j-1)` (moving right).

In a **2D DP array**, we store the number of paths for every cell in the grid:
- `dp[i][j]` stores the number of paths to cell `(i, j)`.

---

### **2. Observing Redundancy in 2D DP**
To compute `dp[i][j]`, we only need:
- The value from **the same column in the previous row** (`dp[i-1][j]`).
- The value from **the previous column in the same row** (`dp[i][j-1]`).

**This means we only need the current row and the previous row at any point in time.**

---

### **3. Optimization: Use a Single 1D Array**
Instead of maintaining a **2D array**, we can compress the space by using a **1D array** to represent only a single row of the grid at a time.

#### **How It Works:**
1. Use a 1D array `dp` of size \( n \) (number of columns).
   - Each element `dp[j]` represents the number of paths to reach the cell in the current row at column \( j \).
2. Update the `dp` array as we iterate row by row:
   - **`dp[j]` = `dp[j]` + `dp[j-1]`**:
     - `dp[j]` already contains the value from the previous row (same column).
     - `dp[j-1]` contains the value from the current row (previous column).

#### **Key Insight:**
The single 1D array gets updated "in place," meaning the values from the previous row are overwritten by the values for the current row.

---

### **4. Example Walkthrough**

#### Without Optimization (2D DP):
For a \( 3 \times 7 \) grid:
- 2D DP array:
\[
\text{dp} = 
\begin{bmatrix}
1 & 1 & 1 & 1 & 1 & 1 & 1 \\
1 & 2 & 3 & 4 & 5 & 6 & 7 \\
1 & 3 & 6 & 10 & 15 & 21 & 28
\end{bmatrix}
\]
Here:
- Row 0: Paths are all 1 (can only move right).
- Row 1: Calculated using values from Row 0.
- Row 2: Calculated using values from Row 1.

#### With Optimization (1D DP):
Instead of a 2D array, use a single 1D array:
1. Start with:
   \[
   \text{dp} = [1, 1, 1, 1, 1, 1, 1]
   \]
2. For Row 1, update `dp` in place:
   - For \( j = 1 \): `dp[1] = dp[1] + dp[0] = 1 + 1 = 2`
   - For \( j = 2 \): `dp[2] = dp[2] + dp[1] = 1 + 2 = 3`
   - Continue updating:
     \[
     \text{dp} = [1, 2, 3, 4, 5, 6, 7]
     \]
3. For Row 2, update `dp` again:
   - For \( j = 1 \): `dp[1] = dp[1] + dp[0] = 2 + 1 = 3`
   - For \( j = 2 \): `dp[2] = dp[2] + dp[1] = 3 + 3 = 6`
   - Continue updating:
     \[
     \text{dp} = [1, 3, 6, 10, 15, 21, 28]
     \]

Result:
- Final `dp` array contains the number of paths for the last row.
- Bottom-right corner value: `dp[n-1] = 28`.

---

### **5. Benefits of Optimization**
1. **Reduced Space Complexity:**
   - **2D DP:** Requires \(O(m \times n)\) space for the entire grid.
   - **1D DP:** Requires only \(O(n)\) space for one row.

2. **Same Time Complexity:**
   - Both approaches have \(O(m \times n)\) time complexity, as we still iterate through all cells.

---

### **Simplified Explanation**
- In the 2D DP approach, we compute values row by row, but the previous rows are no longer needed after processing the current row.
- By reusing a single 1D array, we save space without affecting correctness. Each value in the array is updated in place to reflect the number of ways to reach the current cell using the values from the row above and the column to the left.

---

This optimization is commonly used in grid-based problems to save space while preserving efficiency.