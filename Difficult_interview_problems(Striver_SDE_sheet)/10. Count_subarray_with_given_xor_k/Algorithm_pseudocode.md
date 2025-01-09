# Algorithm

## Input
- Array \(A\)  
- Integer \(B\)

## Initialize
1. Create a hash map `freq` to store the frequency of `prefixXOR`.
2. Set `prefixXOR = 0` to keep track of the XOR of elements up to the current index.
3. Set `count = 0` to store the total number of subarrays with XOR equal to \(B\).

## Iterate Through the Array
1. Update `prefixXOR` by XORing it with the current element.
2. Check if `prefixXOR == B`:
   - If true, increment `count` (these are subarrays starting from index 0).
3. Check if \(`prefixXOR ⊕ B`\) exists in the hash map `freq`:
   - If true, increment `count` by the frequency of \(`prefixXOR ⊕ B`\) (these are subarrays ending at the current index with XOR equal to \(B\)).
4. Update the frequency of `prefixXOR` in the hash map `freq`.

## Return
- Return `count` as the total number of subarrays whose XOR is equal to \(B\).


# Pseudocode
function countSubarraysWithXOR(A, B):
    freq ← empty hash map
    prefixXOR ← 0
    count ← 0

    for num in A:
        prefixXOR ← prefixXOR ⊕ num

        if prefixXOR == B:
            count ← count + 1

        if (prefixXOR ⊕ B) exists in freq:
            count ← count + freq[prefixXOR ⊕ B]

        freq[prefixXOR] ← freq[prefixXOR] + 1

    return count
