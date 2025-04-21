#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> leftProduct(n,1);
    vector<int> rightProduct(n,1);
    vector<int> answer(n);

    //compute prefix products
    for(int i = 1; i< n; i++){
        leftProduct[i] = nums[i-1] * leftProduct[i-1];
    }

    //compute suffix products
    for(int i = n - 2; i>=0; i--){
        rightProduct[i] = nums[i+1] * rightProduct[i+1];
    }

    for(int i = 0; i<n;i++){
        answer[i] = leftProduct[i] * rightProduct[i];
    }

    return answer;
}

int main(){
    vector<int> nums;
    int n,ele;

    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements of the array :";
    for(int i = 0; i<n ; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    vector<int> result = productExceptself(nums);

    cout<<"Output :";
    for(int i : result){
        cout<<i<<" ";
    }
    cout<< endl;

    return 0;
}