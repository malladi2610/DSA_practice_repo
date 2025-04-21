#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool containDuplicates(vector<int> nums){
    unordered_set<int> seen;

    for(auto &num: nums){
        if(seen.find(num) != seen.end()){
            cout<<"Duplicate found : "<<num<<endl;
            return true;
        }
        seen.insert(num);
    }

    cout<<"No duplicates found"<<endl;
    return false;
}

int main(){
    vector<int> nums;

    int n, ele;

    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    cout<<"Enter the elements of the array:";
    for(int i = 0; i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    bool result = containDuplicates(nums);

    cout<<"Output : "<<(result ? "true" : "false") <<endl;

    return 0;
}