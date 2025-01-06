#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longest_sub_array(vector<int> &arr, int k){
    long long prefix_sum = 0; //This is the sum that stores the intermediate computations
    int max_length = 0; //The value that needs to be output
    bool found = false;

    unordered_map<long long, int> prefixIndices;
    prefixIndices[0] = -1; // This indicactes that a intermediate sum of 0 exists before index -1

    for (int i = 0; i<arr.size(); i++){
        prefix_sum += arr[i];

        if(prefix_sum == k){
            found = true;
            max_length = max(max_length, i+1);
        }

        // Check if prefix_sum -k exsitis in the map
        if(prefixIndices.find(prefix_sum - k) != prefixIndices.end()){
            found = true;
            int startIndex = prefixIndices[prefix_sum - k];
            int length = i - startIndex;
            max_length = max(max_length, length);
        }

        // Store prefix_sum in map if not present (to ensure longest subarray)
        // We only store the first occurrence because we want the longest subarray
        // and having the earliest start index is beneficial for maximizing length.
        if(prefixIndices.find(prefix_sum) == prefixIndices.end()) {
            prefixIndices[prefix_sum] = i;
        }
    }
    
    cout<<"The maximum length is :"<<max_length;
    return found ? max_length :0;
        
}

int main(){
    int n;
    int ele;
    int k;
    vector<int> arr;

    cout<<"Enter the no.of elements of the vector :";
    cin>>n;

    cout<<"Enter the maximum sum of the sub array :";
    cin>>k;

    cout<<"Enter the elements of the vector :";
    for(int i = 0; i< n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    longest_sub_array(arr, k);

    return 0;
    
}
