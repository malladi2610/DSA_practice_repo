#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longest_consecutive_array(vector<int> &nums){
    if(nums.size() == 0){
        return 0;
    }

    unordered_set<int> numset(nums.begin(), nums.end());
    int max_length = 0;

    for(int num : numset){
        if(numset.find(num - 1) == numset.end()){
            int currentnum = num;
            int currentlength = 1;

            while(numset.find(currentnum + 1) != numset.end()){
                currentnum++;
                currentlength++;

            }
            max_length = max(max_length, currentlength);
        }
    }
    cout<<"The max_length is"<<max_length;
    return max_length;
}

int main(){
    int n;
    int ele;
    vector<int> nums;

    cout<<"Enter the no.of elements of the vector :";
    cin>>n;

    cout<<"Enter the elements of the vector :";
    for(int i = 0; i< n; i++){
        cin>>ele;
        nums.push_back(ele);
    }
    longest_consecutive_array(nums);
    return 0;
}