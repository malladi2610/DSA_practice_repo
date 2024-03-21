#include<iostream>
using namespace std;
/*
This is the pattern that needs to be generated, 

it's d0ne in the follow ways, Its exactly opposite to the previous pattern 7, but in the reverse order.
This is done as shown below*/

int main(){
    int n = 0;
    for(int i = 0; i<5;i++){
        for(int j = 0; j<i; j++){
            cout<< " ";
        }
        for(int k = 9; k>=2*i + 1;k--){ //Or k>n+i
            cout<<"*";
        }
        for(int l = 0; l<i; l++){
            cout<< " ";
        }
        cout<<"\n";
        n = n+1;
    }

}