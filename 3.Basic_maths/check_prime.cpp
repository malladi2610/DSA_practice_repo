#include <iostream>
#include<cmath>
using namespace std;
int isprime(int n){
    float x;
    x = sqrt(n);
    for(int i = 2; i<=x;i++){
        if(n%i == 0){
        cout<<"Not prime";
        return 0;
            
        }
    }
    cout<<"Prime";
    return 0;
}
int main() {
    // Write C++ code here
    int n;
    cout << "Enter the no. ";
    cin>>n;
    isprime(n);
    return 0;
}