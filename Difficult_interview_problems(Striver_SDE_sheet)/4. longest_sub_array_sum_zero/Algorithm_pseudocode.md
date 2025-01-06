# Algorithm

### Algorithm: Find the Length of the Longest Subarray with Sum 0

#### Input:
- An array `arr` of size `n`.

#### Initialize:
- `prefix_sum = 0` (to store the cumulative sum).
- `max_length = 0` (to store the maximum length of the subarray with sum 0).
- `prefixIndices` as an empty hash map.
- Store `prefixIndices[0] = -1` to handle cases where the subarray starts from index 0.

#### Iterate Over the Array:
1. Add `arr[i]` to `prefix_sum`.
2. If `prefix_sum == 0`:
   - Update `max_length = max(max_length, i + 1)`.
3. If `prefix_sum` exists in the hash map:
   - Calculate the subarray length as `i - prefixIndices[prefix_sum]`.
   - Update `max_length = max(max_length, length)`.
4. If `prefix_sum` is not in the hash map:
   - Store it with its index (`prefixIndices[prefix_sum] = i`).

#### Output:
- Return `max_length`.


# Pseudocode
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
