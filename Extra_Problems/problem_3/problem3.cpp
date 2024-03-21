/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

#include<iostream>
#include<bits\stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

         int sum;
        vector<int> sol;

   
        for(auto i = 0; i < nums.size() ; i++){
            for(auto k = 1; k < nums.size(); k++){

                if(i != k){sum = nums[i] + nums[k];}

                if(sum == target){
                    if(i == k){
                        k = k + 1;
                        sol.push_back(i);
                        sol.push_back(k);
                        return sol;
                    }

                    sol.push_back(i);
                    sol.push_back(k);

                    return sol;
                   
                }
            }
        }

    return sol;
    } 

int main(){
    vector<int> ans;
    vector<int> ele;
    int elem, n = 0, x = 0;

    cout<<"Enter the no.of elements of the array : "<<endl;
    cin>>n;

    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0; i< n; i++){
        cin>>elem;
        ele.push_back(elem);
    }

    cout << "The elements in the vector: "<<endl;
    for (auto it = ele.begin(); it != ele.end(); it++)
        cout<< * it << " ";

    cout<<"Enter the target number :"<<endl;
    cin>>x;

    ans = twoSum(ele, x);


    cout << "The elements in the vector: "<<endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout<< * it << " ";
}