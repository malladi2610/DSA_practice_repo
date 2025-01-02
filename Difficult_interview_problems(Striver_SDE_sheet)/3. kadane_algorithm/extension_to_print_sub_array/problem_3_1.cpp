#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums, int& start, int& end) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    int tempStart = 0;

    start = 0;
    end = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart = i; // Start a new subarray
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart; // Update the start index
            end = i;           // Update the end index
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int start = 0, end = 0;
    int result = maxSubArray(nums, start, end);

    cout << "The maximum subarray sum is: " << result << endl;
    cout << "The subarray is: [";
    for (int i = start; i <= end; i++) {
        cout << nums[i];
        if (i < end) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
