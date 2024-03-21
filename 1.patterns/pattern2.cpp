#include<iostream>
using namespace std;

/*In this a pattern like this needs to be generated 
*
**
***
****
*****

To generate this pattern the following logic needs to be followed,
1. One main for loop to generate 5 lines
2. As the no.of columns are being incremented, initially empty space is printed and as proceeds the no.of empty spaces decrease and the values gets printed*/

int main(){
    int n = 1;
    for(int i = 0; i<5; i++){
        for(int j = 0; j < n; j++){
            if(n==6){
                break;
            }
            cout<<"*";
           


        }

        cout<<"\n";
         n = n+1;

    }
}