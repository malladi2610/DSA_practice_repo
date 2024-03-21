//Check whether a given number is a leap year or not

#include<iostream>
using namespace std;

int main(){
    int year;

    cout<<"Enter a year : ";
    cin>>year;
// "/" is used for the remainder, "%" is used for the quotient
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%400 == 0){
                cout<<"The year "<<year<<" is a leap year";
            }
            else{
                cout<<"The year "<<year<<" is not a leap year";
            }       
        }
        else{
           cout<<"The year "<<year<<" is a leap year"; 
        }
    }
    else{
        cout<<"The year "<<year<<" is not a leap year";
    }

}