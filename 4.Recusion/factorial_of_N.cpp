// find the factorial of a number

#include<iostream>
using namespace std;


int factorial(int n){
if(n == 0){
    return 1;
}
int fact =  n*factorial(n-1);
return fact;

}

int main(){
int n;
int x;
cout<<"Enter the number whose factorial needs to be calculated : ";
cin>>n;
x = factorial(n);
cout<<"The factorial of "<<n<<" is: "<<x;

}