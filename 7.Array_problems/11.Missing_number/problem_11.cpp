#include<iostream>
#include<bits/stdc++.h>
using namespace std;



/*Implementation using the hashmaps*/
void find_missing_number(vector<int> &nums){
    map<int, int> mp;
    int missing = 0;
    for(int i = 0; i<=nums.size(); i++){ //As it is a closed list
        mp[nums[i]] = 1; 
    }

    for(int i = 0; i<=nums.size();i++){
        if(mp.find(i) == mp.end()){
            missing = i;
            break;
        }
    }

    cout<<"The missing number is :"<<missing;
}



/*The working implementation of the same logic (it takes o(n^2))*/
void find_missing_number(vector<int> &nums){
    int missing = 0;
    for(int i = 0; i<=nums.size(); i++){ //As it is a closed list
        bool found = false;
        for(int j = 0; j<nums.size(); j++){
            if(nums[j] == i){
                found = true;
                break;
            }
        }

        if(!found){
            missing = i;
        }       
            
    }
    cout<<"The missing number is :"<<missing;
}



/*This code failed because if the missing of the bool variable that caused incorrect results*/
// void find_missing_number(vector<int> &nums){
//     int missing = 0;
//     for(int i = 0; i<nums.size(); i++){

//         for(int j = 0; j<nums.size(); j++){
//             if(nums[j] == i){
//                 break;
//             }
//             else{
//             missing = i;
//             }
           
//         }       
            
//     }
//     cout<<"The missing number is :"<<missing;
// }

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