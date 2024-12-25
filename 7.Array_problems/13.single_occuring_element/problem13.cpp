#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int single_occuring_element(vector<int> &nums){
    map<int,int> mp;

    for(int num: nums){
        mp[num]++;
    }

    int elementoccuronce = -1;
    for (auto &pair : mp){
        if(pair.second == 1){
            elementoccuronce = pair.first;
            break;
        }
    }

    if(elementoccuronce != -1){
        cout<<"Element that occue once is : "<<elementoccuronce<<endl;;
    } else {
        cout<<"No element appears exactly once"<< endl;
    }

    return 0;

}


int main(){
    vector<int> nums;
    int n;
    int ele;

    cout<<"Enter the no.of elements of the vector";
    cin>>n;

    cout<<"Enter  the elements of the vector";
    for(int i=0; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    single_occuring_element(nums);

    return 0;
}