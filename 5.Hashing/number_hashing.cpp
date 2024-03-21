/*There is a problem with this code, as when ever a hash is used the it's lenght is equal to the largest element in the array. Which leads to wastage of space. This can be solved by maps*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int  n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }


    //precompute
    int hash[13] = {0};
    for(int i = 0; i< n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << hash[number] <<endl;
    }

    return 0;
}