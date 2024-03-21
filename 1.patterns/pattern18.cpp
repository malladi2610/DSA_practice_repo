#include<iostream>
using namespace std;

/*
To develop a pattern like this 
E
DE
CDE
BCDE
ABCDE
*/

int main(){
    char ch = 'E';
    for(int i = 1; i<=5;i++){
        for(int j = 1; j<=i;j++){
            cout<<ch;
            ch++;
        }
        ch = 'E';
        ch = ch - i;
        cout<<"\n";
        
    }
    
}