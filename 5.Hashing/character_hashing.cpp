/*
1. IN case of the range of the characters specified as the smaller letters from the alphabet series then to add the data to the hash the substraction needs to be done to add the letter's frequency to the correct position
2. If there are capital letters from the alphabet series then there is no need to do the substraction as the entire range of the ASCII would be considered*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    //precompute
    int hash[26] = {0};
    for(int i = 0; i<s.size();i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;

        //fetch
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}