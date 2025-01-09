#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int pow(int x, int n){
    int sol = 1;
    int num = x;
    int raise_to = n;

    if(n == 0){
        cout<<"The solution of"<<x<<"to the power of "<<n<<"is "<<"1";
    }
    long long abs_n = n;

    if(n < 0){
        x = 1/x;
        abs_n = -static_cast<long long>(n);
    }

    while(n > 0){
        if (n%2 == 1){
            sol = sol * x;
        }

        x = x*x;
        n = n/2;
    }
    cout<<"The solution of"<<num<<"to the power of "<<raise_to<<"is "<<sol;
    return sol;
}
int main(){
    int n, x;

    cout<<"Enter the values of the numbers whose power needs to be found:";
    cin>>n;

    cout<<"Enter the value of the power";
    cin>>x;

    pow(n,x);

    return 0;
}


