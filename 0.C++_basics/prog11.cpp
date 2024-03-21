//Calculate the sm of natural numbers

#include<iostream>
using namespace std;

int main(){
    int n;
    int sum;
    cout<<"Enter the value of the n :";
    cin>>n;
    sum = (n * (n + 1))/2;
    cout<<"The sum of"<<n<<"natural no. is : "<<sum;
}