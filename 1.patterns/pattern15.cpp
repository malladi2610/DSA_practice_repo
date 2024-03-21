#include<iostream>
using namespace std;

/*
This is pattern is simialr to the 5th one but instead of stars the alphabets are usd
The logic is as follows*/

int main(){
    int i = 0, j = 5;
    for(int i = 1;i<=5; i++){
        int n = 64;
        for(int j = 1; j<= 5-i+1; j++){
            n = n + 1;
            cout<<(char)n;
        }
        cout<<"\n";
    }
}