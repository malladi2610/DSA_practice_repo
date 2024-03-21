//generate multiplication table

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value to get table : ";
    cin>>n;
    for(int i = 1;i<=10;i++){
        cout<<n<<" x "<<i<<" = "<<n*i<<endl;
    }
}