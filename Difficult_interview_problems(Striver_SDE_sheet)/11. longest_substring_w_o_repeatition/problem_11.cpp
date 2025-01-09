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
