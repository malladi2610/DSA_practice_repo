# Algorithm

### Input:
An array `nums` of size `n`.

### Steps to Solve:

1. **Initialize**:
   - `currentSum = nums[0]`
   - `maxSum = nums[0]`

2. **Iterate Over the Array**:
   - For each element starting from the second:
     - Update `currentSum = max(nums[i], currentSum + nums[i])`.
     - Update `maxSum = max(maxSum, currentSum)`.

3. **Output**:
   - Return `maxSum`.


# Pseudocode

function maxSubArray(nums):
    currentSum ← nums[0]
    maxSum ← nums[0]

    for i from 1 to length(nums) - 1:
        currentSum ← max(nums[i], currentSum + nums[i])
        maxSum ← max(maxSum, currentSum)

    return maxSum
