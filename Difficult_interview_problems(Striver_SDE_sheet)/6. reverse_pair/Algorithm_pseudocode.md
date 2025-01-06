# Algorithm
**Input**: Array `nums` of size *n*.

---

**Steps**:

1. Define a recursive function `mergeSortAndCount`:
   - If the array has 1 element, return `0` (base case).
   - Divide the array into two halves.
   - Count reverse pairs in the left half, right half, and across halves.
   - Merge the two halves while maintaining sorted order.

2. During the merge step:
   - Use two pointers to count reverse pairs across the two halves efficiently.

---

**Output**: Total count of reverse pairs.


# Pseudo code
function reversePairs(nums):
    return mergeSortAndCount(nums, 0, nums.length - 1)

function mergeSortAndCount(nums, start, end):
    if start >= end:
        return 0

    mid = (start + end) / 2
    count = 0

    // Count reverse pairs in left and right halves
    count += mergeSortAndCount(nums, start, mid)
    count += mergeSortAndCount(nums, mid + 1, end)

    // Count reverse pairs across the two halves
    j = mid + 1
    for i from start to mid:
        while j <= end and nums[i] > 2 * nums[j]:
            j += 1
        count += (j - (mid + 1))

    // Merge the two halves
    merge(nums, start, mid, end)

    return count

function merge(nums, start, mid, end):
    temp = []
    i = start, j = mid + 1

    while i <= mid and j <= end:
        if nums[i] <= nums[j]:
            temp.append(nums[i])
            i += 1
        else:
            temp.append(nums[j])
            j += 1

    while i <= mid:
        temp.append(nums[i])
        i += 1

    while j <= end:
        temp.append(nums[j])
        j += 1

    for k from 0 to temp.length - 1:
        nums[start + k] = temp[k]
