#include<iostream>
using namespace std;

/*THe following pattern is expected to be generated
                *
            *   *   *
        *   *   *   *   *
    *   *   *   *   *   *   *
*   *   *   *   *   *   *   *   *                          

To generate this pattern the i and j both needs to be adjustedas follows, the outer loop will remain same to print the no.of rows, but the inner loop j */

int main(){
    int n = 1;
    for(int i = 0; i<5; i++){
        if (n == 6){
            break;
        }
        for(int j = 0;j<5-i-1;j++){
            cout<<" ";
        }
        for(int k = 1;k<=i+n; k++){
            cout<<"*";
        }
        for(int l = 0;l<5-i-1;l++){
            cout<<" ";
        }
        cout<<"\n";
        n = n  + 1;
    }
}