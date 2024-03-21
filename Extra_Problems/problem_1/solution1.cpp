#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solution(int a[],int k, int n){
    map<int,int> mp;

    for(int i = 0; i<sizeof(a)/sizeof(a[0]); i++){
        mp.insert({a[i], count(a,a+n,a[i])});
    }
    cout<< "Elements present in the map: "<<endl;
    cout<<"key\tElement"<<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<< it -> first << "\t" << it->second<<endl;
    }


    
}


int main(){
    int a[1000],k,n,same_height;

    cout<<"Enter the no.of nails on the board";
    cin>>n;

    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Enter the no.of nails that can be hammered";
    cin>>k;

    same_height = solution(a,k,n)
}