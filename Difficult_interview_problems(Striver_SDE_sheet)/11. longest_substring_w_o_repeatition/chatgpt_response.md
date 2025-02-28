### **Problem: Longest Substring Without Repeating Characters**

Given a string \( s \), find the length of the **longest substring** without repeating characters.

---

### **1. Approach**

To solve this problem efficiently, we use the **Sliding Window Technique** with a hash map to track characters and their indices. The key idea is to expand the window to include characters until a repetition is found, then adjust the window to remove the repeated character.

---

#### **Steps:**
1. **Sliding Window:**  
   - Use two pointers (`start` and `end`) to represent the current substring window.
   - Start with both pointers at the beginning of the string.

2. **Hash Map to Track Characters:**  
   - Use a hash map (`charIndex`) to store the most recent index of each character in the current window.

3. **Expand and Adjust the Window:**
   - Move the `end` pointer to include the next character.
   - If the character is already in the current window:
     - Adjust the `start` pointer to exclude the repeated character and maintain a valid substring.
   - Update the character's index in the hash map.

4. **Track Maximum Length:**  
   - At each step, calculate the length of the current substring as `end - start + 1`.
   - Update the maximum length if the current length is greater.

5. **Output the Result:**  
   - Return the maximum length.

---

### **Algorithm**

1. **Input:** A string \( s \).
2. **Initialize:**
   - Hash map (`charIndex`) to track the last seen index of each character.
   - Two pointers: `start = 0` and `maxLength = 0`.
3. **Iterate Over the String:**
   - For each character at index \( \text{end} \):
     - If the character is already in `charIndex` and its index is within the current window (`charIndex[char] >= start`):
       - Move the `start` pointer to `charIndex[char] + 1`.
     - Update the character's index in `charIndex`.
     - Calculate the length of the current substring as `end - start + 1`.
     - Update `maxLength` if the current length is greater.
4. **Output:** Return `maxLength`.

---

### **Pseudocode**

```
function longestSubstringWithoutRepeating(s):
    charIndex ← empty hash map
    start ← 0
    maxLength ← 0

    for end from 0 to s.length - 1:
        if s[end] exists in charIndex and charIndex[s[end]] >= start:
            start ← charIndex[s[end]] + 1

        charIndex[s[end]] ← end
        maxLength ← max(maxLength, end - start + 1)

    return maxLength
```

---

### **Complexity Analysis**

- **Time Complexity:** \( O(n) \)
  - Each character is processed at most twice (once by `end` and once by `start`).
- **Space Complexity:** \( O(min(n, \text{charset})) \)
  - The hash map stores up to \( \text{charset} \) distinct characters (e.g., 26 for lowercase English letters).

---

