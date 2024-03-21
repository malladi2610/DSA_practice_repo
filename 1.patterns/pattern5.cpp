#include<iostream>
using namespace std;

/*This pattern is as follows
*****
****
***
**
*

To generate this pattern the value of i, which represents the rows will be incrementing and value of j which represents the columns will be decrementing 
and the value of j will be printed*/

int main(){
    int i =0,j=5;
    for(i = 1; i<=5;i++){
        for(j = 1; j<=5-i+1; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
}