#include<iostream>
using namespace std;

void solution(int i , int n){
    if(i>n){
        return;
    }

    cout<<"MNS"<<endl;
    solution(i+1,n);

}

int main(){

    int n = 0,i = 1;
    cout<<"Enter the no.of times the name needs to be printed";
    cin>>n;

    solution(i,n);
}