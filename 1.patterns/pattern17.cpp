#include<iostream>
using namespace std;

/*
To develop a pattern like this 
            A   
        A   B   A
    A   B   C   B   A
A   B   C   D   C   B   A
*/

int main(){
    int n = 1;
for(int i = 0;i<=4;i++){
    if(n == 4){
        break;
    }
    for(int j = 1; j<4-i+1; j++){
        cout<<" ";
    }
    char ch = 'A';
    int breakpoint = (2*i + 1)/2;
    for(int k = 1;k<=2*i+1; k++){
        cout<<ch;
        if(k <= breakpoint){
            ch++;
        //cout<<ch;
        }
        else{
           ch--;
        //cout<<ch;
        }
        // if(k==(k/2)+1){
        //     int _a = a;
        //     for(int k = i; k>=1; k--){
        //         _a = _a - 1;
        //         cout<<(char)a;
        //     }
        // }
    }
    for(int l = 1; l<4-i+1; l++){
        cout<<" ";
    }
    cout<<"\n";
    int n = n + 1;
}   
}