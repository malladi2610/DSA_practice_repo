//Find the quotient and remainder

#include<iostream>
using namespace std;

int main(){
    int x;
    int y;
    cout<<"Enter the numerator :";
    cin>>x;
    cout<<"Enter the denominator : ";
    cin>>y;
    while(y != 0){
        cout<<"The quotient is : "<<x/y<<endl;
        cout<<"The remainder is : "<<x%y<<endl;
        return 0;
    }
    cout<<"Invalid division";
    return 0;
}