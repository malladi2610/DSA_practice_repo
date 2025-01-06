#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& nums, int start, int mid, int end) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge two sorted halves
    vector<int> temp;
    int i = start, k = mid + 1;

    while (i <= mid && k <= end) {
        if (nums[i] <= nums[k]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[k++]);
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    while (k <= end) {
        temp.push_back(nums[k++]);
    }

    for (int i = 0; i < temp.size(); i++) {
        nums[start + i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(vector<int>& nums, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int count = 0;

    count += mergeSortAndCount(nums, start, mid);
    count += mergeSortAndCount(nums, mid + 1, end);
    count += mergeAndCount(nums, start, mid, end);

    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSortAndCount(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}
