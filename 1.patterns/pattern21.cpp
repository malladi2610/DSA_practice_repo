#include<iostream>
using namespace std;

/*
To develop a pattern like this 
It's a combination of different previous patterns refer to the previous implemention,
Here is the link for the design - https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/
*/

int main(){
    for(int i = 1;i<=4;i++){
        for(int j =1 ;j<=4;j++){
            if(i == 1 || j == 1 || i ==  4|| j == 4){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<"\n";
    }
}