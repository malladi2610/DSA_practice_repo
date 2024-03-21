//Find the largest no.of the three numbers

#include<iostream>
using namespace std;

int main(){
    int x;
    int y;
    int z;

    cout<<"Enter the first no. :";
    cin>>x;
    cout<<"Enter the second no. :";
    cin>>y;
    cout<<"Enter the thrid no. :";
    cin>>z;

    if(x>y){
        cout<<"The number"<<x<<"is greater than"<<y<<endl;
        if(x>z){
        cout<<"The number"<<x<<"is greater than"<<z<<endl;
        cout<<x<<"is the greatest"<<endl;
        }
        else{
        cout<<"The number"<<z<<"is greater than"<<x<<endl;
        cout<<z<<"is the greatest"<<endl;
        }
    }
    else{
        cout<<"The number"<<y<<"is greater than"<<x<<endl;
        if(y > z){
            cout<<"The number"<<y<<"is greater than"<<x<<endl;
            cout<<y<<"is the greatest"<<endl;
        }
        else{
        cout<<"The number"<<z<<"is greater than"<<x<<endl;
        cout<<z<<"is the greatest"<<endl;
        }
    }
}