#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int consecutive_ones(vector<int> &nums){
    vector<int> counter_storage;
    int counter = 0;

    if(nums.size() == 1 ){
        if(nums[0] ==1){
        cout<<"The maximum consecutive ones = "<<counter+1;
        return 0;
        }

        else{
        cout<<"The maximum consecutive ones = "<<0;
        return 0;
         }
    }
    


    for(int i = 0; i<nums.size(); i++){

        if (nums[i] == 1){
            counter += 1;
        }
        else{
            counter_storage.push_back(counter);
            counter = 0;
        }
    }
    counter_storage.push_back(counter);
    counter = *max_element(counter_storage.begin(), counter_storage.end());
    cout<<"The maximun consecutive ones = "<<counter<<endl;
    return 0;

}


int main(){
    vector<int> nums;
    int n;
    int ele;

    cout<<"Enter the no.of elements of the vector : ";
    cin>>n;

    cout<<"Enter the elements of the vector : ";
    for(int i = 0; i<n;i++){
        
        cin>>ele;
        nums.push_back(ele);
    }

    consecutive_ones(nums);

    return 0;
    }

