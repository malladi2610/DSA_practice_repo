#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int unique_path(int m, int n){
    vector<int> dp(n,1);

    for(int i = 1; i<m;i++ ){
        for(int j = 1; j<n; j++){
            dp[j] = dp[j] + dp[j-1];
        }
    }

    cout<<"The no.of unique paths are "<<dp[n-1];
    return dp[n-1];
}


int main(){
    int m, n;

    cout<<"Enter the no.of rows in the grid";
    cin>>m;

    cout<<"Enter the no.of columns in the grid";
    cin>>n;

    unique_path(m,n);

    return 0;
}