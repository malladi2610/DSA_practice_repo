#include<iostream>
using namespace std;

/*In this the following pattern needs to be generated
1
12
123
1234
12345
It is similar to the pattern 2 but instead of the stars the numbers are used*/

int main(){


    for(int i = 1; i<=5;i++){
        for(int j = 1; j<=i; j++){
            cout<<j;
        }
        cout<<"\n";
 
    }
}