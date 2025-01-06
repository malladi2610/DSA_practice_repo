#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : nums) {
        // Only start a sequence if `num - 1` is not in the set
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count the length of the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive sequence: " << longestConsecutive(nums) << endl;
    return 0;
}
