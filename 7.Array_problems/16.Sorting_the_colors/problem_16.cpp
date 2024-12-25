#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> sort_colors(vector<int> &nums){
    map<int,int> counter;
    vector<int> output;

    for(int num:nums){
        counter[num]++;
    }

    for(const auto &pair: counter){
    cout<<pair.first<<pair.second;
    }

    for(const auto &pair: counter){
        for(int i = 0; i<pair.second; i++){
           output.push_back(pair.first); 
        }
    }

    for(int i = 0; i<output.size(); i++){
    cout<<output[i];
    }

    return output;

}
int main(){
    vector<int> nums;
    int ele;
    int n;

    cout<<"Enter the no.of elements of the array:";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i = 0; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    sort_colors(nums);
    return 0;
}