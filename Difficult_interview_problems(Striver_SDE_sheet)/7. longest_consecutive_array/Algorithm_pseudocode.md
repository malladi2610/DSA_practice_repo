# Algorithm

**Input**: Array `nums` of size *n*.

---

**Steps**:

1. Add all elements of `nums` into a hash set.
2. Initialize `maxLength = 0`.
3. For each number \( x \) in `nums`:
   - If \( x - 1 \) is *not* in the hash set, \( x \) is the start of a sequence.
   - Count the length of the sequence by repeatedly checking \( x, x+1, x+2, \dots \) in the hash set.
   - Update `maxLength` with the length of this sequence.
4. Return `maxLength`.

---

**Output**: Length of the longest consecutive sequence.


# Pseudocode

function longestConsecutive(nums):
    if nums.length == 0:
        return 0

    numSet ← set of all elements in nums
    maxLength ← 0

    for num in nums:
        if num - 1 not in numSet:
            currentNum ← num
            currentLength ← 1

            while currentNum + 1 in numSet:
                currentNum ← currentNum + 1
                currentLength ← currentLength + 1

            maxLength ← max(maxLength, currentLength)

    return maxLength
