#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> solution(int n){
    vector<int> v;
    int  i  = 2;
    v.push_back(1);

    do{
        if(n%i == 0){
            v.push_back(i);
        }
        i = i + 1;
    }while(i!=n);

    v.push_back(i);

    return v;

}



int main(){
    int n = 0;
    vector <int> ans;
    cout<<"Enter the number for which the divisors need to be found : ";
    cin>>n;

    ans = solution(n);


    cout << "The elements in the vector: ";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout<< * it << " ";





    
}