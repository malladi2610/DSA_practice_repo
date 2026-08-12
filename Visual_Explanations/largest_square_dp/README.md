# Largest Square of 1s - Visual DP Notes

This folder explains the dynamic programming solution for:

> Find the size of the largest square sub-matrix made only of `1`s.

Open `index.html` in a browser for an interactive walkthrough.

## Core Memory Hook

`dp[i][j]` means:

> The size of the biggest all-`1` square whose bottom-right corner is cell `(i, j)`.

For a cell containing `1`:

```cpp
dp[i][j] = 1 + min(top, left, diagonal)
```

where:

```cpp
top      = dp[i - 1][j]
left     = dp[i][j - 1]
diagonal = dp[i - 1][j - 1]
```

The `min` is used because a square can only grow if all three neighboring directions can support the same size.

## Example

Input matrix:

```text
1 1 0 1 0
1 1 1 1 1
0 0 1 1 1
0 0 1 1 1
1 1 0 0 0
```

Final DP matrix:

```text
1 1 0 1 0
1 2 1 1 1
0 0 1 2 2
0 0 1 2 3
1 1 0 0 0
```

The answer is `3`, because the largest square ends at the cell whose DP value is `3`.

