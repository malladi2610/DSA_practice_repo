# Algorithm


# Binary Search in a 2D Matrix

## Problem Statement
**Input:**  
- A 2D matrix `matrix` of size \( m \times n \).
- An integer `target`.

**Output:**  
- Return `true` if the `target` exists in the matrix.
- Return `false` if the `target` is not found.

## Binary Search Logic
1. Set `low = 0` and `high = m \times n - 1`.
2. While `low <= high`:
   - Compute `mid = low + (high - low) / 2`.
   - Calculate:
     - `row = mid / n`
     - `col = mid % n`
   - If `matrix[row][col] == target`, return `true`.
   - Else if `matrix[row][col] < target`, set `low = mid + 1`.
   - Else, set `high = mid - 1`.

3. Return `false` if the `target` is not found.

# Pseudocode

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





