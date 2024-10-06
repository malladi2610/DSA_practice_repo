#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int consecutive_ones(vector<int> &nums){
    int cons = 0;
    int counter = 0;

    if(nums.size() == 1 && nums[0==1]){
        cout<<"The maximum consecutive ones = "<<cons+1;
        return 0;
    }


    for(int i = 0; i<nums.size(); i++){

        if (nums[i] == 1){
            counter += 1;
        }
        else{
            cons = counter;
            counter = 0;
        }
    }
    cons = counter;
    cout<<"The maximun consecutive ones = "<<cons;
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

