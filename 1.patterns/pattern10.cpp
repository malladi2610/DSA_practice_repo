#include<iostream>

using namespace std;

/*This is the pattern that needs to be generate 
*
**
***
****
*****
****
***
**
* 

To generate this pattern, it is simple, the pattern increase until a cretain point and then starts to drop
*/
int main(){
     for(int i = 1; i<=9; i++){
    int stars = i;
    if(stars > 5 ){
        stars = 10-i;
    } 
        for(int j = 1; j <=stars; j++){
            
            cout<<"*";
           


        }

        cout<<"\n"; 

    }
}