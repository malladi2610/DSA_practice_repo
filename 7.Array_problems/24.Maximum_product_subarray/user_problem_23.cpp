#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxproduct_subarray(vector<int> &nums){
    int max_product = nums[0];
    int curr_max = nums[0];
    int curr_min = nums[0];

    for(int i = 1; i<nums.size(); i++){
        if(nums[i] < 0){
            swap(curr_max, curr_min);
        }

        curr_max = max(nums[i], nums[i]*curr_max);
        curr_min = min(nums[i], nums[i]*curr_min);

        max_product = max(max_product, curr_max);
    }

    return max_product;
}

int main(){
    int n;
    vector<int> nums;
    int ele;

    cout<<"Enter the no.of elements of the vector";
    cin>>n;

    cout<<"Enter the elements of the vector";
    cin>>ele;
    for(int i =0; i<n;i++){
        nums.push_back(ele);
    }

    maxproduct_subarray(nums);
}