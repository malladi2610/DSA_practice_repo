//Find the reverse of the string

#include<iostream>
using namespace std;

int main(){
    int n,reversed_number = 0, remainder;
    cout<<"Enter the number :";
    cin>>n;
    while(n != 0){
        remainder = n % 10;
        reversed_number = reversed_number*10 + remainder;
        n /= 10;

    }
    cout<<reversed_number;


}