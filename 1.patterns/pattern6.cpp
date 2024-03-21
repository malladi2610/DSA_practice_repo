#include<iostream>
using namespace std;

/*In this the following pattern needs to be generated 
12345
1234
123
12
1

This pattern generation follows the same pattern as the pattern 5, where the value of j to be printed in the inner for loops, the conditon for the inner for loop remains the same
 */

int main(){
    for(int i = 1; i<=5;i++){
        for(int j = 1; j<=5-i+1; j++){
            cout<<j;
        }

        cout<<"\n";
    }
}