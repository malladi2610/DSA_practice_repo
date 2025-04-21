/* Library Functions */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Problem-specific function */
int maxProductSubarray(vector<int> &nums) {
    int max_product = nums[0];
    int curr_max = nums[0];
    int curr_min = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < 0)
            swap(curr_max, curr_min);  // Negative flips max/min

        curr_max = max(nums[i], nums[i] * curr_max);
        curr_min = min(nums[i], nums[i] * curr_min);

        max_product = max(max_product, curr_max);
    }
    
    return max_product;
}

/* Main function */
int main(){
    vector<int> nums;
    int n, ele;

    cout << "Enter the number of elements of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> ele;
        nums.push_back(ele);
    }

    int result = maxProductSubarray(nums);
    cout << "The maximum product of any subarray is: " << result << endl;
    return 0;
}
