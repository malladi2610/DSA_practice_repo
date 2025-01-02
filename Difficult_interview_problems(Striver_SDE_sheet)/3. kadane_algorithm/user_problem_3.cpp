#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int kadane_algorithm(vector<int> nums){
    int current_sum = nums[0];
    int sum = nums[0];

    if(nums.size() == 1){
        
        return nums[0];
    }

    for(int i = 0; i<nums.size(); i++){
        current_sum = max(nums[i] , current_sum + nums[i]);
        sum = max(sum, current_sum);


    }

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