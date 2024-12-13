#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int majorityelement(vector<int> &nums){
    map<int, int> counter;

    for(auto &num: nums){
        counter[num]++;
    }

    for(auto &pair: counter){
        if(pair.second > nums.size()/2){
            cout<<pair.first;
            return pair.first;
        }
    }

    return 0;

}

int main(){

    vector<int> nums;
    int n;
    int ele;

    cout<<"Enter the no.of elements of the array :";
    cin>>n;

    cout<<"Enter the elemenets of the array :";
    for(int i = 0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    majorityelement(nums);
    return 0;
}