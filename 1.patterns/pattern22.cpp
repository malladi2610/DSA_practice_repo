#include<iostream>
using namespace std;

/*
To develop a pattern like this 
It's a combination of different previous patterns refer to the previous implemention,
Here is the link for the design - https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/
*/

int main(){
    for(int i = 1; i<=7;i++){
        for(int j = 1; j<=7; j++){
            if(i == 1 || j == 1 || i== 7|| j== 7){
                cout<<"4";
            }
            else if(i == 2 || j == 2 || i== 6|| j== 6){
                cout<<"3";
            }
            else if(i == 3 || j == 3 || i== 5|| j== 5){
                cout<<"2";
            }
            else if(i == 4 || j == 4 || i== 4|| j== 4){
                cout<<"1";
            }
        }
        cout<<"\n";
    }
    
}