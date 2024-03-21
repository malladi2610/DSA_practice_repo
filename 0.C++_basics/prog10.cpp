//find the roots of the quadratic equation

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a;
    int b;
    int c;
    int x;
    float r1;
    float r2;
    float img;

    cout<<"Enter the co-efficent of the first variable : ";
    cin>>a;
    cout<<"Enter the co-efficient of the second variable : ";
    cin>>b;
    cout<<"Enter the co-efficent of the third variable : ";
    cin>>c;
    x = b*b - 4*a*c;
    if(x>0){
        cout<<"The roots are real and distinct";
        r1 = (-b + sqrt(x))/2*a;
        r2 = (-b - sqrt(x))/2*a;
        cout<<r1<<endl<<r2<<endl;
    }
    else if(x == 0){
        cout<<"The roots real and equal";
        r1 = (-b)/2*a;
        r2 = (-b)/2*a;
        cout<<r1<<endl<<r2<<endl;
    }
    else if(x<0){
        cout<<"The roots are imaginary";
        r1 = (-b)/2*a;
        r2 = (-b)/2*a;
        img = sqrt(x)/2*a;
        cout<<r1<<endl<<r2<<endl;
    }

}