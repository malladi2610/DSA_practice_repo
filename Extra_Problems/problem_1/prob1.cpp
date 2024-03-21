#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
1. Sort the array
2. Create a dictionay of the frequencies
3. Then save the data to the sum*/


int largest_sum_of_weights(int N, int a[], int b[],int m){
    int res[3000] = {0};
    int sum = 0;
    int weight[3000] = {0};
    map<int,int> mp;

    // for(int i = 0; i<m;i++){
    //     cout<<a[i]<<" ";
    // }

    // for(int i = 0; i<m;i++){
    //     cout<<b[i]<<" ";
    // }

    int i=0,j=0,k=0;

    while(i<m){
        res[k] = a[i];
        i = i + 1;
        k = k + 1;
    }
    while(j<m){
        res[k] = b[j];
        j = j + 1;
        k = k + 1;        
    }
    // for(int i = 0; i < 2 * m; i++){
    //     cout<<res[i]<<endl;
    // }    


    sort(res, res+2*m);
    for(int i = 0; i < 2*m; i++){
        cout<<res[i]<<endl;
    }

    for(int i = 0; i< sizeof(res)/sizeof(res[0]); i++){
        mp.insert({res[i],count(res,res+2*m,res[i])});
    }
    
    vector<pair<int,int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), [](const pair<int, int>&a, const pair<int,int>&b){
        return a.second > b.second;
    });
    cout << "Elements sorted by frequency:" << endl;
    cout << "Element\tFrequency" << endl;
    for (auto& it : vec) {
        cout << it.first << "\t" << it.second << endl;
    }


        for(auto& it : vec){
            sum = sum + it.second*N;
            N = N -1;
        }


    cout<<sum;

    //Print the sorted array first
    return 0;
}


int main(){
    int N,M,sum;
    int A[1000], B[1000];

    cout<<"Enter the no.of vertices in the graph";
    cin>>N;
    cout<<"Enter the no.of edges in the graph";
    cin>>M;
    cout<<"Enter the elements of the array A";
    for(int i = 0;i<M;i++){
        cin>>A[i];
    }
    cout<<"Enter the elements of the array B";
    for(int i =0;i<M;i++){
        cin>>B[i];
    }

    sum = largest_sum_of_weights(N,A, B,M);

}