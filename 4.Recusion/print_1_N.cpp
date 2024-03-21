#include<iostream>
using namespace std;


void solution(int i, int n){
    if(i>n){
        return;
    }

    cout<<i<<endl;
    solution(i+1,n);
}

int main(){
    int i = 1, n = 0;

    cout<<"Enter the no.of times the loop needs to run";
    cin>>n;

    solution(i,n);
}