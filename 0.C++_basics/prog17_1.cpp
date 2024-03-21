//finding the LCM the other way using GCD
#include<iostream>
using namespace std;

int main(){

    int n1,n2,hcf,temp,lcm;

    cout<<"Enter the two number";
    cin>>n1>>n2;

    hcf = n1;
    temp = n2;

    while(hcf != temp){
        if(hcf > temp)
        hcf = hcf - temp;
        else
        temp = temp - hcf;
    }
    lcm = (n1*n2)/hcf;

    cout<<"LCM = "<<lcm;
    return 0;

}