#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void linear_search(vector<int> &nums, int k){
    int n = nums.size();
    for(int i = 0; i<n;i++){
        if(nums[i] == k){
            cout<<"Element "<<nums[i]<<" is found at the "<<i+1<<endl;
            return;
        }
    }
}

int main(){
    vector<int> nums;
    int n;
    int k;
    cout<<"Enter the elements of the array";
    cin>>n;
    cout<<"The elements of the array are : ";
    for(auto it = 0; it != n; it++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    cout<<"Enter the value of the element to be found";
    cin>>k;

    linear_search(nums,k);
}