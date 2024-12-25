#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> &nums, int k){



    unordered_map<long long, int> space;
    
    if(nums.size() == 2){
        if(nums[0] + nums[1] == k){
            cout<<"The place values are "<<0<<1;
            return {0,1};
        }
        else{
            return {};
        }
    }
    
    
    
    for(int i = 0; i<nums.size();i++){
        long long complement = k - nums[i];

        if(space.find(complement) != space.end()){
            cout << "The place values are {"
         << space[complement] << ", " << i << "}\n";
            return {space[complement], i};
        }
    
        space[nums[i]] = i;
    }

    return {};
}

int main(){
vector<int> nums;
int k;
int ele;
int n;

cout<<"Enter the no.o elements of the array :";
cin>>n;

cout<<"Enter the elements of the array:";
for(int i=0; i<n; i++){
    cin>>ele;
    nums.push_back(ele);
}

cout<<"Enter the sum element: ";
cin>>k;

two_sum(nums, k);
return 0;
}