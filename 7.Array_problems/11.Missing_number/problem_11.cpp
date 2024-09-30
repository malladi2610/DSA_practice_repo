#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void find_missing_number(vector<int> &nums){
    int missing = 0;
    for(int i = 0; i<nums.size(); i++){

        for(int j = 0; j<nums.size(); j++){
            if(nums[j] == i){
                break;
            }
            else{
            missing = i;
            }
           
        }       
            
    }
    // unordered_map<int, int> umap;
    // for (int i=0;  i<nums.size(); i++){
    //     if(umap[])
    // }
    cout<<"The missing number is :"<<missing;
}

int main(){
    vector<int> nums;
    int n;
    int ele;

    cout<<"Enter the no.of elements of the array : ";
    cin>>n;

    cout<<"Enter the elements of the array : ";
    for(int i = 0; i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }


    find_missing_number(nums);

}