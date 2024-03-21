#include<iostream>
using namespace std;
/*This pattern is similar to the pattern 3, but instead of numbers the alphabets are used
the ASCII values are used to print alphabets and these values start from 65 to 90
the logic is as follows*/

int main(){
for(int i = 1; i<=5; i++){
    int n = 64;
    for(int j = 1; j<=i; j++){
        n = n + 1;
        cout<<(char)n;
    }
    cout<<"\n";
}
}