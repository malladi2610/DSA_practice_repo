#include<iostream>
using namespace std;

/*
IN this I have to generate a pattern in this way
1
22
333
4444
55555

In this pattern value of 'i' is printed 'j' times, to undertand it better i value takes care of the rows, whihc remain constant in the entire execution and 
the value of J is the one which represents the columns and changes for every column*/

int main(){
    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=i; j++){
            cout<<i;
        }
        cout<<"\n";
    }
}