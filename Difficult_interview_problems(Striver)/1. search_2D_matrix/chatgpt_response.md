
# Question

Search 2 D matrix

"You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity."

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104



# Answer

### Problem: Search in a 2D Matrix

---

### **1. Approach:**
This is a **search problem in a sorted 2D matrix**, and the matrix has two key properties:
1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

These properties allow us to treat the 2D matrix as a **flattened 1D sorted array**. Using this observation, we can apply **binary search** across the entire matrix to achieve \(O(\log(m \times n))\) time complexity.

#### **Steps to Solve:**
1. Use the dimensions of the matrix \(m\) (rows) and \(n\) (columns) to simulate a flattened 1D array:
   - The **index in the 1D array** maps to **row and column indices** in the 2D matrix as follows:
     - Row: \( \text{row} = \text{index} / n \)
     - Column: \( \text{col} = \text{index} \% n \)

2. Apply **binary search**:
   - Start with `low = 0` and `high = m \times n - 1`.
   - Compute the middle index `mid` in the flattened array.
   - Map `mid` back to the 2D matrix:
     - `row = mid / n`
     - `col = mid % n`
   - Compare the matrix element at `[row][col]` with the target:
     - If equal, return `true`.
     - If smaller, move to the right half (`low = mid + 1`).
     - If larger, move to the left half (`high = mid - 1`).

3. If the loop ends without finding the target, return `false`.

---

### **2. Algorithm (Flashcard Style):**
1. **Input:** A 2D matrix `matrix` of size \(m \times n\) and an integer `target`.
2. **Binary Search Logic:**
   - Set `low = 0` and `high = m \times n - 1`.
   - While `low <= high`:
     1. Compute `mid = low + (high - low) / 2`.
     2. Calculate `row = mid / n` and `col = mid % n`.
     3. If `matrix[row][col] == target`, return `true`.
     4. Else if `matrix[row][col] < target`, set `low = mid + 1`.
     5. Else, set `high = mid - 1`.
3. **Output:** Return `false` if `target` is not found.

---

### **3. Pseudocode:**
```
function searchMatrix(matrix, target):
    m ← number of rows in matrix
    n ← number of columns in matrix

    low ← 0
    high ← m * n - 1

    while low ≤ high:
        mid ← low + (high - low) / 2
        row ← mid / n
        col ← mid % n

        if matrix[row][col] == target:
            return true
        else if matrix[row][col] < target:
            low ← mid + 1
        else:
            high ← mid - 1

    return false
```

---

### **4. Complexity Analysis:**
- **Time Complexity:** \(O(\log(m \times n))\)
  - Binary search over \(m \times n\) elements in the matrix.
- **Space Complexity:** \(O(1)\)
  - Constant space is used.

---

### **5. C++ Implementation:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter the target: ";
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Target found in the matrix!" << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
```

---

### **6. Example Walkthrough:**
#### Input:
```plaintext
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 3
```

#### Execution:
1. \(m = 3, n = 4, \text{low} = 0, \text{high} = 11\)
2. Compute \( \text{mid} = 5 \), map to \( \text{row} = 5 / 4 = 1, \text{col} = 5 \% 4 = 1 \), element = `matrix[1][1] = 11`.
3. \(11 > 3\), so \( \text{high} = 4 \).
4. Compute \( \text{mid} = 2 \), map to \( \text{row} = 2 / 4 = 0, \text{col} = 2 \% 4 = 2 \), element = `matrix[0][2] = 5`.
5. \(5 > 3\), so \( \text{high} = 1 \).
6. Compute \( \text{mid} = 0 \), map to \( \text{row} = 0 / 4 = 0, \text{col} = 0 \% 4 = 0 \), element = `matrix[0][0] = 1`.
7. \(1 < 3\), so \( \text{low} = 1 \).
8. Compute \( \text{mid} = 1 \), map to \( \text{row} = 1 / 4 = 0, \text{col} = 1 \% 4 = 1 \), element = `matrix[0][1] = 3`.
9. Found `target = 3`.

#### Output:
```plaintext
true
```

This approach satisfies the \(O(\log(m \times n))\) complexity requirement.