### **C++ Code**

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int start = 0, maxLength = 0;

    for (int end = 0; end < s.length(); end++) {
        // If the character is already in the map and within the current window
        if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1; // Move the start to the right of the repeated character
        }

        // Update the character's index in the map
        charIndex[s[end]] = end;

        // Update the maximum length
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
```

---

### **Example Walkthrough**

#### Input:
```plaintext
s = "abcabcbb"
```

#### Execution:

| Step | \( \text{end} \) | Character | \( \text{start} \) | Hash Map (`charIndex`)   | Substring Length | \( \text{maxLength} \) |
|------|------------------|-----------|---------------------|--------------------------|------------------|---------------------|
| 1    | 0                | 'a'       | 0                   | {'a': 0}                | 1                | 1                   |
| 2    | 1                | 'b'       | 0                   | {'a': 0, 'b': 1}        | 2                | 2                   |
| 3    | 2                | 'c'       | 0                   | {'a': 0, 'b': 1, 'c': 2}| 3                | 3                   |
| 4    | 3                | 'a'       | 1                   | {'a': 3, 'b': 1, 'c': 2}| 3                | 3                   |
| 5    | 4                | 'b'       | 2                   | {'a': 3, 'b': 4, 'c': 2}| 3                | 3                   |
| 6    | 5                | 'c'       | 3                   | {'a': 3, 'b': 4, 'c': 5}| 3                | 3                   |
| 7    | 6                | 'b'       | 5                   | {'a': 3, 'b': 6, 'c': 5}| 2                | 3                   |
| 8    | 7                | 'b'       | 7                   | {'a': 3, 'b': 7, 'c': 5}| 1                | 3                   |

#### Output:
```plaintext
3
```

---

### **Key Insights**
1. The **sliding window technique** ensures the substring being processed is always valid.
2. The **hash map** provides constant-time lookups to detect repeated characters.
3. This solution handles all constraints efficiently, including special cases like an empty string or all identical characters.




# More detailed explanantion of the code

Let’s break down the code step-by-step to understand how it works.

---

### **Goal**
To find the **length of the longest substring** without repeating characters in the given string \( s \).

---

### **Key Variables**
1. **`unordered_map<char, int> charIndex`:**
   - Tracks the last seen index of each character.
   - Key: Character in the string.
   - Value: Index of the character in \( s \).

2. **`int start = 0`:**
   - Marks the starting index of the current substring being checked.

3. **`int maxLength = 0`:**
   - Tracks the maximum length of substrings without repeating characters.

4. **Loop Variable `end`:**
   - Iterates through the string \( s \), representing the current character.

---

### **How It Works**

#### 1. **Outer Loop:**
   ```cpp
   for (int end = 0; end < s.length(); end++) {
   ```
   - The `end` pointer moves through each character in the string, representing the end of the current substring.

---

#### 2. **Check for Repeated Characters:**
   ```cpp
   if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
       start = charIndex[s[end]] + 1;
   }
   ```
   - **What This Does:**
     - Checks if the character `s[end]` is already in `charIndex` (i.e., it has appeared before).
     - Verifies if the last occurrence of `s[end]` is **within the current substring** (`charIndex[s[end]] >= start`).
   - **If True:**
     - Move the `start` pointer to the right of the last occurrence of the repeated character (`start = charIndex[s[end]] + 1`).
   - **Why This Works:**
     - This ensures the substring from `start` to `end` remains valid (i.e., no repeating characters).

---

#### 3. **Update `charIndex` Map:**
   ```cpp
   charIndex[s[end]] = end;
   ```
   - Records or updates the most recent index of the character `s[end]`.

---

#### 4. **Calculate Current Substring Length:**
   ```cpp
   maxLength = max(maxLength, end - start + 1);
   ```
   - Computes the length of the current substring as:
     \[
     \text{Length} = \text{end} - \text{start} + 1
     \]
   - Updates `maxLength` if the current substring is longer than the previous maximum.

---

### **Return the Result**
   ```cpp
   return maxLength;
   ```
   - Returns the length of the longest substring without repeating characters.

---

### **Example Walkthrough**

#### Input:
```plaintext
s = "abcabcbb"
```

#### Execution:

| Step | `end` | `s[end]` | `charIndex`              | `start` | Substring      | Length | `maxLength` |
|------|-------|----------|--------------------------|---------|----------------|--------|-------------|
| 1    | 0     | a        | {a: 0}                  | 0       | "a"            | 1      | 1           |
| 2    | 1     | b        | {a: 0, b: 1}            | 0       | "ab"           | 2      | 2           |
| 3    | 2     | c        | {a: 0, b: 1, c: 2}      | 0       | "abc"          | 3      | 3           |
| 4    | 3     | a        | {a: 3, b: 1, c: 2}      | 1       | "bca"          | 3      | 3           |
| 5    | 4     | b        | {a: 3, b: 4, c: 2}      | 2       | "cab"          | 3      | 3           |
| 6    | 5     | c        | {a: 3, b: 4, c: 5}      | 3       | "abc"          | 3      | 3           |
| 7    | 6     | b        | {a: 3, b: 6, c: 5}      | 5       | "cb"           | 2      | 3           |
| 8    | 7     | b        | {a: 3, b: 7, c: 5}      | 7       | "b"            | 1      | 3           |

---

#### Output:
```plaintext
maxLength = 3
```

---

### **Key Insights**
1. **Sliding Window:** The `start` pointer adjusts dynamically to maintain a valid substring.
2. **Hash Map:** Tracks the last occurrence of each character efficiently, avoiding the need for nested loops.
3. **Efficient Updates:** Both `start` and `end` pointers move forward, ensuring \( O(n) \) time complexity.

This approach handles the problem constraints effectively and ensures correctness for all edge cases.