//This problem is the modified version of the Boyer-Moore voting algorithm and it has two majority elements as n/3 gives a smaller subset then the n/2 which gives two subsets

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
The `&` sign in `vector<int> &nums` indicates that the parameter `nums` is being passed by reference to the function `majority_element`.

Here are the key reasons for using a reference:

1. **Efficiency**: Passing by reference avoids making a copy of the entire vector, which can be expensive in terms of both time and memory, especially for large vectors. Instead, the function operates directly on the original vector.

2. **Modifications**: If the function needs to modify the contents of the vector, passing by reference allows these modifications to affect the original vector. This is useful if the function needs to update the vector in place.

3. **Consistency**: Passing by reference ensures that any changes made to the vector within the function are reflected outside the function, maintaining consistency between the function's operations and the original data.

In summary, using `vector<int> &nums` allows the function to efficiently and directly manipulate the original vector without the overhead of copying it.
*/


/*This code uses the Boyer-Moore Voting Algorithm to find the majority elements. It first identifies potential candidates and then verifies if they are indeed the majority elements by counting their occurrences in the second pass.*/

vector<int> majority_element(vector<int> &nums){
    int canditate_1 = 0, canditate_2 = 0;
    int count_1 = 0, count_2 = 0;
    vector<int> result;

    /*Candidate selection phase*/
    for(int i =0; i<nums.size(); i++){
        if(nums[i] == canditate_1){
            count_1 += 1;
        }

        else if(nums[i] == canditate_2){
            count_2 += 1;
        }

        else if(count_1 == 0){
            canditate_1 = nums[i];
            count_1 = 1;
        }

        else if(count_2 == 0){
            canditate_2 = nums[i];
            count_2 = 1;
        }

        else{
            count_1 -= 1;
            count_2 -= 1;
        }

    }

    count_1 =0;
    count_2 = 0;

    /*Candidate Verification phase*/
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == canditate_1) {
            count_1 += 1;
        } else if (nums[i] == canditate_2) {
            count_2 += 1;
        }
    }

    /*Majority candidates to result*/
    if(count_1 > nums.size()/3){
        result.push_back(canditate_1);
    }

    if(count_2 > nums.size()/3){
        result.push_back(canditate_2);
    }


    cout<<"The majority elements are:";
    for(int i = 0; i< result.size(); i++){
        cout<<result[i];
        cout<<" ";
    }
    
    return result;

}

int main(){
    int n, ele;
    vector<int> nums;

    cout<<"Enter the values of no.of elements of the array : ";
    cin>>n;

    cout<<"Enter the value of the elements of the array :";
    for(int i = 0; i< n; i++){
        cin>>ele;
        nums.push_back(ele);
    }
    majority_element(nums);

    return 0;
}