#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int print_max_sum_sub_array(vector<int> &nums, int start, int end){
    cout<<"The subarray with the maximum sum is:";
    for(int i = start; i<=end; i++){
        cout<<nums[i];
        if(i<end) cout<<",";
    }

    return 0;

}

int kadane_algorithm(vector<int> nums){
    int current_sum = nums[0];
    int sum = nums[0];
    int tempstart = 0;
    int start = 0;
    int end = 0;

    if(nums.size() == 1){
        
        return nums[0];
    }

    for(int i = 0; i<nums.size(); i++){
       if(nums[i] > current_sum + nums[i]){
        current_sum = nums[i];
        tempstart = i;
       }
       else{
        current_sum += nums[i];
       }

       if(current_sum > sum){
        sum = current_sum;
        start = tempstart;
        end = i;
       }


    }
    print_max_sum_sub_array(nums, start, end);
    cout<<"The sum of the elements is: "<<sum;
    return sum;
}

int main(){

    int n;
    vector<int> nums;
    int ele;

    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n;i++){
        cin>>ele;

        nums.push_back(ele);
    }

    kadane_algorithm(nums);
    return 0;
}