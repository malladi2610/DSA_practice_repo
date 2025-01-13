#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count_subarray_xor(vector<int> &nums, int k){
    unordered_map<int, int> freq;
    int prefix_XOR = 0;
    int count = 0;

    for(int num : nums){
        prefix_XOR ^= num; //This is how the XOR operation is done(I forgot :p)

        if (prefix_XOR==k){
            count+=1;
        }

        if (freq.find(prefix_XOR^k) != freq.end()){
            count += freq[prefix_XOR^k]; //This is done to keep track of all the previous combinations which were possible
        }

        freq[prefix_XOR] += 1;
    }
       cout<<"The final count is:"<<count;
    return count;
}

int main(){
    int n;
    int ele;
    int k;
    vector<int> arr;

    cout<<"Enter the no.of elements of the vector :";
    cin>>n;

    cout<<"Enter the element that needs to match the XOR the sub array :";
    cin>>k;

    cout<<"Enter the elements of the vector :";
    for(int i = 0; i< n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    count_subarray_xor(arr, k);
    return 0;
}