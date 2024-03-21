#include<iostream>
using namespace std;

/*
To develop a pattern like this 
A   
BB
CCC
DDDD
EEEEE
*/

int main(){
    int n = 64;
    for(int i = 1; i<=5; i++){
        n = n + 1;
        for (int j = 1; j<=i;j++){
            cout<<(char)n;
        }
        cout<<endl;
    }
}