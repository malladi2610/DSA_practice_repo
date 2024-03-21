#include<iostream>
using namespace std;

/*
To develop a pattern like this 
It's a combination of different previous patterns refer to the previous implemention,
Here is the link for the design - https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/
*/

int main(){
    //space increases
    int n  = 1;
    for(int i = 5;i>1;i--){
        for(int j = 1; j<=i; j++){
            cout<<"*";
        }
        for(int k =0; k<2*n-2;k++){
            cout<<" ";
        }
        for(int l = 1;l<=i;l++){
            cout<<"*";
        }
        cout<<"\n";
        n = n+1;
    }

    //space decreases
    for(int i = 1;i<=5;i++){
        for(int j = 1; j<=i; j++){
            cout<<"*";
        }
        for(int k = 1; k<=10-2*i;k++){
            cout<<" ";
        }
        for(int l = 1;l<=i;l++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
}