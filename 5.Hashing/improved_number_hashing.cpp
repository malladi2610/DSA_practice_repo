// The problem of having the hash lenght equal to the largest element of the input array can be solved by using the mapping and this can be done to the character hashing also.

/*The timecomplexity of the maps is O(logn)
The timecomplexity of unordered map is O(1) (This should be the one to get started)*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    //precompute
    //Map stores everything is sorted order
    map<int,int> mpp;
    for(int i = 0; i<n;i++){
        mpp[arr[i]]++;
    }


    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

        //fetch
        cout<<mpp[number]<<endl;
    }

    return 0;
}