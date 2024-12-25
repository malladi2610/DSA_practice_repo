## Problem Description

### Input:
An array `nums` of size `n` and an integer `target`.

### Steps to Solve:

1. **Sort the Array**:
   - Sort `nums` in ascending order.

2. **Iterate Over the Array**:
   - Use two nested loops for indices `i` and `j` to fix the first two numbers.
   - For the remaining two numbers, use two pointers `left` and `right`.

3. **Calculate the Current Sum**:
   - Compute `current_sum = nums[i] + nums[j] + nums[left] + nums[right]`.

4. **Check the Conditions**:
   - If `current_sum == target`, add the quadruplet to the result.
   - If `current_sum < target`, move `left` forward to increase the sum.
   - If `current_sum > target`, move `right` backward to decrease the sum.

5. **Handle Duplicates**:
   - Skip duplicates for all four indices to ensure unique quadruplets.

### Output:
Return the result containing all unique quadruplets.



# Pseudocode
function fourSum(nums, target):
    sort(nums)
    result ← []

    for i from 0 to length(nums) - 4:
        if i > 0 and nums[i] == nums[i-1]: 
            continue  // Skip duplicate for the first number

        for j from i+1 to length(nums) - 3:
            if j > i+1 and nums[j] == nums[j-1]:
                continue  // Skip duplicate for the second number

            left ← j+1
            right ← length(nums) - 1

            while left < right:
                current_sum ← nums[i] + nums[j] + nums[left] + nums[right]

                if current_sum == target:
                    result.append([nums[i], nums[j], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left++
                    while left < right and nums[right] == nums[right-1]:
                        right--
                    left++
                    right--
                else if current_sum < target:
                    left++
                else:
                    right--

    return result

