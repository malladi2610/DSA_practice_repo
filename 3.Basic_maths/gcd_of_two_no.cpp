//find the GCD
//Algorithm

#include<iostream>
using namespace std;

int main(){
    int x1,x2,i,n,gcd,temp;
    cout<<"Enter two numbers to find the GCD";
    cin>>x1>>x2;

    if(x2>x1){
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    for(int i = 1; i<=x2; i++){
        if(x1%i == 0 && x2%i == 0){
            gcd = i;
        }
    }
    cout<<"GCD = "<<gcd;

}