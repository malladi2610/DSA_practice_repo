#include<iostream>
using namespace std;

/*The pattern geenrated her is the compbination for the 7 and 8th pattern. 
So, the solution should be compning both the  programs*/

int main(){
     int n = 1;
    for(int i = 0; i<5; i++){
        if (n == 6){
            break;
        }
        for(int j = 0;j<5-i-1;j++){
            cout<<" ";
        }
        for(int k = 1;k<=i+n; k++){
            cout<<"*";
        }
        for(int l = 0;l<5-i-1;l++){
            cout<<" ";
        }
        cout<<"\n";
        n = n  + 1;
    }

    n = 0;
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